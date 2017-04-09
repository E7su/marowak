#include <iostream>
#include <windows.h>

using namespace std;

DWORD WINAPI ThreadProc(CONST LPVOID lpParam)
{
	int* something;
	something = (int*)lpParam;
	for (int i=0;i<*something;i++)
	{
		cout << "thread1 GO" << endl;
	}
	return 0;
}

void main()
{
	int* p;
	int a;
	a = 3;
	p = &a;
	HANDLE thread1 = CreateThread(NULL,0,ThreadProc,p,0,NULL);
	WaitForSingleObject(thread1,INFINITE);
	CloseHandle(thread1);
}
