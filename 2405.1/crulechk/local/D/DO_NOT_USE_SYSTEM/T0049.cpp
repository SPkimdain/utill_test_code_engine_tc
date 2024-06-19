//@checker DO_NOT_USE_SYSTEM

#define SYSTEM_CMD( x ) system( x )

//Base
extern int system (const char* command);

void T0049func1()
{
	//Base01 - ���̵� ����
	system("ls -al"); //@violation DO_NOT_USE_SYSTEM
}

//Complex

void assert( int x )
{
	if( x )
	{
		x++;
	}
	else
	{
		x--;
	}
}

void T0049func2()
{
	int x = 0;

	//Complex01 - �Լ� �Ķ���� �������� system ȣ��
	assert( system( "ls -al" ) ); //@violation DO_NOT_USE_SYSTEM

	//Complex02 - ������ �������� system ȣ��
	if( system( "ls -al" ) == -1 ) //@violation DO_NOT_USE_SYSTEM
	{
		x++;
	}

	//Complex03 - ��ũ�� ���
	SYSTEM_CMD( "ls -al " ); //@violation DO_NOT_USE_SYSTEM
}
