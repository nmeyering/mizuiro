FIND_PROGRAM(
	XSLTPROC_COMMAND xsltproc
)
MARK_AS_ADVANCED(XSLTPROC_COMMAND)

FIND_PACKAGE_HANDLE_STANDARD_ARGS(XSLTPROC DEFAULT_MSG XSLTPROC_COMMAND)

IF(XSLTPROC_FOUND)
	SET(XSLTPROC_EXECUTABLE ${XSLTPROC_COMMAND})
ELSE()
	SET(XSLTPROC_EXECUTABLE)
ENDIF()
