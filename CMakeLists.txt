cmake_minimum_required(VERSION 3.9)
project(Colliding2.1)

file(GLOB_RECURSE Colliding2.1_SRC src/*.cpp include/*.h)

include_directories(include/)
add_executable(Colliding2.1 ${Colliding2.1_SRC})
set(EXTERNAL_DIR ${CMAKE_SOURCE_DIR}/externals)

#SFML
set(SFML_DIR ${EXTERNAL_DIR}/SFML)
set(SFML_BUILD_EXAMPLES FALSE)
add_subdirectory(${SFML_DIR})
include_directories(${SFML_DIR}/include)

LIST(APPEND Colliding2.1_LIBRARIES
	sfml-system
	sfml-window
	sfml-graphics
	sfml-audio
	sfml-network)
	
target_link_libraries(Colliding2.1 ${Colliding2.1_LIBRARIES})
	