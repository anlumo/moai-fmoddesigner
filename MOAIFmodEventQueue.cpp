#include "pch.h"
#include <moaicore/MOAIFmodEventQueue.hpp>
#include "fmod_event.hpp"
#include "MOAIFmodEventQueueEntry.h"


//----------------------------------------------------------------//
/**	@name	classHello
@text	Class (a.k.a. static) method. Prints the string 'MOAIFoo class foo!' to the console.

@out	nil
*/

int MOAIFmodEventQueue::_classFmodEventQueue ( lua_State* L ) {
	UNUSED ( L );
	printf ( "MOAIFmodEventQueue class foo!\n" );

	return 0;
}

//----------------------------------------------------------------//
/**	@name	instanceHello
@text	Prints the string 'MOAIFoo instance foo!' to the console.

@out	nil
*/
int MOAIFmodEventQueue::_instanceFmodEventQueue ( lua_State* L ) {
	MOAI_LUA_SETUP ( MOAIFmodEventQueue, "U" ) // this macro initializes the 'self' variable and type checks arguments

		printf ( "MOAIFmodEventQueue instance foo!\n" );

	return 0;
}

//================================================================//
// MOAIFoo
//================================================================//

//----------------------------------------------------------------//
MOAIFmodEventQueue::MOAIFmodEventQueue () {

	// register all classes MOAIFoo derives from
	// we need this for custom RTTI implementation
	RTTI_BEGIN
		RTTI_EXTEND ( MOAILuaObject )

		// and any other objects from multiple inheritance...
		// RTTI_EXTEND ( MOAIFooBase )
		RTTI_END
	//REGISTER_LUA_CLASS ( MOAIFmodEventQueue );
}

//----------------------------------------------------------------//
MOAIFmodEventQueue::~MOAIFmodEventQueue () {
}

//----------------------------------------------------------------//
void MOAIFmodEventQueue::RegisterLuaClass ( MOAILuaState& state ) {

	// call any initializers for base classes here:
	// MOAIFooBase::RegisterLuaClass ( state );

	// also register constants:
	// state.SetField ( -1, "FOO_CONST", ( u32 )FOO_CONST );

	// here are the class methods:
	luaL_Reg regTable [] = {
		{ "classFmodEventQueue",		_classFmodEventQueue },
		{ NULL, NULL }
	};

	luaL_register ( state, 0, regTable );
}

//----------------------------------------------------------------//
void MOAIFmodEventQueue::RegisterLuaFuncs ( MOAILuaState& state ) {

	// call any initializers for base classes here:
	// MOAIFooBase::RegisterLuaFuncs ( state );

	// here are the instance methods:
	luaL_Reg regTable [] = {
		{ "instanceFmodEventQueue",	_instanceFmodEventQueue },
		{ "add",	add },
		{ "clear",	clear },
		{ "dump",	dump },
		{ "excludeDuckingCategory",	excludeDuckingCategory },
		{ "findFirstEntry",	findFirstEntry },
		{ "findNextEntry",	findNextEntry },
		{ "getMemoryInfo",	getMemoryInfo },
		{ "getPaused",	getPaused },
		{ "getUserData",	getUserData },
		{ "includeDuckingCategory",	includeDuckingCategory },
		{ "release",	release },
		{ "remove",	remove },
		{ "removeHead",	removeHead },
		{ "setCallback",	setCallback },
		{ "setPaused",	setPaused },
		{ "setUserData",	setUserData },
		{ NULL, NULL }
	};

	luaL_register ( state, 0, regTable );
}

int	MOAIFmodEventQueue::add( lua_State* L )
{
	MOAI_LUA_SETUP ( MOAIFmodEventQueue, "U" );
	MOAIFmodEventQueueEntry* entry = state.GetValue <MOAIFmodEventQueueEntry*>(1, 0);
	bool allow = state.GetValue <bool>(2, 0);

	return self->GetEventQueue().add(entry->GetEventQueueEntry(), allow);
}

int	MOAIFmodEventQueue::clear( lua_State* L )
{
	MOAI_LUA_SETUP ( MOAIFmodEventQueue, "U" );

	bool stop = state.GetValue <bool>(1, 0);

	return self->GetEventQueue().clear(stop);
}

int	MOAIFmodEventQueue::dump( lua_State* L )
{
	MOAI_LUA_SETUP ( MOAIFmodEventQueue, "U" );

	return self->GetEventQueue().dump();
}

int	MOAIFmodEventQueue::excludeDuckingCategory( lua_State* L )
{
	MOAI_LUA_SETUP ( MOAIFmodEventQueue, "U" );
	
	FMOD::EventCategory* category = state.GetValue<FMOD::EventCategory*>(1, 0);

	return self->GetEventQueue().excludeDuckingCategory(category);
}

int	MOAIFmodEventQueue::findFirstEntry( lua_State* L )
{
	MOAI_LUA_SETUP ( MOAIFmodEventQueue, "U" );
	FMOD::EventQueueEntry** eventQueueEntry;

	int result = self->GetEventQueue().findFirstEntry(eventQueueEntry);
	
	MOAIFmodEventQueueEntry* moaiEventQueueEntry = new MOAIFmodEventQueueEntry( );
	moaiEventQueueEntry ->setEventQueueEntry ( *eventQueueEntry );
	self->LuaRetain ( moaiEventQueueEntry );
	
	return result;
}

int	MOAIFmodEventQueue::findNextEntry( lua_State* L )
{
	MOAI_LUA_SETUP ( MOAIFmodEventQueue, "U" );
		FMOD::EventQueueEntry** eventQueueEntry;

	int result = self->GetEventQueue().findNextEntry(eventQueueEntry);
	
	MOAIFmodEventQueueEntry* moaiEventQueueEntry = new MOAIFmodEventQueueEntry( );
	moaiEventQueueEntry ->setEventQueueEntry ( *eventQueueEntry );
	self->LuaRetain ( moaiEventQueueEntry );

	return result;
}

int	MOAIFmodEventQueue::getMemoryInfo( lua_State* L )
{
	MOAI_LUA_SETUP ( MOAIFmodEventQueue, "U" );

	unsigned int memorybits = state.GetValue <unsigned int>(1, 0);
	unsigned int event_memorybits = state.GetValue <unsigned int>(2, 0);
	unsigned int* memoryused = state.GetValue <unsigned int*>(3, 0);

	return self->GetEventQueue().getMemoryInfo(memorybits, event_memorybits, memoryused, 0);
}

int	MOAIFmodEventQueue::getPaused( lua_State* L )
{
	MOAI_LUA_SETUP ( MOAIFmodEventQueue, "U" );

	bool* paused = state.GetValue <bool*>(1, 0);

	return self->GetEventQueue().getPaused(paused);
}

int	MOAIFmodEventQueue::getUserData( lua_State* L )
{
	MOAI_LUA_SETUP ( MOAIFmodEventQueue, "U" );

	void** userdata = state.GetValue <void**>(1, 0);

	return self->GetEventQueue().getUserData(userdata);
}

int	MOAIFmodEventQueue::includeDuckingCategory( lua_State* L )
{
	MOAI_LUA_SETUP ( MOAIFmodEventQueue, "U" );

	FMOD::EventCategory* category = state.GetValue<FMOD::EventCategory*>(1, 0);
	float ducked = state.GetValue <float>(2, 0);
	float unducked = state.GetValue <float>(3, 0);
	unsigned int duck_time = state.GetValue <unsigned int>(4, 0);
	unsigned int unduck_time = state.GetValue <unsigned int>(5, 0);

	return self->GetEventQueue().includeDuckingCategory(category, ducked, unducked, duck_time, unduck_time);
}

int	MOAIFmodEventQueue::release( lua_State* L )
{
	MOAI_LUA_SETUP ( MOAIFmodEventQueue, "U" );

	return self->GetEventQueue().release();
}

int	MOAIFmodEventQueue::remove( lua_State* L )
{
	MOAI_LUA_SETUP ( MOAIFmodEventQueue, "U" );

	MOAIFmodEventQueueEntry* entry = state.GetValue <MOAIFmodEventQueueEntry*>(1, 0);

	return self->GetEventQueue().zl_remove(entry->GetEventQueueEntry());
}

int	MOAIFmodEventQueue::removeHead( lua_State* L )
{
	MOAI_LUA_SETUP ( MOAIFmodEventQueue, "U" );

	return self->GetEventQueue().removeHead();
}

int	MOAIFmodEventQueue::setCallback( lua_State* L )
{
	MOAI_LUA_SETUP ( MOAIFmodEventQueue, "U" );

	void* callbackuserdata = state.GetValue <void*>(1, 0);

	return self->GetEventQueue().setCallback(0, callbackuserdata);
}

int	MOAIFmodEventQueue::setPaused( lua_State* L )
{
	MOAI_LUA_SETUP ( MOAIFmodEventQueue, "U" );

	bool paused = state.GetValue <bool>(1, 0);

	return self->GetEventQueue().setPaused(paused);
}

int	MOAIFmodEventQueue::setUserData( lua_State* L )
{
	MOAI_LUA_SETUP ( MOAIFmodEventQueue, "U" );

	void* userdata = state.GetValue <void*>(1, 0);

	return self->GetEventQueue().setUserData(userdata);
}

FMOD::EventQueue MOAIFmodEventQueue::GetEventQueue() {

	return m_EventQueue;
}