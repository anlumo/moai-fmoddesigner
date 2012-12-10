#ifndef MOAIFMODEVENTGROUP_H
#define MOAIFMODEVENTGROUP_H

#include <moaicore/MOAILUA.h>

namespace FMOD {
	class EventGroup;
};

//================================================================//
// MOAIFmodEventGroup
//================================================================//
/**	@name	MOAIFmodEventGroup
	@text	MOAIFmodEventGroup Class
*/
class MOAIFmodEventGroup :
	public virtual MOAILuaObject {
private:
	
	FMOD::EventGroup* eventGroup;

	//for testing
	static int		_classHello			( lua_State* L );
	static int		_instanceHello		( lua_State* L );

	/*
	FMOD_RESULT EventGroup::freeEventData(
	  Event *  event, 
	  bool  waituntilready
	);

	event
	Single event to free resources for. Specify 0 or NULL to ignore. Note: The specified event must exist in this EventGroup, not in a child of this EventGroup. 

	waituntilready
	If TRUE, this function will block until all pending asynchronous loads have completed before freeing the event data. If FALSE, this function will return FMOD_ERR_NOTREADY if any asynchronous loads are pending and it will NOT free any event data. Default = TRUE.
	*/
	static int		_freeEventData		( lua_State* L );

	/*
	FMOD_RESULT EventGroup::getEvent(
	  const char *  name, 
	  FMOD_EVENT_MODE  mode, 
	  Event **  event
	);

	name
	The name of an event within this event group. 

	mode
	If not already loaded with EventGroup::loadEventData, this FMOD_EVENT_MODE flag will determine if data should be loaded from disk synchronously or asynchronously. It also allows an 'info only' event retreival (events that cant be played) and can be used to produce an error on disk access. 

	event
	Address of a variable to receive the selected event within this event group.
	*/
	static int		_getEvent			( lua_State* L );

	/*
	FMOD_RESULT EventGroup::getEventByIndex(
	  int  index, 
	  FMOD_EVENT_MODE  mode, 
	  Event **  event
	);

	index
	The index of an event within this event sub-group. Indices are 0 based. 

	mode
	If not already loaded with EventGroup::loadEventData, this FMOD_EVENT_MODE flag will determine if data should be loaded from disk synchronously or asynchronously. It also allows an 'info only' event retreival (events that cant be played) and can be used to produce an error on disk access. 

	event
	Address of a variable to receive the selected event within this event group.
	*/
	static int		_getEventByIndex	( lua_State* L );

	/*
	FMOD_RESULT EventGroup::getGroup(
	  const char *  name, 
	  bool  cacheevents, 
	  EventGroup **  group
	);

	name
	The name of an event sub-group that belongs to this event group. 

	cacheevents
	If cacheevents is true then all event instances within this event group will be pre-allocated so that there are no memory allocs when getEvent is called. 

	group
	Address of a variable to receive the selected event sub-group within this event group.
	*/
	static int		_getGroup			( lua_State* L );

	/*
	FMOD_RESULT EventGroup::getGroupByIndex(
	  int  index, 
	  bool  cacheevents, 
	  EventGroup **  group
	);

	index
	The index of an event sub-group within this event group. Indices are 0 based. 

	cacheevents
	If cacheevents is true then all event instances within this event group will be pre-allocated so that there are no memory allocs when getEvent is called. 

	group
	Address of a variable to receive the selected event sub-group within this event group.
	*/
	static int		_getGroupByIndex	( lua_State* L );

	/*
	FMOD_RESULT EventGroup::getInfo(
	  int *  index, 
	  char **  name
	);

	index
	Address of a variable to receive the event group index. 

	name
	Address of a variable to receive the event group name.
	*/
	static int		_getInfo			( lua_State* L );

	/*
	FMOD_RESULT EventGroup::getMemoryInfo(
	  unsigned int  memorybits, 
	  unsigned int  event_memorybits, 
	  unsigned int *  memoryused, 
	  FMOD_MEMORY_USAGE_DETAILS *  memoryused_details
	);

	memorybits
	Memory usage bits for FMOD Ex. See FMOD_MEMBITS. 

	event_memorybits
	Memory usage bits for FMOD Event System. See FMOD_EVENT_MEMBITS. 

	memoryused
	Optional. Specify 0 to ignore. Address of a variable to receive how much memory is being used by this object given the specified "memorybits" and "event_memorybits". 

	memoryused_details
	Optional. Specify 0 to ignore. Address of a user-allocated FMOD_MEMORY_USAGE_DETAILS structure to be filled with detailed memory usage information about this object.
	*/
	static int		_getMemoryInfo		( lua_State* L );

	/*
	FMOD_RESULT EventGroup::getNumEvents(
	  int *  numevents
	);

	numevents
	Adress of a variable to receive the number of events within this event group.
	*/
	static int		_getNumEvents		( lua_State* L );

	/*
	FMOD_RESULT EventGroup::getNumGroups(
	  int *  numgroups
	);

	numgroups
	Adress of a variable to receive the number of groups within this event group.
	*/
	static int		_getNumGroups		( lua_State* L );

	/*
	FMOD_RESULT EventGroup::getNumProperties(
	  int *  numproperties
	);

	numproperties
	Address of a variable to receive the number of properties for this event group.
	*/
	static int		_getNumProperties	( lua_State* L );

	/*
	FMOD_RESULT EventGroup::getParentGroup(
	  EventGroup **  group
	);

	group
	Address of a variable that receives a pointer to the eventgroup's parent eventgroup

	*/
	static int		_getParentGroup		( lua_State* L );

	/*
	FMOD_RESULT EventGroup::getParentProject(
	  EventProject **  project
	);

	project
	?
	*/
	static int		_getParentProject	( lua_State* L );

	/*
	FMOD_RESULT EventGroup::getProperty(
	  const char *  propertyname, 
	  void *  value
	);

	propertyname
	Name of the property to retrieve. This is the name that was specified in FMOD Designer. 

	value
	Address of a variable to receive the event group property.
	*/
	static int		_getProperty		( lua_State* L );

	/*
	FMOD_RESULT EventGroup::getPropertyByIndex(
	  int  propertyindex, 
	  void *  value
	);

	propertyindex
	Index of the property to retrieve. 

	value
	Address of a variable to receive the event group property.
	*/
	static int		_getPropertyByIndex	( lua_State* L );

	/*
	FMOD_RESULT EventGroup::getState(
	  FMOD_EVENT_STATE *  state
	);

	state
	Address of a variable that receives the event group's current state.
	*/
	static int		_getState			( lua_State* L );

	/*
	FMOD_RESULT EventGroup::getUserData(
	  void **  userdata
	);

	userdata
	Address of a pointer that receives the data specified with the EventGroup::setUserData function.
	*/
	static int		_getUserData		( lua_State* L );

	/*
	FMOD_RESULT EventGroup::loadEventData(
	  FMOD_EVENT_RESOURCE  resource, 
	  FMOD_EVENT_MODE  mode
	);

	resource
	Type of wave data to load. Either load samples, streams, or both. See FMOD_EVENT_RESOURCE. 

	mode
	Use either FMOD_EVENT_DEFAULT for blocking behaviour or FMOD_EVENT_NONBLOCKING for non-blocking behaviour.
	*/
	static int		_loadEventData		( lua_State* L );

	/*
	FMOD_RESULT EventGroup::setUserData(
	  void *  userdata
	);
	
	userdata
	Address of user data that the user wishes stored within the EventGroup object.
	*/
	static int		_setUserData		( lua_State* L );

public:
	
	DECL_LUA_FACTORY ( MOAIFmodEventGroup )

	//----------------------------------------------------------------//
					MOAIFmodEventGroup			();
					~MOAIFmodEventGroup			();
	void			RegisterLuaClass	( MOAILuaState& state );
	void			RegisterLuaFuncs	( MOAILuaState& state );
};

#endif