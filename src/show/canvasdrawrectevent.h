#ifndef CANVASDRAWRECTEVENT_H
#define CANVASDRAWRECTEVENT_H

#include "../canvas/canvas.h"
#include "../core/point.h"
#include "event.h"

namespace PixelMaestro {
	class CanvasDrawRectEvent : public Event {
		public:
			CanvasDrawRectEvent(unsigned long time, Canvas* canvas, unsigned short origin_x, unsigned short origin_y, unsigned short size_x, unsigned short size_y, bool fill);
			void run();

		private:
			Canvas* canvas_;
			unsigned short origin_x_, origin_y_;
			unsigned short size_x_, size_y_;
			bool fill_;
	};
}

#endif // CANVASDRAWRECTEVENT_H
