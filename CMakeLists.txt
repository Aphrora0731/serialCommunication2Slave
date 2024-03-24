cmake_minimum_required(VERSION 3.26)
project(SerialComunication2Slave)

set(CMAKE_CXX_STANDARD 23)

add_executable(SerialComunication2Slave main.cpp
        Frame.cpp
        Frame.h
        Header.cpp
        Header.h
        GenerateAlgorithm.cpp
        GenerateAlgorithm.h
        SeiralComunication.cpp
        SeiralComunication.h)
