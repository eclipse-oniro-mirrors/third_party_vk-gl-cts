add_definitions(-DDE_OS="DE_OS_UNIX")
add_definitions(-DDE_COMPILER="DE_COMPILER_CLANG")
add_definitions(-DDE_CPU="DE_CPU_ARM")
set(CMAKE_CROSSCOMPILINGTRUE)
set(CMAKE_SYSTEM_NAMELinux)
set(CMAKE_CXX_COMPILER_IDClang)
SET(CMAKE_SYSTEM_PROCESSORarm)
add_definitions(-DFE_TONEAREST=0x00000000)
add_definitions(-DFE_UPWARD=0x00400000)
add_definitions(-DFE_DOWNWARD=0x00800000)
add_definitions(-DFE_TOWARDZERO=0x00c00000)#add_definitions(-D_XOPEN_SOURCE=600)
SET(CMAKE_FIND_ROOT_PATH_MODE_PROGRAMNEVER)
SET(CMAKE_FIND_ROOT_PATH_MODE_LIBRARYONLY)
SET(CMAKE_FIND_ROOT_PATH_MODE_INCLUDEONLY)
SET(CROSS_COMPILATION_ARCHITECTUREarmv7-a)
set(CMAKE_TOOLCHAIN_PREFIXllvm-)
set(PROJECT_ROOT/home/hrt/master/source) #{ohos源码的工具链}
#指定c编译工具（确保工具链所在路径已经添加到了PATH环境变量中）和编译标志，使用clang编译时标志中必须指定--target，否则无法交叉编译。
set(CMAKE_C_COMPILER${PROJECT_ROOT}/prebuilts/clang/ohos/linux-
x86_64/llvm/bin/clang)
mfloat-abi=softfp-mfpu=neon-vfpv4-w")
#指定c++编译工具（确保工具链所在路径已经添加到了PATH环境变量中）和编译标志，必须指定--
target，否则无法交叉编译。
set(CMAKE_CXX_COMPILER${PROJECT_ROOT}/prebuilts/clang/ohos/linux-
x86_64/llvm/bin/clang++)
set(CMAKE_CXX_FLAGS"--target=arm-linux-ohosmusl-D__clang__-march=armv7-a -mfloat-abi=softfp-mfpu=neon-vfpv4-w")
#指定链接工具和链接标志，必须指定--target和--sysroot，其中OHOS_ROOT_PATH可通过cmake 命令后缀参数来指定。
set(MY_LINK_FLAGS"--target=arm-linux-ohosmusl--
sysroot=${PROJECT_ROOT}/out/rk3568/obj/third_party/musl/")
set(CMAKE_LINKER${PROJECT_ROOT}/prebuilts/clang/ohos/linux-
x86_64/llvm/bin/clang)
set(CMAKE_CXX_LINKER${PROJECT_ROOT}/prebuilts/clang/ohos/linux-
x86_64/llvm/bin/clang++)
set(CMAKE_C_LINKER${PROJECT_ROOT}/prebuilts/clang/ohos/linux-
x86_64/llvm/bin/clang)
#指定链接库的查找路径。
set(CMAKE_SYSROOT${PROJECT_ROOT}/out/rk3568/obj/third_party/musl/)
set(CMAKE_EXE_LINKER_FLAGS"-Wl,--dynamic-linker,/system/bin/ld-musl-arm.so.1")