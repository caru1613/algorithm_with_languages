cmake_minimum_required(VERSION 3.11)

Project(
    SinglyLinkedList
    VERSION 0.0
    DESCRIPTION "SinglyLinkedList"
    LANGUAGES CXX)

add_executable (SinglyLinkedList SinglyLinkedList.cpp Test_SinglyLinkedList.cpp)
target_compile_options (SinglyLinkedList PUBLIC -Wall -Werror)
