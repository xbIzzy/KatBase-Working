#pragma once

enum TitleId : std::uintptr_t
{
	BOOT_UP = 0x00000000,
	DASHBOARD = 0xFFFE07D1,
	FREESTYLEDASH = 0xF5D20000,
	COD_CLASSIC = 0x584109CA,
	COD_WORLD_AT_WAR = 0x4156081C,
	COD_MODERN_WARFARE = 0x415607E6,
	COD_MODERN_WARFARE_2 = 0x41560817,
	COD_MODERN_WARFARE_3 = 0x415608CB,
	COD_BLACK_OPS_1 = 0x41560855,
	COD_BLACK_OPS_2 = 0x415608C3,
	COD_BLACK_OPS_3 = 0x4156091D,
	COD_GHOSTS = 0x415608FC,
	COD_ADVANCED_WARFARE = 0x41560914,
	CSGO = 0x5841125A,
	DESTINY = 0x415608F8,
	GTAV = 0x545408A7
};

typedef void(*XNotifyQueueUI_t)(std::uintptr_t type, std::uintptr_t userIndex, std::uintptr_t priority, LPCWSTR string, std::uint64_t param);
typedef std::uintptr_t(*XamGetCurrentTitleId_t)(void);

extern XNotifyQueueUI_t pXNotifyQueueUI;
extern XamGetCurrentTitleId_t pXamGetCurrentTitleId;

std::uint32_t ResolveImport(const char* importName, std::int32_t index);
void XNotify(const char* text, XNOTIFYQUEUEUI_TYPE icon = XNOTIFYUI_TYPE_PREFERRED_REVIEW);

char* va(const char* fmt, ...);
char* concat(const char* text, ...);

void WriteMemory(std::uint32_t Address, BYTE Data[], std::int32_t size);
BYTE* ReadMemory(std::uint32_t Address, std::int32_t size);

extern XINPUT_STATE Buttons;
bool KeyIsDown(XINPUT_STATE xState, short button);

typedef QWORD(*StubCallback)(...);

class MinHook_t
{
	unsigned long* address,
		* saveStub,
		destination,
		originalStub[4];

public:
	MinHook_t() {};
	MinHook_t(unsigned long address, unsigned long destination, bool stub);

	void Start();
	void Stop();
	void Clean();
	StubCallback Stub;
};

extern MinHook_t MinHook[10];


void StopHooks();
void CleanHooks();
void StartHooks();

