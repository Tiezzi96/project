cmake_minimum_required(VERSION 3.5)
project(cellsumformula)


set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(SOURCE_FILES CMakeLists.txt main.cpp Subject.cpp Subject.h Observer.cpp Observer.h Cell.cpp Cell.h SumFormula.cpp SumFormula.h MaxFormula.cpp MaxFormula.h MinFormula.cpp MinFormula.h MeanFormula.cpp MeanFormula.h Notebook.cpp Notebook.h main.h MyGrid.cpp MyGrid.h ListException.h)
add_subdirectory(test)
set(SOURCE_FILE Cell.h SumFormula.h Observer.h MaxFormula.h MinFormula.h MeanFormula.h)
add_executable(cellsumformula main.cpp)
add_library(core ${SOURCE_FILES})
target_link_libraries(cellsumformula core)

find_package(wxWidgets REQUIRED net gl core base adv)
include(${wxWidgets_USE_FILE})
# and for each of your dependent executable/library targets:
target_link_libraries(cellsumformula core ${wxWidgets_LIBRARIES})