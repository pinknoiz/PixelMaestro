#ifndef SECTIONSETCYCLEINTERVAL_H
#define SECTIONSETCYCLEINTERVAL_H

#include "Transition.h"

namespace PixelMaestro {
	class SectionSetCycleIntervalTransition : public Transition {
		public:
			SectionSetCycleIntervalTransition(unsigned long time, Section *section, unsigned short interval, unsigned short pause = 0);
			void run();

		private:
			Section *section_;
			unsigned short interval_;
			unsigned short pause_;
	};
}

#endif // SECTIONSETCYCLEINTERVAL_H
