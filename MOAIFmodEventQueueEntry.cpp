// Copyright (c) 2010-2011 Zipline Games, Inc. All Rights Reserved.
// http://getmoai.com
// Version 1.0
// Changes:
//     - fixed project headers to accompany common project structure
//     - initializing and freeing of EventQueueEntry
//     - added copy constructor
//     - added getter and setter for userData
//     - added getter for memory info

#include "pch.h"
#include <moaicore/MOAIFmodEventQueueEntry.h>

#include <fmod_event.hpp>
#include <moaicore/MOAIFmodEvent.h>

//================================================================//
// MOAIFmodEventQueueEntry
//================================================================//
FMOD::EventQueueEntry* 		MOAIFmodEventQueueEntry::mEventQueueEntry;

//----------------------------------------------------------------//
MOAIFmodEventQueueEntry::MOAIFmodEventQueueEntry () {

	// register all classes MOAIFmodEventQueueEntry derives from
	// we need this for custom RTTI implementation
	RTTI_BEGIN
		RTTI_EXTEND ( MOAILuaObject )

		// and any other objects from multiple inheritance...
		// RTTI_EXTEND ( MOAIFmodEventQueueEntryBase )
	RTTI_END
    
    mEventQueueEntry = new FMOD::EventQueueEntry();
}

MOAIFmodEventQueueEntry::MOAIFmodEventQueueEntry (FMOD::EventQueueEntry* eventQueueEntry) {
    
	// register all classes MOAIFmodEventQueueEntry derives from
	// we need this for custom RTTI implementation
	RTTI_BEGIN
    RTTI_EXTEND ( MOAILuaObject )
    
    // and any other objects from multiple inheritance...
    // RTTI_EXTEND ( MOAIFmodEventQueueEntryBase )
	RTTI_END
    
    mEventQueueEntry = new FMOD::EventQueueEntry(eventQueueEntry);
}

//----------------------------------------------------------------//
MOAIFmodEventQueueEntry::~MOAIFmodEventQueueEntry () {
    delete mEventQueueEntry;
}

//----------------------------------------------------------------//
void MOAIFmodEventQueueEntry::RegisterLuaClass ( MOAILuaState& state ) {

	// call any initializers for base classes here:
	// MOAIFmodEventQueueEntryBase::RegisterLuaClass ( state );

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
void MOAIFmodEventQueueEntry::RegisterLuaFuncs ( MOAILuaState& state ) {

	// call any initializers for base classes here:
	// MOAIFmodEventQueueEntryBase::RegisterLuaFuncs ( state );

	// here are the instance methods:
	luaL_Reg regTable [] = {
		{ "instanceHello",		_instanceHello },
		{ "getCrossfadeTime",	_getCrossfadeTime },
		{ "getDelayTime",		_getDelayTime },
		{ "getExpiryTime",		_getExpiryTime },
		//{ "getInfoOnlyEvent",	_getInfoOnlyEvent },
		{ "getInterrupt",		_getInterrupt },
		{ "getMemoryInfo",		_getMemoryInfo },
		{ "getPriority",		_getPriority },
		{ "getRealEvent",		_getRealEvent },
		{ "getUserData",		_getUserData },
		{ "release",			_release },
		{ "setCrossfadeTime",	_setCrossfadeTime },
		{ "setDelayTime",		_setDelayTime },
		{ "setExpiryTime",		_setExpiryTime },
		{ "setInterrupt",		_setInterrupt },
		{ "setPriority",		_setPriority },
		{ "setUserData",		_setUserData },
		{ NULL, NULL }
	};

	luaL_register ( state, 0, regTable );
}

void MOAIFmodEventQueueEntry::setEventQueueEntry( FMOD::EventQueueEntry& eventQueueEntry ) {
	this->mEventQueueEntry = &eventQueueEntry;
	return;
}

/**	@name	getCrossfadeTime
	@text	Retrieve the crossfade time for this event queue entry.

	@out	nil
*/
int MOAIFmodEventQueueEntry::_getCrossfadeTime( lua_State* L ) {
// FMOD_RESULT EventQueueEntry::getCrossfadeTime( int* crossfade );
	MOAI_LUA_SETUP ( MOAIFmodEventQueueEntry, "U" );
	
	int crossfade;
	
	mEventQueueEntry->getCrossfadeTime( &crossfade );
	
	lua_pushnumber( L, crossfade );
	
	return 1;
}

/**	@name	getDelayTime
	@text	Retrieve the delay time for this event queue entry.

	@out	nil
*/
int MOAIFmodEventQueueEntry::_getDelayTime( lua_State* L ) {
// FMOD_RESULT EventQueueEntry::getDelayTime( unsigned int* delay );
	MOAI_LUA_SETUP ( MOAIFmodEventQueueEntry, "U" );
	
	unsigned int delay;
	
	mEventQueueEntry->getDelayTime( &delay );
	
	lua_pushnumber( L, delay );
	
	return 1;
}

/**	@name	getExpiryTime
	@text	Retrieve the expiry time for this event queue entry.

	@out	nil
*/
int MOAIFmodEventQueueEntry::_getExpiryTime( lua_State* L ) {
// FMOD_RESULT EventQueueEntry::getExpiryTime( unsigned int* expirytime );
	MOAI_LUA_SETUP ( MOAIFmodEventQueueEntry, "U" );
	
	unsigned int expirytime;
	
	mEventQueueEntry->getExpiryTime( &expirytime );
	
	lua_pushnumber( L, expirytime );
	return 1;
}

/**	@name	getInfoOnlyEvent
	@text	Retrieve a handle to the event that is associated with this event queue entry.

	@out	nil
*/
/*
//TODO: method not implemented completely
int MOAIFmodEventQueueEntry::_getInfoOnlyEvent( lua_State* L ) {
    FMOD_RESULT EventQueueEntry::getInfoOnlyEvent( Event** infoonlyevent );
	MOAI_LUA_SETUP ( MOAIFmodEventQueueEntry, "U" );
	
	Event* infoonlyevent;

	mEventQueueEntry->getInfoOnlyEvent( &infoonlyevent );
	
	lua_push"type"( L, "value" );
	
	return 1;
}
*/

/**	@name	getInterrupt
	@text	Retrieve the interrupt flag for this event queue entry.

	@out	nil
*/
int MOAIFmodEventQueueEntry::_getInterrupt( lua_State* L ) {
// FMOD_RESULT EventQueueEntry::getInterrupt( bool* interrupt );
	MOAI_LUA_SETUP ( MOAIFmodEventQueueEntry, "U" );
	
	bool interrupt;
	
	mEventQueueEntry->getInterrupt( &interrupt );
	
	lua_pushboolean( L, interrupt );
		
	return 1;
}

/**	@name	getMemoryInfo
	@text	Retrieve detailed memory usage information about this object.

	@out	nil
*/
int MOAIFmodEventQueueEntry::_getMemoryInfo( lua_State* L ) {
	MOAI_LUA_SETUP (MOAIFmodEventQueueEntry, "UNN")
    
    unsigned int in_memorybits	= state.GetValue<unsigned int>(2, 0U);
    unsigned int in_event_memorybits	= state.GetValue<unsigned int>(3, 0U);
    unsigned int* out_memoryused;
    FMOD_MEMORY_USAGE_DETAILS* out_memoryused_details;
    
    FMOD_RESULT result = mEventQueueEntry->getMemoryInfo(in_memorybits, in_event_memorybits, out_memoryused, out_memoryused_details);
    state.Push(out_memoryused_details);
    state.Push(out_memoryused);
    
    return result;
}


/**	@name	getPriority
	@text	Get the priority of this event queue entry.

	@out	nil
*/
int MOAIFmodEventQueueEntry::_getPriority( lua_State* L ) {
// FMOD_RESULT EventQueueEntry::getPriority( unsigned char* priority );
	MOAI_LUA_SETUP ( MOAIFmodEventQueueEntry, "U" );
	
	unsigned char priority;
	
	mEventQueueEntry->getPriority( &priority );
	
	lua_pushstring( L, "value" );
	
	return 1;
}

/**	@name	getRealEvent
	@text	Retrieve a handle to the playing event that is associated with this event queue entry.

	@out	nil
*/
int MOAIFmodEventQueueEntry::_getRealEvent( lua_State* L ) {
// FMOD_RESULT EventQueueEntry::getRealEvent( Event** realevent );
	MOAI_LUA_SETUP ( MOAIFmodEventQueueEntry, "U" );
	
	FMOD::Event* realevent;
	mEventQueueEntry->getRealEvent( &realevent );
	MOAIFmodEvent* event;
	
	
	lua_pushstring( L, "value" );
	
	return 1;
}

/**	@name	getUserData
	@text	Retrieves the user value that that was set by calling the MOAIFmodEventQueueEntry::setUserData function.

	@out	nil
*/

int	MOAIFmodEventQueueEntry::_getUserData ( lua_State* L ) {
    MOAI_LUA_SETUP (MOAIFmodEventQueueEntry, "U")
    
    void** out_userdata;
    
    FMOD_RESULT result = mEventQueueEntry->getUserData(out_userdata);
    state.Push(out_userdata);
    
    return result;
}

/**	@name	release
	@text	Release this event queue entry and all associated memory.

	@out	nil
*/
int MOAIFmodEventQueueEntry::_release( lua_State* L ) {
// FMOD_RESULT EventQueueEntry::release();
	MOAI_LUA_SETUP ( MOAIFmodEventQueueEntry, "U" );
	
	mEventQueueEntry->release();
	
	return 0;
}

/**	@name	setCrossfadeTime
	@text	Set a crossfade time for this event queue entry.

	@out	nil
*/
int MOAIFmodEventQueueEntry::_setCrossfadeTime( lua_State* L ) {
// FMOD_RESULT EventQueueEntry::setCrossfadeTime( int crossfade );
	MOAI_LUA_SETUP ( MOAIFmodEventQueueEntry, "U" );
	int crossfade = state.GetValue < int >( 1, 0 );

	mEventQueueEntry->setCrossfadeTime( crossfade );
	
	return 0;
}

/**	@name	setDelayTime
	@text	Set a delay time for this event queue entry.

	@out	nil
*/
int MOAIFmodEventQueueEntry::_setDelayTime( lua_State* L ) {
// FMOD_RESULT EventQueueEntry::setDelayTime( unsigned int delay );
	MOAI_LUA_SETUP ( MOAIFmodEventQueueEntry, "U" );
	unsigned int delay = state.GetValue < unsigned int >( 1, 0 );
	
	mEventQueueEntry->setDelayTime( delay );
	
	return 0;
}

/**	@name	setExpiryTime
	@text	Set an expiry time for this event queue entry.

	@out	nil
*/
int MOAIFmodEventQueueEntry::_setExpiryTime( lua_State* L ) {
// FMOD_RESULT EventQueueEntry::setExpiryTime( unsigned int expirytime );
	MOAI_LUA_SETUP ( MOAIFmodEventQueueEntry, "U" );
	unsigned int expirytime = state.GetValue < unsigned int >( 1, 0 );
	
	mEventQueueEntry->setExpiryTime( expirytime );
	
	return 0;
}

/**	@name	setInterrupt
	@text	Set the interrupt flag for this event queue entry.

	@out	nil
*/
int MOAIFmodEventQueueEntry::_setInterrupt( lua_State* L ) {
// FMOD_RESULT EventQueueEntry::setInterrupt( bool interrupt );
	MOAI_LUA_SETUP ( MOAIFmodEventQueueEntry, "U" );
	bool interrupt = state.GetValue < bool >( 1, 0 );
	
	mEventQueueEntry->setInterrupt( interrupt );
	
	return 0;
}

/**	@name	setPriority
	@text	Set the priority of this event queue entry.

	@out	nil
*/
int MOAIFmodEventQueueEntry::_setPriority( lua_State* L ) {
// FMOD_RESULT EventQueueEntry::setPriority( unsigned char priority );
	MOAI_LUA_SETUP ( MOAIFmodEventQueueEntry, "U" );
	unsigned char priority = state.GetValue < unsigned char >( 1, 0 );
	
	mEventQueueEntry->setPriority( priority );
	
	return 0;
}

/**	@name	setUserData
	@text	Sets a user value that the EventQueueEntry object will store internally. Can be retrieved with MOAIFmodEventQueueEntry::getUserData.

	@out	nil
*/
int	MOAIFmodEventQueueEntry::_setUserData ( lua_State* L ) {
    MOAI_LUA_SETUP (MOAIFmodEventQueueEntry, "UU")
    
    void* in_userdata = state.GetValue<void*>(2, NULL);
    
    FMOD_RESULT result = mEventQueueEntry->setUserData(in_userdata);
    return result;
}

