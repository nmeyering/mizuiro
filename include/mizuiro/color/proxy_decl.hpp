//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_PROXY_DECL_HPP_INCLUDED
#define MIZUIRO_COLOR_PROXY_DECL_HPP_INCLUDED

#include <mizuiro/color/types/pointer.hpp>
#include <mizuiro/color/types/channel_value.hpp>
#include <mizuiro/color/types/channel_reference.hpp>
#include <mizuiro/color/proxy_fwd.hpp>
#include <mizuiro/const_tag.hpp>

namespace mizuiro
{
namespace color
{

template<
	typename Access,
	typename Format,
	typename Constness
>
class proxy
{
public:
	typedef Access access;

	typedef Format format;

	typedef typename color::types::pointer<
		Access,
		Format,
		Constness
	>::type pointer;

	explicit proxy(
		pointer data
	);

	template<
		typename OtherConstness
	>
	proxy(
		color::proxy<
			Access,
			Format,
			OtherConstness
		> const &
	);

	template<
		typename Other
	>
	proxy const &
	operator=(
		Other const &
	) const;

	template<
		typename Channel
	>
	void
	set(
		typename types::channel_value<
			Format,
			Channel
		>::type const &
	) const;

	template<
		typename Channel
	>
	typename types::channel_reference<
		Access,
		Format,
		Channel,
		mizuiro::const_tag
	>::type
	get() const;

	pointer
	data() const;
private:
	pointer data_;	
};

}
}

#endif
