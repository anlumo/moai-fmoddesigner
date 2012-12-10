// Copyright (c) 2012 Nikolaus Pöttler Florian Gnadlinger
// http://www.technikum-wien.at

#ifndef MOAIFMODEVENTPARAMETER_H
#define MOAIFMODEVENTPARAMETER_H

#include <moaicore/MOAILua.h>
#include <moaicore/moaicore.h>
#include <fmod.hpp>
#include <fmod_event.hpp>


namespace FMOD {
	class System;
	class Sound;
	class Channel;
	class ChannelGroup;
	class EventParameter;
};

//================================================================//
// MOAIFmodEventParamter
//================================================================//
class MOAIFmodEventParameter :
    public MOAIGlobalClass < MOAIFmodEventParameter, MOAILuaObject >  {

private:
 
    //----------------------------------------------------------------//
    static int _classEventParameter( lua_State* L );
    static int _instanceEventParameter( lua_State* L );
	
	static int _getInfo( lua_State* L);
	static int _disableAutomation( lua_State* L);
	static int _getMemoryInfo( lua_State* L);
	static int _getRange( lua_State* L);
	static int _getSeekSpeed( lua_State* L);
	static int _getUserData(lua_State* L);
	static int _getValue(lua_State* L);
	static int _getVelocity(lua_State* L);
	static int _keyOff(lua_State* L);
	static int _setSeekSpeed(lua_State* L);
	static int _setUserData(lua_State* L);
	static int _setValue(lua_State* L);
	static int _setVelocity(lua_State* L);
 
public:
	FMOD::EventParameter m_EventParameter;
 
    DECL_LUA_FACTORY ( MOAIFmodEventParameter )
 
    //----------------------------------------------------------------//
                    MOAIFmodEventParameter             ();
                    ~MOAIFmodEventParameter            ();
    void            RegisterLuaClass    ( MOAILuaState& state );
    void            RegisterLuaFuncs    ( MOAILuaState& state );

	FMOD::EventParameter GetEventParameter();
};
#endif