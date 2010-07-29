#ifndef MIZUIRO_ARRAY_HPP_INCLUDED
#define MIZUIRO_ARRAY_HPP_INCLUDED

#include <mizuiro/config.hpp>
#ifdef MIZUIRO_HAVE_FCPPT
#include <fcppt/tr1/array.hpp>
#else
#include <boost/array.hpp>
#endif
#include <cstddef>

namespace mizuiro
{

template<
	typename T,
	std::size_t N
>
struct array
{
#ifdef MIZUIRO_HAVE_FCPPT
	typedef std::tr1::array<
		T,
		N
	> type;
#else
	typedef boost::array<
		T,
		N
	> type;
#endif
};

}

#endif