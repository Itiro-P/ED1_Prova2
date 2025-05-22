cmake_minimum_required(VERSION 3.30)

project(ED1_PROVA2 VERSION 1.0 LANGUAGES CXX)

set(SOURCES
  codigo/main.cpp
  #codigo/busca.cpp
  codigo/gerador_dados.cpp
  #codigo/ordenacao.cpp
)

add_executable(ed1_prova2 ${SOURCES})

target_include_directories(ed1_prova2 PRIVATE ${CMAKE_SOURCE_DIR}/codigo)

set_target_properties(ed1_prova2 PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin" CXX_EXTENSIONS OFF)

target_compile_features(ed1_prova2 PRIVATE cxx_std_23)

target_compile_definitions(ed1_prova2 PRIVATE DATA_DIR="${CMAKE_SOURCE_DIR}/dados")