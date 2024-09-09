set(TARGET token_test)

add_library(${TARGET})

target_sources(${TARGET} PRIVATE
	${CMAKE_CURRENT_LIST_DIR}/token_test.cpp
)

target_include_directories(${TARGET} PRIVATE
	${CMAKE_CURRENT_LIST_DIR}
)

target_link_libraries(${TARGET} PUBLIC
	token
)