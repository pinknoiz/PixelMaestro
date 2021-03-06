#include "animation.h"

namespace PixelMaestro {
	/**
	 * Constructor.
	 * @param section The Section that this animation will render in.
	 * @param colors Initial color palette.
	 * @param num_colors The number of colors in the palette.
	 * @param speed The amount of time (in milliseconds) to run a single animation cycle.
	 * @param pause The amount of time (in milliseconds) to wait before starting an animation cycle.
	 */
	Animation::Animation(Colors::RGB* colors, unsigned char num_colors, unsigned short speed, unsigned short pause) {
		colors_ = colors;
		num_colors_ = num_colors;
		speed_ = speed;
		pause_ = pause;
	}

	/**
		Returns the color at the specified index.
		If the index exceeds the size of the color palette, the index will wrap around to the start of the array and count the remainder.
		For example, if the Section has 10 Pixels and 5 Colors, the Pixel at index 7 will use the color at index 2 (7 % 5 == 2).
		Used mainly to determine which color a Pixel should use during an animation based on where it is in the array.

		@param index Desired index.
		@return Color at the specified index.
	*/
	Colors::RGB* Animation::get_color_at_index(unsigned char index) {
		if (num_colors_ > 0 && index >= num_colors_) {
			return &colors_[index % num_colors_];
		}

		return &colors_[index];
	}

	/**
	 * Returns the current cycle index.
	 *
	 * @return Cycle index.
	 */
	unsigned char Animation::get_cycle_index() {
		return cycle_index_;
	}

	/**
	 * Returns whether the animation is fading.
	 * @return True if fading.
	 */
	bool Animation::get_fade() {
		return fade_;
	}

	/**
	 * Returns the number of colors in the animation's palette.
	 *
	 * @return Number of colors in the color palette.
	 */
	unsigned char Animation::get_num_colors() {
		return num_colors_;
	}

	/**
	 * Returns the animation's orientation.
	 * @return Animation's orientation
	 */
	Animation::Orientations Animation::get_orientation() {
		return orientation_;
	}

	/**
	 * Returns the amount of time (in milliseconds) to wait before starting an animation cycle.
	 * @return Pause time.
	 */
	unsigned short Animation::get_pause() {
		return pause_;
	}

	/**
	 * Returns whether the animation is running in reverse.
	 *
	 * @return True if running in reverse.
	 */
	bool Animation::get_reverse() {
		return reverse_;
	}

	/**
	 * Returns the animation's speed.
	 * @return Speed.
	 */
	unsigned short Animation::get_speed() {
		return speed_;
	}

	/**
		Replaces the current color palette.

		@param colors New color palette.
		@param num_colors Number of colors in the palette.
	*/
	void Animation::set_colors(Colors::RGB* colors, unsigned char num_colors) {
		colors_ = colors;
		num_colors_ = num_colors;
	}

	/**
	 * Sets the cycle index to the specified index.
	 * To be safe, we keep it under num_colors_.
	 *
	 * @param index New cycle index.
	 */
	void Animation::set_cycle_index(unsigned char index) {
		if (num_colors_ && index > num_colors_) {
			index %= num_colors_;
		}

		cycle_index_ = index;
	}

	/**
	 * Toggles fading the animation.
	 *
	 * @param fade If true, fade between cycles.
	 */
	void Animation::set_fade(bool fade) {
		fade_ = fade;
	}

	/**
	 * Sets the animation's orientation.
	 *
	 * @param orientation New orientation.
	 */
	void Animation::set_orientation(Orientations orientation) {
		orientation_ = orientation;
	}

	/**
		Sets whether to run the animation in reverse.

		@param reverse If true, run in reverse.
	 */
	void Animation::set_reverse(bool reverse) {
		reverse_ = reverse;
	}

	/**
	 * Sets the amount of time between animation updates.
	 *
	 * @param speed Amount of time (in milliseconds) between animation cycles.
	 * @param pause AMount of time (in milliseconds) to wait before starting an animation cycle.
	 */
	void Animation::set_speed(unsigned short speed, unsigned short pause) {
		speed_ = speed;
		pause_ = pause;
	}

	/**
	 * Updates the animation.
	 * This checks to see if the animation should update, then calls the derived class's update method.
	 * @param current_time The current runtime.
	 * @param section The parent Section.
	 * @return True if the update was processed.
	 */
	bool Animation::update(const unsigned long &current_time, Section *section) {
		// If the color palette is not set, exit.
		if (num_colors_ == 0 || colors_ == nullptr) {
			return false;
		}

		/*
			Update the animation cycle.
			cycle_interval_ tracks the amount of time between cycles, while last_cycle_ tracks the time of the last change.
			If it's time for the next cycle, run the animation.
		*/
		if (current_time - last_cycle_ >= (unsigned long)speed_) {

			// Run the derived Animation's update function.
			update(section);

			// Update the last cycle time.
			last_cycle_ = current_time;

			return true;
		}
		return false;
	}

	// Private methods

	/**
		Incremnets the current animation cycle.
		If reverse_animation_ is true, this decrements the cycle, moving the animation backwards.
		If the animation reaches the end of its cycle, it will jump back (or forward) to the start (or end).

		@param min The minimum possible value of cycle_index_.
		@param max The maximum possible value of cycle_index_.
	*/
	void Animation::update_cycle(unsigned char min, unsigned char max) {
		if (reverse_) {
			if (cycle_index_ == 0) {
				cycle_index_ = max - 1;
			}
			else {
				cycle_index_--;
			}
		}
		else {
			if (cycle_index_ >= max - 1) {
				cycle_index_ = min;
			}
			else {
				cycle_index_++;
			}
		}
	}

}
