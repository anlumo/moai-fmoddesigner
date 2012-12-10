// Copyright (c) 2010-2011 Zipline Games, Inc. All Rights Reserved.
// http://getmoai.com

#ifndef MOAIFMODEVENTQUEUEENTRY_H
#define MOAIFMODEVENTQUEUEENTRY_H

#include <fmod.hpp>
#include <fmod_event.hpp>
#include <moaicore/moaicore.h>
#include <moaicore/MOAILua.h>
#include <moaicore/MOAIFmodEvent.h>

//================================================================//
// MOAIFmodEventQueueEntry
//================================================================//
/**	@name	MOAIFmodEventQueueEntry
	@text	Example class for extending Moai using MOAILuaObject.
			Copy this object, rename it and add your own stuff.
			Just don't forget to register it with the runtime
			using the REGISTER_LUA_CLASS macro (see moaicore.cpp).
*/
class MOAIFmodEventQueueEntry :
	public virtual MOAILuaObject {	
private:

	static FMOD::EventQueueEntry* 		mEventQueueEntry;
	
	//----------------------------------------------------------------//
	static int		_classHello			( lua_State* L );	
	static int		_instanceHello		( lua_State* L );
	static int 		_getCrossfadeTime	( lua_State* L );
	static int 		_getDelayTime		( lua_State* L );
	static int 		_getExpiryTime		( lua_State* L );
	//static int		_getInfoOnlyEvent	( lua_State* L );
	static int		_getInterrupt		( lua_State* L );
	//static int		_getMemoryInfo		( lua_State* L );
	static int		_getPriority		( lua_State* L );
	static int		_getRealEvent		( lua_State* L );
	//static int		_getUserData		( lua_State* L );
	static int		_release			( lua_State* L );
	static int		_setCrossfadeTime	( lua_State* L );
	static int		_setDelayTime		( lua_State* L );
	static int		_setExpiryTime		( lua_State* L );
	static int		_setInterrupt		( lua_State* L );
	static int		_setPriority		( lua_State* L );
	//static int		_setUserData		( lua_State* L );

public:

	DECL_LUA_FACTORY ( MOAIFmodEventQueueEntry )

	//----------------------------------------------------------------//
					MOAIFmodEventQueueEntry				();
					~MOAIFmodEventQueueEntry			();
	void			RegisterLuaClass	( MOAILuaState& state );
	void			RegisterLuaFuncs	( MOAILuaState& state );
	void			setEventQueueEntry	( FMOD::EventQueueEntry& eventQueueEntry );
};

#endif