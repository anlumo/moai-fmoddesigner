
#include "pch.h"
#include <moaicore/MOAIFmodEventGroup.h>
#include <moaicore/MOAIFmodEventProject.h>
#include <moaicore/MOAIFmodEvent.h>

#include <fmod_event.hpp>


MOAIFmodEventGroup::MOAIFmodEventGroup () {
	
	// register all classes MOAIFoo derives from
	// we need this for custom RTTI implementation
	RTTI_BEGIN
		RTTI_EXTEND ( MOAILuaObject )
		
		// and any other objects from multiple inheritance...
		// RTTI_EXTEND ( MOAIFooBase )
	RTTI_END

	eventGroup = new FMOD::EventGroup();
}

MOAIFmodEventGroup::MOAIFmodEventGroup (FMOD::EventGroup* eventGroup) {
	
	// register all classes MOAIFoo derives from
	// we need this for custom RTTI implementation
	RTTI_BEGIN
		RTTI_EXTEND ( MOAILuaObject )
		
		// and any other objects from multiple inheritance...
		// RTTI_EXTEND ( MOAIFooBase )
	RTTI_END

	this->eventGroup = new FMOD::EventGroup(eventGroup);
}

//----------------------------------------------------------------//
MOAIFmodEventGroup::~MOAIFmodEventGroup () {
	delete this->eventGroup;
}


int	MOAIFmodEventGroup::_freeEventData ( lua_State* L ) {
	MOAI_LUA_SETUP (MOAIFmodEventGroup, "UUB")

	FMOD::Event* in_event	= state.GetValue<FMOD::Event*>(2, NULL);
	bool in_waituntilready	= state.GetValue<bool>(3, true);

	FMOD_RESULT result = self->eventGroup->freeEventData(in_event, in_waituntilready);
	return result;
}

int	MOAIFmodEventGroup::_getEvent ( lua_State* L ) {
	MOAI_LUA_SETUP (MOAIFmodEventGroup, "USN")

	const char* in_name		= state.GetValue<const char*>(2, NULL);
	FMOD_EVENT_MODE in_mode	= state.GetValue<FMOD_EVENT_MODE>(3, 0U);
	FMOD::Event** out_event;

	FMOD_RESULT result = self->eventGroup->getEvent(in_name, in_mode, out_event);
	MOAIFmodEvent* fmodEvent = new MOAIFmodEvent(*out_event);
	fmodEvent->BindToLua(state);
	state.Push(fmodEvent);

	return result;
}

int	MOAIFmodEventGroup::_getEventByIndex ( lua_State* L ) {
	MOAI_LUA_SETUP (MOAIFmodEventGroup, "UNU")

	int in_index			= state.GetValue<int>(2, 0);
	FMOD_EVENT_MODE in_mode	= state.GetValue<FMOD_EVENT_MODE>(3, 0U);
	FMOD::Event** out_event;

	FMOD_RESULT result = self->eventGroup->getEventByIndex(in_index, in_mode, out_event);
	MOAIFmodEvent* fmodEvent = new MOAIFmodEvent(*out_event);
	fmodEvent->BindToLua(state);
	state.Push(fmodEvent);

	return result;
}

int	MOAIFmodEventGroup::_getGroup ( lua_State* L ) {
	MOAI_LUA_SETUP (MOAIFmodEventGroup, "USB")

	const char* in_name	= state.GetValue<const char*>(2, NULL);
	bool in_cacheevents	= state.GetValue<bool>(3, false);
	FMOD::EventGroup** out_group;

	FMOD_RESULT result = self->eventGroup->getGroup(in_name, in_cacheevents, out_group);
	MOAIFmodEventGroup* fmodEventGroup = new MOAIFmodEventGroup(*out_group);
	fmodEventGroup->BindToLua(state);
	state.Push(fmodEventGroup);

	return result;
}

int	MOAIFmodEventGroup::_getGroupByIndex ( lua_State* L ) {
	MOAI_LUA_SETUP (MOAIFmodEventGroup, "UNBU")

	int in_index		= state.GetValue<int>(2, 0);
	bool in_cacheevents	= state.GetValue<bool>(3, false);
	FMOD::EventGroup** out_group;
	
	FMOD_RESULT result = self->eventGroup->getGroupByIndex(in_index, in_cacheevents, out_group);
	MOAIFmodEventGroup* fmodEventGroup = new MOAIFmodEventGroup(*out_group);
	fmodEventGroup->BindToLua(state);
	state.Push(fmodEventGroup);

	return result;
}

int	MOAIFmodEventGroup::_getInfo ( lua_State* L ) {
	MOAI_LUA_SETUP (MOAIFmodEventGroup, "U")

	int* out_index;
	char** out_name;
	
	FMOD_RESULT result = self->eventGroup->getInfo(out_index, out_name);
	state.Push(out_name);
	state.Push(out_index);

	return result;
}

int	MOAIFmodEventGroup::_getMemoryInfo ( lua_State* L ) {
	MOAI_LUA_SETUP (MOAIFmodEventGroup, "UNN")

	unsigned int in_memorybits			= state.GetValue<unsigned int>(2, 0U);
	unsigned int in_event_memorybits	= state.GetValue<unsigned int>(3, 0U);
	unsigned int* out_memoryused;
	FMOD_MEMORY_USAGE_DETAILS* out_memoryused_details;
	
	FMOD_RESULT result = self->eventGroup->getMemoryInfo(in_memorybits, in_event_memorybits, out_memoryused, out_memoryused_details);
	state.Push(out_memoryused_details);
	state.Push(out_memoryused);

	return result;
}

int	MOAIFmodEventGroup::_getNumEvents ( lua_State* L ) {
	MOAI_LUA_SETUP (MOAIFmodEventGroup, "U")

	int* out_numevents;
	
	FMOD_RESULT result = self->eventGroup->getNumEvents(out_numevents);
	state.Push(out_numevents);

	return result;
}

int	MOAIFmodEventGroup::_getNumGroups ( lua_State* L ) {
	MOAI_LUA_SETUP (MOAIFmodEventGroup, "UU")

	int* out_numgroups;
	
	FMOD_RESULT result = self->eventGroup->getNumGroups(out_numgroups);
	state.Push(out_numgroups);

	return result;
}

int	MOAIFmodEventGroup::_getNumProperties ( lua_State* L ) {
	MOAI_LUA_SETUP (MOAIFmodEventGroup, "U")

	int* out_numproperties;
	
	FMOD_RESULT result = self->eventGroup->getNumProperties(out_numproperties);
	state.Push(out_numproperties);

	return result;
}

int	MOAIFmodEventGroup::_getParentGroup ( lua_State* L ) {
	MOAI_LUA_SETUP (MOAIFmodEventGroup, "U")

	FMOD::EventGroup** out_group;
	
	FMOD_RESULT result = self->eventGroup->getParentGroup(out_group);
	MOAIFmodEventGroup* fmodEventGroup = new MOAIFmodEventGroup(*out_group);
	fmodEventGroup->BindToLua(state);
	state.Push(fmodEventGroup);
	
	return result;
}

int	MOAIFmodEventGroup::_getParentProject ( lua_State* L ) {
	MOAI_LUA_SETUP (MOAIFmodEventGroup, "U")

	FMOD::EventProject** out_project;

	FMOD_RESULT result = self->eventGroup->getParentProject(out_project);
	MOAIFmodEventProject* fmodEventProject = new MOAIFmodEventProject(*out_project);
	fmodEventProject->BindToLua(state);
	state.Push(fmodEventProject);
	
	return result;
}

int	MOAIFmodEventGroup::_getProperty ( lua_State* L ) {
	MOAI_LUA_SETUP (MOAIFmodEventGroup, "US")

	const char* out_propertyname	= state.GetValue<const char*>(2, NULL);
	void* out_value;
	
	FMOD_RESULT result = self->eventGroup->getProperty(out_propertyname, out_value);
	state.Push(out_value);
	state.Push(out_propertyname);

	return result;
}

int	MOAIFmodEventGroup::_getPropertyByIndex ( lua_State* L ) {
	MOAI_LUA_SETUP (MOAIFmodEventGroup, "UN")

	int out_propertyindex	= state.GetValue<int>(2, 0);
	void* out_value;
	
	FMOD_RESULT result = self->eventGroup->getPropertyByIndex(out_propertyindex, out_value);
	state.Push(out_value);
	state.Push(out_propertyindex);

	return result;
}

int	MOAIFmodEventGroup::_getState ( lua_State* L ) {
	MOAI_LUA_SETUP (MOAIFmodEventGroup, "U")

	FMOD_EVENT_STATE* out_state;
	
	FMOD_RESULT result = self->eventGroup->getState(out_state);
	state.Push(out_state);

	return result;
}

int	MOAIFmodEventGroup::_getUserData ( lua_State* L ) {
	MOAI_LUA_SETUP (MOAIFmodEventGroup, "U")

	void** out_userdata;
	
	FMOD_RESULT result = self->eventGroup->getUserData(out_userdata);
	state.Push(out_userdata);

	return result;
}

int	MOAIFmodEventGroup::_loadEventData ( lua_State* L ) {
	MOAI_LUA_SETUP (MOAIFmodEventGroup, "UNN")

	FMOD_EVENT_RESOURCE in_resource = static_cast<FMOD_EVENT_RESOURCE>(state.GetValue<int>(2, 0));
	FMOD_EVENT_MODE in_mode			= state.GetValue<FMOD_EVENT_MODE>(3, FMOD_EVENT_DEFAULT);
	
	FMOD_RESULT result = self->eventGroup->loadEventData(in_resource, in_mode);
	return result;
}

int	MOAIFmodEventGroup::_setUserData ( lua_State* L ) {
	MOAI_LUA_SETUP (MOAIFmodEventGroup, "UU")

	void* in_userdata = state.GetValue<void*>(2, NULL);
	
	FMOD_RESULT result = self->eventGroup->setUserData(in_userdata);
	return result;
}




//----------------------------------------------------------------//
void MOAIFmodEventGroup::RegisterLuaClass ( MOAILuaState& state ) {

	// call any initializers for base classes here:
	// MOAIFooBase::RegisterLuaClass ( state );

	// also register constants:
	// state.SetField ( -1, "FOO_CONST", ( u32 )FOO_CONST );

	// here are the class methods:
	luaL_Reg regTable [] = {
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