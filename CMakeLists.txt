cmake_minimum_required(VERSION 3.16)

project(main VERSION 0.0.1 LANGUAGES CXX)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

file(GLOB_RECURSE headers_h src/*.h)
file(GLOB_RECURSE headers_hpp src/*.hpp)
file(GLOB_RECURSE sources_cpp src/*.cpp)

add_executable(${PROJECT_NAME} ${headers_h} ${headers_hpp} ${sources_cpp})

target_link_libraries(
  ${PROJECT_NAME} 
  PRIVATE
  ${CONAN_LIBS}
 )