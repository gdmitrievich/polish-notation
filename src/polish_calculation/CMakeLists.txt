set(TARGET polish_calculation_lib)

add_library(${TARGET})

target_sources(${TARGET} PRIVATE
	${CMAKE_CURRENT_LIST_DIR}/polish_calculation.cpp
)

target_include_directories(${TARGET} PUBLIC
	${CMAKE_CURRENT_LIST_DIR}
)

target_link_libraries(${TARGET}
	INTERFACE
		queue
		stack
	PUBLIC
		token
)
