#include "moaiext-fmod-designer/MOAIFmodEventProject.h"

#include "moaiext-fmod-designer/MOAIFmodEvent.h"
#include "moaiext-fmod-designer/MOAIFmodEventGroup.h"

//----------------------------------------------------------------//
/** @name cancelAllLoads
@text Cancels any queued up asynchronous loads caused by FMOD_EVENT_NONBLOCKING flag.
@in MOAIFmodEventProject self

*/

int MOAIFmodEventProject::_cancelAllLoads ( lua_State* L ) {

MOAI_LUA_SETUP ( MOAIFmodEventProject, "U" )

self->mEventProject->cancelAllLoads();

return 1;
}

//----------------------------------------------------------------//
/** @name getEvent
@text Retrieve an event object by name.

@in MOAIFmodEventProject self
@in string eventName
@in int eventMode
@out MOAIFmodEvent event

*/

int MOAIFmodEventProject::_getEvent ( lua_State* L ) {
MOAI_LUA_SETUP ( MOAIFmodEventProject, "UUN" )

FMOD::Event** event;

char* name = state.GetValue< char* > ( 1, "" );
u32 loadflag =	state.GetValue < u32 > ( 2, 0 );
self->mEventProject->getEvent ( name, loadflag, event );

MOAIFmodEvent* moaiEvent = new MOAIFmodEvent( *event );
self->LuaRetain ( moaiEvent );

moaiEvent->PushLuaUserdata ( state );
}

//----------------------------------------------------------------//
/** @name getEventByProjectID
@text Retrieve an event handle by a project unique id.

@in MOAIFmodEventProject self
@in int eventID
@in int eventModeflag
@out MOAIFmodEvent event

*/

int MOAIFmodEventProject::_getEventByProjectID ( lua_State* L ) {
MOAI_LUA_SETUP ( MOAIFmodEventProject, "UNN" )

FMOD::Event** event;

int projectID = state.GetValue< int > ( 1, 0 );
u32 loadflag =	state.GetValue < u32 > ( 2, 0 );
self->mEventProject->getEventByProjectID ( projectID, loadflag, event );

MOAIFmodEvent* moaiEvent = new MOAIFmodEvent ( *event );
self->LuaRetain ( moaiEvent );

moaiEvent->PushLuaUserdata ( state );
}

//----------------------------------------------------------------//
/** @name getGroup
@text Retrieves an event group object by name.

@in MOAIFmodEventProject self
@in string groupName
@in int eventModeflag
@out MOAIFmodEventGroup group

*/

int MOAIFmodEventProject::_getGroup ( lua_State* L ) {
MOAI_LUA_SETUP ( MOAIFmodEventProject, "UUN" )

FMOD::EventGroup** eventGroup;

char* name = state.GetValue< char* > ( 1, "" );
u32 loadflag =	state.GetValue < u32 > ( 2, 0 );
self->mEventProject->getGroup ( name, loadflag, eventGroup );

MOAIFmodEventGroup* moaiEventGroup = new MOAIFmodEventGroup( );
//moaiEventGroup->setGroup ( *moaiEventGroup );
self->LuaRetain ( moaiEventGroup );

moaiEventGroup->PushLuaUserdata ( state );
}

//----------------------------------------------------------------//
/** @name getGroupByIndex
@text Retrieves an event group object by index.

@in MOAIFmodEventProject self
@in int groupID
@in int eventModeflag
@out MOAIFmodEventGroup group

*/

int MOAIFmodEventProject::_getGroupByIndex ( lua_State* L ) {
MOAI_LUA_SETUP ( MOAIFmodEventProject, "UNN" )

FMOD::EventGroup** eventGroup;

int groupID = state.GetValue< int > ( 1, 0 );
u32 loadflag =	state.GetValue < u32 > ( 2, 0 );
self->mEventProject->getGroupByIndex ( groupID, loadflag, eventGroup );

MOAIFmodEventGroup* moaiEventGroup = new MOAIFmodEventGroup( );
moaiEventGroup->setGroup ( *moaiEventGroup );
self->LuaRetain ( moaiEventGroup );

moaiEventGroup->PushLuaUserdata ( state );
}

// FIXME
//----------------------------------------------------------------//
/** @name getInfo
@text Retrieve information about this event project.

@in MOAIFmodEventProject self
// FIXME:
@out int index
@out string name
@out int numEvents
@out int numinstances
@out int maxwavebanks
@out FIXME: FMOD_EVENT_WAVEBANKINFO * wavebankinfo
@out int numPlayingEvents
@out FIXME: table playingEvents

*/
//FIXME:
int MOAIFmodEventProject::_getInfo ( lua_State* L ) {
MOAI_LUA_SETUP ( MOAIFmodEventProject, "U" )

FMOD_EVENT_PROJECTINFO* info;
FMOD_EVENT_WAVEBANKINFO* wave_info;
info->wavebankinfo = wave_info;

self->mEventProject->getInfo(info);

lua_pushnumber( state, info->index );
lua_pushstring( state, info->name );
lua_pushnumber( state, info->numevents );
lua_pushnumber( state, info->numinstances );
lua_pushnumber( state, info->maxwavebanks );

// FIXME:
/*
MOAIFmodWaveBankInfo wave_info = new MOAIFmodWaveBankInfo();
wave_info->SetWaveBankInfo(info->wavebankinfo);
self->LuaRetain ( wave_info );
wave_info->PushLuaUserdata ( state );
*/
lua_pushnumber( state, info->numplayingevents );

// FIXME: PLAYING EVENTS
// FIXME: memory management?
// FIXME: cast?
/*
lua_newtable( state );
int top = lua_gettop( state );
for( int i = 0; i < info->numevents; i++ ) {
MOAIFmodEvent* event = new MOAIFmodEvent ();
event->setEvent ( ( FMOD::Event* ) info->playingevents[i] );
lua_pushnumber ( state, i);
lua_pushlightuserdata ( state, event );
lua_settable( state, top );
}
*/
}

//----------------------------------------------------------------//
/** @name getMemoryInfo
@text Retrieve detailed memory usage information about this object.

@in MOAIFmodEventProject self
@in int memoryFlag
@in int eventMemoryFlag
@out int memoryUsed
@out FIXME

*/
//FIXME: implement MEMORY info struct
int MOAIFmodEventProject::_getMemoryInfo ( lua_State* L ) {
MOAI_LUA_SETUP ( MOAIFmodEventProject, "U" )

u32 loadflag =	state.GetValue < u32 > ( 2, 0 );
u32 eventloadflag =	state.GetValue < u32 > ( 3, 0 );

unsigned int* memoryUsed;
self->mEventProject->getMemoryInfo(loadflag, eventloadflag, memoryUsed, 0);

lua_pushnumber( state, *memoryUsed);
}

//----------------------------------------------------------------//
/** @name getNumEvents
@text Returns the total number of events for this project only.

@in MOAIFmodEventProject self
@out int numberOfEvents

*/

int MOAIFmodEventProject::_getNumEvents ( lua_State* L ) {
MOAI_LUA_SETUP ( MOAIFmodEventProject, "U" )

int* numEvents;
self->mEventProject->getNumEvents ( numEvents );

lua_pushnumber( state, *numEvents);
}

//----------------------------------------------------------------//
/** @name getNumGroups
@text Retrieves the number of event groups stored within this event project.

@in MOAIFmodEventProject self
@out int numGroups

*/

int MOAIFmodEventProject::_getNumGroups ( lua_State* L ) {
MOAI_LUA_SETUP ( MOAIFmodEventProject, "U" )

int* numGroups;
self->mEventProject->getNumGroups ( numGroups );

lua_pushnumber( state, *numGroups);
}

//FIXME: ???
//----------------------------------------------------------------//
/** @name getUserData
@text Retrieves the user value that that was set by calling
the EventProject::setUserData function.

@in MOAIFmodEventProject self
@out void* Userdata

*/

int MOAIFmodEventProject::_getUserData ( lua_State* L ) {
MOAI_LUA_SETUP ( MOAIFmodEventProject, "U" )

}

//----------------------------------------------------------------//
/** @name loadSampleData
@text Load sample data for multiple events/eventgroups
at once in an optimized way.

@in MOAIFmodEventProject self
@in Table EventIDs
@in int numberOfEvents
@in Table GroupNames
@in int numberOfGroups

*/

int MOAIFmodEventProject::_loadSampleData ( lua_State* L ) {
MOAI_LUA_SETUP ( MOAIFmodEventProject, "UUNUNN" )

int sizeOfEventIDs = state.GetValue< int > ( 2, 0 );
int* eventIDs = new int [ sizeOfEventIDs ];
for ( int i = 0; i < sizeOfEventIDs; i++ ) {
lua_pushstring( state, std::string("ID" + i).c_str() );
eventIDs[i] = lua_tonumber( state, 1 );
}

int sizeOfGroupNames = state.GetValue< int > ( 4, 0 );
char** projectIDs= new char* [ sizeOfGroupNames ];
for ( int i = 0; i < sizeOfGroupNames; i++ ) {
lua_pushstring( state, std::string("ID_length" + i).c_str() );
size_t* length;
*length = lua_tonumber( state, 3 );
lua_pushstring( state, std::string("ID" + i).c_str() );
projectIDs[i] = const_cast < char* > ( lua_tolstring( state, 3, length) );
}

u32 loadflag =	state.GetValue < u32 > ( 5, 0 );

self->mEventProject->loadSampleData ( eventIDs, sizeOfEventIDs, projectIDs,
sizeOfGroupNames, loadflag );
}

//----------------------------------------------------------------//
/** @name release
@text Release this event project and all the
events/eventgroups that it contains.

@in MOAIFmodEventProject self

*/

int MOAIFmodEventProject::_release( lua_State* L ) {
MOAI_LUA_SETUP ( MOAIFmodEventProject, "U" )

self->mEventProject->release();
}

//----------------------------------------------------------------//
/** @name setUserData
@text Sets a user value that the EventProject object will store internally.
Can be retrieved with EventProject::getUserData.

@in MOAIFmodEventProject self
@in void* userdata

*/

int MOAIFmodEventProject::_setUserData( lua_State* L ) {
MOAI_LUA_SETUP ( MOAIFmodEventProject, "U" )

//FIXME
self->mEventProject->setUserData(0);
}

//----------------------------------------------------------------//
/** @name stopAllEvents
@text Stop all events in this project.

@in MOAIFmodEventProject self
@in boolean immediately

*/

int MOAIFmodEventProject::_stopAllEvents ( lua_State* L ) {
MOAI_LUA_SETUP ( MOAIFmodEventProject, "U" )

bool immediate = state.GetValue < bool > ( 1, false );
self->mEventProject->stopAllEvents( immediate );
}


//----------------------------------------------------------------//

void MOAIFmodEventProject::RegisterLuaClass ( MOAILuaState& state ) {

MOAIFmodEventProject::RegisterLuaClass ( state );

state.SetField ( -1, "DEFAULT_EVENT", ( u32 )DEFAULT_EVENT );
state.SetField ( -1, "NONBLOCKING_EVENT", ( u32 )NONBLOCKING_EVENT );
state.SetField ( -1, "ERROR_ON_DISCACCESS_EVENT", ( u32 )ERROR_ON_DISCACCESS_EVENT );
state.SetField ( -1, "INFO_ONLY_EVENT", ( u32 )INFO_ONLY_EVENT );
state.SetField ( -1, "USERDSP_EVENT", ( u32 )USERDSP_EVENT );

state.SetField ( -1, "MAX_NONBLOCKING_THREADS", ( u32 )MAX_NONBLOCKING_THREADS );
state.SetField ( -1, "NONBLOCKING_EVENT_THREAD0", ( u32 )NONBLOCKING_EVENT_THREAD0 );
state.SetField ( -1, "NONBLOCKING_EVENT_THREAD1", ( u32 )NONBLOCKING_EVENT_THREAD1 );
state.SetField ( -1, "NONBLOCKING_EVENT_THREAD2", ( u32 )NONBLOCKING_EVENT_THREAD2 );
state.SetField ( -1, "NONBLOCKING_EVENT_THREAD3NT", ( u32 )NONBLOCKING_EVENT_THREAD3 );
state.SetField ( -1, "NONBLOCKING_EVENT_THREAD4", ( u32 )NONBLOCKING_EVENT_THREAD4 );

state.SetField ( -1, "MEMBITS_OTHER", ( u32 )MEMBITS_OTHER );
state.SetField ( -1, "MEMBITS_STRING", ( u32 )MEMBITS_STRING );
state.SetField ( -1, "MEMBITS_SYSTEM", ( u32 )MEMBITS_SYSTEM );
state.SetField ( -1, "MEMBITS_PLUGINS", ( u32 )MEMBITS_PLUGINS );
state.SetField ( -1, "MEMBITS_OUTPUT", ( u32 )MEMBITS_OUTPUT );
state.SetField ( -1, "MEMBITS_CHANNEL", ( u32 )MEMBITS_CHANNEL );
state.SetField ( -1, "MEMBITS_CHANNELGROUP", ( u32 )MEMBITS_CHANNELGROUP );
state.SetField ( -1, "MEMBITS_CODEC", ( u32 )MEMBITS_CODEC );
state.SetField ( -1, "MEMBITS_FILE", ( u32 )MEMBITS_FILE );
state.SetField ( -1, "MEMBITS_SOUND", ( u32 )MEMBITS_SOUND );
state.SetField ( -1, "MEMBITS_SECONDARYRAM", ( u32 )MEMBITS_SECONDARYRAM );
state.SetField ( -1, "MEMBITS_SOUNDGROUND", ( u32 )MEMBITS_SOUNDGROUND );
state.SetField ( -1, "MEMBITS_STREAMBUFFER", ( u32 )MEMBITS_STREAMBUFFER );
state.SetField ( -1, "MEMBITS_DSPCONNECTION", ( u32 )MEMBITS_DSPCONNECTION );
state.SetField ( -1, "MEMBITS_DSP", ( u32 )MEMBITS_DSP );
state.SetField ( -1, "MEMBITS_DSPCODEC", ( u32 )MEMBITS_DSPCODEC );
state.SetField ( -1, "MEMBITS_PROFILE", ( u32 )MEMBITS_PROFILE );
state.SetField ( -1, "MEMBITS_RECORDBUFFER", ( u32 )MEMBITS_RECORDBUFFER );
state.SetField ( -1, "MEMBITS_REVERB", ( u32 )MEMBITS_REVERB );
state.SetField ( -1, "MEMBITS_REVERBCHANNELPROPS", ( u32 )MEMBITS_REVERBCHANNELPROPS );
state.SetField ( -1, "MEMBITS_GEOMETRY", ( u32 )MEMBITS_GEOMETRY );
state.SetField ( -1, "MEMBITS_SYNCPOINT", ( u32 )MEMBITS_SYNCPOINT );
state.SetField ( -1, "MEMBITS_ALL", ( u32 )MEMBITS_ALL );

state.SetField ( -1, "EVENT_MEMBITS_EVENTSYTEM", ( u32 )EVENT_MEMBITS_EVENTSYTEM );
state.SetField ( -1, "EVENT_MEMBITS_MUSICSYSTEM", ( u32 )EVENT_MEMBITS_MUSICSYSTEM );
state.SetField ( -1, "EVENT_MEMBITS_FEV", ( u32 )EVENT_MEMBITS_FEV );
state.SetField ( -1, "EVENT_MEMBITS_MEMORYFSB", ( u32 )EVENT_MEMBITS_MEMORYFSB );
state.SetField ( -1, "EVENT_MEMBITS_EVENTPROJECT", ( u32 )EVENT_MEMBITS_EVENTPROJECT );
state.SetField ( -1, "EVENT_MEMBITS_EVENTGROUPI", ( u32 )EVENT_MEMBITS_EVENTGROUPI );
state.SetField ( -1, "EVENT_MEMBITS_SOUNDBANKCLASS", ( u32 )EVENT_MEMBITS_SOUNDBANKCLASS );
state.SetField ( -1, "EVENT_MEMBITS_SOUNDBANKLIST", ( u32 )EVENT_MEMBITS_SOUNDBANKLIST );
state.SetField ( -1, "EVENT_MEMBITS_STREAMINSTANCE", ( u32 )EVENT_MEMBITS_STREAMINSTANCE );
state.SetField ( -1, "EVENT_MEMBITS_SOUNDDEFCLASS", ( u32 )EVENT_MEMBITS_SOUNDDEFCLASS );
state.SetField ( -1, "EVENT_MEMBITS_SOUNDDEFDEFCLASS", ( u32 )EVENT_MEMBITS_SOUNDDEFDEFCLASS );
state.SetField ( -1, "EVENT_MEMBITS_SOUNDDEFPOOL", ( u32 )EVENT_MEMBITS_SOUNDDEFPOOL );
state.SetField ( -1, "EVENT_MEMBITS_REVERBDEF", ( u32 )EVENT_MEMBITS_REVERBDEF );
state.SetField ( -1, "EVENT_MEMBITS_EVENTREVERB", ( u32 )EVENT_MEMBITS_EVENTREVERB );
state.SetField ( -1, "EVENT_MEMBITS_USERPROPERTY", ( u32 )EVENT_MEMBITS_USERPROPERTY );
state.SetField ( -1, "EVENT_MEMBITS_EVENTINSTANCE", ( u32 )EVENT_MEMBITS_EVENTINSTANCE );
state.SetField ( -1, "EVENT_MEMBITS_EVENTINSTANCE_COMPLEX", ( u32 )EVENT_MEMBITS_EVENTINSTANCE_COMPLEX );
state.SetField ( -1, "EVENT_MEMBITS_EVENTINSTANCE_SIMPLE", ( u32 )EVENT_MEMBITS_EVENTINSTANCE_SIMPLE );
state.SetField ( -1, "EVENT_MEMBITS_EVENTINSTANCE_LAYER", ( u32 )EVENT_MEMBITS_EVENTINSTANCE_LAYER );
state.SetField ( -1, "EVENT_MEMBITS_EVENTINSTANCE_SOUND", ( u32 )EVENT_MEMBITS_EVENTINSTANCE_SOUND );
state.SetField ( -1, "EVENT_MEMBITS_EVENTENVELOPE", ( u32 )EVENT_MEMBITS_EVENTENVELOPE );
state.SetField ( -1, "EVENT_MEMBITS_EVENTEVELOPEDEF", ( u32 )EVENT_MEMBITS_EVENTEVELOPEDEF );
state.SetField ( -1, "EVENT_MEMBITS_EVENTPARAMETER", ( u32 )EVENT_MEMBITS_EVENTPARAMETER );
state.SetField ( -1, "EVENT_MEMBITS_EVENTCATEGORY", ( u32 )EVENT_MEMBITS_EVENTCATEGORY );
state.SetField ( -1, "EVENT_MEMBITS_EVENTENVELOPEPOINT", ( u32 )EVENT_MEMBITS_EVENTENVELOPEPOINT );
state.SetField ( -1, "EVENT_MEMBITS_EVENTINSTANCEPOOL", ( u32 )EVENT_MEMBITS_EVENTINSTANCEPOOL );
state.SetField ( -1, "EVENT_MEMBITS_ALL", ( u32 )EVENT_MEMBITS_ALL );
state.SetField ( -1, "EVENT_MEMBITS_EVENTINSTANCEGROUP", ( u32 )EVENT_MEMBITS_EVENTINSTANCEGROUP );
state.SetField ( -1, "EVENT_MEMBITS_SOUNDDEF_GROUP", ( u32 )EVENT_MEMBITS_SOUNDDEF_GROUP );

// here are the class methods:
luaL_Reg regTable [] = {
{ "new",	MOAILogMessages::_alertNewIsUnsupported }
};

luaL_register ( state, 0, regTable );
}

//----------------------------------------------------------------//
void MOAIFmodEventProject::RegisterLuaFuncs ( MOAILuaState& state ) {

luaL_Reg regTable [] = {
{ "cancelAllLoads",	_cancelAllLoads },
{ "getEvent",	_getEvent },
{ "getEventByProjectID",	_getEventByProjectID },
{ "getGroup",	_getGroup},
{ "getGroupByIndex",	_getGroupByIndex},
{ "getInfo",	_getGroupByIndex},
{ "getMemoryInfo",	_getMemoryInfo},
{ "getNumEvents",	_getNumEvents},
{ "getNumGroups",	_getNumGroups},
{ "getUserData",	_getUserData},
{ "loadSampleData",	_loadSampleData},
{ "release",	_release},
{ "setUserData",	_setUserData},
{ "stopAllEvents",	_stopAllEvents},
{ "new",	MOAILogMessages::_alertNewIsUnsupported }
};

luaL_register ( state, 0, regTable );
}

//----------------------------------------------------------------//
MOAIFmodEventProject::MOAIFmodEventProject ()
{
RTTI_BEGIN
RTTI_EXTEND ( MOAILuaObject )
RTTI_END
}

MOAIFmodEventProject::MOAIFmodEventProject ( FMOD::EventProject* project ) {
RTTI_BEGIN
RTTI_EXTEND ( MOAILuaObject )
RTTI_END
this->mEventProject = project;
}

MOAIFmodEventProject::~MOAIFmodEventProject ()
{
if(mEventProject)
delete this->mEventProject;
}

void MOAIFmodEventProject::setEventProject(FMOD::EventProject* project)
{
if(this->mEventProject)
delete mEventProject;
this->mEventProject = project;
}