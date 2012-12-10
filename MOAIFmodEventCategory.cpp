#include "MOAIFmodEventCategory.h"

void MOAIFmodEventCategory::setCategory(FMOD::EventCategory* cat)
{
	this->mEventCategory=cat;
	
}
int MOAIFmodEventCategory::getInfo( lua_State* L )
{
	MOAI_LUA_SETUP(MOAIFmodEventCategory, "N");
	//	return 1;*/
//	MOAILuaState state ( L );
	int* index = state.GetValue < int* >( 1, 0 );
	char** name = state.GetValue < char** >( 2, 0 );
	FMOD_RESULT result = self->mEventCategory->getInfo(index, name);
	state.Push(*index);
	state.Push(name);
	return (int) result;
}

int MOAIFmodEventCategory:: getCategory( lua_State* L )
{
	MOAI_LUA_SETUP(MOAIFmodEventCategory, "U");
	//MOAILuaState state ( L );
	char* name = state.GetValue < char* >( 1, 0 );
	FMOD::EventCategory** category;
	FMOD_RESULT result = self->mEventCategory->getCategory(name,category);
	MOAIFmodEventCategory* moaiEvent = new MOAIFmodEventCategory( );
	moaiEvent->setCategory( *category );
	self->LuaRetain( moaiEvent );
	moaiEvent->PushLuaUserdata( state );

	return (int) result;
}

int MOAIFmodEventCategory:: getCategoryByIndex ( lua_State* L )
{
	MOAI_LUA_SETUP(MOAIFmodEventCategory, "U");
	int index = state.GetValue < int>( 1, 0 );
	FMOD::EventCategory** category;
	FMOD_RESULT result = self->mEventCategory->getCategoryByIndex(index,category);
	MOAIFmodEventCategory* moaiEvent = new MOAIFmodEventCategory( );
	moaiEvent->setCategory( *category );
	self->LuaRetain( moaiEvent );
	moaiEvent->PushLuaUserdata( state );

	return (int) result;
}

int MOAIFmodEventCategory:: getNumCategories( lua_State* L )
{
	MOAI_LUA_SETUP(MOAIFmodEventCategory, "N");
	int* numcat = state.GetValue < int* >( 1, 0 );
	FMOD_RESULT result = self->mEventCategory->getNumCategories(numcat);
	state.Push(numcat);

	return (int) result;

}
int MOAIFmodEventCategory:: getEventByIndex( lua_State* L )
{
	MOAI_LUA_SETUP(MOAIFmodEventCategory, "U");
	int index = state.GetValue < int>( 1, 0 );
	FMOD_EVENT_MODE mode= state.GetValue < FMOD_EVENT_MODE >( 2, 0 );
	FMOD::Event** myevent;

	FMOD_RESULT result = self->mEventCategory->getEventByIndex(index,mode, myevent);
	MOAIFmodEvent* moaiEvent = new MOAIFmodEvent( );
	moaiEvent->setEvent( *myevent );
	self->LuaRetain( moaiEvent );
	moaiEvent->PushLuaUserdata( state );
	return (int) result;
}

int MOAIFmodEventCategory:: getNumEvents( lua_State* L )
{
	MOAI_LUA_SETUP(MOAIFmodEventCategory, "N");
	int* numcat = state.GetValue < int* >( 1, 0 );
	FMOD_RESULT result = self->mEventCategory->getNumEvents(numcat);
	state.Push(numcat);

	return (int) result;
}

int MOAIFmodEventCategory:: getParentCategory  ( lua_State* L )
{
	MOAI_LUA_SETUP(MOAIFmodEventCategory, "U");

	FMOD::EventCategory** category;
	FMOD_RESULT result = self->mEventCategory->getParentCategory(category);
	MOAIFmodEventCategory* moaiEvent = new MOAIFmodEventCategory( );
	moaiEvent->setCategory( *category );
	self->LuaRetain( moaiEvent );
	moaiEvent->PushLuaUserdata( state );

	return (int) result;
}

int MOAIFmodEventCategory:: stopAllEvents      ( lua_State* L )
{
	MOAI_LUA_SETUP(MOAIFmodEventCategory, "U");
	FMOD_RESULT result = self->mEventCategory->stopAllEvents();
	return (int) result;

}

int MOAIFmodEventCategory:: setVolume( lua_State* L )
{
		MOAI_LUA_SETUP(MOAIFmodEventCategory, "U");

	float volume = state.GetValue(2, 0.0f);
	FMOD_RESULT res = self->mEventCategory->setVolume(volume);
	return res;
}

int MOAIFmodEventCategory:: getVolume( lua_State* L )
{
	MOAI_LUA_SETUP(MOAIFmodEventCategory, "N");


	float* volume;
	FMOD_RESULT res = self->mEventCategory->getVolume(volume);
	state.Push(volume);
	return res;
}

int MOAIFmodEventCategory:: setPitch           ( lua_State* L )
{
	MOAI_LUA_SETUP(MOAIFmodEventCategory, "N");
	float pitch = state.GetValue < float >( 1, 0.0f);
	FMOD_EVENT_PITCHUNITS units = (FMOD_EVENT_PITCHUNITS) state.GetValue < int>( 2, 0 );
	FMOD_RESULT result = self->mEventCategory->setPitch(pitch,units);
	return result;
}

int MOAIFmodEventCategory:: getPitch           ( lua_State* L )
{
	MOAI_LUA_SETUP(MOAIFmodEventCategory, "N");
	float* pitch;
	FMOD_EVENT_PITCHUNITS units = (FMOD_EVENT_PITCHUNITS) state.GetValue < int>( 1, 0 );
	FMOD_RESULT result = self->mEventCategory->getPitch(pitch,units);
	state.Push(pitch);
	return result;
}

int MOAIFmodEventCategory::setPaused( lua_State* L )
{
	MOAI_LUA_SETUP(MOAIFmodEventCategory, "N");
	bool paused = state.GetValue < bool >( 1, 0 );
	FMOD_RESULT result = self->mEventCategory->setPaused(paused);
	return (int) result;
}

int	MOAIFmodEvent::getPaused( lua_State* L )
{
	MOAI_LUA_SETUP(MOAIFmodEventCategory, "N");
	bool* paused;
	FMOD_RESULT result =self->mEventCategory->getPaused(paused);
	state.Push(paused);
	return (int) result;
}

int MOAIFmodEventCategory::setMute( lua_State* L )
{
	MOAI_LUA_SETUP(MOAIFmodEventCategory, "N");
	bool mute = state.GetValue < bool >( 1, 0 );
	FMOD_RESULT result = self->mEventCategory->setMute(mute);
	return (int) result;
}

int MOAIFmodEventCategory::getMute( lua_State* L )
{
	MOAI_LUA_SETUP(MOAIFmodEventCategory, "N");
	bool* mute;
	FMOD_RESULT result = self->mEventCategory->getMute(mute);
	state.Push(mute);
	return (int) result;
}
int MOAIFmodEventCategory::getChannelGroup    ( lua_State* L )
{
	MOAI_LUA_SETUP(MOAIFmodEventCategory, "U");
	FMOD::ChannelGroup** channelgroup = state.GetValue < FMOD::ChannelGroup** >( 1, 0 );
	FMOD_RESULT result = self->mEventCategory->getChannelGroup(channelgroup);
	//MOAIFmodEventCategory* moaiEvent = new MOAIFmodEventCategory( );
	//moaiEvent->setCategory( *category );
	//channelgroup->BindToLua(state);

	return result;


	}

void MOAIFmodEventCategory::RegisterLuaClass ( MOAILuaState& state ) 
{
	luaL_Reg regTable [] = {{ "new",	MOAILogMessages::_alertNewIsUnsupported }};

	luaL_register ( state, 0, regTable );
}

//----------------------------------------------------------------//
void MOAIFmodEventCategory::RegisterLuaFuncs ( MOAILuaState& state ) {

	luaL_Reg regTable [] = {
	{ "getInfo",	getInfo },
	{ "getCategory",	getCategory },
	{ "getCategoryByIndex",	getCategoryByIndex },
	{ "getNumCategories",	getNumCategories},
	{ "getEventByIndex ",	getEventByIndex },
	{ "getNumEvents",	getNumEvents},
	{ "getParentCategory",	getParentCategory},
	{"stopAllEvents",stopAllEvents},
	{"setVolume",setVolume},
	{"getVolume ",getVolume },
	{"setPitch",setPitch},
	{"getPitch",getPitch},
	{"setPaused",setPaused},
	{"getPaused",getPaused},
	{"setMute",setMute},
	{"getMute",getMute},
	{"getChannelGroup",getChannelGroup},
	//{"setUserData",setUserData},
	//{"getUserData",getUserData},
	//{"getMemoryInfo",getMemoryInfo},
	{ "new",	MOAILogMessages::_alertNewIsUnsupported }
	};

	luaL_register ( state, 0, regTable );
}

//----------------------------------------------------------------//
MOAIFmodEventCategory::MOAIFmodEventCategory ()
{
	RTTI_BEGIN
	RTTI_EXTEND ( MOAILuaObject )
	RTTI_END
}

MOAIFmodEventCategory::~MOAIFmodEventCategory ()
{
	if(mEventCategory)
	delete this->mEventCategory;
}

