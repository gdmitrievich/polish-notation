set(TARGET menu_data_container)

add_library(${TARGET})

target_sources(${TARGET} PRIVATE
	src/menu_data_container.cpp
)

target_include_directories(${TARGET}
	PUBLIC
		${CMAKE_CURRENT_LIST_DIR}/include
	PRIVATE
		${CMAKE_CURRENT_LIST_DIR}/src
)

target_link_libraries(${TARGET}
	PUBLIC
		parser
		console_renderer
		field_generator
		shunting_yard_alg
		invalid_function
		user_input
)