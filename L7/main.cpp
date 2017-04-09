#include <iostream.h>
#include <windows.h>

using namespace std;

HANDLE Semaphore;
HANDLE hMutex;

char buff;
boolean ifread;

DWORD WINAPI Proc(CONST LPVOID lpParam)
{
	bool ok;
	DWORD dw;
	ok = true;
	while (ok)
	{
		dw = WaitForSingleObject(Semaphore,0L);
		switch (dw)
		{
			case WAIT_OBJECT_0: {
			WaitForSingleObject(hMutex, INFINITE);
			cout << "Thread No" << GetCurrentThreadId() << " capture succeeded" << endl;
			ReleaseMutex(hMutex);
			Sleep(2);
			ReleaseSemaphore(Semaphore,1,NULL);
			ok = false;
			break; }
			
			case WAIT_TIMEOUT: {
			WaitForSingleObject(hMutex, INFINITE);
			cout << "Thread No" << GetCurrentThreadId() << " capture not succeeded" << endl;
			ReleaseMutex(hMutex);
			break; }
		}
	}
	return 0;
}


void main()
{
	int i;
	HANDLE threads[10];
	Semaphore = CreateSemaphore(NULL,5,5,NULL);
	hMutex = CreateMutex(NULL,false,NULL);
	for(i = 0; i<10; i++)
	{
		threads[i] = CreateThread(NULL,0,Proc,0,0,NULL);
	}
	WaitForMultipleObjects(10,threads,TRUE,INFINITE);
	for(i = 0; i<10; i++)
	{
		CloseHandle(threads[i]);
	}
	CloseHandle(Semaphore);
	CloseHandle(hMutex);
	
}