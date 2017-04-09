#include <iostream.h>
#include <windows.h>

using namespace std;

HANDLE hMutex;

char buff;
boolean ifread;

DWORD WINAPI Writer(CONST LPVOID lpParam)
{
	char* a;
	a = (char*)lpParam;
	int j = 0;
	while(j<11)
	{
		if(ifread == true)
		{
			WaitForSingleObject(hMutex, INFINITE);
			cout << "I write: " << a[j];
			buff = a[j];
			cout << endl;
			ifread = false;
			j++;
			ReleaseMutex(hMutex);
			Sleep(10);
			
		}
	}
	return 0;
}

DWORD WINAPI Reader(CONST LPVOID lpParam)
{
	char* a;
	a = (char*)lpParam;
	int j = 0;
	while(j<11)
	{
		if(ifread == false)
		{
			WaitForSingleObject(hMutex, INFINITE);		
			cout << "               I read: " << buff;
			cout << endl;
			ifread = true;
			j++;
			ReleaseMutex(hMutex);
			Sleep(10);
		}
	}
	return 0;
}

void main()
{

	char a[11] = "Hello_world";
	ifread = true;
	hMutex = CreateMutex(NULL,false,NULL);
	HANDLE thread1 = CreateThread(NULL,0,Writer,a,0,NULL);
	HANDLE thread2 = CreateThread(NULL,0,Reader,0,0,NULL);
	WaitForSingleObject(thread1,INFINITE);
	WaitForSingleObject(thread2,INFINITE);
	CloseHandle(thread1);
	CloseHandle(thread2);
	CloseHandle(hMutex);
}