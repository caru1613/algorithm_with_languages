cmake_minimum_required(VERSION 3.11)

Project(
    CircularLinkedList
    VERSION 0.0
    DESCRIPTION "CircularLinkedList"
    LANGUAGES CXX)

add_executable (CircularLinkedList CircularLinkedList.cpp Test_CircularLinkedList.cpp)
#target_compile_options (CircularLinkedList PUBLIC -Wall -Werror)
