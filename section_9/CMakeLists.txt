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

message(STATUS "Compiling...")
# add_executable(learn cpp_104.cpp)
# add_executable(learn cpp_105.cpp)
# add_executable(learn cpp_106.cpp)
# add_executable(learn cpp_107.cpp)
# add_executable(learn cpp_108.cpp)
add_executable(learn cpp_109.cpp)

# target_compile_options(learn PRIVATE $<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:GNU>>:-Wno-narrowing>)
# -Wno-overflow -Woverflow
# -Wno-narrowing

