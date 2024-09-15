set(TARGET console_renderer)

add_library(${TARGET})

target_sources(${TARGET} PRIVATE
	${CMAKE_CURRENT_LIST_DIR}/console_renderer.cpp
)

target_include_directories(${TARGET} PUBLIC
	${CMAKE_SOURCE_DIR}/include
)
