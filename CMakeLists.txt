cmake_minimum_required(VERSION 3.23)
project(graph)

set(CMAKE_CXX_STANDARD 14)

add_executable(graph main.cpp)
add_executable(graph-1 图的存储.cpp)
add_executable(graph-2 图基本操作.cpp)
add_executable(graph-3 图的广度优先遍历.cpp)
add_executable(graph-4 图的深度优先遍历.cpp)
add_executable(graph-5 最小生成树.cpp)
add_executable(graph-6 最短路径算法.cpp)
add_executable(graph-7 最短路径Floyd算法.cpp)
add_executable(graph-8 拓扑排序.cpp)



