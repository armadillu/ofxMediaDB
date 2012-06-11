ofxMediaDB allows you to easily reach your ofTexture, ofSoundPlayer, ofTrueTypeFont or ofxFontStash objects from anywhere within your code - ofxMediaDB uses the "singleton" design patern to centralize all your loaded media objects. Useful on videogame projects and such, where multpile remote objects may share the same resoruces. It has a few Macros defined to simplify access even further.

example on how to handle textures:

	//organize your texture ID list as enums for clarity and simplicity
	enum myTextureIDs{ 
		TEX_MONKEY, 
		TEX_BANANA,
		etc…
	};
	
	void setup(){
		//load a texture
		bool didLoad1 = MEDIA_LOAD_TEXTURE("monkey.png", TEX_MONKEY);
	}
	
	... meanwhile, in some other class ...
	
	void draw(){	
		//easily reach your textures from any file within your project
		ofTexture * tex = MEDIA_GET_TEXURE(TEX_MONKEY);
	}
	
same can be done with ofSoundPlayers, ofTrueTypeFont and ofxFontStash