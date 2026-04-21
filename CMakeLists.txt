cmake_minimum_required(VERSION 3.20)
project(FractalJulia)

# Le decimos a CMake que busque fmt y SFML
find_package(fmt CONFIG REQUIRED)
find_package(SFML COMPONENTS Graphics Window System REQUIRED)

add_executable(fractal_julia main.cpp fractal_serial.cpp)

# Enlazamos las librerías a tu programa
target_link_libraries(fractal_julia PRIVATE fmt::fmt SFML::Graphics SFML::Window SFML::System)

