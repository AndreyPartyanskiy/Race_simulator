cmake_minimum_required (VERSION 3.10)
set(CMAKE_CCX_STANDART 20)
set(CMAKE_CXX_STANDART_REQUIRED True)
project(DYNAMIC_LIB)
set(SOURCE_DLL Boots.h Boots.cpp Broom.h Broom.cpp Camel.h Camel.cpp Centaur.h Centaur.cpp Eagle.h Eagle.cpp Fly_object.h Fly_object.cpp Ground_object.h Ground_object.cpp Hyper_Camel.h Hyper_Camel.cpp Magic_carpet.h Magic_carpet.cpp Race_object.h Race_object.cpp)
add_library(DYNAMIC_LIB SHARED ${SOURCE_DLL})