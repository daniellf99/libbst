cmake_minimum_required(VERSION 3.16)
project(libbst C)

set(CMAKE_C_STANDARD 11)

add_library(libbst src/bst.c src/bst.h)