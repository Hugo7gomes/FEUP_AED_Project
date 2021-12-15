cmake_minimum_required(VERSION 3.20)
project(Project)

set(CMAKE_CXX_STANDARD 14)

add_executable(Project main.cpp src/aviao.cpp src/aviao.h src/voo.cpp src/voo.h src/servico.cpp src/servico.h src/passageiro.cpp src/passageiro.h src/bilhete.cpp src/bilhete.h src/transpTerrestre.cpp src/transpTerrestre.h src/defs.h src/carrinhoTransporte.cpp src/carrinhoTransporte.h src/carruagem.cpp src/carruagem.h src/Aeroporto.cpp src/Aeroporto.h src/load.cpp src/load.h src/menus.cpp src/menus.h src/input.cpp src/input.h src/update.cpp src/update.h)
