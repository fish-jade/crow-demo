# Galaxy
## 快速开始
```
mkdir build
cd build
conan install .. --build missing -s build_type=Release
cmake .. -DCMAKE_BUILD_TYPE=Release --preset conan-release
cd Release
make
```

## 安装conan
```
conan profile detect
```

## 在ubuntu中交叉编译
```
conan profile detect --name rc-build-root // conan2.x

vi rc-build-root


[settings]
os=Linux
arch=armv8
compiler=gcc
compiler.version=9
compiler.libcxx=libstdc++11

[conf]
tools.build:compiler_executables={'c': 'aarch64-rockchip-linux-gnu-gcc', 'cpp': 'aarch64-rockchip-linux-gnu-g++'}

```
### ubuntu conan
直接安装的conan是3.10.2版本比较旧
建议用pip进行安装

### 安装conan依赖
```
mkdir build
cd build
conan install .. -pr=rc-build-root --build missing -s build_type=Release
cmake .. -DCMAKE_BUILD_TYPE=Release --preset conan-release
cd Release
make
```