set(TARGET queue_tests)

add_executable(${TARGET})

target_sources(${TARGET} PRIVATE
	queue_tests.cpp
)

target_include_directories(${TARGET} PRIVATE
	${CMAKE_SOURCE_DIR}/include
)

target_link_libraries(${TARGET} PUBLIC
	gtest_main
)

target_link_libraries(${TARGET} INTERFACE
	queue_tests_lib
)