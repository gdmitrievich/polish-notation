add_subdirectory(token)
add_subdirectory(parser)
add_subdirectory(shunting_yard_alg)
add_subdirectory(polish_calculation)
add_subdirectory(renderer)
add_subdirectory(exceptions)
add_subdirectory(user_err_mess_printer)
add_subdirectory(user_input)

set(TARGET polish_notation)

add_executable(${TARGET})

target_sources(${TARGET} PRIVATE
	polish_notation.cpp
)

target_link_libraries(${TARGET}
	PRIVATE
		menu_data_container
		user_err_mess_printer
)