//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_CONVERT_DETAIL_CHANNEL_TO_MAX_HPP_INCLUDED
#define MIZUIRO_COLOR_CONVERT_DETAIL_CHANNEL_TO_MAX_HPP_INCLUDED

#include <mizuiro/color/types/channel_value.hpp>
#include <mizuiro/color/channel_max.hpp>

namespace mizuiro
{
namespace color
{
namespace detail
{

template<
	typename Channel,
	typename Color
>
void
channel_to_max(
	Color &_color
)
{
	_color.template set<
		Channel
	>
	(
		color::channel_max<
			typename color::types::channel_value<
				typename Color::format,
				Channel
			>::type
		>()
	);
}

}
}
}

#endif
