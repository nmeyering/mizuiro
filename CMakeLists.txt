CMAKE_MINIMUM_REQUIRED(VERSION 2.6)

PROJECT (mizuiro)

INCLUDE(FcpptCMakeUtils)

FIND_PACKAGE(
	Boost 1.40.0 REQUIRED
)

OPTION(
	ENABLE_FCPPT "Use fcppt's variant. Required for ternary visitation." OFF
)

IF(ENABLE_FCPPT)
	FIND_PACKAGE(
		Fcppt
		REQUIRED
	)
ENDIF()

SET(
	MIZUIRO_HAVE_FCPPT
	${FCPPT_FOUND}
)

INCLUDE_DIRECTORIES(
	include
)

INCLUDE_DIRECTORIES(
	SYSTEM
	${Boost_INCLUDE_DIR}
)

IF(FCPPT_FOUND)
	INCLUDE_DIRECTORIES(
		${Fcppt_INCLUDE_DIRS}
	)
ENDIF()

IF (CMAKE_COMPILER_IS_GNUCXX OR FCPPT_UTILS_COMPILER_IS_CLANGPP)
	INCLUDE (CheckCXXSourceCompiles)

	CHECK_CXX_SOURCE_COMPILES(
		"int main()
		{
		if(__builtin_expect(true, 0))
		{}
		}"
		MIZUIRO_HAVE_BUILTIN_EXPECT
	)
ENDIF ()

CONFIGURE_FILE(
	${CMAKE_SOURCE_DIR}/config.hpp.in
	${CMAKE_BINARY_DIR}/include/mizuiro/config.hpp
)

INCLUDE_DIRECTORIES(
	${CMAKE_BINARY_DIR}/include
)

INSTALL(
	DIRECTORY
	include/
	DESTINATION
	${INSTALL_INCLUDE_DIR}
)

INSTALL(
	FILES
	${CMAKE_BINARY_DIR}/include/mizuiro/config.hpp
	DESTINATION
	${INSTALL_INCLUDE_DIR}/mizuiro
)

INSTALL(
	FILES
	${CMAKE_SOURCE_DIR}/CMakeModules/FindMizuiro.cmake
	DESTINATION
	${INSTALL_CMAKEMODULES_DIR}
)

OPTION(ENABLE_DOC "Build the documentation" OFF)

IF (ENABLE_DOC)
	ADD_SUBDIRECTORY (doc)
ENDIF ()

OPTION (ENABLE_EXAMPLES "Build the examples" ON)

IF(ENABLE_EXAMPLES)
	ADD_SUBDIRECTORY(examples)
ENDIF()

OPTION (ENABLE_TEST "Build the tests" ON)

IF(ENABLE_TEST)
	ENABLE_TESTING()
	ADD_SUBDIRECTORY(test)
ENDIF()
