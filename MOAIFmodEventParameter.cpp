#include "pch.h"
#include "MOAIFmodEventParameter.h"
 
//================================================================//
// lua
//================================================================//
//----------------------------------------------------------------//
/**	@name	getInfo
	@text	Retrieve information about this event parameter.  



	@opt	index 
	@text   Address of a variable to receive the event parameters index into the parent event. 
	@opt    name
	@text   Address of a variable to receive the event parameter name. 

	@out    FMOD_RESULT
	@text   If the function succeeds then the return value is FMOD_OK. If the function fails then the return value will be one of the values defined in the FMOD_RESULT enumeration.
*/
int	MOAIFmodEventParameter::_getInfo( lua_State* L) {
	MOAI_LUA_SETUP ( MOAIFmodEventParameter, "U" );

	int* index = state.GetValue < int* >(1, 0);
	char** name = state.GetValue <char**>(2, 0);
	

	return self->GetEventParameter().getInfo(index, name);
}
//----------------------------------------------------------------//
/**	@name	disableAutomation
	@text	Turn off automation for a parameter. This is only relevant to automatic parameters such as (distance), (event angle), (listener angle) within FMOD Designer.  
	
	@opt	disable 
	@text   When true, FMOD stops automatically updating parameters, allowing the user to set it manually. When false, the parameter updates automatically (default behaviour). 

	@out    FMOD_RESULT
	@text   If the function succeeds then the return value is FMOD_OK. If the function fails then the return value will be one of the values defined in the FMOD_RESULT enumeration.
*/
int MOAIFmodEventParameter::_disableAutomation( lua_State* L) {
	MOAI_LUA_SETUP ( MOAIFmodEventParameter, "U" );
  
	bool  disable = state.GetValue<bool>(1,false);

	return self->GetEventParameter().disableAutomation (disable);
}
//----------------------------------------------------------------//
/**	@name	getMemoryInfo
	@text	Retrieve detailed memory usage information about this object.  

	@opt memorybits
	@text Memory usage bits for FMOD Ex. See FMOD_MEMBITS. 

	@opt event_memorybits
	@text Memory usage bits for FMOD Event System. See FMOD_EVENT_MEMBITS. 

	@opt memoryused
	@text Optional. Specify 0 to ignore. Address of a variable to receive how much memory is being used by this object given the specified "memorybits" and "event_memorybits". 

	@opt memoryused_details
	@text Optional. Specify 0 to ignore. Address of a user-allocated FMOD_MEMORY_USAGE_DETAILS structure to be filled with detailed memory usage information about this object. 

	@out    FMOD_RESULT
	@text   If the function succeeds then the return value is FMOD_OK. If the function fails then the return value will be one of the values defined in the FMOD_RESULT enumeration.
*/
int MOAIFmodEventParameter::_getMemoryInfo( lua_State* L) {
  MOAI_LUA_SETUP ( MOAIFmodEventParameter, "U" );

  unsigned int memorybits  = state.GetValue< unsigned int>(1,0);
  unsigned int event_memorybits = state.GetValue< unsigned int>(2,0);
  unsigned int *  memoryused =  state.GetValue< unsigned int *>(3,0);
  FMOD_MEMORY_USAGE_DETAILS *  memoryused_details = state.GetValue<FMOD_MEMORY_USAGE_DETAILS *>(4,0);

  return self->GetEventParameter().getMemoryInfo(memorybits,event_memorybits,memoryused,memoryused_details);
}

//----------------------------------------------------------------//
/**	@name	getRange
	@text	Retrieve the minimum and maximum values for this event parameter.  

	@opt rangemin
	@text Address of variable to receive the minimum value allowed for this EventParameter. 
	
	@opt rangemax
	@text Address of variable to receive the maximum value allowed for this EventParameter. 
	
	@out    FMOD_RESULT
	@text   If the function succeeds then the return value is FMOD_OK. If the function fails then the return value will be one of the values defined in the FMOD_RESULT enumeration.
*/
int MOAIFmodEventParameter::_getRange( lua_State* L) {
  MOAI_LUA_SETUP ( MOAIFmodEventParameter, "U" );
	
	float *  rangemin =  state.GetValue<float *>(1,0);
	float *  rangemax =  state.GetValue<float *>(2,0);

	return self->GetEventParameter().getRange(rangemin,rangemax);
}

//----------------------------------------------------------------//
/**	@name	getSeekSpeed
	@text	Receieves the seek velocity of an event.  

	@opt value
	
	@out    FMOD_RESULT
	@text   If the function succeeds then the return value is FMOD_OK. If the function fails then the return value will be one of the values defined in the FMOD_RESULT enumeration.
*/
int MOAIFmodEventParameter::_getSeekSpeed( lua_State* L) {
  MOAI_LUA_SETUP ( MOAIFmodEventParameter, "U" );
	
	float *  value =  state.GetValue<float *>(1,0);

	return self->GetEventParameter().getSeekSpeed(value);
}
//----------------------------------------------------------------//
/**	@name	getUserData
	@text	Retrieves the user value that that was set by calling the EventParameter::setUserData function.  

	@opt userdata
	@text Address of a pointer that receives the data specified with the EventParameter::setUserData function. 

	@out    FMOD_RESULT
	@text   If the function succeeds then the return value is FMOD_OK. If the function fails then the return value will be one of the values defined in the FMOD_RESULT enumeration.
*/
int MOAIFmodEventParameter::_getUserData( lua_State* L) {
  MOAI_LUA_SETUP ( MOAIFmodEventParameter, "U" );
	
	void **  userdata =  state.GetValue<void **>(1,0);

	return self->GetEventParameter().getUserData(userdata);
}
//----------------------------------------------------------------//
/**	@name	getValue
	@text	Retrieve the current value of this parameter.  

	@opt value
	@text Address of variable to receive the parameter value. 

	@out    FMOD_RESULT
	@text   If the function succeeds then the return value is FMOD_OK. If the function fails then the return value will be one of the values defined in the FMOD_RESULT enumeration.
*/
int MOAIFmodEventParameter::_getValue( lua_State* L) {
  MOAI_LUA_SETUP ( MOAIFmodEventParameter, "U" );
	
	float* value =  state.GetValue<float*>(1,0);

	return self->GetEventParameter().getValue(value);
}
//----------------------------------------------------------------//
/**	@name	getVelocity
	@text	Receieves the velocity of an event.  

	@opt value
	
	@out    FMOD_RESULT
	@text   If the function succeeds then the return value is FMOD_OK. If the function fails then the return value will be one of the values defined in the FMOD_RESULT enumeration.
*/
int MOAIFmodEventParameter::_getVelocity( lua_State* L) {
  MOAI_LUA_SETUP ( MOAIFmodEventParameter, "U" );
	
	float* value =  state.GetValue<float*>(1,0);

	return self->GetEventParameter().getVelocity(value);
}

//----------------------------------------------------------------//
/**	@name	keyOff
	@text	Triggers a keyoff on an event parameter that has sustain points in it. If an event parameter is currently sustaining on a sustain point,  triggering a keyoff will release it and allow the parameter to continue.   
	
	@out    FMOD_RESULT
	@text   If the function succeeds then the return value is FMOD_OK. If the function fails then the return value will be one of the values defined in the FMOD_RESULT enumeration.
*/
int MOAIFmodEventParameter::_keyOff( lua_State* L) {
  MOAI_LUA_SETUP ( MOAIFmodEventParameter, "U" );
	
  return self->GetEventParameter().keyOff();
}

//----------------------------------------------------------------//
/**	@name	setSeekSpeed
	@text	Sets the seek velocity of a parameter.  

	@opt value

	@out    FMOD_RESULT
	@text   If the function succeeds then the return value is FMOD_OK. If the function fails then the return value will be one of the values defined in the FMOD_RESULT enumeration.
*/
int MOAIFmodEventParameter::_setSeekSpeed( lua_State* L) {
  MOAI_LUA_SETUP ( MOAIFmodEventParameter, "U" );

  float value =  state.GetValue<float>(1,0);
	
  return self->GetEventParameter().setSeekSpeed(value);
}
//----------------------------------------------------------------//
/**	@name	setUserData
	@text	Sets the seek velocity of a parameter.  

	@opt userdata
	@text Address of user data that the user wishes stored within the EventParameter object. 

	@out    FMOD_RESULT
	@text   If the function succeeds then the return value is FMOD_OK. If the function fails then the return value will be one of the values defined in the FMOD_RESULT enumeration.
*/
int MOAIFmodEventParameter::_setUserData( lua_State* L) {
  MOAI_LUA_SETUP ( MOAIFmodEventParameter, "U" );

  void * userdata =  state.GetValue< void *>(1,0);
	
  return self->GetEventParameter().setUserData(userdata);
}

//----------------------------------------------------------------//
/**	@name	setValue
	@text	Set the 'value' of this parameter.  

	@opt value
	@text Value to set this parameter to. Note! Must lie in the range described by EventParameter::getRange. 

	@out    FMOD_RESULT
	@text   If the function succeeds then the return value is FMOD_OK. If the function fails then the return value will be one of the values defined in the FMOD_RESULT enumeration.
*/
int MOAIFmodEventParameter::_setValue( lua_State* L) {
  MOAI_LUA_SETUP ( MOAIFmodEventParameter, "U" );

  float value =  state.GetValue<float>(1,0);
	
  return self->GetEventParameter().setValue(value);
}
//----------------------------------------------------------------//
/**	@name	setVelocity
	@text	Set the 'value' of this parameter.  

	@opt value
	
	@out    FMOD_RESULT
	@text   If the function succeeds then the return value is FMOD_OK. If the function fails then the return value will be one of the values defined in the FMOD_RESULT enumeration.
*/
int MOAIFmodEventParameter::_setVelocity( lua_State* L) {
  MOAI_LUA_SETUP ( MOAIFmodEventParameter, "U" );

  float value =  state.GetValue<float>(1,0);
	
  return self->GetEventParameter().setVelocity(value);
}


//----------------------------------------------------------------//
/** @name   classEventParameter
    @text   Initialized a EventParamter
 
    @out    nil
*/
int MOAIFmodEventParameter::_classEventParameter ( lua_State* L ) {
    MOAI_LUA_SETUP ( MOAIFmodEventParameter, "U" );
 
    return 0;
}
 
//----------------------------------------------------------------//
/** @name   instanceHello 
    @text   Prints the string 'MOAIFmodEventParamter instance foo!' to the console.
 
    @out    nil
*/
int MOAIFmodEventParameter::_instanceEventParameter ( lua_State* L ) {
 
    // this macro initializes the 'self' variable 
    // and type checks arguments
    MOAI_LUA_SETUP ( MOAIFmodEventParameter, "U" )
 
    printf ( "MOAIFmodEventParamter instance hello!\n" );
 
    return 0;
}
 
//================================================================//
// MOAIFmodEventParamter
//================================================================//
 
//----------------------------------------------------------------//
MOAIFmodEventParameter::MOAIFmodEventParameter () {

	m_EventParameter = FMOD::EventParameter();
 
    // register all classes MOAIFmodEventParamter derives from
    // we need this for custom RTTI implementation
    RTTI_BEGIN
        RTTI_EXTEND ( MOAILuaObject )
 
        // and any other objects from multiple inheritance...
        // RTTI_EXTEND ( MOAIFmodEventParamterBase )
    RTTI_END
}
 
//----------------------------------------------------------------//
MOAIFmodEventParameter::~MOAIFmodEventParameter () {
}
 
//----------------------------------------------------------------//
void MOAIFmodEventParameter::RegisterLuaClass ( MOAILuaState& state ) {
 
    // call any initializers for base classes here:
    // MOAIFmodEventParamterBase::RegisterLuaClass ( state );
 
    // also register constants:
    // state.SetField ( -1, "FOO_CONST", ( u32 )FOO_CONST );
 
    // here are the class methods:
    luaL_Reg regTable [] = {
        { "classEventParameter",     _classEventParameter },
        { NULL, NULL }
    };
 
    luaL_register ( state, 0, regTable );
}
 
//----------------------------------------------------------------//
void MOAIFmodEventParameter::RegisterLuaFuncs ( MOAILuaState& state ) {
 
    // call any initializers for base classes here:
    // MOAIFmodEventParamterBase::RegisterLuaFuncs ( state );
 
    // here are the instance methods:
    luaL_Reg regTable [] = {
		{ "instanceEventParameter", _instanceEventParameter},
		{"disableAutomation", _disableAutomation},
		{"getInfo",  _getInfo },
		{"getMemoryInfo",_getMemoryInfo},
		{"getRange",_getRange},
		{"getSeekSpeed",_getSeekSpeed},
		{"getUserData",_getUserData},
		{"getValue",_getValue},
		{"getVelocity",_getVelocity},
		{"keyOff",_keyOff},
		{"setSeekSpeed",_setSeekSpeed},
		{"setUserData",_setUserData},
		{"setValue",_setValue},
		{"setVelocity",_setVelocity},
        { NULL, NULL }
    };
 
    luaL_register ( state, 0, regTable );
}

FMOD::EventParameter MOAIFmodEventParameter::GetEventParameter() {

	return m_EventParameter;
}