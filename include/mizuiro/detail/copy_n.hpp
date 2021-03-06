//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_DETAIL_COPY_N_HPP_INCLUDED
#define MIZUIRO_DETAIL_COPY_N_HPP_INCLUDED

#include <boost/mpl/and.hpp>
#include <boost/utility/enable_if.hpp>
#include <boost/type_traits/is_fundamental.hpp>
#include <cstring>
#include <cstddef>

namespace mizuiro
{
namespace detail
{

template<
	typename Source,
	typename Size,
	typename Dest
>
typename boost::enable_if<
	boost::mpl::and_<
		boost::is_fundamental<
			Source
		>,
		boost::is_fundamental<
			Dest
		>
	>,
	void
>::type
copy_n(
	Source const *const _src,
	Size const _size,
	Dest *const _dest
)
{
	std::memcpy(
		_dest,
		_src,
		static_cast<
			std::size_t
		>(
			_size
			*
			static_cast<
				Size
			>
			(
				sizeof(Source)
			)
		)
	);
}

}
}

#endif
