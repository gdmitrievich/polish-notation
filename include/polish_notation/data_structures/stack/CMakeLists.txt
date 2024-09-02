set(headers
	stack.h
	stack.ipp
)

set(TARGET_LIBRARY stack)

add_library(${TARGET_LIBRARY} INTERFACE
	${headers}
)
