//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_IMAGE_ALGORITHM_DETAIL_COPY_RAW_HPP_INCLUDED
#define MIZUIRO_IMAGE_ALGORITHM_DETAIL_COPY_RAW_HPP_INCLUDED

#include <mizuiro/image/algorithm/detail/apply_binary_iteration.hpp>
#include <mizuiro/image/algorithm/detail/copy_element.hpp>
#include <mizuiro/image/is_linear_range.hpp>
#include <mizuiro/image/underlying_data_pointer.hpp>
#include <mizuiro/detail/copy.hpp>
#include <boost/mpl/and.hpp>
#include <boost/utility/enable_if.hpp>

namespace mizuiro
{
namespace image
{
namespace algorithm
{
namespace detail
{

struct copy_raw
{
	typedef void result_type;

	template<
		typename RangeS,
		typename RangeD
	>
	typename boost::disable_if<
		boost::mpl::and_<
			is_linear_range<
				RangeS
			>,
			is_linear_range<
				RangeD
			>
		>,
		result_type
	>::type
	operator()(
		RangeS const &_source,
		RangeD const &_dest
	) const
	{
		// TODO: optimize this as well!
		apply_binary_iteration(
			detail::copy_element()
		)(
			_source,
			_dest
		);
	}

	template<
		typename RangeS,
		typename RangeD
	>
	typename boost::enable_if<
		boost::mpl::and_<
			is_linear_range<
				RangeS
			>,
			is_linear_range<
				RangeD
			>
		>,
		result_type
	>::type
	operator()(
		RangeS const &_src,
		RangeD const &_dest
	) const
	{
		mizuiro::detail::copy(
			underlying_data_pointer(
				_src.begin()
			),
			underlying_data_pointer(
				_src.end()
			),
			underlying_data_pointer(
				_dest.begin()
			)
		);
	}
};

}
}
}
}

#endif
