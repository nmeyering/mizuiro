//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_IMAGE_STORE_IMPL_HPP_INCLUDED
#define MIZUIRO_IMAGE_STORE_IMPL_HPP_INCLUDED

#include <mizuiro/image/store_decl.hpp>
#include <mizuiro/image/view_impl.hpp>
#include <mizuiro/image/detail/raw_container_impl.hpp>

template<
	typename Format,
	typename Access 
>
mizuiro::image::store<Format, Access>::store()
:
	dim_(
		dim_type::null()
	),
	data_()
{}

template<
	typename Format,
	typename Access 
>
mizuiro::image::store<Format, Access>::store(
	dim_type const &_dim
)
:
	dim_(
		_dim
	),
	data_(
		data_store_size(
			Access(),
			Format(),
			dim_
		)
	)
{}

template<
	typename Format,
	typename Access 
>
typename mizuiro::image::store<Format, Access>::pointer
mizuiro::image::store<Format, Access>::data()
{
	return data_.data();
}

template<
	typename Format,
	typename Access 
>
typename mizuiro::image::store<Format, Access>::const_pointer
mizuiro::image::store<Format, Access>::data() const
{
	return data_.data();
}

template<
	typename Format,
	typename Access 
>
typename mizuiro::image::store<Format, Access>::view_type const
mizuiro::image::store<Format, Access>::view()
{
	return view_type(
		dim(),
		data()
	);
}

template<
	typename Format,
	typename Access 
>
typename mizuiro::image::store<Format, Access>::const_view_type const
mizuiro::image::store<Format, Access>::view() const
{
	return const_view_type(
		dim(),
		data()
	);
}
template<
	typename Format,
	typename Access 
>
typename mizuiro::image::store<Format, Access>::dim_type const &
mizuiro::image::store<Format, Access>::dim() const
{
	return dim_;
}

#endif
