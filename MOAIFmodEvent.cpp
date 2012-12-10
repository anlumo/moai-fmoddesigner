// Copyright (c) 2010-2011 Zipline Games, Inc. All Rights Reserved.
// http://getmoai.com

#include <lua.h>
#include <moaicore/moaicore.h>
#include <fmod.hpp>
#include "MOAIFmodEvent.h"

//not exisiting yet
#include "MOAIEventCategory.h"


//================================================================//
// MOAIFoo
//================================================================//

//----------------------------------------------------------------//
MOAIFmodEvent::MOAIFmodEvent () 
{

	RTTI_BEGIN
		RTTI_EXTEND ( MOAILuaObject )
	RTTI_END

	_event = new FMOD::Event();
}

//----------------------------------------------------------------//
MOAIFmodEvent::~MOAIFmodEvent () 
{
	delete _event;
}

//----------------------------------------------------------------//
//void MOAIFmodEvent::RegisterLuaClass ( MOAILuaState& state ) {
//
//	luaL_Reg regTable [] = {
//		{ "classFmodEvent",		_classFmodEvent },
//		{ NULL, NULL }
//	};
//
//	luaL_register ( state, 0, regTable );
//}

//----------------------------------------------------------------//
void MOAIFmodEvent::RegisterLuaFuncs ( MOAILuaState& state ) {

	// here are the instance methods:
	luaL_Reg regTable [] = {
	{ "_get3DAttributes",		_get3DAttributes		},
	{ "_get3DOcclusion",		_get3DOcclusion			},
	{ "_getCategory",		_getCategory			},
	{ "_getChannelGroup",		_getChannelGroup		},
	{ "_getInfo",		_getInfo				},
	{ "_getMemoryInfo",		_getMemoryInfo			},
	{ "_getMute",		_getMute				},
	{ "_getNumParameters",		_getNumParameters		},
	{ "_getNumProperties",		_getNumProperties		},
	{ "_getParameter",		_getParameter			},
	{ "_getParameterByIndex",		_getParameterByIndex	},
	{ "_getParentGroup",		_getParentGroup			},
	{ "_getPaused",		_getPaused				},
	{ "_getPitch",		_getPitch				},
	{ "_getProperty",		_getProperty			},
	{ "_getPropertyByIndex",		_getPropertyByIndex		},
	{ "_getPropertyInfo",		_getPropertyInfo		},
	{ "_getReverbProperties",		_getReverbProperties	},
	{ "_getState",		_getState				},
	{ "_getUserData",		_getUserData			},
	{ "_getVolume",		_getVolume				},
	{ "_release",		_release				},
	{ "_set3DAttributes",		_set3DAttributes		},
	{ "_set3DOcclusion",		_set3DOcclusion			},
	{ "_setCallback",		_setCallback			},
	{ "_setMute",		_setMute				},
	{ "_setPaused",		_setPaused				},
	{ "_setPitch",		_setPitch				},
	{ "_setProperty",		_setProperty			},
	{ "_setPropertyByIndex",		_setPropertyByIndex		},
	{ "_setReverbProperties",		_setReverbProperties	},
	{ "_setUserData",		_setUserData			},
	{ "_setVolume",		_setVolume				},
	{ "_start",		_start					},
	{ "_stop",		_stop					},
		{ NULL, NULL }
	};

	luaL_register ( state, 0, regTable );
}

int	MOAIFmodEvent::_get3DAttributes( lua_State* L )
{
	MOAI_LUA_SETUP ( MOAIFmodEvent, "UUUU" );

	if ( !self->_event ) {
		MOAILog ( state, MOAILogMessages::MOAI_BadCast_DS );
		return 0;
	}

	FMOD_VECTOR* position = state.GetValue < FMOD_VECTOR* >( 1, 0 );
	FMOD_VECTOR* velocity = state.GetValue < FMOD_VECTOR* >( 2, 0 );
	FMOD_VECTOR* orientation = state.GetValue < FMOD_VECTOR* >( 3, 0 );

	FMOD_RESULT result = self->_event->get3DAttributes(position, velocity, orientation);

	lua_pushnumber ( state, result );
	return 1;
}
int	MOAIFmodEvent::_get3DOcclusion( lua_State* L )
{
	MOAI_LUA_SETUP ( MOAIFmodEvent, "UUU" );

	if ( !self->_event ) {
		MOAILog ( state, MOAILogMessages::MOAI_BadCast_DS );
		return 0;
	}

	float* directocclusion = state.GetValue < float* >( 1, 0 );
	float* reverbocclusion = state.GetValue < float* >( 2, 0 );

	FMOD_RESULT result = self->_event->get3DOcclusion(directocclusion, reverbocclusion);

	lua_pushnumber ( state, result );

	return 1;
}

int	MOAIFmodEvent::_getCategory( lua_State* L )
{
	MOAI_LUA_SETUP ( MOAIFmodEvent, "UU" );

	if ( !self->_event ) {
		MOAILog ( state, MOAILogMessages::MOAI_BadCast_DS );
		return 0;
	}

	FMOD::EventCategory** category = state.GetValue < FMOD::EventCategory** >( 1, 0 );

	FMOD_RESULT result = self->_event->getCategory(category);

	lua_pushnumber ( state, result );
	return 1;
}

int	MOAIFmodEvent::_getChannelGroup( lua_State* L )
{
	MOAI_LUA_SETUP ( MOAIFmodEvent, "UU" );

	if ( !self->_event ) {
		MOAILog ( state, MOAILogMessages::MOAI_BadCast_DS );
		return 0;
	}

	FMOD::ChannelGroup** channelgroup = state.GetValue < FMOD::ChannelGroup** >( 1, 0 );
	FMOD_RESULT result = self->_event->getChannelGroup(channelgroup);
	
	lua_pushnumber ( state, result );
	return 1;
}

int	MOAIFmodEvent::_getInfo( lua_State* L )
{
	MOAI_LUA_SETUP ( MOAIFmodEvent, "UUUU" );

	if ( !self->_event ) {
		MOAILog ( state, MOAILogMessages::MOAI_BadCast_DS );
		return 0;
	}

	int* index = state.GetValue < int* >( 1, 0 );
	char** name = state.GetValue < char** >( 2, 0 );
	FMOD_EVENT_INFO* info = state.GetValue < FMOD_EVENT_INFO* >( 3, 0 );

	FMOD_RESULT result = self->_event->getInfo(index, name, info);
	
	lua_pushnumber ( state, result );
	return 1;
}

int	MOAIFmodEvent::_getMemoryInfo( lua_State* L )
{
	MOAI_LUA_SETUP ( MOAIFmodEvent, "UNNUU" );

	if ( !self->_event ) {
		MOAILog ( state, MOAILogMessages::MOAI_BadCast_DS );
		return 0;
	}

	unsigned int memorybits = state.GetValue < unsigned int >( 1, 0 );
	unsigned int event_memorybits = state.GetValue < unsigned int >( 2, 0 );
	unsigned int* memoryused = state.GetValue < unsigned int* >( 3, 0 );
	FMOD_MEMORY_USAGE_DETAILS* memoryused_details = state.GetValue < FMOD_MEMORY_USAGE_DETAILS* >( 4, 0 );

	FMOD_RESULT result = self->_event->getMemoryInfo(memorybits, event_memorybits, memoryused, memoryused_details);
	lua_pushnumber ( state, result );
	return 1;
}

int	MOAIFmodEvent::_getMute( lua_State* L )
{
	MOAI_LUA_SETUP ( MOAIFmodEvent, "UU" );

	if ( !self->_event ) {
		MOAILog ( state, MOAILogMessages::MOAI_BadCast_DS );
		return 0;
	}

	bool* mute = state.GetValue < bool* >( 1, 0 );
	FMOD_RESULT result = self->_event->getMute(mute);
	lua_pushnumber ( state, result );
	return 1;
}

int	MOAIFmodEvent::_getNumParameters( lua_State* L )
{
	MOAI_LUA_SETUP ( MOAIFmodEvent, "UU" );

	if ( !self->_event ) {
		MOAILog ( state, MOAILogMessages::MOAI_BadCast_DS );
		return 0;
	}

	int* numparameters = state.GetValue < int* >( 1, 0 );

	FMOD_RESULT result = self->_event->getNumParameters(numparameters);
	lua_pushnumber ( state, result );
	return 1;
}

int	MOAIFmodEvent::_getNumProperties( lua_State* L )
{
	MOAI_LUA_SETUP ( MOAIFmodEvent, "UU" );

	if ( !self->_event ) {
		MOAILog ( state, MOAILogMessages::MOAI_BadCast_DS );
		return 0;
	}
	int* numproperities = state.GetValue < int* >( 1, 0 );
	FMOD_RESULT result = self->_event->getNumProperties(numproperities);
	lua_pushnumber ( state, result );
	return 1;
}

int	MOAIFmodEvent::_getParameter( lua_State* L )
{
	MOAI_LUA_SETUP ( MOAIFmodEvent, "UUU" );

	if ( !self->_event ) {
		MOAILog ( state, MOAILogMessages::MOAI_BadCast_DS );
		return 0;
	}
	const char* name = state.GetValue < const char* >( 1, 0 );
	FMOD::EventParameter** parameter = state.GetValue < FMOD::EventParameter** >( 2, 0 );
	FMOD_RESULT result = self->_event->getParameter(name, parameter);
	lua_pushnumber ( state, result );
	return 1;
}

int	MOAIFmodEvent::_getParameterByIndex( lua_State* L )
{
	MOAI_LUA_SETUP ( MOAIFmodEvent, "UNU" );

	if ( !self->_event ) {
		MOAILog ( state, MOAILogMessages::MOAI_BadCast_DS );
		return 0;
	}

	int index = state.GetValue < int >( 1, 0 );
	FMOD::EventParameter** parameter = state.GetValue < FMOD::EventParameter ** >( 2, 0 );
	FMOD_RESULT result = self->_event->getParameterByIndex(index, parameter);
	lua_pushnumber ( state, result );
	return 1;

}

int	MOAIFmodEvent::_getParentGroup( lua_State* L )
{
	MOAI_LUA_SETUP ( MOAIFmodEvent, "UU" );

	if ( !self->_event ) {
		MOAILog ( state, MOAILogMessages::MOAI_BadCast_DS );
		return 0;
	}
	FMOD::EventGroup ** group = state.GetValue < FMOD::EventGroup ** >( 1, 0 );
	FMOD_RESULT result = self->_event->getParentGroup(group);
	lua_pushnumber ( state, result );
	return 1;

}

int	MOAIFmodEvent::_getPaused( lua_State* L )
{
	MOAI_LUA_SETUP ( MOAIFmodEvent, "UU" );

	if ( !self->_event ) {
		MOAILog ( state, MOAILogMessages::MOAI_BadCast_DS );
		return 0;
	}
	bool* paused = state.GetValue < bool* >( 1, 0 );
	FMOD_RESULT result = self->_event->getPaused(paused);
	lua_pushnumber ( state, result );
	return 1;
}

int	MOAIFmodEvent::_getPitch( lua_State* L )
{
	MOAI_LUA_SETUP ( MOAIFmodEvent, "UUU" );

	if ( !self->_event ) {
		MOAILog ( state, MOAILogMessages::MOAI_BadCast_DS );
		return 0;
	}
	float* pitch = state.GetValue < float* >( 1, 0 );
	FMOD_EVENT_PITCHUNITS units = (FMOD_EVENT_PITCHUNITS) state.GetValue < int >( 2, 0 );
	FMOD_RESULT result = self->_event->getPitch(pitch, units);
	lua_pushnumber ( state, result );
	return 1;

}

int	MOAIFmodEvent::_getProperty( lua_State* L )
{
	MOAI_LUA_SETUP ( MOAIFmodEvent, "UUUN" );

	if ( !self->_event ) {
		MOAILog ( state, MOAILogMessages::MOAI_BadCast_DS );
		return 0;
	}
	const char* propertyname = state.GetValue < const char* >( 1, 0 );
	void* value = state.GetValue < void* >( 2, 0 );
	bool this_instance = state.GetValue < bool >( 3, 0 );
	FMOD_RESULT result = self->_event->getProperty(propertyname, value, this_instance);
	lua_pushnumber ( state, result );
	return 1;
}
int	MOAIFmodEvent::_getPropertyByIndex( lua_State* L )
{
	MOAI_LUA_SETUP ( MOAIFmodEvent, "UNUN" );

	if ( !self->_event ) {
		MOAILog ( state, MOAILogMessages::MOAI_BadCast_DS );
		return 0;
	}
	int propertyindex = state.GetValue < int >( 1, 0 );
	void* value = state.GetValue < void* >( 2, 0 );
	bool this_instance = state.GetValue < bool >( 3, 0 );
	FMOD_RESULT result = self->_event->getPropertyByIndex(propertyindex, value, this_instance);
	lua_pushnumber ( state, result );
	return 1;
}

int	MOAIFmodEvent::_getPropertyInfo( lua_State* L )
{
	MOAI_LUA_SETUP ( MOAIFmodEvent, "UUUU" );

	if ( !self->_event ) {
		MOAILog ( state, MOAILogMessages::MOAI_BadCast_DS );
		return 0;
	}
	int* propertyindex = state.GetValue < int* >( 1, 0 );
	char** propertyname = state.GetValue < char** >( 2, 0 );
	FMOD_EVENTPROPERTY_TYPE* type = state.GetValue < FMOD_EVENTPROPERTY_TYPE* >( 3, 0 );
	FMOD_RESULT result = self-> _event->getPropertyInfo(propertyindex, propertyname, type);
	lua_pushnumber ( state, result );
	return 1;
}

int	MOAIFmodEvent::_getReverbProperties( lua_State* L )
{
	MOAI_LUA_SETUP ( MOAIFmodEvent, "UU" );

	if ( !self->_event ) {
		MOAILog ( state, MOAILogMessages::MOAI_BadCast_DS );
		return 0;
	}
	FMOD_REVERB_CHANNELPROPERTIES* props = state.GetValue < FMOD_REVERB_CHANNELPROPERTIES* >( 1, 0 );
	FMOD_RESULT result = self->_event->getReverbProperties(props);
	lua_pushnumber ( state, result );
	return 1;
}

int	MOAIFmodEvent::_getState( lua_State* L )
{
	MOAI_LUA_SETUP ( MOAIFmodEvent, "UU" );

	if ( !self->_event ) {
		MOAILog ( state, MOAILogMessages::MOAI_BadCast_DS );
		return 0;
	}
	FMOD_EVENT_STATE* event_state = state.GetValue < FMOD_EVENT_STATE* >( 1, 0 );
	FMOD_RESULT result = self->_event->getState(event_state);
	lua_pushnumber ( state, result );
	return 1;
}

int	MOAIFmodEvent::_getUserData( lua_State* L )
{
	MOAI_LUA_SETUP ( MOAIFmodEvent, "UU" );

	if ( !self->_event ) {
		MOAILog ( state, MOAILogMessages::MOAI_BadCast_DS );
		return 0;
	}
	void** userdata = state.GetValue < void** >( 1, 0 );
	FMOD_RESULT result = self->_event->getUserData(userdata);
	lua_pushnumber( state, result );
	return 1;
}

int	MOAIFmodEvent::_getVolume( lua_State* L )
{
	MOAI_LUA_SETUP ( MOAIFmodEvent, "UN" );

	if ( !self->_event ) {
		MOAILog ( state, MOAILogMessages::MOAI_BadCast_DS );
		return 0;
	}
	float* volume = state.GetValue < float* >( 1, 0 );
	FMOD_RESULT result = self->_event->getVolume(volume);
	lua_pushnumber ( state, result );
	return 1;
}

int	MOAIFmodEvent::_release( lua_State* L )
{
	MOAI_LUA_SETUP ( MOAIFmodEvent, "UNN" );

	if ( !self->_event ) {
		MOAILog ( state, MOAILogMessages::MOAI_BadCast_DS );
		return 0;
	}
	bool freeeventdata = state.GetValue < bool >( 1, 0 );
	bool waituntilready = state.GetValue < bool >( 2, 0 );
	FMOD_RESULT result = self->_event->release(freeeventdata, waituntilready);
	lua_pushnumber ( state, result );
	return 1;
}

int	MOAIFmodEvent::_set3DAttributes( lua_State* L )
{
	MOAI_LUA_SETUP ( MOAIFmodEvent, "UUUU" );

	if ( !self->_event ) {
		MOAILog ( state, MOAILogMessages::MOAI_BadCast_DS );
		return 0;
	}
	const FMOD_VECTOR* position = state.GetValue < const FMOD_VECTOR* >( 1, 0 );
	const FMOD_VECTOR* velocity = state.GetValue < const FMOD_VECTOR* >( 2, 0 );
	const FMOD_VECTOR* orientation = state.GetValue < const FMOD_VECTOR* >( 3, 0 );
	FMOD_RESULT result = self->_event->set3DAttributes(position, velocity, orientation);
	lua_pushnumber ( state, result );
	return 1;
}

int	MOAIFmodEvent::_set3DOcclusion( lua_State* L )
{
	MOAI_LUA_SETUP ( MOAIFmodEvent, "UNN" );

	if ( !self->_event ) {
		MOAILog ( state, MOAILogMessages::MOAI_BadCast_DS );
		return 0;
	}
	float directocclusion = state.GetValue < float >( 1, 0 );
	float reverbocclusion = state.GetValue < float >( 2, 0 );
	FMOD_RESULT result = self->_event->set3DOcclusion(directocclusion, reverbocclusion);
	lua_pushnumber ( state, result );
	return 1;
}

int	MOAIFmodEvent::_setCallback( lua_State* L )
{
	MOAI_LUA_SETUP ( MOAIFmodEvent, "UUU" );

	if ( !self->_event ) {
		MOAILog ( state, MOAILogMessages::MOAI_BadCast_DS );
		return 0;
	}
	FMOD_EVENT_CALLBACK callback = state.GetValue < FMOD_EVENT_CALLBACK >( 1, 0 );
	void* userdata = state.GetValue < void* >( 2, 0 );
	FMOD_RESULT result = self->_event->setCallback(callback, userdata);
	lua_pushnumber ( state, result );
	return 1;
}

int	MOAIFmodEvent::_setMute( lua_State* L )
{
	MOAI_LUA_SETUP ( MOAIFmodEvent, "UN" );

	if ( !self->_event ) {
		MOAILog ( state, MOAILogMessages::MOAI_BadCast_DS );
		return 0;
	}
	bool mute = state.GetValue < bool >( 1, 0 );
	FMOD_RESULT result = self->_event->setMute(mute);
	lua_pushnumber ( state, result );
	return 1;
}

int	MOAIFmodEvent::_setPaused( lua_State* L )
{
	MOAI_LUA_SETUP ( MOAIFmodEvent, "UN" );

	if ( !self->_event ) {
		MOAILog ( state, MOAILogMessages::MOAI_BadCast_DS );
		return 0;
	}
	bool paused = state.GetValue < bool >( 1, 0 );
	FMOD_RESULT result = self->_event->setPaused(paused);
	lua_pushnumber ( state, result );
	return 1;
}

int	MOAIFmodEvent::_setPitch( lua_State* L )
{
	MOAI_LUA_SETUP ( MOAIFmodEvent, "UNU" );

	if ( !self->_event ) {
		MOAILog ( state, MOAILogMessages::MOAI_BadCast_DS );
		return 0;
	}
	float pitch = state.GetValue < float >( 1, 0 );
	FMOD_EVENT_PITCHUNITS units = (FMOD_EVENT_PITCHUNITS) state.GetValue < int >( 2, 0 );
	FMOD_RESULT result = self->_event->setPitch( pitch, units);
	lua_pushnumber ( state, result );
	return 1;
}

int	MOAIFmodEvent::_setProperty( lua_State* L )
{
	MOAI_LUA_SETUP ( MOAIFmodEvent, "UUUN" );

	if ( !self->_event ) {
		MOAILog ( state, MOAILogMessages::MOAI_BadCast_DS );
		return 0;
	}
	const char* propertyname = state.GetValue < const char* >( 1, 0 );
	void* value = state.GetValue < void* >( 2, 0 );
	bool this_instance = state.GetValue < bool >( 3, 0 );
	FMOD_RESULT result = self->_event->setProperty(propertyname, value, this_instance);
	lua_pushnumber ( state, result );
	return 1;
}

int	MOAIFmodEvent::_setPropertyByIndex( lua_State* L )
{
	MOAI_LUA_SETUP ( MOAIFmodEvent, "UNUN" );

	if ( !self->_event ) {
		MOAILog ( state, MOAILogMessages::MOAI_BadCast_DS );
		return 0;
	}
	int propertyindex = state.GetValue < int >( 1, 0 );
	void* value = state.GetValue < void* >( 2, 0 );
	bool this_instance = state.GetValue < bool >( 3, 0 );
	FMOD_RESULT result = self->_event->setPropertyByIndex( propertyindex, value, this_instance);
	lua_pushnumber ( state, result );
	return 1;
}

int	MOAIFmodEvent::_setReverbProperties( lua_State* L )
{
	MOAI_LUA_SETUP ( MOAIFmodEvent, "UU" );

	if ( !self->_event ) {
		MOAILog ( state, MOAILogMessages::MOAI_BadCast_DS );
		return 0;
	}
	const FMOD_REVERB_CHANNELPROPERTIES * props = state.GetValue < const FMOD_REVERB_CHANNELPROPERTIES * >( 1, 0 );
	FMOD_RESULT result = self->_event->setReverbProperties(props);
	lua_pushnumber ( state, result );
	return 1;
}

int	MOAIFmodEvent::_setUserData( lua_State* L )
{
	MOAI_LUA_SETUP ( MOAIFmodEvent, "UU" );

	if ( !self->_event ) {
		MOAILog ( state, MOAILogMessages::MOAI_BadCast_DS );
		return 0;
	}
	void* userdata = state.GetValue < void * >( 1, 0 );
	FMOD_RESULT result = self->_event->setUserData(userdata);
	lua_pushnumber ( state, result );
	return 1;

}

int	MOAIFmodEvent::_setVolume( lua_State* L )
{
	MOAI_LUA_SETUP ( MOAIFmodEvent, "UN" );

	if ( !self->_event ) {
		MOAILog ( state, MOAILogMessages::MOAI_BadCast_DS );
		return 0;
	}
	float volume = state.GetValue < float >( 1, 0 );
	FMOD_RESULT result = self->_event->setVolume( volume);
	lua_pushnumber ( state, result );
	return 1;

}

int	MOAIFmodEvent::_start( lua_State* L )
{
	MOAI_LUA_SETUP ( MOAIFmodEvent, "U" );

	if ( !self->_event ) {
		MOAILog ( state, MOAILogMessages::MOAI_BadCast_DS );
		return 0;
	}
	FMOD_RESULT result = self->_event->start();
	lua_pushnumber ( state, result );
	return 1;

}

int	MOAIFmodEvent::_stop( lua_State* L )
{
	MOAI_LUA_SETUP ( MOAIFmodEvent, "UN" );

	if ( !self->_event ) {
		MOAILog ( state, MOAILogMessages::MOAI_BadCast_DS );
		return 0;
	}
	bool immediate = state.GetValue < bool >( 1, 0 );
	FMOD_RESULT result = self->_event->stop( immediate);
	lua_pushnumber ( state, result );
	return 1;
}