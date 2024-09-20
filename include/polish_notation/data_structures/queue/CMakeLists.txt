set(TARGET queue)

add_library(${TARGET} INTERFACE)

target_include_directories(${TARGET} INTERFACE
	${CMAKE_SOURCE_DIR}/include
)