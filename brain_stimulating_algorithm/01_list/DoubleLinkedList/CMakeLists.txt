cmake_minimum_required(VERSION 3.11)

Project(
    DoubleLinkedList
    VERSION 0.0
    DESCRIPTION "DoubleLinkedList"
    LANGUAGES CXX)

add_executable (DoubleLinkedList DoubleLinkedList.cpp Test_DoubleLinkedList.cpp)
#target_compile_options (DoubleLinkedList PUBLIC -Wall -Werror)
