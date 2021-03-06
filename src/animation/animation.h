#ifndef ANIMATION_H
#define ANIMATION_H

#include "../core/colors.h"
#include "../core/section.h"

namespace PixelMaestro {
	class Section;

	class Animation {
		public:

			/// The orientation of the animation. Does not affect animations that don't have a specific direction (e.g. CycleAnimation).
			enum Orientations {
				HORIZONTAL,
				VERTICAL
			};

			Animation(Colors::RGB* colors = nullptr, unsigned char num_colors = 0, unsigned short speed = 100, unsigned short pause = 0);
			Colors::RGB* get_color_at_index(unsigned char index);
			unsigned char get_cycle_index();
			bool get_fade();
			unsigned char get_num_colors();
			unsigned int get_num_pixels();
			Orientations get_orientation();
			bool get_reverse();
			unsigned short get_pause();
			unsigned short get_speed();
			void set_colors(Colors::RGB* colors, unsigned char num_colors);
			void set_cycle_index(unsigned char index);
			void set_fade(bool fade);
			void set_orientation(Orientations orientation);
			void set_speed(unsigned short speed, unsigned short pause = 0);
			void set_reverse(bool reverse);
			bool update(const unsigned long& current_time, Section *section);
			virtual void update(Section* section) = 0;

		protected:			
			/// Array of colors used in the animation.
			Colors::RGB* colors_ = nullptr;

			///	The current stage in the animation cycle. Defaults to 0.
			unsigned char cycle_index_ = 0;

			/// Whether to fade between cycles. Defaults to true.
			bool fade_ = true;

			/// The amount of time (in milliseconds) since the last animation cycle change.
			unsigned long last_cycle_ = 0;

			/// The number of colors in colors_.
			unsigned char num_colors_ = 0;

			/// The orientation of the animation. Defaults to HORIZONTAL.
			Orientations orientation_ = Orientations::HORIZONTAL;

			/// The amount of time (in milliseconds) to wait before starting an animation cycle. Defaults to 0.
			unsigned short pause_ = 0;

			/// Whether to animate the current animation in reverse. Defaults to false.
			bool reverse_ = false;

			/// The amount of time (in milliseconds) between animation updates. Defaults to 100.
			unsigned short speed_ = 100;

			void update_cycle(unsigned char min, unsigned char max);
	};
}

#endif // ANIMATION_H
