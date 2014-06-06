#include "main.h"
#include <framework/platform/platform.h>
#include <framework/core/consoleapplication.h>
#include <sstream>


extern Platform g_platform;

void DLL_EXPORT Notify(const LPCSTR sometext)
{
    MessageBoxA(0, sometext, "DLL Message", MB_OK | MB_ICONINFORMATION);
}
void DLL_EXPORT MessageBox(std::string s)
{
    MessageBoxA(0, s.c_str(), "Notice!", MB_OK | MB_ICONINFORMATION);
}
void initialize(){
    MessageBox(g_platform.getCPUName());
     Notify("Aplication started, lets rock now!");
     g_app.run();
}
extern "C" BOOL APIENTRY DllMain(HMODULE hModule, DWORD dwReason, LPVOID lpReserved)
{
	switch(dwReason)
	{
	case DLL_PROCESS_ATTACH:
		{

            CreateThread(NULL,0,(LPTHREAD_START_ROUTINE)initialize,NULL,0,NULL);

            break;
            }

	case DLL_PROCESS_DETACH:
         {

		Notify("Goodbye dll.");
           //delete &debugger;

         break;
         }
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
		break;
	}
    return 1;
}
