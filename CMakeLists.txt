cmake_minimum_required(VERSION 3.22)
project(cpp_learn)

set(CMAKE_CXX_STANDARD 11)
# main.cpp
# myArrayUse.cpp dynamicArray.cpp
#workerManger.cpp workerManger.h worker.h employee.cpp employee.h manager.cpp manager.h boss.cpp boss.h worker.cpp myArray.hpp
# staffGroupByMap.cpp
add_executable(cpp_learn main.cpp Identity.h student.cpp student.h teacher.cpp teacher.h manager.cpp manager.h globalFile.h student.txt)
