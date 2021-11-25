cmake_minimum_required(VERSION 3.20)
project(Project)

set(CMAKE_CXX_STANDARD 14)

add_executable(Project main.cpp src/avião.cpp src/avião.h src/voo.cpp src/voo.h src/serviço.cpp src/serviço.h src/passageiro.cpp src/passageiro.h src/bilhete.cpp src/bilhete.h src/transpTerrestre.cpp src/transpTerrestre.h src/defs.h)
