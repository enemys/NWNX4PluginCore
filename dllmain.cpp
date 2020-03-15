// dllmain.cpp : Defines the entry point for the DLL application.
#include <Windows.h>
#include "SamplePlugin.h"

SamplePlugin g_Plugin;

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        DisableThreadLibraryCalls(hModule);
        break;
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

NWNX4PluginBase*
WINAPI
GetPluginPointerV2(
)
/*++
Routine Description:
    This routine returns a pointer to the NWNX4 plugin instance that is
    implemented by the module.
Arguments:
    None.
Return Value:
    A pointer the plugin object is returned on success, else NULL is reutrned.
Environment:
    User mode.
--*/
{
    return &g_Plugin;
}
