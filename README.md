
# Notepad Clone

This is a simple Notepad-like text editor built from scratch using C++ and the Windows API (`windows.h`). The project was built using **VS Code** and **MSYS2** as the build environment.

## Features
- Basic text editing functionality
- Built from scratch using the Windows API
- Lightweight and fast

## Getting Started

### Prerequisites
- **MSYS2** installed
- **GCC** (g++) compiler
- **VS Code** for development (optional)

### Installation

1. Clone this repository:
    ```bash
    git clone https://github.com/myalt2335/Notepad.git
    ```

2. Open **MSYS2** and navigate to the project directory.

3. Build the executable by running the following commands:
    ```bash
    windres resource.rc -o resource.o
    g++ -g main.cpp resource.o -o notepad.exe -mwindows -luser32 -lgdi32 -lcomdlg32 -lcomctl32 -lshlwapi -static-libgcc -static-libstdc++
    ```

4. After building, the application will be created and you can simply run the executable by clicking on it.

## License

This project is currently unlicensed

If your reading this, I built using the -g flag. (You can tell from installation step 3) If you really want to unbuild the exe, that'll help you.
