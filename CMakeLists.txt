cmake_minimum_required(VERSION 3.21)

project(gb-emulator
    DESCRIPTION "C Game Boy Emulator" 
    LANGUAGES C
)

set(CMAKE_C_STANDARD 23)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

add_executable(gameboy
    src/main.c
    src/cpu.c
)

target_include_directories(gameboy
    PRIVATE
        include
)

enable_testing()

add_executable(test_cpu
    tests/test_cpu.c
    src/cpu.c
)

target_include_directories(test_cpu
    PRIVATE
        include
)

add_test(
    NAME cpu
    COMMAND test_cpu
)
