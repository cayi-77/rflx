cmake_minimum_required(VERSION 3.12.0)
project(main VERSION 0.0.1)

set(CMAKE_CXX_STANDARD 20)


add_library(rflx INTERFACE)
target_include_directories(rflx INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:${CMAKE_INSTALL_PREFIX}/include>
)

if(${CMAKE_PROJECT_NAME} STREQUAL ${PROJECT_NAME})
  add_executable(example example/example.cpp)
  target_link_libraries(example PRIVATE rflx)
endif()

