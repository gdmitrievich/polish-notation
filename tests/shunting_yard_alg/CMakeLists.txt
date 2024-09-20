set(TARGET shunting_yard_alg_tests)

add_executable(${TARGET})

target_sources(${TARGET} PRIVATE
	${CMAKE_CURRENT_LIST_DIR}/shunting_yard_alg_tests.cpp
)

target_link_libraries(${TARGET}
	PRIVATE
		shunting_yard_alg
		token_test
	PUBLIC
		gtest_main
)