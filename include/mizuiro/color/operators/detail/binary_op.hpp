//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_OPERATORS_DETAIL_BINARY_OP_HPP_INCLUDED
#define MIZUIRO_COLOR_OPERATORS_DETAIL_BINARY_OP_HPP_INCLUDED

#include <mizuiro/color/operators/detail/binary_op_channel.hpp>
#include <mizuiro/color/object_impl.hpp>
#include <mizuiro/color/for_each_channel.hpp>

namespace mizuiro
{
namespace color
{
namespace operators
{
namespace detail
{

template<
	template<
		typename
	> class Operation,
	typename Color1,
	typename Color2
>
color::object<
	typename Color1::format
> const
binary_op(
	Color1 const &color1_,
	Color2 const &color2_
)
{
	typedef typename Color1::format format;

	typedef color::object<
		format
	> result_type;

	result_type result(
		color1_
	);

	color::for_each_channel<
		format
	>(
		color::operators::detail::binary_op_channel<
			Operation,
			result_type,
			Color2
		>(
			result,
			color2_
		)
	);

	return result;
}

}
}
}
}

#endif
