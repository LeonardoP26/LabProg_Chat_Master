add_subdirectory(./lib/gtest-1.7.0-master/)
set(gtest_SOURCE_DIR, ./lib/gtest-1.7.0-master/)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})


add_executable(runAllTests runAllTests.cpp TestMessaggio.cpp UserTest.cpp)


target_link_libraries(runAllTests gtest gtest_main core)
