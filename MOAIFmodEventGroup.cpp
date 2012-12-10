
#include "pch.h"
#include <moaicore/MOAIFmodEventGroup.h>

#include <fmod_event.hpp>

//----------------------------------------------------------------//
/**	@name	classHello
	@text	Class (a.k.a. static) method. Prints the string 'MOAIFoo class foo!' to the console.

	@out	nil
*/
int MOAIFmodEventGroup::_classHello ( lua_State* L ) {
	UNUSED ( L );
	
	printf ( "MOAIFmodEventGroup class foo!\n" );
	
	return 0;
}

//----------------------------------------------------------------//
/**	@name	instanceHello
	@text	Prints the string 'MOAIFoo instance foo!' to the console.

	@out	nil
*/
int MOAIFmodEventGroup::_instanceHello ( lua_State* L ) {
	MOAI_LUA_SETUP ( MOAIFmodEventGroup, "U" ) // this macro initializes the 'self' variable and type checks arguments

	printf ( "MOAIFmodEventGroup instance foo!\n" );
	
	return 0;
}


MOAIFmodEventGroup::MOAIFmodEventGroup () {
	
	// register all classes MOAIFoo derives from
	// we need this for custom RTTI implementation
	RTTI_BEGIN
		RTTI_EXTEND ( MOAILuaObject )
		
		// and any other objects from multiple inheritance...
		// RTTI_EXTEND ( MOAIFooBase )
	RTTI_END
}

//----------------------------------------------------------------//
MOAIFmodEventGroup::~MOAIFmodEventGroup () {
}


int	MOAIFmodEventGroup::_freeEventData ( lua_State* L ) {
	MOAI_LUA_SETUP (MOAIFmodEventGroup, "UUB")

	FMOD::Event* in_event	= state.GetValue<FMOD::Event*>(2, NULL);
	bool in_waituntilready	= state.GetValue<bool>(3, true);
		

	return self->eventGroup->freeEventData(in_event, in_waituntilready);
}

int	MOAIFmodEventGroup::_getEvent ( lua_State* L ) {
	MOAI_LUA_SETUP (MOAIFmodEventGroup, "USUU")

	const char* in_name		= state.GetValue<const char*>(2, NULL);
	FMOD_EVENT_MODE in_mode	= state.GetValue<FMOD_EVENT_MODE>(3, 0U);
	FMOD::Event** in_event	= state.GetValue<FMOD::Event**>(4, NULL);

	return self->eventGroup->getEvent(in_name, in_mode, in_event);
}

int	MOAIFmodEventGroup::_getEventByIndex ( lua_State* L ) {
	MOAI_LUA_SETUP (MOAIFmodEventGroup, "UNUU")

	int in_index			= state.GetValue<int>(2, 0);
	FMOD_EVENT_MODE in_mode	= state.GetValue<FMOD_EVENT_MODE>(3, 0U);
	FMOD::Event** in_event	= state.GetValue<FMOD::Event**>(4, NULL);

	return self->eventGroup->getEventByIndex(in_index, in_mode, in_event);
}

int	MOAIFmodEventGroup::_getGroup ( lua_State* L ) {
	MOAI_LUA_SETUP (MOAIFmodEventGroup, "USBU")

	const char* in_name			= state.GetValue<const char*>(2, NULL);
	bool in_cacheevents			= state.GetValue<bool>(3, false);
	FMOD::EventGroup** in_group	= state.GetValue<FMOD::EventGroup**>(4, NULL);

	return self->eventGroup->getGroup(in_name, in_cacheevents, in_group);
}

int	MOAIFmodEventGroup::_getGroupByIndex ( lua_State* L ) {
	MOAI_LUA_SETUP (MOAIFmodEventGroup, "UNBU")

	int in_index				= state.GetValue<int>(2, 0);
	bool in_cacheevents			= state.GetValue<bool>(3, false);
	FMOD::EventGroup** in_group	= state.GetValue<FMOD::EventGroup**>(4, NULL);

	return self->eventGroup->getGroupByIndex(in_index, in_cacheevents, in_group);
}

int	MOAIFmodEventGroup::_getInfo ( lua_State* L ) {
	MOAI_LUA_SETUP (MOAIFmodEventGroup, "UUU")

	int* in_index	= state.GetValue<int*>(2, NULL);
	char** in_name	= state.GetValue<char**>(3, NULL);
	
	return self->eventGroup->getInfo(in_index, in_name);
}

int	MOAIFmodEventGroup::_getMemoryInfo ( lua_State* L ) {
	MOAI_LUA_SETUP (MOAIFmodEventGroup, "UNNUU")

	unsigned int in_memorybits							= state.GetValue<unsigned int>(2, 0U);
	unsigned int in_event_memorybits					= state.GetValue<unsigned int>(3, 0U);
	unsigned int* in_memoryused							= state.GetValue<unsigned int*>(4, NULL);
	FMOD_MEMORY_USAGE_DETAILS* in_memoryused_details	= state.GetValue<FMOD_MEMORY_USAGE_DETAILS*>(5, NULL);
	
	return self->eventGroup->getMemoryInfo(in_memorybits, in_event_memorybits, in_memoryused, in_memoryused_details);
}

int	MOAIFmodEventGroup::_getNumEvents ( lua_State* L ) {
	MOAI_LUA_SETUP (MOAIFmodEventGroup, "UU")

	int* in_numevents	= state.GetValue<int*>(2, NULL);
	
	return self->eventGroup->getNumEvents(in_numevents);
}

int	MOAIFmodEventGroup::_getNumGroups ( lua_State* L ) {
	MOAI_LUA_SETUP (MOAIFmodEventGroup, "UU")

	int* in_numgroups	= state.GetValue<int*>(2, NULL);
	
	return self->eventGroup->getNumGroups(in_numgroups);
}

int	MOAIFmodEventGroup::_getNumProperties ( lua_State* L ) {
	MOAI_LUA_SETUP (MOAIFmodEventGroup, "UU")

	int* in_numproperties	= state.GetValue<int*>(2, NULL);
	
	return self->eventGroup->getNumProperties(in_numproperties);
}

int	MOAIFmodEventGroup::_getParentGroup ( lua_State* L ) {
	MOAI_LUA_SETUP (MOAIFmodEventGroup, "UU")

	FMOD::EventGroup** in_group	= state.GetValue<FMOD::EventGroup**>(2, NULL);
	
	return self->eventGroup->getParentGroup(in_group);
}

int	MOAIFmodEventGroup::_getParentProject ( lua_State* L ) {
	MOAI_LUA_SETUP (MOAIFmodEventGroup, "UU")

	FMOD::EventProject** in_project	= state.GetValue<FMOD::EventProject**>(2, NULL);
	
	return self->eventGroup->getParentProject(in_project);
}

int	MOAIFmodEventGroup::_getProperty ( lua_State* L ) {
	MOAI_LUA_SETUP (MOAIFmodEventGroup, "USU")

	const char* in_propertyname	= state.GetValue<const char*>(2, NULL);
	void* in_value				= state.GetValue<void*>(3, NULL);
	
	return self->eventGroup->getProperty(in_propertyname, in_value);
}

int	MOAIFmodEventGroup::_getPropertyByIndex ( lua_State* L ) {
	MOAI_LUA_SETUP (MOAIFmodEventGroup, "UNU")

	int in_propertyindex	= state.GetValue<int>(2, 0);
	void* in_value			= state.GetValue<void*>(3, NULL);
	
	return self->eventGroup->getPropertyByIndex(in_propertyindex, in_value);
}

int	MOAIFmodEventGroup::_getState ( lua_State* L ) {
	MOAI_LUA_SETUP (MOAIFmodEventGroup, "UU")

	FMOD_EVENT_STATE* in_state	= state.GetValue<FMOD_EVENT_STATE*>(2, NULL);
	
	return self->eventGroup->getState(in_state);
}

int	MOAIFmodEventGroup::_getUserData ( lua_State* L ) {
	MOAI_LUA_SETUP (MOAIFmodEventGroup, "UU")

	void** in_userdata	= state.GetValue<void**>(2, NULL);
	
	return self->eventGroup->getUserData(in_userdata);
}

int	MOAIFmodEventGroup::_loadEventData ( lua_State* L ) {
	MOAI_LUA_SETUP (MOAIFmodEventGroup, "UUU")

	FMOD_EVENT_RESOURCE in_resource;
	in_resource	= static_cast<FMOD_EVENT_RESOURCE>(state.GetValue<int>(2, 0));
	FMOD_EVENT_MODE in_mode = state.GetValue<FMOD_EVENT_MODE>(3, 0U);
	
	return self->eventGroup->loadEventData(in_resource, in_mode);
}

int	MOAIFmodEventGroup::_setUserData ( lua_State* L ) {
	MOAI_LUA_SETUP (MOAIFmodEventGroup, "UU")

	void* in_userdata	= state.GetValue<void*>(2, NULL);
	
	return self->eventGroup->setUserData(in_userdata);
}




//----------------------------------------------------------------//
void MOAIFmodEventGroup::RegisterLuaClass ( MOAILuaState& state ) {

	// call any initializers for base classes here:
	// MOAIFooBase::RegisterLuaClass ( state );

	// also register constants:
	// state.SetField ( -1, "FOO_CONST", ( u32 )FOO_CONST );

	// here are the class methods:
	luaL_Reg regTable [] = {
		{ "classHello",		_classHello },
		{ NULL, NULL }
	};

	luaL_register ( state, 0, regTable );
}

//----------------------------------------------------------------//
void MOAIFmodEventGroup::RegisterLuaFuncs ( MOAILuaState& state ) {

	// call any initializers for base classes here:
	// MOAIFooBase::RegisterLuaFuncs ( state );

	// here are the instance methods:
	luaL_Reg regTable [] = {
		{ "instanceHello",	_instanceHello },
		{ "freeEventData",	_freeEventData },
		{ "getEvent",	_getEvent },
		{ "getEventByIndex",	_getEventByIndex },
		{ "getGroup",	_getGroup },
		{ "getGroupByIndex",	_getGroupByIndex },
		{ "getInfo",	_getInfo },
		{ "getMemoryInfo",	_getMemoryInfo },
		{ "getNumEvents",	_getNumEvents },
		{ "getNumGroups",	_getNumGroups },
		{ "getNumProperties",	_getNumProperties },
		{ "getParentGroup",	_getParentGroup },
		{ "getParentProject",	_getParentProject },
		{ "getProperty",	_getProperty },
		{ "getPropertyByIndex",	_getPropertyByIndex },
		{ "getState",	_getState },
		{ "getUserData",	_getUserData },
		{ "loadEventData",	_loadEventData },
		{ "setUserData",	_setUserData },
		{ NULL, NULL }
	};

	luaL_register ( state, 0, regTable );
}