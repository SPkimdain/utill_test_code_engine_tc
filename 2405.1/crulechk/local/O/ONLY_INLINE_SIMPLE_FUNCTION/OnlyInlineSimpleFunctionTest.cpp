//@checker ONLY_INLINE_SIMPLE_FUNCTION 

//�⺻�ɼ����� ���μ� 15��, ����15���� �Ѿ�� �ȵǴ� ������ ��

class OISF
{
	int OISF_func1( int x )
	{
		int y = x + 10;
		return y;
	}
	
	//���μ� ����
	void OISF_func2( int x ) //@violation ONLY_INLINE_SIMPLE_FUNCTION
	{
		if( x > 1 &&
			x != 10 &&
			x != 15 &&
			x != 20 &&
			x != 30
			)
		{
			int y = x * x;
			if( y > 1 &&
				y != 10 &&
				y != 15 &&
				y != 20 &&
				y != 30 &&
				y != 40 &&
				y != 50 &&
				y != 60
				)
			{
				int z = y * y;
			}
		}
		
	}

	void OISF_func3( int offset );
};

//statements ����
inline void OISF::OISF_func3( int offset ) //@violation ONLY_INLINE_SIMPLE_FUNCTION
{
	int x = 0; int y = 3; int z = 5; int a = 10; int b = 15; int c = 20;
	if( x + offset == y )
	{
		x += offset; y += offset; z += offset; a += x; b += y; c += z;
	}
}
