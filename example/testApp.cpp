#include "testApp.h"


void testApp::setup(){

	ofEnableAlphaBlending();
	ofBackground(22);
	
	bool didLoad1 = MEDIA_LOAD_TEXTURE("monkey.png", TEX_MONKEY);		
	bool didLoad2 = MEDIA_LOAD_TEXTURE("banana_missing.png", TEX_BANANA); //this one wont load, file is missing
	
	ofSoundPlayer * sp = new ofSoundPlayer();
	sp->loadSound("monkey.aif");
	MEDIA_ADD_SOUND(sp, SOUND_MONKEY);
	
	ofTrueTypeFont * ttf = new ofTrueTypeFont();
	ttf->loadFont("arial.ttf", 24, true);
	MEDIA_ADD_FONT(ttf, FONT_ARIAL);

	ofxFontStash * fs = new ofxFontStash();
	fs->setup("arial.ttf");
	MEDIA_ADD_FONTSTASH(fs, FONTSTASH_ARIAL);
	
}


void testApp::draw(){

	ofTranslate(10, 10);
	
	MEDIA_GET_TEXURE(TEX_MONKEY)->draw(0,0);
	
	//careful, this one would crash, as ofxMediaDB returns NULL for that ID (file not found)
	//MEDIA_GET_TEXURE(BANANA_TEX)->draw(200,0);	
	
	if ( !MEDIA_GET_SOUND(SOUND_MONKEY)->getIsPlaying() )
		MEDIA_GET_SOUND(SOUND_MONKEY)->play();

	MEDIA_GET_FONT(FONT_ARIAL)->drawString("test", 10, 100);
	MEDIA_GET_FONTSTASH(FONTSTASH_ARIAL)->draw("test2", 24, 10, 130);	
	
		
}


