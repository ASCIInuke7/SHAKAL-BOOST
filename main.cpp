#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QSlider>
#include <QLabel>
#include <QFileDialog>
#include <QProcess>
#include <QMessageBox>
#include <QFileInfo>

class MegaBassBooster : public QWidget {
    Q_OBJECT
public:
    MegaBassBooster(QWidget *parent = nullptr) : QWidget(parent) {
        setWindowTitle("Shakal Bass Booster 3000");
        resize(450, 300);

        QVBoxLayout *layout = new QVBoxLayout(this);

        btnSelect = new QPushButton("Select song", this);
        lblFile = new QLabel("File is not selected", this);
        lblFile->setWordWrap(true);

        layout->addWidget(new QLabel("Bass power (Gain):"));
        sliderBass = new QSlider(Qt::Horizontal);
        sliderBass->setRange(0, 50);
        sliderBass->setValue(20);
        layout->addWidget(sliderBass);

        layout->addWidget(new QLabel("Shakal level (Distortion/Bitcrush):"));
        sliderShakal = new QSlider(Qt::Horizontal);
        sliderShakal->setRange(1, 10);
        sliderShakal->setValue(1);
        layout->addWidget(sliderShakal);

        btnGo = new QPushButton("ShakalBoost by el punch", this);
        btnGo->setEnabled(false);
        btnGo->setStyleSheet("background-color: #ff4444; color: white; font-weight: bold;");

        layout->addWidget(btnSelect);
        layout->addWidget(lblFile);
        layout->addStretch();
        layout->addWidget(btnGo);

        process = new QProcess(this);

        connect(btnSelect, &QPushButton::clicked, this, &MegaBassBooster::pickFile);
        connect(btnGo, &QPushButton::clicked, this, &MegaBassBooster::boom);
        connect(process, &QProcess::finished, this, &MegaBassBooster::done);
    }

private slots:
    void pickFile() {
        path = QFileDialog::getOpenFileName(this, "Select", "", "Audio (*.mp3 *.wav)");
        if (!path.isEmpty()) { 
            lblFile->setText(path); 
            btnGo->setEnabled(true); 
        }
    }

    void boom() {
        QString out = QFileDialog::getSaveFileName(this, "Save result", "SHAKAL_" + QFileInfo(path).fileName());
        if (out.isEmpty()) return;

        btnGo->setEnabled(false);
        btnGo->setText("Bastboosting...");

        int b = sliderBass->value();
        int s = sliderShakal->value();

        double bits = 16.0 - (s * 1.2);
        QString filter = QString("bass=g=%1:f=60:w=0.5,acrusher=bits=%2:mode=log,volume=%3dB,aecho=0.8:0.9:20:0.3")
                         .arg(b).arg(bits).arg(s * 5);

        process->start("ffmpeg", {"-y", "-i", path, "-af", filter, out});
    }

    void done() {
        btnGo->setEnabled(true);
        btnGo->setText("ShakalBoost by el punch");
        QMessageBox::information(this, "ShakalBoost", "BassBoosted!");
    }

private:
    QPushButton *btnSelect, *btnGo;
    QLabel *lblFile;
    QSlider *sliderBass, *sliderShakal;
    QProcess *process;
    QString path;
};

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    MegaBassBooster w;
    w.show();
    return a.exec();
}
#include "main.moc"