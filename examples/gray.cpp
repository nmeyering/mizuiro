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

struct set_color {
	typedef void result_type;

	template<
		typename T
	>
	result_type
	operator()(
		T const &t
	) const
	{
		t. template set<
			mizuiro::color::channel::gray
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
