cmake_minimum_required(VERSION 3.15)
project(Cpp)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -lm" )

add_executable(Problem1214F Y2019/M09/D17/Problem1214F.cpp)
add_executable(ICPC_D Y2019/M09/D25/ICPC_D.cpp)
add_executable(HIGHWAYS Y2019/M10/D09/HIGHWAYS.cpp)
add_executable(TecNM_B Y2019/M10/D16/TecNM_B.cpp)
add_executable(TecNM_B.c Y2019/M10/D19/TecNM_BinC.c)
