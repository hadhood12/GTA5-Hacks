// dllmain.cpp : Defines the entry point for the DLL application.
#include "stdafx.h"

HMODULE g_handle;

// ReSharper disable once CppInconsistentNaming
BOOL APIENTRY DllMain(HMODULE hmodule, const DWORD ul_reason_for_call, LPVOID /*lp_reserved*/)
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
		g_handle = hmodule;
		register_script(g_handle, script_main);
		break;
    case DLL_THREAD_ATTACH:
		break;
    case DLL_THREAD_DETACH:
		break;
    case DLL_PROCESS_DETACH:
		remove_script(g_handle);
		break;
    default:
		break;
    }
    return TRUE;
}

