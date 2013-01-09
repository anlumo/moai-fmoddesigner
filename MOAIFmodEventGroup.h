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
class MOAIFmodEventGroup : public virtual MOAILuaObject {
private:
	
	FMOD::EventGroup* eventGroup;

	static int		_freeEventData		( lua_State* L );
	static int		_getEvent			( lua_State* L );
	static int		_getEventByIndex	( lua_State* L );
	static int		_getGroup			( lua_State* L );
	static int		_getGroupByIndex	( lua_State* L );
	static int		_getInfo			( lua_State* L );
	static int		_getMemoryInfo		( lua_State* L );
	static int		_getNumEvents		( lua_State* L );
	static int		_getNumGroups		( lua_State* L );
	static int		_getNumProperties	( lua_State* L );
	static int		_getParentGroup		( lua_State* L );
	static int		_getParentProject	( lua_State* L );
	static int		_getProperty		( lua_State* L );
	static int		_getPropertyByIndex	( lua_State* L );
	static int		_getState			( lua_State* L );
	static int		_getUserData		( lua_State* L );
	static int		_loadEventData		( lua_State* L );
	static int		_setUserData		( lua_State* L );

public:
	
	DECL_LUA_FACTORY ( MOAIFmodEventGroup )

	//----------------------------------------------------------------//
					MOAIFmodEventGroup			();
					MOAIFmodEventGroup			(FMOD::EventGroup* eventGroup);
					~MOAIFmodEventGroup			();
	void			RegisterLuaClass	( MOAILuaState& state );
	void			RegisterLuaFuncs	( MOAILuaState& state );
};

#endif