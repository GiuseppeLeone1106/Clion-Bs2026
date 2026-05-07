cmake_minimum_required(VERSION 4.2)
project(clion_BS2026 C)

set(CMAKE_C_STANDARD 99)

add_executable(clion_BS2026 main.c
        keyValStore.c
        keyValStore.h)
