#ifndef MIZUIRO_COLOR_DENORMALIZE_HPP_INCLUDED
#define MIZUIRO_COLOR_DENORMALIZE_HPP_INCLUDED

namespace mizuiro
{
namespace color
{
template
<
	class Color,
	class Channel,
	class Float
>
typename detail::channel_ref
<
	typename Color::proxy::layout,
	Channel,
	mizuiro::detail::const_tag
>::type
denormalize
(
	Color &c,
	Float const f
)
{
	typedef 
		typename detail::channel_ref
		<
			typename Color::proxy::layout,
			Channel,
			mizuiro::detail::const_tag
		>::type target_type;

	return 
		static_cast<target_type>
		(
			typename Color::layout::template channel_min
			<
				Channel
			>()
			+
			f*
			(
				typename Color::layout::template channel_max
				<
					Channel
				>()
				-
				typename Color::layout::template channel_min
				<
					Channel
				>()
			)
		);
}
}
}

#endif