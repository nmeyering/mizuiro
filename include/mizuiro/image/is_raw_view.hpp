//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_IMAGE_IS_RAW_VIEW_HPP_INCLUDED
#define MIZUIRO_IMAGE_IS_RAW_VIEW_HPP_INCLUDED

#include <mizuiro/access/raw.hpp>
#include <boost/type_traits/is_same.hpp>

namespace mizuiro
{
namespace image
{

template<
	typename View
>
struct is_raw_view
:
boost::is_same<
	typename View::access,
	::mizuiro::access::raw
>
{};

}
}

#endif
