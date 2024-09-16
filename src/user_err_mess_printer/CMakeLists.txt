set(TARGET user_err_mess_printer)

add_library(${TARGET})

target_sources(${TARGET} PRIVATE
	src/user_err_mess_printer.cpp
)

target_include_directories(${TARGET} PUBLIC
	${CMAKE_CURRENT_LIST_DIR}/include
	${CMAKE_CURRENT_LIST_DIR}/src
)

target_link_libraries(${TARGET} PUBLIC
	invalid_function
)