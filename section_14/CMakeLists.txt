cmake_minimum_required (VERSION 3.8)

# set(CMAKE_CXX_STANDARD 11)
# set(CMAKE_CXX_STANDARD_REQUIRED on)
set(CMAKE_CXX_FLAGS "-std=c++14")

project (learn
  LANGUAGES C CXX
  VERSION "1.0.0"
)

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

# set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/binary)
# set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/binary)
set(INCLUDE_DIR /inc)
include_directories (${INCLUDE_DIR})

message(STATUS "Compiling...")
# add_executable(learn cpp_170.cpp)
# add_executable(learn cpp_171.cpp)
# add_executable(learn cpp_172.cpp)
# add_executable(learn cpp_173.cpp)
# add_executable(learn cpp_174.cpp)
# add_executable(learn cpp_175.cpp)
# add_executable(learn cpp_176.cpp)
# add_executable(learn cpp_177.cpp)
# add_executable(learn cpp_178.cpp)
# add_executable(learn cpp_179.cpp)
add_executable(learn cpp_180.cpp)

target_link_libraries (learn PRIVATE Threads::Threads)

# set_target_properties(learn PROPERTIES COMPILE_FLAGS "-S") #Generate assembly code
# target_compile_options(learn PRIVATE $<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:GNU>>:-Wno-narrowing>)
# -Wno-overflow -Woverflow
# -Wno-narrowing

