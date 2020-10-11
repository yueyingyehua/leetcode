cmake_minimum_required(VERSION 3.13)
project(LeetCode)

set(CMAKE_CXX_STANDARD 14)

add_executable(
        LeetCode main.cpp
        BiNode/Solution.cpp
        merge/Solution.cpp
        BiNode/BiNodeClient.cpp
        Utils/Utils.cpp
        Utils/Utils.h
        BalanceBST/Solution.cpp
        Utils/UtilsTestClient.cpp)