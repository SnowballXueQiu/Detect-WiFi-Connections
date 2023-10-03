# 指定最低的CMake版本
cmake_minimum_required(VERSION 3.10)

# 设置项目名称
project(Detect-WiFi-Connections)

# 添加C++编译选项
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 添加 C++ 源文件，确保路径正确
add_library(wifi-module STATIC wifi-module/main.cpp)

# 添加 WebAssembly 源文件，确保路径正确
add_executable(wifi-module-wasm wasm/main.cpp)

# 链接 C++ 库到 WebAssembly
target_link_libraries(wifi-module-wasm wifi-module)

# 设置编译标志以支持 WebAssembly
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -s WASM=1")

# 设置输出目标文件的名称和位置
set_target_properties(wifi-module-wasm PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/frontend/public"
)

# 指定需要导出的函数（用于 WebAssembly 模块）
set(EMSCRIPTEN_EXPORTED_FUNCTIONS
        "_getWifiInfo"
)

# 将函数列表写入 .js 文件以供 JavaScript 使用，确保路径正确
file(WRITE "${CMAKE_BINARY_DIR}/frontend/src/functions.js" "Module['onRuntimeInitialized'] = function() { Module['addRunDependency']('wasm-instantiate'); Module['_getWifiInfo'] = Module.cwrap('_getWifiInfo', 'number', []); Module['removeRunDependency']('wasm-instantiate'); if (!Module['calledRun']) run(); };")

# 将生成的 .js 文件复制到输出目录
add_custom_command(TARGET wifi-module-wasm POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${CMAKE_BINARY_DIR}/frontend/src/functions.js"
        "$<TARGET_FILE_DIR:wifi-module-wasm>"
)
