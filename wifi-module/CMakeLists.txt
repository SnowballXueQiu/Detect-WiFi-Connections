cmake_minimum_required(VERSION 3.10)

project(WifiApp)

add_subdirectory(cpp)   # 构建C++部分
add_subdirectory(wasm)  # 构建WebAssembly部分

add_library(wifi-module STATIC main.cpp)
