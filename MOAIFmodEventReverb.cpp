#include "MOAIFmodEventReverb.h"

//----------------------------------------------------------------//
/**	@name	get3DAttributes
	@text	Gets the 3D attributes of the event 3D reverb object  
	@in		MOAIFmodEventReverb self
	@out	FMOD_Vector position	pointer to a vector in 3D space where the reverb is centred 
	@out	number mindistance	radius within which the reverb has full effect 
	@out	number maxdistance	radius outside of which the reverb has zero effect 
*/
int _get3DAttributes(lua_State* L)
{
	MOAI_LUA_SETUP ( MOAIFmodEventReverb, "U" )

	FMOD_VECTOR position;
	float mindistance;
	float maxdistance;

	if(self->Get3DAttributes(&position, &mindistance, &maxdistance))
	{
		lua_pushlightuserdata(state, &position);
		lua_pushnumber(state, mindistance);
		lua_pushnumber(state, maxdistance);
		return 3;
	}
	
	return 0;
}

//----------------------------------------------------------------//
/**	@name	getActive
	@text	Retrieves the active state of the reverb object 
	@in		MOAIFmodEventReverb self
	@out	bool* active	Address of a variable to receive the current active state of the reverb object 
*/
int _getActive(lua_State* L)
{
	MOAI_LUA_SETUP ( MOAIFmodEventReverb, "U" )

	bool active;
	if(self->IsActive(&active))
	{
		lua_pushboolean(state, active);
		return 1;
	}
	
	return 0;
}

/**	@name	getMemoryInfo
	@text	Retrieve detailed memory usage information about this object
	@in		MOAIFmodEventReverb self
	@out	unsigned int  memorybits	Memory usage bits for FMOD Ex. See FMOD_MEMBITS. 
	@out	unsigned int  event_memorybits		Memory usage bits for FMOD Event System. See FMOD_EVENT_MEMBITS. 
	@out	unsigned int  memoryused	Address of a variable to receive how much memory is being used by this object given the specified "memorybits" and "event_memorybits". 
	@out	FMOD_MEMORY_USAGE_DETAILS memoryused_details	Address of a user-allocated FMOD_MEMORY_USAGE_DETAILS structure to be filled with detailed memory usage information about this object. 
*/
int _getMemoryInfo(lua_State* L)
{
	MOAI_LUA_SETUP ( MOAIFmodEventReverb, "U" )

	unsigned int memorybits;
	unsigned int event_memorybits;
	unsigned int memoryused;

	//TODO
	//System::GetMemoryInfo(&memorybits, &event_memorybits, &memoryused); 

	lua_pushinteger(state, memorybits);
	lua_pushinteger(state, event_memorybits);
	lua_pushinteger(state, memoryused);
	return 3;
}

/**	@name	getProperties
	@text	Retrieves the current reverb properties for this event 3d reverb object
	@in		MOAIFmodEventReverb self
	@out	FMOD_REVERB_PROPERTIES *  props	Address of a variable to receive the FMOD_REVERB_PROPERTIES information
*/
int _getProperties(lua_State* L)
{
	MOAI_LUA_SETUP ( MOAIFmodEventReverb, "U" )

	FMOD_REVERB_PROPERTIES* props=(FMOD_REVERB_PROPERTIES*)lua_newuserdata(state, sizeof(FMOD_REVERB_PROPERTIES));
	self->GetProperties(props);
	return 1;
}

/**	@name	getUserData
	@text	Retrieves the user value that that was set by calling the EventReverb::setUserData function
	@in		MOAIFmodEventReverb self
	@out	void**  userdata	Address of a pointer that receives the data specified with the EventReverb::setUserData function
*/
int _getUserData(lua_State* L)
{
	MOAI_LUA_SETUP ( MOAIFmodEventReverb, "U" )
	//TODO?
	return 1;
}

//----------------------------------------------------------------//
/**	@name	set3DAttributes
	@text	Sets the 3D attributes of the event 3D reverb object  
	@in		MOAIFmodEventReverb self
	@in		FMOD_Vector position	pointer to a vector in 3D space where the reverb is centred 
	@in		number mindistance	radius within which the reverb has full effect 
	@in		number maxdistance	radius outside of which the reverb has zero effect 
	@out	nil
*/
int _set3DAttributes(lua_State* L)
{
	MOAI_LUA_SETUP ( MOAIFmodEventReverb, "UUNN" )

	FMOD_VECTOR* position=state.GetValue<FMOD_VECTOR*>(1,NULL);
	float mindistance=state.GetValue<float>(2, 0.0f);
	float maxdistance=state.GetValue<float>(3, 0.0f);

	self->Set3DAttributes(position, mindistance, maxdistance);
	return 0;
}

//----------------------------------------------------------------//
/**	@name	setActive
	@text	Disables or enables a reverb object so that it does or does not contribute to the 3d scene.  
	@in		MOAIFmodEventReverb self
	@in	bool* active	true = active, false = not active. Default = true.  
	@out nil
*/
int _setActive(lua_State* L)
{
	MOAI_LUA_SETUP ( MOAIFmodEventReverb, "UB" )
	bool isActive=state.GetValue<bool>(1, true);

	self->SetActive(isActive);

	return 0;
}

/**	@name	setProperties
	@text	Sets the reverb properties for this event 3d reverb object
	@in		MOAIFmodEventReverb self
	@in		FMOD_REVERB_PROPERTIES *  Pointer to a FMOD_REVERB_PROPERTIES structure definition
*/
int _setProperties(lua_State* L)
{
	MOAI_LUA_SETUP ( MOAIFmodEventReverb, "UU" )

	FMOD_REVERB_PROPERTIES* props=state.GetValue<FMOD_REVERB_PROPERTIES*>(1,NULL);
	self->SetProperties(props);

	return 0;
}

/**	@name	setUserData
	@text	Sets a user value that the EventReverb object will store internally. Can be retrieved with EventReverb::getUserData
	@in		MOAIFmodEventReverb self
	@out	void**  userdata	Address of user data that the user wishes stored within the EventReverb object
*/
int _setUserData(lua_State* L)
{
	MOAI_LUA_SETUP ( MOAIFmodEventReverb, "UU" )
	return 0;
}

MOAIFmodEventReverb::MOAIFmodEventReverb(void):mReverb(NULL)
{
	RTTI_SINGLE ( MOAINode )
}

void MOAIFmodEventReverb::RegisterLuaClass ( MOAILuaState& state ) 
{
}

void MOAIFmodEventReverb::RegisterLuaFuncs ( MOAILuaState& state ) {

	luaL_Reg regTable [] = {
		{ "get3DAttributes",_get3DAttributes },
		{ "getActive",_getActive },
		{ "getMemoryInfo",_getMemoryInfo },
		{ "getProperties",_getProperties },
		{ "getUserData",_getUserData },
		{ "set3DAttributes",_set3DAttributes },
		{ "setActive",_setActive },
		{ "setProperties",_setProperties },
		{ "setUserData",_setUserData },
		{ NULL, NULL }
	};

	luaL_register ( state, 0, regTable );
}

bool MOAIFmodEventReverb::IsActive(bool* active)
{
	return FMOD_CHECK(mReverb->getActive(active));
}

bool MOAIFmodEventReverb::SetActive(bool active)
{
	return FMOD_CHECK(mReverb->setActive(active));
}

bool MOAIFmodEventReverb::GetProperties(FMOD_REVERB_PROPERTIES* props)
{
	return FMOD_CHECK(mReverb->getProperties(props));
}

bool MOAIFmodEventReverb::SetProperties(FMOD_REVERB_PROPERTIES* props)
{
	return FMOD_CHECK(mReverb->setProperties(props));
}

bool MOAIFmodEventReverb::Get3DAttributes(FMOD_VECTOR* position, float* mindistance, float* maxdistance)
{
	return FMOD_CHECK(mReverb->get3DAttributes(position, mindistance, maxdistance));
}

bool MOAIFmodEventReverb::Set3DAttributes(FMOD_VECTOR* position, float mindistance, float maxdistance)
{
	return FMOD_CHECK(mReverb->set3DAttributes(position, mindistance, maxdistance));
}

bool MOAIFmodEventReverb::FMOD_CHECK(FMOD_RESULT result)
{
	if(result==FMOD_OK)
		return true;

	std::cout << "FMOD error: " <<  result << std::endl;
	return false;
}

MOAIFmodEventReverb::~MOAIFmodEventReverb(void)
{
	mReverb->release();
	delete mReverb;
	mReverb=NULL;
}
