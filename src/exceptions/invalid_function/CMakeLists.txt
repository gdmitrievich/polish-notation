set(TARGET invalid_function)

add_library(${TARGET})

target_sources(${TARGET} PRIVATE
	invalid_function.cpp
)

target_include_directories(${TARGET} PUBLIC
	${CMAKE_SOURCE_DIR}/include
)