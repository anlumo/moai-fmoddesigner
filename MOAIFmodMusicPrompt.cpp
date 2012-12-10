// Copyright (c) 2012 Clemens F. Scharfen and Dominik Nussbaumer. All Rights Reserved.
// http://getmoai.com

// #include "pch.h"
#include "MOAIFmodMusicPrompt.h"

//================================================================//
// MOAIFmodMusicPrompt
//================================================================//

//----------------------------------------------------------------//
MOAIFmodMusicPrompt::MOAIFmodMusicPrompt () {

	// register all classes MOAIFmodMusicPrompt derives from
	// we need this for custom RTTI implementation
	RTTI_BEGIN
		RTTI_EXTEND ( MOAILuaObject )

		// and any other objects from multiple inheritance...
		// RTTI_EXTEND ( MOAIFmodMusicPromptBase )
	RTTI_END
}

//----------------------------------------------------------------//
MOAIFmodMusicPrompt::~MOAIFmodMusicPrompt () {
	// Nothing to do here...
}

//----------------------------------------------------------------//
void MOAIFmodMusicPrompt::RegisterLuaClass ( MOAILuaState& state ) {

	// call any initializers for base classes here:
	// MOAIFmodMusicPrompt::RegisterLuaClass ( state );

	// also register constants:
	// state.SetField ( -1, "FOO_CONST", ( u32 )FOO_CONST );

	// here are the class methods:
	luaL_Reg regTable [] = {
		//{ "classHello",		_classHello },
		{ NULL, NULL }
	};

	luaL_register ( state, 0, regTable );
}

//----------------------------------------------------------------//
void MOAIFmodMusicPrompt::RegisterLuaFuncs ( MOAILuaState& state ) {

	// call any initializers for base classes here:
	// MOAIFmodMusicPromptBase::RegisterLuaFuncs ( state );

	// here are the instance methods:
	luaL_Reg regTable [] = {
		{ "begin",			_begin },
		{ "end",			_end },
		{ "getMemoryInfo",	_getMemoryInfo },
		{ "isActive",		_isActive },
		{ "release",		_release },
		{ NULL, NULL }
	};

	luaL_register ( state, 0, regTable );
}

void MOAIFmodMusicPrompt::SetMusicPrompt(FMOD::MusicPrompt* musicPrompt)
{
	if(this->mMusicPrompt)
		delete mMusicPrompt;
	this->mMusicPrompt = musicPrompt;
}

int MOAIFmodMusicPrompt::_begin(lua_State* L)
{
	MOAI_LUA_SETUP ( MOAIFmodMusicPrompt, "U" )

	self->mMusicPrompt->begin();

	return 0;
}

int MOAIFmodMusicPrompt::_end(lua_State* L)
{
	MOAI_LUA_SETUP ( MOAIFmodMusicPrompt, "U" )

	self->mMusicPrompt->end();

	return 0;
}

// Von Jean-Luc übernommen...
//FIXME: implement MEMORY info struct
int MOAIFmodMusicPrompt::_getMemoryInfo(lua_State* L)
{
	MOAI_LUA_SETUP ( MOAIFmodMusicPrompt, "U" )

	u32 loadflag =	state.GetValue < u32 > ( 2, 0 );
	u32 eventloadflag =	state.GetValue < u32 > ( 3, 0 );

	unsigned int* memoryUsed;
	// FMOD_MEMORY_USAGE_DETAILS temp; // -> Als referenz übergeben

	self->mMusicPrompt->getMemoryInfo(loadflag, eventloadflag, memoryUsed, 0);

	lua_pushnumber( state, *memoryUsed);

	return 1;
}

int MOAIFmodMusicPrompt::_isActive(lua_State* L)
{
	MOAI_LUA_SETUP ( MOAIFmodMusicPrompt, "U" )

	bool isActive;
	self->mMusicPrompt->isActive(&isActive);

	lua_pushboolean(L, isActive);

	return 1;
}

int MOAIFmodMusicPrompt::_release(lua_State* L)
{
	MOAI_LUA_SETUP ( MOAIFmodMusicPrompt, "U" )

	self->mMusicPrompt->release();

	return 0;
}