cmake_minimum_required(VERSION 3.2)

SET(CMAKE_INSTALL_PREFIX $ENV{HOME} CACHE PATH "")
 
PROJECT(flapmodel)

find_package(VTK REQUIRED)
include(${VTK_USE_FILE})
 
add_executable(flapmodel flapmodel parse)
 
if(VTK_LIBRARIES)
	target_link_libraries(flapmodel ${VTK_LIBRARIES})
else()
	target_link_libraries(flapmodel vtkHybrid vtkWidgets)
endif()

install(TARGETS flapmodel DESTINATION bin)

