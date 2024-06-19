//@checker EXCESSIVE_STACK_DEPTH

//Base

void T0078func1()
{
	//Base01 - ���̵� ����
	char buf[65537]; //@violation EXCESSIVE_STACK_DEPTH	
}

//Complex

typedef struct _ComplexStruct
{
	int x;
	long y;
	float z;
} ComplexStruct;

void T0078func2()
{
	int x = 5;
	int bufxxx[3000] = {x + 1};
	int bufxx[3000] = {5};
	int bufx[3000] = {0, 1, 2, 3, 5};
	//Complex01 - ��������� ���� 65536�̻�	
	int buf[30000] = {0, x}; //@violation EXCESSIVE_STACK_DEPTH
}

void T0078func3()
{
	//Complex02 - Ư�� �ڷ����� ��������� ���� 65536 �̻�
	ComplexStruct cs[30000]; //@violation EXCESSIVE_STACK_DEPTH
}

void T0078func4()
{
	//Complex03 - 2���� �迭 ũ���� ���� 65536 �̻�
	char buf[10][6560]; //@violation EXCESSIVE_STACK_DEPTH
}

void T0078func5()
{
	//Complex04 - �ڷ��� �� 2���� �迭�� ���� ���� ������ ���� 65536 �̻�
	ComplexStruct cs[10][3000]; //@violation EXCESSIVE_STACK_DEPTH
}

//C++Support

class T0078A
{
public:
	//C++Support01 - �ʵ� ������ ũ�Ⱑ 65535 �̻�
	char buf[65537]; //@violation EXCESSIVE_STACK_DEPTH

	void mFunc1()
	{
		return;
	}
};

class T0078B
{
public:
	char x;
};

void T0078func6()
{
	//C++Support02 - Ŭ���� Ÿ���� ������ ���� 65536 �̻�
	T0078B buf[65536]; //@violation EXCESSIVE_STACK_DEPTH	
}

template<typename T>
class T0078C
{
public:
	//C++Support08 - 81�� ���ο� ���� int buf[30000];¥�� �ڵ尡 �����ǹǷ� �ش� ��ġ���� �˶� �߻�
	T buf[30000]; //@violation EXCESSIVE_STACK_DEPTH
};

void T0078func7()
{
	//C++Support03 - ���ø��� ���� �������� Ư�� ���� �ʵ� ������ ���� 65535�̻�
	T0078C<int> t; //@violation EXCESSIVE_STACK_DEPTH
};

