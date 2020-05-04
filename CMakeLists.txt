cmake_minimum_required(VERSION 3.16)

project(example VERSION 0.0.1 LANGUAGES CXX)

file(GLOB_RECURSE fileCollection src/*.cpp)
add_executable(${PROJECT_NAME} ${fileCollection})

find_package(Boost REQUIRED)
find_package(GSL REQUIRED)

target_include_directories(
  ${PROJECT_NAME}
  PRIVATE
  ${CMAKE_CURRENT_SOURCE_DIR}/src
  ${Boost_INCLUDE_DIRS}
)

target_link_directories(
  ${PROJECT_NAME}
  PRIVATE
  ${CMAKE_CURRENT_SOURCE_DIR}/src
  ${Boost_LIBRARY_DIRS}
)

target_link_libraries(
  ${PROJECT_NAME} 
  PRIVATE
  ${Boost_LIBRARIES}
  GSL::gsl 
  GSL::gslcblas
 )