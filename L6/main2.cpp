#include <iostream.h>
#include <windows.h>

using namespace std;

HANDLE hMutex;

DWORD WINAPI ThreadProc(CONST LPVOID lpParam)
{
	char* a;
	a = (char*)lpParam;
	for (int j=0;j<5;j++)
	{
		WaitForSingleObject(hMutex, INFINITE);
		for (int i=0;i<10;i++)
		{
			cout << a;
			Sleep(10);
		}
		cout << endl;
		ReleaseMutex(hMutex);
	}
	return 0;
}

void main()
{

	char a[10] = "+";
	char b[10] = "0";
	hMutex = CreateMutex(NULL,false,NULL);
	HANDLE thread1 = CreateThread(NULL,0,ThreadProc,b,0,NULL);
	HANDLE thread2 = CreateThread(NULL,0,ThreadProc,a,0,NULL);
	WaitForSingleObject(thread1,INFINITE);
	WaitForSingleObject(thread2,INFINITE);
	CloseHandle(thread1);
	CloseHandle(thread2);
	CloseHandle(hMutex);
}