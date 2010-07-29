//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_IMAGE_DETAIL_STACKED_DIM_TYPE_HPP_INCLUDED
#define MIZUIRO_IMAGE_DETAIL_STACKED_DIM_TYPE_HPP_INCLUDED

#include <mizuiro/image/detail/pitch_type.hpp>
#include <mizuiro/image/dimension_decl.hpp>
#include <mizuiro/array.hpp>

namespace mizuiro
{
namespace image
{
namespace detail
{

template<
	typename Dim
>
struct stacked_dim_type
:
mizuiro::array<
	typename Dim::value_type,
	detail::pitch_type<
		Dim
	>::type::static_size
>
{
};

}
}
}

#endif
