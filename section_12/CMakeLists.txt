cmake_minimum_required (VERSION 3.8)

# set(CMAKE_CXX_STANDARD 11)
# set(CMAKE_CXX_STANDARD_REQUIRED on)
set(CMAKE_CXX_FLAGS "-std=c++14")

project (learn
  LANGUAGES C CXX
  VERSION "1.0.0"
)

# set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/binary)
# set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/binary)
set(INCLUDE_DIR /inc)
include_directories (${INCLUDE_DIR})

message(STATUS "Compiling...")
# add_executable(learn cpp_142.cpp)
# add_executable(learn cpp_143.cpp)
# add_executable(learn cpp_144.cpp)
# add_executable(learn cpp_145.cpp)
# add_executable(learn cpp_146.cpp)
# add_executable(learn cpp_147.cpp)
# add_executable(learn cpp_148.cpp)
add_executable(learn cpp_149.cpp)

# set_target_properties(learn PROPERTIES COMPILE_FLAGS "-S") #Generate assembly code
# target_compile_options(learn PRIVATE $<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:GNU>>:-Wno-narrowing>)
# -Wno-overflow -Woverflow
# -Wno-narrowing

