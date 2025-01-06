the assembly file was already converted to an object file, so you can build with:

g++ main.o resource.o -o notepad.exe -mwindows -luser32 -lgdi32 -lcomdlg32 -lcomctl32 -lshlwapi -static-libgcc -static-libstdc++

or build directly from assembly if you really want im not gonna stop you.

This assembly code was generated from C++ and is likely targeted for the x64 (64-bit) architecture. If it is indeed 64-bit, it will not be compatible with 32-bit systems. Additionally, this code relies on Windows-specific APIs and is therefore not portable to non-Windows platforms. (sorry, Linux users)
