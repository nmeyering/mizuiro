//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_CONVERT_LUMINANCE_TO_RGB_HPP_INCLUDED
#define MIZUIRO_COLOR_CONVERT_LUMINANCE_TO_RGB_HPP_INCLUDED

#include <mizuiro/color/convert/detail/max_alpha.hpp>
#include <mizuiro/color/normalize.hpp>
#include <mizuiro/color/denormalize.hpp>
#include <mizuiro/color/channel/luminance.hpp>
#include <mizuiro/color/is_rgb.hpp>
#include <mizuiro/color/is_luminance.hpp>
#include <mizuiro/color/object_impl.hpp>
#include <boost/mpl/and.hpp>
#include <boost/utility/enable_if.hpp>

namespace mizuiro
{
namespace color
{

template
<
	class Dest,
	class Src
>
typename
boost::enable_if<
	boost::mpl::and_<
		color::is_rgb<
			Dest
		>,
		color::is_luminance<
			typename Src::format
		>
	>,
	color::object<
		Dest
	> const
>::type
convert(
	Src const &_src
)
{
	typedef object<
		Dest
	> dest_object;

	dest_object dest;

	detail::max_alpha
	(
		dest
	);
	
	float const src_normalized = 
		normalize
		<
			channel::luminance,
			float
		>
		(
			_src
		);

	dest.template set<channel::red>
	(
		denormalize<
			typename dest_object::format,
			channel::red
		>
		(
			0.3f * src_normalized
		)
	);

	dest.template set<channel::green>
	(
		denormalize<
			typename dest_object::format,
			channel::green
		>
		(
			0.59f * src_normalized
		)
	);

	dest.template set<channel::blue>
	(
		denormalize<
			typename dest_object::format,
			channel::blue
		>
		(
			0.11f * src_normalized
		)
	);

	return dest;
}

}
}

#endif
