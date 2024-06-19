
//@checker MISSING_VALIDATION_OF_ARRAY_INDEX

#define CHECK_BOUNDARY_VALUE( index, boundary ) index < boundary

//Base

void func1( int index, int value )
{
	int arr[30];

	//Base01 - ���̵� ����
	arr[index] = value; //@violation MISSING_VALIDATION_OF_ARRAY_INDEX
}

void func2( int index, int index2, int value, int& value2 )
{
	int arr[10];
	
	//Base02 - ���̵� ����2
	arr[index] = value; //@violation MISSING_VALIDATION_OF_ARRAY_INDEX

	//Base03 - ������
	value2 = arr[index2]; //@violation MISSING_VALIDATION_OF_ARRAY_INDEX
}


int func3( int arr[], int index, int index2, int value )
{
	//Base04 - 2�� ���(���� ����, �ٸ� ����)
	return arr[index] + //@violation MISSING_VALIDATION_OF_ARRAY_INDEX
		arr[index2]; //@violation MISSING_VALIDATION_OF_ARRAY_INDEX
}

void func4( int arr[][10], int index )
{
	//Base05 - 2���� �迭(�պκ�)
	arr[index][0] = 10; //@violation MISSING_VALIDATION_OF_ARRAY_INDEX
	
	//Base06 - 2���� �迭(�޺κ�)
	arr[0][index] = 10;
}


//Complex

void func5( int index, int index2, int value )
{
	int arr[5][10];

	//Complex01 - ������ �迭���� �� ������ ������ �˻�(ù��° ����)
	if( index < 5 )
	{
		arr[index][index2] = value;
	}

	//Complex02 - ������ �迭���� �� ������ ������ �˻�(�ι�° ����)
	if( index2 < 10 )
	{
		arr[index][index2] = value; //@violation MISSING_VALIDATION_OF_ARRAY_INDEX
	}
}

int getSize( bool flag)
{
	//�����Ϸ� ����ȭ ���� �ʵ��� ���⼺ �ο�
	int x = 1;
	if( flag )
	{
		return x + 9;
	}
	else
	{
		return x + 5;
	}

}

void func6( int index, int value )
{
	int arr[10];
	//Complex03 - �˻翡 ���Ǵ� �� ���İ��� �Լ��� ���ϰ�
	if( index < getSize( true ) )
	{
		arr[index] = value; //Checking False Alarm
	}
}

void func7( int index, int value )
{
	int arr[10];
	//Complex04 - ������ ����( ��ȣ + ���� Operand ��ġ )
	if( ( 1 + index ) < 11 )
	{
		arr[index] = value; //Checking False Alarm
	}
}

void func8( int index, int value )
{
	int arr[10];
	//Complex05 - ��ũ��
	if( CHECK_BOUNDARY_VALUE( index, 10 ) )
	{
		arr[index] = value; //Checking False Alarm
	}
}

void func14( int index, int value )
{
	int arr[10];
	//Complex06 - ������ ��� ��� ����
	if( index >= 10 )
	{
		return;
	}

	arr[index] = value; //Checking False Alarm
}

void func15( int index, int value )
{
	int arr[10];
	//Complex07 - �˻縦 ������ �ƹ��͵� ���� ����
	if( index >= 10 )
	{
		int x = 0;
	}

	arr[index] = value; //@violation MISSING_VALIDATION_OF_ARRAY_INDEX
}

//C++Support

namespace 
{
	void func9( int index, int value )
	{
		int arr[10];
		//C++Support01 - ���ӽ����̽� �� �Լ�
		arr[index] = value; //@violation MISSING_VALIDATION_OF_ARRAY_INDEX
	}
	
	namespace nested
	{
		void func10( int index, int value )
		{
			int arr[10];
			//C++Support02 - nested ���ӽ����̽� �� �Լ�
			arr[index] = value; //@violation MISSING_VALIDATION_OF_ARRAY_INDEX
		}
	}
}



class T0037A
{
public:
	void mfunc1( int index, int value )
	{
		int arr[10];
		//C++Support03 - Ŭ���� �����
		arr[index] = value; //@violation MISSING_VALIDATION_OF_ARRAY_INDEX
	}

	void mfunc2( int index, int value );
};

void T0037A::mfunc2(int index, int value)
{
	int arr[10];
	//C++Support04 - Ŭ���� ���Ǻ�
	arr[index] = value; //@violation MISSING_VALIDATION_OF_ARRAY_INDEX
}

void func13( int index, int value )
{
	int arr[10];

	try
	{
		//C++Support09 - try��
		arr[index] = value; //@violation MISSING_VALIDATION_OF_ARRAY_INDEX

		if( index >= 10 )
		{
			throw index;
		}

		//C++Support10 - try������ ��ȿ�� ����(������ ������ catch��)
		//arr[index] = value; //Checking False Alarm
	}
	catch( int exp )
	{
		int x = exp;
	}
}
