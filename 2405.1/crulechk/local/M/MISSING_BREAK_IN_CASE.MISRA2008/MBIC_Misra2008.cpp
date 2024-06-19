//@checker MISSING_BREAK_IN_CASE.MISRA2008
void MBIC_Misra2008()
{
	int x = 0;
	int y = 0;
	switch( x )
	{
	case 0:
	case 1:
	//Base01 - ���̵� ����(���̵� ������ �̽��� ���ɼ��� ����)
	case 2:
	case 3:
		break;
	default:
		//not happen.
		y++;
	}

	switch( x )
	{
	//Base02 - CERT ���� �˶��� �߻��ؾ� �� �κ�
	case 0: 
		y++; //@violation MISSING_BREAK_IN_CASE.MISRA2008 
	case 1:
	case 2:
		break;
	case 4:
		y++;
		break;
	//Base03 - default�� ������ case�� ��� �ش� ���ǿ��� ���ܵ�
	default: //Checking False Alarm
		y++;		
	}
}

//Complex

void T0053func2()
{
	int x = 0;
	int y = 0;
	int z = 0;
	int k = 0;

	switch( x )
	{
	case 0:
		if( y == 0 )
		{
			switch( z )
			{
			//Complex01 - nested switch ���
			case 0: 
				k++; //@violation MISSING_BREAK_IN_CASE.MISRA2008
			case 1:
				break;
			//Complex02 - ������ case��(default�� �ƴ� �Ϲ� case)
			case 2: //Checking False Alarm
				k++;
			}
		}
		break;
	//Complex03 - Ư���� statement���� ������ �ִ°��
	case 1: //Checking False Alaram



	case 2:
		break;
	}
	
}

//C++Support

namespace 
{
	void T0053func9( int index, int value )
	{
		int x = 0;
		int y = 0;
		
		switch( x )
		{
		//C++Support01 - ���ӽ����̽� �� �Լ�
		case 0: 
			y++; //@violation MISSING_BREAK_IN_CASE.MISRA2008 
		case 1:
			break;
		}
	}
	
	namespace nested
	{
		int x = 0;
		int y = 0;

		void T0053func10( int index, int value )
		{	
			switch( x )
			{
			//C++Support02 - nested ���ӽ����̽� �� �Լ�
			case 0: 
				y++; //@violation MISSING_BREAK_IN_CASE.MISRA2008 
			case 1:
				break;
			}
		}
	}
}

class T0053A
{
public:
	int x;
	int y;
	void mfunc1( int index, int value )
	{	
		switch( x )
		{
		//C++Support03 - Ŭ���� �����
		case 0: 
			y++; //@violation MISSING_BREAK_IN_CASE.MISRA2008
		case 1:
			break;
		}
	}

	void mfunc2( int index, int value );
};

void T0053A::mfunc2(int index, int value)
{
	switch( x )
	{
	//C++Support04 - Ŭ���� ���Ǻ�
	case 0: 
		y++; //@violation MISSING_BREAK_IN_CASE.MISRA2008
	case 1:
		break;
	}
}


void T0053func13( int index, int value )
{
	int x = 0;
	int y = 0;

	try
	{
		switch( x )
		{
		//C++Support08 - try��		
		case 0: 
			y++; //@violation MISSING_BREAK_IN_CASE.MISRA2008
		case 1:
			break;
		}

		if( y >= 10 )
		{
			throw index;
		}

	}
	catch( int exp )
	{
		switch( x )
		{
		//C++Support09 - catch��		
		case 0: 
			y++; //@violation MISSING_BREAK_IN_CASE.MISRA2008
		case 1:
			break;
		}		
	}
}
