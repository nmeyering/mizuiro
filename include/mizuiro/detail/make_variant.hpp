//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_DETAIL_MAKE_VARIANT_HPP_INCLUDED
#define MIZUIRO_DETAIL_MAKE_VARIANT_HPP_INCLUDED

#include <mizuiro/config.hpp>
#ifdef MIZUIRO_HAVE_FCPPT
#include <fcppt/variant/object_fwd.hpp>
#else
#include <boost/variant/variant.hpp>
#endif

namespace mizuiro
{
namespace detail
{

template<
	typename Sequence
>
struct make_variant
{
#ifdef MIZUIRO_HAVE_FCPPT
	typedef fcppt::variant::object<
		Sequence
	> type;
#else
	typedef typename boost::make_variant_over<
		Sequence
	>::type type;
#endif
};

}
}

#endif
