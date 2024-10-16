
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
    cd notepad-clone
    ```

2. Open **MSYS2** and navigate to the project directory.

3. Build the executable by running the following commands:
    ```bash
    windres resource.rc -o resource.o
    g++ -g main.cpp resource.o -o notepad_clone.exe -mwindows -luser32 -lgdi32 -lcomdlg32 -static-libgcc -static-libstdc++
    ```

4. After building, run the executable:
    ```bash
    ./notepad_clone.exe
    ```

### VS Code Configuration

If you're using **VS Code**, the `.vscode` folder contains pre-configured settings and tasks for building the project.

## License

This project is currently unlicensed
