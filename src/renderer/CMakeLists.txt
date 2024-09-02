set(TARGET field_generator)

add_library(${TARGET})

target_sources(${TARGET} PRIVATE
	${CMAKE_CURRENT_LIST_DIR}/field_generator.cpp
)

target_include_directories(${TARGET} PUBLIC
	${CMAKE_CURRENT_LIST_DIR}
)

target_link_libraries(${TARGET}
	INTERFACE
		queue
	PUBLIC
		token
		polish_calculation_lib
)

add_subdirectory(console_renderer)
