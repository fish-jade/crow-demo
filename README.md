# Galaxy
```
mkdir build
cd build
conan install .. --build missing -s build_type=Debug
cmake .. -DCMAKE_BUILD_TYPE=Debug --preset conan-release
cd Debug
make
./galaxy
```