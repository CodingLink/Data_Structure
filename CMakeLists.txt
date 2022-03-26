cmake_minimum_required(VERSION 3.21)
project (Data_Structure)

set(CMAKE_CXX_STANDARD 14)

add_executable(Data_Structure Linear_table/SqList.cpp Linear_table/SqList.cpp Linear_table/LinkList.cpp Queue_and_Stack/SqQueue.cpp Queue_and_Stack/SqQueue.h Linear_table/DList.cpp Queue_and_Stack/Stack.cpp BiTree/function.h BiTree/LinkQueue.cpp)
