﻿#ifndef DRAGONBONES_RENDERER_DBCC_LUA_UTILS_H
#define DRAGONBONES_RENDERER_DBCC_LUA_UTILS_H
#if 0
#include "dbccMacro.h"
#include "DBCCArmature.h"

#if (DRAGON_BONES_ENABLE_LUA == 1)

extern "C" {
#include "lua.h"
}

NAME_SPACE_DRAGON_BONES_BEGIN

#define LUA_PUSH_BASE_KV(L, key, value, func) do \
{ \
    lua_pushstring(L, key); \
    func(L, value); \
    lua_rawset(L, -3); \
} while(0)

class DBCCLuaUtils
{
public:
    static void pushEventData(EventData *eventData, DBCCArmatureNode *armatureNode);

private:
    template<class T>
    static void pushObjectKV(lua_State *state, const char *key, T* value, const char* type);

    DRAGON_BONES_DISALLOW_COPY_AND_ASSIGN(DBCCLuaUtils);
};
NAME_SPACE_DRAGON_BONES_END
#endif
#endif // !DRAGON_BONES_ENABLE_LUA
#endif // DRAGONBONES_RENDERER_DBCC_LUA_UTILS_H
