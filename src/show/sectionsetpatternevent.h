#ifndef SECTIONSETPATTERNEVENT_H
#define SECTIONSETPATTERNEVENT_H

#include "../section.h"
#include "event.h"

namespace PixelMaestro {
	class SectionSetPatternEvent : public Event {
		public:
			SectionSetPatternEvent(unsigned long time, Section *section, Pattern *pattern);
			void run();

		private:
			Pattern *pattern_;
			Section *section_;
	};
}

#endif // SECTIONSETPATTERNEVENT_H
