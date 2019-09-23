cmake_minimum_required(VERSION 3.2)

project(VrmlApp)

set(vrml_app_files
lib/ico12v.h
lib/ico162v.h
lib/VrmlFunctions.h
lib/VrmlFunctions.cpp
src/VrmlApp.cpp
)

include_directories(lib)

add_executable(vrmlApp ${vrml_app_files})

