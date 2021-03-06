//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_IMAGE_DETAIL_RAW_VIEW_FROM_POINTER_HPP_INCLUDED
#define MIZUIRO_IMAGE_DETAIL_RAW_VIEW_FROM_POINTER_HPP_INCLUDED

#include <mizuiro/image/view_fwd.hpp>
#include <mizuiro/detail/choose_const.hpp>
#include <mizuiro/access/raw.hpp>

namespace mizuiro
{
namespace image
{
namespace detail
{

template<
	typename Format,
	typename Pointer
>
struct raw_view_from_pointer
{
	typedef view<
		::mizuiro::access::raw,
		Format,
		typename mizuiro::detail::choose_const<
			Pointer
		>::type
	> type;
};

}
}
}

#endif
