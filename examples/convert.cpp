#include <mizuiro/color/homogenous.hpp>
#include <mizuiro/color/object_impl.hpp>
#include <mizuiro/color/layout/rgba.hpp>
#include <mizuiro/color/layout/gray.hpp>
#include <mizuiro/color/convert.hpp>
#include <mizuiro/color/init.hpp>
#include <mizuiro/color/output.hpp>
#include <boost/cstdint.hpp>
#include <iostream>
#include <ostream>

int main()
{
	typedef mizuiro::color::object<
		mizuiro::color::homogenous<
			boost::uint8_t,
			mizuiro::color::layout::rgba
		>
	> rgba_color;

	typedef mizuiro::color::object<
		mizuiro::color::homogenous<
			boost::uint8_t,
			mizuiro::color::layout::gray
		>
	> gray_color;

	gray_color const test_gray(
		(mizuiro::color::init::gray = 42)
	);

	rgba_color const test_rgb(
		mizuiro::color::convert<
			rgba_color
		>(
			test_gray
		)
	);

	std::cout 
		<< "gray value was: " 
		<< test_gray 
		<< " and was converted to" 
		<< test_rgb
		<< '\n';
	
	typedef 
		mizuiro::color::object
		<
			mizuiro::color::homogenous
			<
				float,
				mizuiro::color::layout::rgba
			>
		> rgba_float_color;

	/*
	rgba_float_color test_float
	(
		mizuiro::color::convert
		<
			rgba_float_color
		>
		(
			test_rgb
		)
	);
	
	std::cout 
		<< "converted the rgb value to floats: "
		<< test_float
		<< '\n';
	*/
}
