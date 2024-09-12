set(TARGET polish_calculation_tests)

add_executable(${TARGET})

target_sources(${TARGET} PRIVATE
	polish_calculation_tests.cpp
)

target_link_libraries(${TARGET}
	PRIVATE
		polish_calculation_lib
	PUBLIC
		gtest_main
)