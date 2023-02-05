cmake_minimum_required(VERSION 3.11)
project(BinaryTree)

set(CMAKE_CXX_STANDARD 14)

include_directories(AVLTreeLib BinarySearchTreeLib benchmark)

add_library(AVLTreeLib AVLTreeLib/AVLTree.h AVLTreeLib/AVLTreeLib.cpp)
add_library(BSTTreeLib BinarySearchTreeLib/BinarySearchTree.h BinarySearchTreeLib/BinarySearchTreeLib.cpp)

add_executable(AVLTreeApp AVLTreeApp/AVLTreeApp.cpp)
add_executable(BinarySearchTreeApp BinarySearchTreeApp/BinarySearchTreeApp.cpp)
target_link_libraries(AVLTreeApp PUBLIC AVLTreeLib)
target_link_libraries(BinarySearchTreeApp PUBLIC BSTTreeLib)

include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
if (WIN32)
    # For Windows: Prevent overriding the parent project's compiler/linker settings
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
endif (WIN32)#ifndef _WIN32
#endif
FetchContent_MakeAvailable(googletest)
include(GoogleTest)

enable_testing()
add_executable(AVLTreeUnitTest AVLTreeUnitTest/AVLTreeUnitTest.cpp)
add_executable(BinarySearchTreeUnitTest BinarySearchTreeUnitTest/BinarySearchTreeUnitTest.cpp)
target_link_libraries(AVLTreeUnitTest PUBLIC AVLTreeLib gtest_main)
target_link_libraries(BinarySearchTreeUnitTest PUBLIC BSTTreeLib gtest_main)
gtest_discover_tests(AVLTreeUnitTest)
gtest_discover_tests(BinarySearchTreeUnitTest)
