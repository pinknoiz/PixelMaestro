#include "../utility.h"
#include "sparkleanimation.h"

namespace PixelMaestro {
	SparkleAnimation::SparkleAnimation(Section *section, Colors::RGB* colors, unsigned short num_colors, unsigned char threshold) : ColorAnimation(section, colors, num_colors) {
		this->threshold_ = threshold;
	}

	void SparkleAnimation::update() {
		for (unsigned short row = 0; row < section_->get_dimensions()->y; row++) {
			for (unsigned short column = 0; column < section_->get_dimensions()->x; column++) {
				if ((Utility::rand() % 100) > threshold_) {
					section_->set_one(row, column, get_color_at_index(column));
				}
				else {
					section_->set_one(row, column, &Colors::BLACK);
				}
			}
		}
	}
}
