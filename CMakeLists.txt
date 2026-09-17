cmake_minimum_required(VERSION 3.50)

project(gb-emulator
    DESCRIPTION "C Game Boy Emulator" 
    LANGUAGES C
)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_C_STANDARD 23)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

find_package(SDL3 REQUIRED CONFIG REQUIRED COMPONENTS SDL3-shared)

add_executable(gameboy
    src/main.c
    src/cpu.c
)

target_include_directories(gameboy
    PRIVATE
        include
)

target_link_libraries(gameboy PRIVATE SDL3::SDL3)

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
