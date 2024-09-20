set(TARGET user_input)

add_library(${TARGET})

target_sources(${TARGET} PRIVATE
	src/user_input.cpp
)

target_include_directories(${TARGET} PUBLIC
	${CMAKE_CURRENT_LIST_DIR}/include
	${CMAKE_SOURCE_DIR}/include
	${CMAKE_CURRENT_LIST_DIR}/src
)