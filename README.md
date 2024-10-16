I made this with vs code by the way, if you couldn't tell from the .vscode folder. I built using MSYS2 with the command:
windres resource.rc -o resource.o 
g++ -g main.cpp resource.o -o notepad_clone.exe -mwindows -luser32 -lgdi32 -lcomdlg32 -static-libgcc -static-libstdc++
