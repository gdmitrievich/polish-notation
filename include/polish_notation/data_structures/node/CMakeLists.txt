set(headers
	node.h
	node.ipp
)

set(TARGET_LIBRARY node)

add_library(${TARGET_LIBRARY} INTERFACE
	${headers}
)
