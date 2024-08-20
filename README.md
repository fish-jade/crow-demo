# Galaxy
## 快速开始
```
mkdir build
cd build
conan install .. --build missing -s build_type=Release
cmake .. --preset conan-release
cd Release
cmake --build --preset conan-release
```