//@checker DO_NOT_USE_SIZEOF_ON_ARRAY_PARAM

#define CHECK_SIZE( Y ) sizeof( Y )
typedef unsigned int size_t;

//Base

void func1( int arr[] )
{
	int x = 0;
	size_t size;
	
	//Base01 - ���̵� ����
	int i;
	for( i = 0; i< sizeof( arr ) / sizeof( arr[0] ); i++ ) //@violation DO_NOT_USE_SIZEOF_ON_ARRAY_PARAM
	{
		x++;
	}

	//Base02 - �迭 ��ü sizeof( 01�� �и� �׽�Ʈ )
	size = sizeof( arr ); //@violation DO_NOT_USE_SIZEOF_ON_ARRAY_PARAM

	//Base03 - �迭 ��� sizeof( 01�� �и� �׽�Ʈ )
	size = sizeof( arr[0] ); //Checking False Alarm
}


//Complex

void func2( int arr[], int arr2[][10] )
{
	int x = 0;
	size_t size;

	//Complex01 - ���� �迭
	size = sizeof( arr2 ); //@violation DO_NOT_USE_SIZEOF_ON_ARRAY_PARAM

	//Complex02 - ������ �����׿��� ���
	if( x == 1 && sizeof( arr2 ) > 10 ) //@violation DO_NOT_USE_SIZEOF_ON_ARRAY_PARAM
	{
		x++;
	}

	//Complex03 - ���ռ�����
	size = 3 + 5 + ( x - 2 / ( sizeof( arr ) ) ); //@violation DO_NOT_USE_SIZEOF_ON_ARRAY_PARAM

	//Complex04 - ��ũ�� �̿�
	size = CHECK_SIZE( 5 );

}

//C++Support


namespace 
{
	int x = 0;
	size_t size;

	void func2( int arr[] )
	{
		//C++Support01 - ���ӽ����̽� �� �Լ�
		size = sizeof( arr ); //@violation DO_NOT_USE_SIZEOF_ON_ARRAY_PARAM
	}
	
	namespace nested
	{
		void func3( int arr[] )
		{
			//C++Support02 - nested ���ӽ����̽� �� �Լ�
			size = sizeof( arr ); //@violation DO_NOT_USE_SIZEOF_ON_ARRAY_PARAM
		}
	}
}



class T0043A
{
public:
	int x;
	size_t size;

	void mfunc1( int arr[] )
	{
		//C++Support03 - Ŭ���� �����
		size = sizeof( arr ); //@violation DO_NOT_USE_SIZEOF_ON_ARRAY_PARAM
	}

	void mfunc2( int arr[] );
};

void T0043A::mfunc2( int arr[] )
{
	//C++Support04 - Ŭ���� ���Ǻ�
	size = sizeof( arr ); //@violation DO_NOT_USE_SIZEOF_ON_ARRAY_PARAM
}

