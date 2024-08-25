if (BUILD_TESTING)
	project(polish_notation_tests LANGUAGES CXX)

	set(sources
		polish_notation_tests.cpp
	)

	add_executable(${PROJECT_NAME} ${sources})

	target_link_libraries(${PROJECT_NAME} PRIVATE
		gtest_main
	)

	include(GoogleTest)
	gtest_discover_tests(${PROJECT_NAME})
endif()