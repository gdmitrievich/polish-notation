add_subdirectory(token)
add_subdirectory(parser)
add_subdirectory(shunting_yard_alg)
add_subdirectory(polish_calculation)
add_subdirectory(renderer)
add_subdirectory(exceptions)

set(TARGET polish_notation)

add_executable(${TARGET})

target_sources(${TARGET} PRIVATE
	polish_notation.cpp
)

target_link_libraries(${TARGET}
	PRIVATE
		parser
		console_renderer
		field_generator
		shunting_yard_alg
	INTERFACE
		queue
		token
)