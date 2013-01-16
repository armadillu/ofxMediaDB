#ifndef ofxMediaDB_h
#define ofxMediaDB_h

#include "ofConstants.h"
#include "ofMain.h"
#include <map>

//define USING_FONTSTASH  in your project if you want to use ofxFontStash
//#define USING_FONTSTASH
//https://github.com/armadillu/ofxFontStash


#ifdef USING_FONTSTASH
	#include "ofxFontStash.h"
	//if you get a "Can't find ofxFontStash.h error, most likely you are not using the ofxFontStash addon
	//to fix the error, just define USING_FONTSTASH as "false" instead of "true" (6 lines above this one)
#endif


#ifdef TARGET_OF_IPHONE
	#include "ofxOpenALSoundPlayer.h"
#endif


//QUICK ACCESS-FROM-ANYWHERE MACROS
#define MEDIA_LOAD_TEXTURE(fileName,ID)			(ofxMediaDB::instance()->loadTexture(fileName,ID))
#define MEDIA_GET_TEXURE(ID)					(ofxMediaDB::instance()->getTexture(ID))
#define MEDIA_ADD_FONT(ofTTFPtr,ID)				(ofxMediaDB::instance()->addFont(ofTTFPtr,ID))
#define MEDIA_GET_FONT(ID)						(ofxMediaDB::instance()->getFont(ID))
#define MEDIA_ADD_SOUND(ofSoundPtr,ID)			(ofxMediaDB::instance()->addSound(ofSoundPtr,ID))
#define MEDIA_GET_SOUND(ID)						(ofxMediaDB::instance()->getSound(ID))

#ifdef TARGET_OF_IPHONE
#define MEDIA_ADD_OAL_SOUND(OALSoundPPtr,ID)	(ofxMediaDB::instance()->addOALSound(OALSoundPPtr,ID))
#define MEDIA_GET_OAL_SOUND(ID)						(ofxMediaDB::instance()->getOALSound(ID))
#endif

#ifdef USING_FONTSTASH
#define MEDIA_ADD_FONTSTASH(fontStashPtr,ID)	(ofxMediaDB::instance()->addFontStash(fontStashPtr,ID))
#define MEDIA_GET_FONTSTASH(ID)					(ofxMediaDB::instance()->getFontStash(ID))
#endif


class ofxMediaDB{

	public:
	
		static ofxMediaDB* instance();
		
		//ofTextures
		bool loadTexture(string fileName, int ID);
		ofTexture* getTexture(int ID);	
		void deleteAllTextures();

		//ofTrueTypeFont
		void addFont(ofTrueTypeFont *, int ID);
		ofTrueTypeFont* getFont(int ID);

		//ofSounds
		void addSound(ofSoundPlayer *, int ID);
		ofSoundPlayer* getSound(int ID);	

		//ofxOpenALSoundPlayer
		#ifdef TARGET_OF_IPHONE
		void addOALSound(ofxOpenALSoundPlayer *, int ID);
		ofxOpenALSoundPlayer* getOALSound(int ID);	
		#endif
	
		//ofxFontStash
		#if USING_FONTSTASH 
		void addFontStash(ofxFontStash *, int ID);
		ofxFontStash* getFontStash(int ID);	
		#endif
	
	
	private:
	
		static ofxMediaDB* singleton;
	
		map<int, ofTexture*> textureDB;
		map<int, ofTrueTypeFont*> fontDB;
		map<int, ofSoundPlayer*> soundDB;
	
		#if USING_FONTSTASH 
		map<int, ofxFontStash*> fontStashDB;
		#endif
	
		#ifdef TARGET_OF_IPHONE
		map<int, ofxOpenALSoundPlayer*> soundOALDB;
		#endif
};

#endif