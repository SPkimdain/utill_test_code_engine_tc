//@checker DO_NOT_USE_SIZEOF_ON_PTR

typedef int INTTYPE;
typedef INTTYPE *INTTYPE_PTR;

//Base

void T0057func1()
{
	int *arr;
	int x = 0;
	//Base01 - ���̵� ����
	if( sizeof( arr ) < 10 ) //@violation DO_NOT_USE_SIZEOF_ON_PTR
	{
		x++;
	}
}

//Complex

void T0057func2()
{
	int **arr;
	int x = 0;
	int size = 0;
	//Complex01 - ���������Ϳ� 1���� ������ �� ���
	if( sizeof( *arr ) < 10 ) //@violation DO_NOT_USE_SIZEOF_ON_PTR
	{
		x++;
	}

	//Complex02 - ���۷����� ���� sizeof �� ���
	if( sizeof( &x ) < 10 ) //@violation DO_NOT_USE_SIZEOF_ON_PTR
	{
		x++;
	}

	//Complex03 - ���������� sizeof ���
	size = 5 + x + ( sizeof( arr ) + 10 ); //@violation DO_NOT_USE_SIZEOF_ON_PTR

	INTTYPE_PTR z;
	//Complex04 - typedef ������ Ÿ�� �̿�
	if( sizeof( z ) == 10 ) //@violation DO_NOT_USE_SIZEOF_ON_PTR
	{
		x++;
	}

	//Complex05 - ���� ���ú��� �迭�� ���(�ش� ��츦 sizeof �� ��� �������� ���� ����)
	char* arr2[32];
	if( sizeof( arr2 ) == 128 ) //Checking False Alarm
	{
		x++;
	}
}
