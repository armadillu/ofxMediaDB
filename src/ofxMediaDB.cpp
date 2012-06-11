#include "ofxMediaDB.h"


ofxMediaDB* ofxMediaDB::singleton = NULL; //init singleton here

ofxMediaDB* ofxMediaDB::instance(){	
	if (!singleton){   // Only allow one instance of class to be generated.
		singleton = new ofxMediaDB();
	}
	return singleton;
}

// TEXTURES ////////////////////////////////////////////////////////////////////////////////////////

bool ofxMediaDB::loadTexture(string fileName, int ID){

	ofTexture * tex = new ofTexture();	
	bool load = ofLoadImage( *tex, fileName );

	if (load){	//tex was loaded just fine
		
		map<int,ofTexture*>::iterator it = textureDB.find(ID);		
		if ( it != textureDB.end() ){	//we already have a texture!!
			delete textureDB[ID]; //delete / replace the old texture with that ID
			printf( "ofxMediaDB loadTexture(): REPLACED texture (%s) with ID: %d\n", fileName.c_str(), ID );
		}else{
			printf( "ofxMediaDB loadTexture(): LOADED texture (%s) with ID: %d\n", fileName.c_str(), ID );		
		}
		textureDB[ID] = tex;

	}else{ //couldnt laod tex
		delete tex; //dont leak unused tex object
		printf( "ofxMediaDB loadTexture(): CANT LOAD TEXTURE (%s) with ID: %d\n", fileName.c_str(), ID );
	}

	return load;
}


ofTexture* ofxMediaDB::getTexture(int ID){
	
	ofTexture * tex = NULL;
	map<int, ofTexture*>::iterator it = textureDB.find(ID);		
	if ( it == textureDB.end() ){	//NO texture with that ID found!
		printf( "ofxMediaDB getTexture(): NO TEXTURE FOUND with ID: %d\n", ID );
	}else{
		tex = textureDB[ID];
	}
	return tex;	
}


void ofxMediaDB::deleteAllTextures(){

	for( map<int,ofTexture*>::iterator ii = textureDB.begin(); ii != textureDB.end(); ++ii ){
		ofTexture* tex = (*ii).second;
		delete tex;
	}
	textureDB.clear();
}

// SOUNDS ////////////////////////////////////////////////////////////////////////////////////////

void ofxMediaDB::addSound(ofSoundPlayer* s, int ID){
	
	map<int,ofSoundPlayer*>::iterator it = soundDB.find(ID);		
	if ( it != soundDB.end() ){	//we already have one!!
		delete soundDB[ID]; //delete / replace the old obj with that ID
		printf( "ofxMediaDB addSound(): REPLACED sound with ID: %d\n", ID );
	}else{
		printf( "ofxMediaDB addSound(): LOADED sound with ID: %d\n", ID );		
	}
	soundDB[ID] = s;		
}


ofSoundPlayer* ofxMediaDB::getSound(int ID){
	
	ofSoundPlayer * obj = NULL;
	map<int, ofSoundPlayer*>::iterator it = soundDB.find(ID);		
	if ( it == soundDB.end() ){	
		printf( "ofxMediaDB getSound(): NO SOUND FOUND with ID: %d\n", ID );
	}else{
		obj = soundDB[ID];
	}
	return obj;	
}


// OF_FONT ////////////////////////////////////////////////////////////////////////////////////////

void ofxMediaDB::addFont(ofTrueTypeFont* f, int ID){
	
	map<int,ofTrueTypeFont*>::iterator it = fontDB.find(ID);
	if ( it != fontDB.end() ){	//we already have one!!
		delete fontDB[ID]; //delete / replace the old obj with that ID
		printf( "ofxMediaDB addFont(): REPLACED font with ID: %d\n", ID );
	}else{
		printf( "ofxMediaDB addFont(): LOADED font with ID: %d\n", ID );
	}
	fontDB[ID] = f;	
}


ofTrueTypeFont* ofxMediaDB::getFont(int ID){
	
	ofTrueTypeFont * obj = NULL;
	map<int, ofTrueTypeFont*>::iterator it = fontDB.find(ID);
	if ( it == fontDB.end() ){
		printf( "ofxMediaDB getFont(): NO FONT FOUND with ID: %d\n", ID );
	}else{
		obj = fontDB[ID];
	}
	return obj;
}


// FONT_STASH ////////////////////////////////////////////////////////////////////////////////////////

#if USING_FONTSTASH
void ofxMediaDB::addFontStash(ofxFontStash* f, int ID){
	
	map<int,ofxFontStash*>::iterator it = fontStashDB.find(ID);
	if ( it != fontStashDB.end() ){	//we already have one!!
		delete fontStashDB[ID]; //delete / replace the old obj with that ID
		printf( "ofxMediaDB addFontStash(): REPLACED fontStash with ID: %d\n", ID );
	}else{
		printf( "ofxMediaDB addFontStash(): LOADED fontStash with ID: %d\n", ID );
	}
	fontStashDB[ID] = f;	
}


ofxFontStash* ofxMediaDB::getFontStash(int ID){
	
	ofxFontStash * obj = NULL;
	map<int, ofxFontStash*>::iterator it = fontStashDB.find(ID);
	if ( it == fontStashDB.end() ){
		printf( "ofxMediaDB getFontStash(): NO FONTSTASH FOUND with ID: %d\n", ID );
	}else{
		obj = fontStashDB[ID];
	}
	return obj;
}

#endif
