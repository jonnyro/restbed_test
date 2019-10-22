cmake -DCMAKE_TOOLCHAIN_FILE=C:\git\vcpkg\scripts\buildsystems\vcpkg.cmake -DVCPKG_TARGET_TRIPLET=x64-windows -G "Visual Studio 15 2017" -A x64
cmake --build .
REM Debug\main.exe