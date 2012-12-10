// Copyright (c) 2010-2011 Zipline Games, Inc. All Rights Reserved.
// http://getmoai.com

#ifndef MOAIFMODEVENT_H
#define MOAIFMODEVENT_H

#include <moaicore/moaicore.h>
#include <fmod_event.hpp>

//================================================================//
// MOAIFoo
//================================================================//
/**	@name	MOAIFoo
	@text	Example class for extending Moai using MOAILuaObject.
			Copy this object, rename it and add your own stuff.
			Just don't forget to register it with the runtime
			using the REGISTER_LUA_CLASS macro (see moaicore.cpp).
*/
class MOAIFmodEvent :
	public virtual MOAILuaObject {
private:

	//----------------------------------------------------------------//

	static int		_get3DAttributes		( lua_State* L );
	static int		_get3DOcclusion			( lua_State* L );
	static int		_getCategory			( lua_State* L );
	static int		_getChannelGroup		( lua_State* L );
	static int		_getInfo				( lua_State* L );
	static int		_getMemoryInfo			( lua_State* L );
	static int		_getMute				( lua_State* L );
	static int		_getNumParameters		( lua_State* L );
	static int		_getNumProperties		( lua_State* L );
	static int		_getParameter			( lua_State* L );
	static int		_getParameterByIndex	( lua_State* L );
	static int		_getParentGroup			( lua_State* L );
	static int		_getPaused				( lua_State* L );
	static int		_getPitch				( lua_State* L );
	static int		_getProperty			( lua_State* L );
	static int		_getPropertyByIndex		( lua_State* L );
	static int		_getPropertyInfo		( lua_State* L );
	static int		_getReverbProperties	( lua_State* L );
	static int		_getState				( lua_State* L );
	static int		_getUserData			( lua_State* L );
	static int		_getVolume				( lua_State* L );
	static int		_release				( lua_State* L );
	static int		_set3DAttributes		( lua_State* L );
	static int		_set3DOcclusion			( lua_State* L );
	static int		_setCallback			( lua_State* L );
	static int		_setMute				( lua_State* L );
	static int		_setPaused				( lua_State* L );
	static int		_setPitch				( lua_State* L );
	static int		_setProperty			( lua_State* L );
	static int		_setPropertyByIndex		( lua_State* L );
	static int		_setReverbProperties	( lua_State* L );
	static int		_setUserData			( lua_State* L );
	static int		_setVolume				( lua_State* L );
	static int		_start					( lua_State* L );
	static int		_stop					( lua_State* L );

	//----------------------------------------------------------------//

	FMOD::Event* _event;

	//----------------------------------------------------------------//

public:
	
	DECL_LUA_FACTORY ( MOAIFmodEvent )

	//----------------------------------------------------------------//
					MOAIFmodEvent				();
					~MOAIFmodEvent			();
	void			RegisterLuaClass	( MOAILuaState& state );
	void			RegisterLuaFuncs	( MOAILuaState& state );

	
};

#endif //MOAIFMODEVENT_H