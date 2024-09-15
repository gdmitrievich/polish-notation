set(TARGET parser_tests)

add_executable(${TARGET})

target_sources(${TARGET} PRIVATE
	parser_tests.cpp
)

target_link_libraries(${TARGET}
	PRIVATE
		gtest_main
		token_test
		parser
		queue_test
)