set(TARGET polish_calculation)

add_library(${TARGET})

target_sources(${TARGET} PRIVATE
	polish_calculation.cpp
)

target_include_directories(${TARGET} PUBLIC
	${CMAKE_SOURCE_DIR}/include
)

target_link_libraries(${TARGET} PUBLIC
	queue
	stack
	token
)
