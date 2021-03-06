//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_OBJECT_IMPL_HPP_INCLUDED
#define MIZUIRO_COLOR_OBJECT_IMPL_HPP_INCLUDED

#include <mizuiro/color/init/detail/assign_object.hpp>
#include <mizuiro/color/object_decl.hpp>
#include <mizuiro/color/proxy_impl.hpp>
#include <mizuiro/color/is_color.hpp>
#include <mizuiro/access/homogenous_normal.hpp>
#include <boost/utility/enable_if.hpp>

template<
	typename Format
>
mizuiro::color::object<Format>::object()
:
	data_()
{}

template<
	typename Format
>
mizuiro::color::object<Format>::object(
	object const &other
)
:
	data_(other.data_)
{}

template<
	typename Format
>
template<
	typename Other
>
mizuiro::color::object<Format>::object(
	Other const &other_,
	typename boost::enable_if<
		color::is_color<
			Other
		>
	>::type *
)
{
	proxy(
		data_.data()
	) = other_;
}

template<
	typename Format
>
template<
	typename Init
>
mizuiro::color::object<Format>::object(
	Init const &init_,
	typename boost::disable_if<
		color::is_color<
			Init
		>
	>::type *
)
{
	init::detail::assign_object(
		*this,
		init_
	);
}

template<
	typename Format
>
template<
	typename Channel
>
void
mizuiro::color::object<Format>::set(
	typename types::channel_value<
		format,
		Channel
	>::type const &ref
)
{
	proxy(
		data_.data()
	).set<
		Channel
	>(
		ref
	);
}

template<
	typename Format
>
template<
	typename Channel
>
typename mizuiro::color::types::channel_reference<
	typename mizuiro::color::object<
		Format
	>::access,
	typename mizuiro::color::object<
		Format
	>::format,
	Channel,
	mizuiro::const_tag
>::type
mizuiro::color::object<Format>::get() const
{
	return
		const_proxy(
			data_.data()
		).get<
			Channel
		>();
}

template<
	typename Format
>
typename mizuiro::color::object<
	Format
>::pointer
mizuiro::color::object<Format>::data()
{
	return data_.data();
}

template<
	typename Format
>
typename mizuiro::color::object<
	Format
>::const_pointer
mizuiro::color::object<Format>::data() const
{
	return data_.data();
}

#endif
