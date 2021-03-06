# - Try to find the mizuiro library
#
# This module defines the following variables
#
#	MIZUIRO_FOUND        - True when mizuiro was found
#	MIZUIRO_INCLUDE_DIRS - The path to the mizuiro header files
#
# This modules accepts the following variables
#
#	MIZUIRO_INCLUDEDIR    - Hint where the mizuiro includes might be.

find_package(
	Boost
	${Mizuiro_FIND_REQUIRED}
)

find_path(
	Mizuiro_INCLUDE_DIR
	NAMES mizuiro/config.hpp
	HINTS ${MIZUIRO_INCLUDEDIR}
)

if(
	Mizuiro_INCLUDE_DIR
)
	find_file(
		MIZUIRO_CONFIG_HEADER
		mizuiro/config.hpp
		HINTS ${Mizuiro_INCLUDE_DIR}
	)

	include(
		CheckSymbolExists
	)

	check_symbol_exists(
		MIZUIRO_HAVE_FCPPT
		${MIZUIRO_CONFIG_HEADER}
		MIZUIRO_FCPPT_REQUIRED
	)

	if(
		MIZUIRO_FCPPT_REQUIRED
	)
		find_package(
			Fcppt
			${Mizuiro_FIND_REQUIRED}
		)
	endif()
endif()

include(
	FindPackageHandleStandardArgs
)

set(
	Mizuiro_INCLUDE_DIRS
	${Mizuiro_INCLUDE_DIR};${Boost_INCLUDE_DIRS}
)

if(
	MIZUIRO_FCPPT_REQUIRED
)
	set(
		Mizuiro_INCLUDE_DIRS
		${Mizuiro_INCLUDE_DIRS};${Fcppt_INCLUDE_DIRS}
	)
endif()

find_package_handle_standard_args(
	Mizuiro
	DEFAULT_MSG
	Mizuiro_INCLUDE_DIR
)

mark_as_advanced(
	Mizuiro_INCLUDE_DIR
	MIZUIRO_CONFIG_HEADER
	MIZUIRO_FCPPT_REQUIRED
)
