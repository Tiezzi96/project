cmake_minimum_required(VERSION 3.5)

add_subdirectory(./lib/googletest)

set(gtest_SOURCE_DIR, ./lib/googletest/)

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

set(TEST_SOURCE_FILES runAllTests.cpp Celltest.h Celltest.cpp Formuletest.h)

add_executable(runTest ${TEST_SOURCE_FILES} Formuletest.h)

find_package(wxWidgets REQUIRED net gl core base adv)
include(${wxWidgets_USE_FILE})

target_link_libraries(runTest gtest gtest_main core ${wxWidgets_LIBRARIES})
