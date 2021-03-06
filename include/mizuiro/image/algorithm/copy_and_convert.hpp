//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_IMAGE_ALGORITHM_COPY_AND_CONVERT_HPP_INCLUDED
#define MIZUIRO_IMAGE_ALGORITHM_COPY_AND_CONVERT_HPP_INCLUDED

#include <mizuiro/image/algorithm/detail/apply_binary_iteration.hpp>
#include <mizuiro/image/algorithm/detail/copy_and_convert.hpp>
#include <mizuiro/image/algorithm/copy.hpp>
#include <mizuiro/image/views_are_compatible.hpp>
#include <mizuiro/detail/variant_apply_binary.hpp>
#include <boost/utility/enable_if.hpp>

namespace mizuiro
{
namespace image
{
namespace algorithm
{

template<
	typename ViewS,
	typename ViewD
>
typename boost::disable_if<
	image::views_are_compatible<
		ViewS,
		ViewD
	>,
	void
>::type
copy_and_convert(
	ViewS const &_src,
	ViewD const &_dest
)
{
	mizuiro::detail::variant_apply_binary(
		detail::apply_binary_iteration(
			detail::copy_and_convert()
		),
		_src.range(),
		_dest.range()
	);
}

template<
	typename ViewS,
	typename ViewD
>
typename boost::enable_if<
	image::views_are_compatible<
		ViewS,
		ViewD
	>,
	void
>::type
copy_and_convert(
	ViewS const &_src,
	ViewD const &_dest
)
{
	algorithm::copy(
		_src,
		_dest
	);
}

}
}
}

#endif
