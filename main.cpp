#include <iostream>

extern "C" {
	#include <lua.h>
	#include <lauxlib.h> 
    #include <lualib.h>
}

int main(int argc, char** argv) {

	std::string expr;
	
	if (argc == 2) {
		expr = argv[1];

		// buils expression for lua
		expr = "a = (" + expr + ")";
		const char *cexpr = expr.c_str();
		
		lua_State* LS = luaL_newstate();
		luaL_dostring(LS, cexpr);
		lua_getglobal(LS, "a");
		// return the result off the stack
		int i = lua_tointeger(LS, -1);

		// output the answer
		std::cout << " = " << i << "\n";
		// close lua
		lua_close(LS);

	} else {
		std::cout << "Nothing to calculate";
	}

	return 0;
}