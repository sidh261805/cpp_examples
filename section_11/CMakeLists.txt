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
# add_executable(learn cpp_121.cpp)
# add_executable(learn cpp_123.cpp)
# add_executable(learn cpp_125.cpp)
# add_executable(learn cpp_126.cpp)
# add_executable(learn cpp_128.cpp inc/integer.cpp)
# add_executable(learn cpp_129.cpp inc/integer.cpp)
# add_executable(learn cpp_130_131.cpp inc/integer.cpp)
# add_executable(learn cpp_133.cpp)
# add_executable(learn cpp_134.cpp)
# add_executable(learn cpp_135.cpp)
# add_executable(learn cpp_137.cpp)
# add_executable(learn cpp_138.cpp)
# add_executable(learn cpp_139.cpp)
add_executable(learn cpp_140.cpp)

# set_target_properties(learn PROPERTIES COMPILE_FLAGS "-S") #Generate assembly code
# target_compile_options(learn PRIVATE $<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:GNU>>:-Wno-narrowing>)
# -Wno-overflow -Woverflow
# -Wno-narrowing

