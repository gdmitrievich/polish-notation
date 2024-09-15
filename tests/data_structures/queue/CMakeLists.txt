add_subdirectory(queue_test)

set(TARGET queue_tests)

add_executable(${TARGET})

target_sources(${TARGET} PRIVATE
	queue_tests.cpp
)

target_link_libraries(${TARGET}
	PRIVATE
		gtest_main
		queue_test
)