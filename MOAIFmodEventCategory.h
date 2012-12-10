
#ifndef MOAIFMODEVENTGROUP_H
#define MOAIFMODEVENTGROUP_H

#include <moaicore/moaicore.h>
#include <fmod_event.hpp>
#include "MOAIFmodEvent.h"
class MOAIFmodEventCategory :
public virtual MOAILuaObject {

private:

//----------------------------------------------------------------//

public:

		DECL_LUA_FACTORY ( MOAIFmodEventCategory)

//----------------------------------------------------------------//
		MOAIFmodEventCategory	();
		~MOAIFmodEventCategory	();
		void	RegisterLuaClass	( MOAILuaState& state );
		void	RegisterLuaFuncs	( MOAILuaState& state );


		static int  getInfo            ( lua_State* L );
        static int  getCategory        ( lua_State* L );
        static int  getCategoryByIndex ( lua_State* L );
        static int  getNumCategories   ( lua_State* L );
        static int  getEventByIndex    ( lua_State* L );
        static int  getNumEvents       ( lua_State* L );
        static int  getParentCategory  ( lua_State* L );

        static int  stopAllEvents      ( lua_State* L );
        static int  setVolume          ( lua_State* L );
        static int  getVolume          ( lua_State* L );
        static int  setPitch           ( lua_State* L );
        static int  getPitch           ( lua_State* L );
        static int  setPaused          ( lua_State* L );
        static int  getPaused          ( lua_State* L );
        static int  setMute            ( lua_State* L );
        static int  getMute            ( lua_State* L );
        static int  getChannelGroup    ( lua_State* L );
     //   static int  setUserData        ( lua_State* L );
       // static int  getUserData        ( lua_State* L );

      //  static int  getMemoryInfo(lua_State* L);
		void setCategory(FMOD::EventCategory* cat);


		FMOD::EventCategory* mEventCategory;

};

#endif