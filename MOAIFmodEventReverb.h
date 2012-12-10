#pragma once
#include <moaicore/moaicore.h>
#include "fmod.hpp"

class MOAIFmodEventReverb:
	public virtual MOAINode
{
private:
	FMOD::Reverb* mReverb;

	static bool FMOD_CHECK(FMOD_RESULT result);

	static int _get3DAttributes(lua_State* L);
	static int _getActive(lua_State* L);
	static int _getMemoryInfo(lua_State* L);
	static int _getProperties(lua_State* L);
	static int _getUserData(lua_State* L);
	static int _set3DAttributes(lua_State* L);
	static int _setActive(lua_State* L);
	static int _setProperties(lua_State* L);
	static int _setUserData(lua_State* L);
public:
	friend class MOAIFmodEx;

	DECL_LUA_FACTORY ( MOAIFmodEventReverb )
	DECL_ATTR_HELPER ( MOAIFmodEventReverb )

	MOAIFmodEventReverb(void);
	void RegisterLuaClass ( MOAILuaState& state );
	void RegisterLuaFuncs ( MOAILuaState& state );

	bool IsActive(bool* active);
	bool SetActive(bool active);
	bool GetProperties(FMOD_REVERB_PROPERTIES* props);
	bool SetProperties(FMOD_REVERB_PROPERTIES* props);
	bool Get3DAttributes(FMOD_VECTOR* position, float* mindistance, float* maxdistance);
	bool Set3DAttributes(FMOD_VECTOR* position, float mindistance, float maxdistance);


	~MOAIFmodEventReverb(void);
};

