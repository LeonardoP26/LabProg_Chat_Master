cmake_minimum_required(VERSION 3.5)
project(LabProg_Chat_Master)
set(CMAKE_CXX_STANDARD 14)

add_subdirectory(Test)
include_directories(Test/lib/)

set(HEADER_FILES MessageNotification.h Messaggio.h Observer.h Subject.h Chat.h User.h)
set(SOURCE_FILES Messaggio.cpp Chat.cpp User.cpp MessageNotification.cpp)
add_executable(LabProg_Chat_Master main.cpp)


add_library(core ${SOURCE_FILES} ${HEADER_FILES})
target_link_libraries(LabProg_Chat_Master core)