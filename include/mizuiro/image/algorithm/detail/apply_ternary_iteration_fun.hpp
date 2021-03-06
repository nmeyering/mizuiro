//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_IMAGE_ALGORITHM_DETAIL_APPLY_TERNARY_ITERATION_FUN_HPP_INCLUDED
#define MIZUIRO_IMAGE_ALGORITHM_DETAIL_APPLY_TERNARY_ITERATION_FUN_HPP_INCLUDED

namespace mizuiro
{
namespace image
{
namespace algorithm
{
namespace detail
{

template<
	typename Function
>
class apply_ternary_iteration_fun
{
public:
	apply_ternary_iteration_fun()
	:
		fun_()
	{}

	explicit apply_ternary_iteration_fun(
		Function const &_fun
	)
	:
		fun_(_fun)
	{}

	typedef void result_type;

	template<
		typename T1,
		typename T2,
		typename T3
	>
	result_type
	operator()(
		T1 const &_range1,
		T2 const &_range2,
		T3 const &_range3
	) const
	{
		typename T2::iterator it2(
			_range2.begin()
		);

		typename T3::iterator it3(
			_range3.begin()
		);

		typename T2::iterator const end1(
			_range1.end()
		);

		for(
			typename T1::iterator it1(
				_range1.begin()
			);
			it1 != end1; 
			++it1, ++it2, ++it3
		)
			fun_(
				*it1,
				*it2,
				*it3
			);
	}
private:
	Function const fun_;
};

}
}
}
}

#endif
