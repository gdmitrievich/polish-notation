set(TARGET parser_tests)

add_executable(${TARGET})

target_sources(${TARGET} PRIVATE
	parser_tests.cpp
)

target_link_libraries(${TARGET}
	PUBLIC
		gtest_main
		token_test
	PRIVATE
		parser
	INTERFACE
		queue_test
)