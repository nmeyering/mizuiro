//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_IMAGE_DETAIL_EDGE_POS_BEGIN_HPP_INCLUDED
#define MIZUIRO_IMAGE_DETAIL_EDGE_POS_BEGIN_HPP_INCLUDED

namespace mizuiro
{
namespace image
{
namespace detail
{

template<
	typename Bound
>
typename Bound::dim_type const
edge_pos_begin(
	Bound const &bound,
	typename Bound::size_type const index
)
{
	typedef typename Bound::dim_type dim_type;

	dim_type ret;

	for(
		typename dim_type::size_type i = 0;
		i < dim_type::static_size;
		++i
	)
		ret[i] =
			(i == index + 1)
			? bound.positions()[i] + 1
			: bound.positions()[i];
	
	return ret;
}

}
}
}

#endif
