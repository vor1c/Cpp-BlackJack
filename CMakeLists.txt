cmake_minimum_required(VERSION 3.24)
project(Cpp_Kartenspiel)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(Kartenspiel)

add_executable(Cpp_Kartenspiel
        Abhebestapel.cpp
        Abhebestapel.h
        Ablegestapel.cpp
        Ablegestapel.h
        Deck.cpp
        Deck.h
        Hand.cpp
        Hand.h
        Karte.cpp
        Karte.h
        Kartenspiel.cpp
        Kartenspiel.h
        test_kartenspiel.cpp)
        #Sauaufdrahn.cpp)
