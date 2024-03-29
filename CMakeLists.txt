cmake_minimum_required(VERSION 3.20)
project(Project)

set(CMAKE_CXX_STANDARD 14)

add_executable(Project main.cpp src/aviao.cpp src/aviao.h src/voo.cpp src/voo.h src/servico.cpp src/servico.h src/passageiro.cpp src/passageiro.h src/bilhete.cpp src/bilhete.h src/transpTerrestre.cpp src/transpTerrestre.h src/defs.h src/carrinhoTransporte.cpp src/carrinhoTransporte.h src/carruagem.cpp src/carruagem.h src/Aeroporto.cpp src/Aeroporto.h src/load.cpp src/load.h src/menus.cpp src/menus.h src/input.cpp src/input.h src/update.cpp src/update.h src/bst.h src/gerenciarTransportes.cpp src/gerenciarTransportes.h src/gerenciarTransportes.cpp src/gerenciarTransportes.h src/gerenciarAeroportos.cpp src/gerenciarAeroportos.h)

# Doxygen Build
find_package(Doxygen)
if(DOXYGEN_FOUND)
    set(BUILD_DOC_DIR "${CMAKE_SOURCE_DIR}/docs/output")
    if(NOT EXISTS "${BUILD_DOC_DIR}")
        file(MAKE_DIRECTORY "${BUILD_DOC_DIR}")
    endif()

    set(DOXYGEN_IN "${CMAKE_CURRENT_SOURCE_DIR}/docs/Doxyfile")
    set(DOXYGEN_OUT "${CMAKE_CURRENT_BINARY_DIR}/Doxyfile")
    configure_file("${DOXYGEN_IN}" "${DOXYGEN_OUT}" @ONLY)

    message("Doxygen build started")
    add_custom_target(Doxygen ALL
            COMMAND "${DOXYGEN_EXECUTABLE}" "${DOXYGEN_OUT}"
            WORKING_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}"
            COMMENT "Generating API documentation with Doxygen"
            VERBATIM)
else(DOXYGEN_FOUND)
    message("Doxygen needs to be installed to generate the documentation.")
endif(DOXYGEN_FOUND)