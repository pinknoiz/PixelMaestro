#ifndef SECTIONSETCOLORANIMATIONEVENT_H
#define SECTIONSETCOLORANIMATIONEVENT_H

#include "../Section.h"
#include "Event.h"

using namespace PixelMaestro;

namespace PixelMaestro {
	class SectionSetColorAnimationEvent : public Event {
		public:
			SectionSetColorAnimationEvent(unsigned long time, Section *section, Section::ColorAnimations animation_, bool reverseAnimation, Section::AnimationOrientations orientation);
			SectionSetColorAnimationEvent(unsigned long time, Section *section, Section::ColorAnimations *animations, unsigned int numAnimations, bool reverseAnimation, Section::AnimationOrientations orientation);
			void run();

		private:
			Section::ColorAnimations animation_;;
			Section::ColorAnimations *animations_ = nullptr;
			unsigned int num_animations_;
			Section::AnimationOrientations orientation;
			bool reverseAnimation;
			Section *section_;

	};
}

#endif // SECTIONSETCOLORANIMATIONEVENT_H
