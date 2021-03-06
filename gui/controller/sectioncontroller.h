/*
 * SectionController - Wrapper class for managing a Section using a MaestroController.
 */

#ifndef SECTIONCONTROLLER_H
#define SECTIONCONTROLLER_H

#include "core/colors.h"
#include "core/pixel.h"
#include "core/section.h"
#include <memory>
#include <vector>

using namespace PixelMaestro;

class SectionController {
	public:
		/// Selected MaestroControl color scheme (helper member). Defaults to ColorWheel.
		int mc_color_scheme_ = 3;

		SectionController(Point* layout);
		SectionController(Section* section, bool is_overlay = false);
		std::shared_ptr<SectionController> add_overlay(Colors::MixMode mix_mode, float alpha = 0.5);
		Colors::RGB* get_colors();
		unsigned char get_num_colors();
		Section::Overlay* get_overlay();
		std::shared_ptr<SectionController> get_overlay_controller();
		std::shared_ptr<Section> get_section();
		void set_colors(Colors::RGB* colors, unsigned char num_colors);

	private:
		/// Colors used by the Section and its Overlay.
		std::vector<Colors::RGB> colors_;

		/// Stores the size of the grid.
		Point dimensions_ = {0, 0};

		/// Determines whether this Section is an Overlay.
		bool is_overlay_ = false;

		/// Controller for the Overlay Section.
		std::shared_ptr<SectionController> overlay_controller_ = nullptr;

		/// Stores the Section.
		std::shared_ptr<Section> section_ = nullptr;
};

#endif // SECTIONCONTROLLER_H
