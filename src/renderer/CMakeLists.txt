set(TARGET field_generator)

add_library(${TARGET})

target_sources(${TARGET} PRIVATE
	field_generator.cpp
)

target_include_directories(${TARGET} PUBLIC
	${CMAKE_SOURCE_DIR}/include
)

target_link_libraries(${TARGET}
	PUBLIC
		queue
		token
		polish_calculation
)

add_subdirectory(console_renderer)
