#include "MapHack.h"
#include <Windows.h>

#define COUNT_BYTES_TO_REWRITE 11
#define HOOK_ADDRESS 0x006D79B9

void MapHack::execute() const {
	DWORD old_protect;
	unsigned char* hook_location = (unsigned char*)HOOK_ADDRESS;
	unsigned char new_bytes[COUNT_BYTES_TO_REWRITE] = { NOP, NOP, NOP, NOP, NOP, NOP, 0x83, 0x0E, 0xFF, NOP, NOP };

	VirtualProtect((void*)hook_location, COUNT_BYTES_TO_REWRITE, PAGE_EXECUTE_READWRITE, &old_protect);
	for (int i = 0; i < sizeof(new_bytes); i++) {
		*(hook_location + i) = new_bytes[i];
	}
}


