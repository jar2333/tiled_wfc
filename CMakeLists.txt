cmake_minimum_required(VERSION 3.5)
project(tiled_wfc VERSION 0.0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)

add_executable(${PROJECT_NAME} src/main.cpp)
# add_library(${PROJECT_NAME} STATIC src/engine.cpp)

# target_include_directories(${PROJECT_NAME}
#     PUBLIC
#         $<INSTALL_INTERFACE:include>
#         $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
#     PRIVATE

# )

# target_link_libraries(${PROJECT_NAME}
#     PUBLIC

#     PRIVATE

# )