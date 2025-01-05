the assembly file was already converted to an object file, so you can build with:
g++ main.o resource.o -o notepad.exe -mwindows -luser32 -lgdi32 -lcomdlg32 -lcomctl32 -lshlwapi -static-libgcc -static-libstdc++
or build directly from assembly if you really want im not gonna stop you.