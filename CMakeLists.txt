cmake_minimum_required(VERSION 3.6)
project(AES_Tool)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES main.c)
add_executable(AES_Tool ${SOURCE_FILES})