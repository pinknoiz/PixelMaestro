/*
	Section.cpp - Class for controlling multiple Pixels.
	Requires Pixel and Colors classes.
*/

#ifndef SECTION_H
#define SECTION_H

#include "Colors.h"
#include "Pixel.h"

namespace PixelMaestro {
	class Section {

		public:
			/// Set of animations usable by the Section.
			enum ColorAnimations {
				NONE,			/// Turns off all Pixels in the Section.
				SOLID,			/// Displays the default color of each Pixel.
				BLINK,			/// Alternates Pixels between their default color and black (off).
				WAVE,			/// Scrolls the color array across the Section.
				PONG,			/// Scrolls the color array back and forth in a ping-pong pattern.
				MERGE,			/// Converges colors into the center of the Section.
				RANDOMINDEX,	/// Sets each Pixel to a random color stored in colors_.
				SPARKLE,		/// Creates a shimmering effect by turning on random pixels.
				PATTERN,		/// Scrolls through the pattern set in pattern_.
				CYCLE,			/// Cycles all pixels through all stored colors.
				STATIC			/// Creates a static effect by blending each pixel between varying levels of gray.
			};

			/** Overlays a second Section on top of the current one.
				Use with getPixelColor() to automatically perform the blending.
			*/
			struct Overlay {
				Section *section = nullptr;
				Colors::MixMode mixMode;
				float alpha;

				void operator=(Overlay newLayer) {
					section = newLayer.section;
					mixMode = newLayer.mixMode;
					alpha = newLayer.alpha;
				}
			};

			/**
				Defines the Pixel layout of the Section.
				The number of Pixels in this Section is determined by rows * columns.
			*/
			struct Layout {
				unsigned short rows;
				unsigned short columns;
			};

			Section();
			Section(Pixel *pixels, unsigned short rows, unsigned short columns);

			Section::ColorAnimations getColorAnimation();
			bool getFade();
			Layout *getLayout();
			unsigned char getNumPixels();
			Pixel *getPixel(unsigned short row, unsigned short column);
			Pixel *getPixel(unsigned int pixel);
			Colors::RGB getPixelColor(unsigned short row, unsigned short column);
			Colors::RGB getPixelColor(unsigned int pixel);
			unsigned char getUpdateSpeed();
			void setAll(Colors::RGB *color);
			void setColorAnimation(Section::ColorAnimations animation = ColorAnimations(NONE), bool reverseAnimation = false);
			void setColors(Colors::RGB *colors, unsigned int numColors);
			void setCycleIndex(unsigned int index);
			void setOverlay(Overlay overlay);
			void setOne(unsigned int pixel, Colors::RGB *color);
			void setOne(unsigned short row, unsigned short column, Colors::RGB *color);
			void setPattern(unsigned char *pattern, unsigned char patternLength);
			void setPixels(Pixel *pixels, unsigned short rows, unsigned short columns);
			void setUpdateSpeed(unsigned char speed, unsigned char delay = 0);
			void toggleFade();
			void update(unsigned long currentTime);
			void unsetOverlay();

		private:
			Colors::RGB *colors_;			/// Array of colors used in the Section.
			unsigned long *current_time_;	/// The current program time. Used to determine when to update the Section.
			unsigned long cycle_end_;		/// The end time of the last cycle. Used to determine when to run the next cycle.
			unsigned int cycle_index_ = 0;	///	The current cycle index.
			unsigned char delay_ = 0;		/// Any delay between cycles.
			bool fade_ = true;				/// Whether to fade between cycles.
			unsigned long last_time_ = 0;	/// The last time the Section was updated. Note that this is different than cycle_end_.
			Layout layout_;					/// The Pixel layout of the array.
			Overlay overlay_;				/// Section overlaying the current section (if applicable);
			Pixel *pixels_;					/// Array of Pixels stored in the Section.
			Section::ColorAnimations color_animation_ = ColorAnimations(SOLID);	/// The current Section animation. Defaults to SOLID.
			unsigned int num_colors_;		/// The number of colors in colors_.
			unsigned char *pattern_;		/// The pattern to display when the PATTERN animation is active.
			unsigned char pattern_length_ = 0;	/// The number of pattern elements in pattern_.
			bool reverse_animation_ = false;	/// Whether to reverse the animation in color_animation_.
			unsigned char speed_ = 10;		/// The update speed of the Section (in ms). Defaults to 10.

			// Color animation functions
			void animation_blink();
			void animation_cycle();
			void animation_decrementCycle();
			unsigned int animation_getColorIndex(unsigned int count);
			void animation_incrementCycle();
			void animation_merge();
			void animation_pattern();
			void animation_pong();
			void animation_randomIndex();
			void animation_solid();
			void animation_sparkle();
			void animation_static();
			void animation_wave();
	};
}

#endif