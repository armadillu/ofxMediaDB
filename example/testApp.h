#pragma once

#include "ofMain.h"
#include "ofxMediaDB.h"

class testApp : public ofBaseApp{

	public:
	
		enum TextureIDs{ //define our texture ID's as enums (int)
			TEX_MONKEY, 
			TEX_BANANA,
		};
	
		enum FontIDs{ //define our Font ID's as enums (int)
			FONT_ARIAL
		};

		enum SoundIDs{ //define our Sound ID's as enums (int)
			SOUND_MONKEY
		};

		enum FontStashIDs{ //define our FontStash ID's as enums (int)
			FONTSTASH_ARIAL
		};

		void setup();
		void draw();

};
