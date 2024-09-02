set(TARGET node_tests)

add_executable(${TARGET})

target_sources(${TARGET} PRIVATE
	node_tests.cpp
)

target_include_directories(${TARGET} PRIVATE
	${CMAKE_SOURCE_DIR}/include
)

target_link_libraries(${TARGET} PUBLIC
	gtest_main
)

target_link_libraries(${TARGET} INTERFACE
	node
)