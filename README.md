Shakal Bass Booster 3000
A high-performance C++ application with a Qt6 graphical interface designed to transform clean audio into "Deep Fried" / "Earrape" masterpieces. This tool leverages the power of the FFmpeg engine to apply aggressive digital signal processing (DSP) in real-time.

Features
Extreme Bass Boost: Sub-frequency gain (up to +50dB) centered at 60Hz for maximum desk-shaking impact.

Shakal Mode (Distortion): Dynamic bitcrushing that reduces audio bit-depth to create that signature "crunchy" and "sandy" lo-fi noise.

Digital Clipping: Intentionally drives volume beyond 0dB to force hard-clipping distortion.

Echo Resonator: Adds a tight, metallic echo to simulate the "audio in a trash can" effect.

Non-Blocking UI: Uses QProcess for asynchronous rendering, so the GUI remains responsive during processing.

Prerequisites
To build and run this application (recommended for Arch/CachyOS or any modern Linux), ensure the following are installed:

Compiler: GCC (g++) with C++17 support.

Framework: Qt6 (base).

Engine: FFmpeg (must be available in your $PATH).

Build Tools: cmake or pkg-config.

Bash
# Install dependencies on Arch/CachyOS
sudo pacman -S base-devel cmake qt6-base ffmpeg
🚀 Building the Project
Option 1: Using CMake (Recommended)
Ensure your configuration file is named exactly CMakeLists.txt (case-sensitive).

Run the following:

Bash
mkdir build && cd build
cmake ..
make
./BassBooster
Option 2: Manual Compilation via g++
If you prefer a direct approach without CMake:

Bash
# Generate Qt Meta-Object code
/usr/lib/qt6/moc main.cpp -o main.moc

# Compile with Qt6 flags
g++ main.cpp -o ShakalBoost -fPIC $(pkg-config --cflags --libs Qt6Widgets)

# Run
./ShakalBoost
 How to Use
Click "Select song" to load your .mp3 or .wav file.

Dial up the "Bass power" for low-end pressure.

Max out the "Shakal Level" to embrace true digital chaos.

Hit "ShakalBoost by el punch" and choose your output destination.

 Disclaimer
WARNING: This application is capable of generating extremely loud and distorted signals.

DO NOT listen to the output at max volume on headphones.

The author is not responsible for blown speakers, terrified pets, or permanent hearing loss.

Built with C++, Qt6, and a total disregard for audio fidelity.

sry for the ai readme, I didn't have time for that. But TS is selfcode, don't scold me
