@echo off
setlocal

set BUILD_DIR=build

if exist %BUILD_DIR% (
    echo Cleaning existing build directory...
    rmdir /s /q %BUILD_DIR%
)

mkdir %BUILD_DIR%

cd /d %BUILD_DIR%

cmake -G "MinGW Makefiles" .. > NUL
make > NUL
main.exe

