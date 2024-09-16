set(TARGET invalid_field_info_exception)

add_library(${TARGET})

target_sources(${TARGET} PRIVATE
	invalid_field_info_exception.cpp
)

target_include_directories(${TARGET} PUBLIC
	${CMAKE_SOURCE_DIR}/include
)