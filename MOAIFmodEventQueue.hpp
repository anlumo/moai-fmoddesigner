#include <moaicore/MOAILUA.h>
#include <fmod_event.hpp>

namespace FMOD {
	class System;
	class Sound;
	class Channel;
	class ChannelGroup;
	class EventQueue;
};

//================================================================//
// MOAIFoo
//================================================================//
/**	@name	MOAIFoo
	@text	Example class for extending Moai using MOAILuaObject.
			Copy this object, rename it and add your own stuff.
			Just don't forget to register it with the runtime
			using the REGISTER_LUA_CLASS macro (see moaicore.cpp).
*/
class MOAIFmodEventQueue :
	public MOAIGlobalClass < MOAIFmodEventQueue, MOAILuaObject > {
private:
	//----------------------------------------------------------------//
	static int		_classFmodEventQueue	( lua_State* L );
	static int		_instanceFmodEventQueue	( lua_State* L );
	
	static int						add						( lua_State* L );
	static int						clear					( lua_State* L );
	static int						dump					( lua_State* L );
	static int						excludeDuckingCategory	( lua_State* L );
	static int						findFirstEntry			( lua_State* L );
	static int						findNextEntry			( lua_State* L );
	static int						getMemoryInfo			( lua_State* L );
	static int						getPaused				( lua_State* L );
	static int						getUserData				( lua_State* L );
	static int						includeDuckingCategory	( lua_State* L );
	static int						release					( lua_State* L );
	static int						remove					( lua_State* L );
	static int						removeHead				( lua_State* L );
	static int						setCallback				( lua_State* L );
	static int						setPaused				( lua_State* L );
	static int						setUserData				( lua_State* L );

public:
	FMOD::EventQueue m_EventQueue;
	DECL_LUA_FACTORY ( MOAIFmodEventQueue )

	//----------------------------------------------------------------//
					MOAIFmodEventQueue		();
					~MOAIFmodEventQueue		();
	void			RegisterLuaClass		( MOAILuaState& state );
	void			RegisterLuaFuncs		( MOAILuaState& state );

	FMOD::EventQueue GetEventQueue();
};