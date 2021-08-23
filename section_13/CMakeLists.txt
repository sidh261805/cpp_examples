cmake_minimum_required (VERSION 3.8)

set(CMAKE_CXX_FLAGS "-std=c++17")

project (learn
  LANGUAGES C CXX
  VERSION "1.0.0"
)

link_libraries(stdc++fs) #for filesystem experimental

set(THREADS_PREFER_PTHREAD_FLAG ON)


set(INCLUDE_DIR /inc)
include_directories (${INCLUDE_DIR})

message(STATUS "Compiling...")
# add_executable(learn cpp_152.cpp)
# add_executable(learn cpp_153.cpp)
# add_executable(learn cpp_154.cpp)
# add_executable(learn cpp_155.cpp)
# add_executable(learn cpp_156.cpp)
# add_executable(learn cpp_157.cpp)
# add_executable(learn cpp_158.cpp)
# add_executable(learn cpp_161.cpp)
# add_executable(learn cpp_162.cpp)
# add_executable(learn cpp_165.cpp)
add_executable(learn cpp_166.cpp)


# set_target_properties(learn PROPERTIES COMPILE_FLAGS "-S") #Generate assembly code
# target_compile_options(learn PRIVATE $<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:GNU>>:-Wno-narrowing>)
# -Wno-overflow -Woverflow
# -Wno-narrowing

