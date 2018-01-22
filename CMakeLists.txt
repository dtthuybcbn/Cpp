cmake_minimum_required(VERSION 3.10.0)
PROJECT(MyDailyCodingProjects)

include_directories(${PROJECT_BINARY_DIR})


MACRO (Add_project project_name)
   ADD_EXECUTABLE(${project_name} ${project_name}.cpp)
   TARGET_LINK_LIBRARIES (${project_name})
ENDMACRO()

####
### cmake -G "Visual Studio 14 2015 Win64"
### cmake --build . --config Release
###
Add_project(hello)