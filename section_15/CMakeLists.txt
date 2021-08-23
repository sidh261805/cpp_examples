cmake_minimum_required (VERSION 3.8)

# set(CMAKE_CXX_STANDARD 11)
# set(CMAKE_CXX_STANDARD_REQUIRED on)
# set(CMAKE_BUILD_TYPE debug)
# set(CMAKE_CXX_FLAGS "-std=c++2a") # for cpp 20
set(CMAKE_CXX_FLAGS "-std=c++17")

project (learn
  LANGUAGES C CXX
  VERSION "1.0.0"
)

link_libraries(stdc++fs) #for filesystem experimental

set(THREADS_PREFER_PTHREAD_FLAG ON)
# find_package(Threads REQUIRED)

# set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/binary)
# set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/binary)
set(INCLUDE_DIR /inc)
include_directories (${INCLUDE_DIR})

message(STATUS "Compiling...")
# add_executable(learn cpp_184.cpp)
# add_executable(learn cpp_185.cpp)
# add_executable(learn cpp_186.cpp)
# add_executable(learn cpp_187.cpp inc/vars.hpp inc/a.cpp inc/b.cpp)
# add_executable(learn cpp_188.cpp)
# add_executable(learn cpp_189.cpp)
# add_executable(learn cpp_190.cpp)
# add_executable(learn cpp_191.cpp)
# add_executable(learn cpp_192.cpp)
# add_executable(learn cpp_193.cpp)
add_executable(learn cpp_194.cpp)

# target_link_libraries (learn PRIVATE Threads::Threads)

# set_target_properties(learn PROPERTIES COMPILE_FLAGS "-S") #Generate assembly code
# target_compile_options(learn PRIVATE $<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:GNU>>:-Wno-narrowing>)
# -Wno-overflow -Woverflow
# -Wno-narrowing

