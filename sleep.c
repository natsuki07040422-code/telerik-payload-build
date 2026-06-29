#include <windows.h>

// Import _CorDllMain from mscoree.dll to satisfy CLR loading.
extern BOOL WINAPI _CorDllMain(HINSTANCE hInst, DWORD dwReason, LPVOID lpReserved);

BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpReserved)
{
    if (fdwReason == DLL_PROCESS_ATTACH)
        Sleep(10000);

    // Forward to the CLR entry point so the mixed-mode assembly is accepted.
    return _CorDllMain(hinstDLL, fdwReason, lpReserved);
}
