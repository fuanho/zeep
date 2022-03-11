cmake_minimum_required(VERSION 3.19)

project("zeep")

add_executable(zeep src/zeep.cpp includes/compressor.h src/huffman.cpp includes/huffman.h src/util.cpp includes/util.h)

include_directories(includes)

add_compile_definitions(_GLIBCXX_CONCEPT_CHECKS _GLIBCXX_DEBUG _GLIBCXX_DEBUG_PEDANTIC)