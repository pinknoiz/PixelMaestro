#ifndef BLINKDEMO_H
#define BLINKDEMO_H

#include "drawingarea/controller/maestrocontroller.h"
#include "../drawingarea/simpledrawingarea.h"

class BlinkDemo : public SimpleDrawingArea {
	public:
		BlinkDemo(QWidget *parent, MaestroController *maestroController);
};

#endif // BLINKDEMO_H