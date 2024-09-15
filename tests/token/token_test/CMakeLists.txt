set(TARGET token_test)

add_library(${TARGET})

target_sources(${TARGET} PRIVATE
	src/token_test.cpp
)

target_include_directories(${TARGET}
	PUBLIC
		${CMAKE_CURRENT_LIST_DIR}/include
	PRIVATE
		${CMAKE_CURRENT_LIST_DIR}/src
)

target_link_libraries(${TARGET} PUBLIC
	token
)