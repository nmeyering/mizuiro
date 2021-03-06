//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_IMAGE_ITERATOR_IMPL_HPP_INCLUDED
#define MIZUIRO_IMAGE_ITERATOR_IMPL_HPP_INCLUDED

#include <mizuiro/image/iterator_decl.hpp>
#include <mizuiro/image/detail/advance_iterator.hpp>
#include <mizuiro/image/detail/increment_iterator.hpp>
#include <mizuiro/image/detail/decrement_iterator.hpp>
#include <mizuiro/image/detail/iterator_difference.hpp>
#include <mizuiro/image/detail/dereference_iterator.hpp>
#include <mizuiro/image/detail/compare_iterator.hpp>
#include <mizuiro/image/detail/iterator_data.hpp>
#include <mizuiro/detail/variant_impl.hpp>
#include <mizuiro/detail/variant_apply_unary.hpp>
#include <mizuiro/detail/variant_apply_binary.hpp>

template<
	typename Access,
	typename Format,
	typename Constness
>
mizuiro::image::iterator<Access, Format, Constness>::iterator(
	internal_type const &_internal
)
:
	internal_(_internal)
{}

template<
	typename Access,
	typename Format,
	typename Constness
>
typename mizuiro::image::iterator<Access, Format, Constness>::internal_type const &
mizuiro::image::iterator<Access, Format, Constness>::internal() const
{
	return internal_;
}

template<
	typename Access,
	typename Format,
	typename Constness
>
typename mizuiro::image::iterator<Access, Format, Constness>::pointer
mizuiro::image::iterator<Access, Format, Constness>::data() const
{
	return
		mizuiro::detail::variant_apply_unary(
			detail::iterator_data<
				pointer
			>(),
			internal_
		);
}

template<
	typename Access,
	typename Format,
	typename Constness
>
void
mizuiro::image::iterator<Access, Format, Constness>::advance(
	difference_type	const _diff
)
{
	internal_ =
		mizuiro::detail::variant_apply_unary(
			detail::advance_iterator<
				internal_type,
				difference_type
			>(
				_diff
			),
			internal_
		);
}
	
template<
	typename Access,
	typename Format,
	typename Constness
>
void
mizuiro::image::iterator<Access, Format, Constness>::increment()
{
	internal_ =
		mizuiro::detail::variant_apply_unary(
			detail::increment_iterator<
				internal_type
			>(),
			internal_
		);
}

template<
	typename Access,
	typename Format,
	typename Constness
>
void
mizuiro::image::iterator<Access, Format, Constness>::decrement()
{
	internal_ =
		mizuiro::detail::variant_apply_unary(
			detail::decrement_iterator<
				internal_type
			>(),
			internal_
		);
}

template<
	typename Access,
	typename Format,
	typename Constness
>
typename mizuiro::image::iterator<Access, Format, Constness>::difference_type
mizuiro::image::iterator<Access, Format, Constness>::distance_to(
	iterator const &_other
) const
{
	return
		mizuiro::detail::variant_apply_binary(
			detail::iterator_difference<
				difference_type
			>(),
			internal_,
			_other.internal_
		);
}

template<
	typename Access,
	typename Format,
	typename Constness
>
typename mizuiro::image::iterator<Access, Format, Constness>::reference
mizuiro::image::iterator<Access, Format, Constness>::dereference() const
{
	return
		mizuiro::detail::variant_apply_unary(
			detail::dereference_iterator<
				reference
			>(),
			internal_
		);
}

template<
	typename Access,
	typename Format,
	typename Constness
>
bool
mizuiro::image::iterator<Access, Format, Constness>::equal(
	iterator const &_other
) const
{
	return
		mizuiro::detail::variant_apply_binary(
			detail::compare_iterator(),
			internal_,
			_other.internal_
		);
}

#endif
