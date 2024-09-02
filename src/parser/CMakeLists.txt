set(TARGET parser)

add_library(${TARGET})

target_sources(${TARGET} PRIVATE
	${CMAKE_CURRENT_LIST_DIR}/parser.cpp
)

target_include_directories(${TARGET} PRIVATE
	${CMAKE_CURRENT_LIST_DIR}
)
