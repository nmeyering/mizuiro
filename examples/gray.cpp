//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <mizuiro/color/channel/luminance.hpp>
#include <mizuiro/color/layout/gray.hpp>
#include <mizuiro/color/homogenous.hpp>
#include <mizuiro/color/proxy.hpp>
#include <mizuiro/image/store.hpp>
#include <mizuiro/image/format.hpp>
#include <mizuiro/image/view.hpp>
#include <mizuiro/image/interleaved.hpp>
#include <mizuiro/image/dimension.hpp>
#include <mizuiro/image/algorithm/for_each.hpp>
#include <boost/cstdint.hpp>

typedef mizuiro::image::format<
	mizuiro::image::dimension<
		2
	>,
	mizuiro::image::interleaved<
		mizuiro::color::homogenous<
			boost::uint8_t,
			mizuiro::color::layout::gray
		>
	>
> format;

struct set_color
{
	typedef void result_type;

	template<
		typename T
	>
	result_type
	operator()(
		T const &_color
	) const
	{
		_color. template set<
			mizuiro::color::channel::luminance
		>(
			42
		);
	}
};

int main()
{
	typedef mizuiro::image::store<
		format
	> store;

	store img(
		store::dim_type(
			32,
			64
		)
	);

	typedef store::view_type view_type;

	view_type const view(
		img.view()
	);

	typedef view_type::iterator iterator;

	mizuiro::image::algorithm::for_each(
		view,
		set_color()
	);
}
