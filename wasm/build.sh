#!/bin/bash

# 调用 Emscripten 编译 C++ 代码为 WebAssembly 模块
emcc ../wifi-module/main.cpp -o wifiapp.js -s EXPORTED_FUNCTIONS="['_getWifiInfo']" -s EXTRA_EXPORTED_RUNTIME_METHODS='["ccall", "cwrap"]' -s MODULARIZE=1 -s ALLOW_MEMORY_GROWTH=1 -s WASM=1
