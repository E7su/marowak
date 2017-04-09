#include <iostream.h>
#include <windows.h>

using namespace std;


DWORD WINAPI ThreadProc(CONST LPVOID lpParam)
{
	int* a;
	a = (int*)lpParam;
	for (int i=0;i<*a;i++)
	{
		Sleep(10);
	}
	cout << "thread GO " << *a << endl;
	return 0;
}

void main()
{

	int a = 7;
	int b = 70;
	HANDLE thread1 = CreateThread(NULL,0,ThreadProc,&b,0,NULL);
	HANDLE thread2 = CreateThread(NULL,0,ThreadProc,&a,0,NULL);
	WaitForSingleObject(thread1,INFINITE);
	WaitForSingleObject(thread2,INFINITE);
	CloseHandle(thread1);
	CloseHandle(thread2);
}