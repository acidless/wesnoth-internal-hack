#include <Windows.h>
#include <iostream>
#include "HackModuleHandler.h"
#include "MapHack.h";

DWORD* player;
DWORD* game;
DWORD* gold;
char gold_bytes[4] = { 0, };


DWORD ori_call_address = 0x5F36E0;
DWORD return_address = 0x005F71DE;

__declspec(naked) void codecave() {

	__asm {
		pushad
	}

	player = (DWORD*)0x17FED3C;
	game = (DWORD*)(*player + 0xA90);
	gold = (DWORD*)(*game + 0x274);

	sprintf_s(gold_bytes, 4, "%d", *gold);

	__asm {
		popad
		pushad
		mov eax, dword ptr ds:[edx]
		mov bl, gold_bytes[0]
		mov byte ptr ds:[eax], bl
		mov bl, gold_bytes[1]
		mov byte ptr ds : [eax + 1] , bl
		mov bl, gold_bytes[2]
		mov byte ptr ds : [eax + 2] , bl
		mov bl, gold_bytes[3]
		mov byte ptr ds : [eax + 3] , bl
		
		popad
		call ori_call_address
		jmp return_address
	}
}

BOOL WINAPI DllMain(HINSTANCE hInsDll, DWORD reason, void* pReserved) {
	if (reason == DLL_PROCESS_ATTACH) {
		std::vector<HackModule*> hackModules = { new MapHack() };
		auto* pHMH = new HackModuleHandler(hackModules);
		pHMH->initModules();
	}

	return true;
}