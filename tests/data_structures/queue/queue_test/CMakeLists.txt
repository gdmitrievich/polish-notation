set(headers
	queue_test.h
	queue_test.ipp
)

set(TARGET_LIBRARY queue_test)

add_library(${TARGET_LIBRARY} INTERFACE
	${headers}
)
