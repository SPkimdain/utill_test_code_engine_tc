//@checker IMPROPER_RANDOM_USAGE

#include <stdlib.h>
#include <time.h>
#define DWORD int
#define BYTE char
int hProvider = 0;

extern int rand();
extern void CryptGenRandom(int, const int, char*);

void T0054func1()
{
	srand( time(NULL) );
	//Base01 - ���̵� ����
	int x = 0;
	x = rand(); //@violation IMPROPER_RANDOM_USAGE

	//Linux Function Test�� ����(srandom)

	const DWORD dwLength = 8;
	BYTE pbBuffer[dwLength] = {};
	//Base02 - CryptGenRandom�� CryptAcquireContext ���� ȣ��	
	CryptGenRandom( hProvider, dwLength, pbBuffer ); //@violation IMPROPER_RANDOM_USAGE

}
