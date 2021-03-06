/*
 * SimpleDrawingArea - Implementation of a MaestroDrawingArea as a simple 2D grid.
 */

#ifndef SIMPLEDRAWINGAREA_H
#define SIMPLEDRAWINGAREA_H

#include "controller/maestrocontroller.h"
#include "maestrodrawingarea.h"

class SimpleDrawingArea : public MaestroDrawingArea {
	public:
		SimpleDrawingArea(QWidget* parent, MaestroController* maestro_controller);
		void resize_pixels();

	protected:
		void paintEvent(QPaintEvent *event) override;
		void resizeEvent(QResizeEvent *event) override;

		/// The size of each rendered Pixel.
		unsigned char radius_ = 20;
		/// The amount of space between each Pixel.
		unsigned char pad_ = radius_ * 2;

		/// Used to determine whether the Maestro's size has changed.
		unsigned int last_pixel_count_ = 0;
};

#endif // SIMPLEDRAWINGAREA_H
