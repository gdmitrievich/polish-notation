set(headers
	queue_tests.h
	queue_tests.ipp
)

set(TARGET_LIBRARY queue_tests)

add_library(${TARGET_LIBRARY} INTERFACE
	${headers}
)
