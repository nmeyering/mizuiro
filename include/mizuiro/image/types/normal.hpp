//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_IMAGE_TYPES_NORMAL_HPP_INCLUDED
#define MIZUIRO_IMAGE_TYPES_NORMAL_HPP_INCLUDED

#include <mizuiro/image/types/pointer.hpp>
#include <mizuiro/image/types/data_store.hpp>
#include <mizuiro/image/detail/raw_container_fwd.hpp>
#include <mizuiro/color/types/homogenous_normal.hpp>
#include <mizuiro/color/types/pointer.hpp>
#include <mizuiro/color/types/store.hpp>
#include <mizuiro/color/homogenous.hpp>
#include <mizuiro/access/normal.hpp>

namespace mizuiro
{
namespace image
{
namespace types
{

template<
	typename Format,
	typename Constness
>
struct pointer<
	::mizuiro::access::normal,
	Format,
	Constness
>
:
mizuiro::color::types::pointer<
	::mizuiro::access::normal,
	typename Format::color_format,
	Constness
>
{};

template<
	typename ChannelType,
	typename Layout
>
struct data_store<
	::mizuiro::access::normal,
	::mizuiro::color::homogenous<
		ChannelType,
		Layout
	>
>
{
	typedef detail::raw_container<
		ChannelType
	> type;
};

}
}
}

#endif
