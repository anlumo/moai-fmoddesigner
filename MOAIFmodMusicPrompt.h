// Copyright (c) 2012 Clemens F. Scharfen and Dominik Nussbaumer. All Rights Reserved.
// http://getmoai.com

#ifndef MOAIFMODMUSICPROMPT_H
#define MOAIFMODMUSICPROMPT_H

#include <fmod.hpp>
#include <fmod_event.hpp>
#include <fmod_errors.h>
#include <moaicore/moaicore.h>

//================================================================//
// MOAIFmodMusicPrompt
//================================================================//
/**	@name	MOAIFmodMusicPrompt
	@text	Example class for extending Moai using MOAILuaObject.
			Copy this object, rename it and add your own stuff.
			Just don't forget to register it with the runtime
			using the REGISTER_LUA_CLASS macro (see moaicore.cpp).
*/
class MOAIFmodMusicPrompt :
	public virtual MOAILuaObject {	
private:

	static int		_begin			( lua_State* L );
	static int		_end			( lua_State* L );
	static int		_getMemoryInfo	( lua_State* L );
	static int		_isActive		( lua_State* L );
	static int		_release		( lua_State* L );

public:

	FMOD::MusicPrompt* mMusicPrompt;

	DECL_LUA_FACTORY ( MOAIFmodMusicPrompt )

	//----------------------------------------------------------------//
					MOAIFmodMusicPrompt				();
					~MOAIFmodMusicPrompt			();
	void			RegisterLuaClass	( MOAILuaState& state );
	void			RegisterLuaFuncs	( MOAILuaState& state );
	void			SetMusicPrompt		( FMOD::MusicPrompt* musicPrompt);
};

#endif