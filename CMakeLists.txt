cmake_minimum_required(VERSION 3.19)

project("zeep")

add_executable(zeep src/zeep.cpp includes/compressor.h)

include_directories(includes)
