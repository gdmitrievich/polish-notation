set(TARGET queue_test)

add_library(${TARGET} INTERFACE)

target_include_directories(${TARGET} INTERFACE
	${CMAKE_CURRENT_LIST_DIR}/include
)

target_link_libraries(${TARGET} INTERFACE
	queue
)