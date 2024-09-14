set(TARGET parser)

add_library(${TARGET})

target_sources(${TARGET} PRIVATE
	parser.cpp
)

target_include_directories(${TARGET} PUBLIC
	${CMAKE_SOURCE_DIR}/include
)

target_link_libraries(${TARGET} PUBLIC
	queue
	token
)
