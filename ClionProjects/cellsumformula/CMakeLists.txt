cmake_minimum_required(VERSION 3.5)
project(cellsumformula)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Subject.cpp Subject.h Observer.cpp Observer.h Cell.cpp Cell.h SumFormula.cpp SumFormula.h MaxFormula.cpp MaxFormula.h MinFormula.cpp MinFormula.h MeanFormula.cpp MeanFormula.h)
add_executable(cellsumformula ${SOURCE_FILES})

find_package(wxWidgets REQUIRED net gl core base)
include(${wxWidgets_USE_FILE})
# and for each of your dependent executable/library targets:
target_link_libraries(cellsumformula ${wxWidgets_LIBRARIES})