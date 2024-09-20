set(TARGET node)

add_library(${TARGET} INTERFACE)

target_include_directories(${TARGET} INTERFACE
	${CMAKE_SOURCE_DIR}/include
)