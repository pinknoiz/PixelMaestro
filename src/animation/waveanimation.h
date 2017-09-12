#ifndef WAVEANIMATION_H
#define WAVEANIMATION_H

#include "animation.h"

namespace PixelMaestro {
	class WaveAnimation : public Animation {
		public:
			WaveAnimation(Colors::RGB* colors = nullptr, unsigned short num_colors = 0);
			void update(Section* section);
	};
}

#endif // WAVEANIMATION_H
