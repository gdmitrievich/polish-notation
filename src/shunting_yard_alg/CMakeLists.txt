set(TARGET shunting_yard_alg)

add_library(${TARGET})

target_sources(${TARGET} PRIVATE
	${CMAKE_CURRENT_LIST_DIR}/shunting_yard_alg.cpp
)

target_include_directories(${TARGET} PRIVATE
	${CMAKE_CURRENT_LIST_DIR}
)

target_link_libraries(${TARGET}
	INTERFACE
		queue
		stack
	PUBLIC
		token
)