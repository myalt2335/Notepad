
# Notepad Clone

This is a simple Notepad clone built from scratch using C++ and the Windows API (`windows.h`). 

This project was built using **VS Code** and **MSYS2** as the build environment.

## Features
- Basic text editing functionality
- High speed

## Getting Started

### Prerequisites
- **MSYS2** installed
- **GCC** (g++) compiler
- **VS Code** for development (optional)

### Installation

Simply download the latest release, alternatively if you want to build it yourself:

### Building it

1. Clone this repository:
    ```bash
    git clone https://github.com/myalt2335/Notepad.git
    ```

2. Open **MSYS2** and navigate to the project directory.

3. Build the executable by running the following commands:
    ```bash
    windres resource.rc -o resource.o
    g++ main.cpp resource.o -o notepad.exe -mwindows -luser32 -lgdi32 -lcomdlg32 -lcomctl32 -lshlwapi -static-libgcc -static-libstdc++
    ```

4. After building, the application will be created and you can simply run the executable by clicking on it.

## License

This project is currently unlicensed
