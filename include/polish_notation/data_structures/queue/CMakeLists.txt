set(headers
	queue.h
	queue.ipp
)

set(TARGET_LIBRARY queue)

add_library(${TARGET_LIBRARY} INTERFACE
	${headers}
)
