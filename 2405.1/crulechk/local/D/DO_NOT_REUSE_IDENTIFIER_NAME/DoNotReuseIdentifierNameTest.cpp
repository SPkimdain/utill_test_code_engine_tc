//@checker DO_NOT_REUSE_IDENTIFIER_NAME

// 1. �Լ���, �󺧸�, enum �����, ������, �Լ� ���ڸ�, �±׸�, �ʵ�� == �Լ���, �󺧸�, enum �����, ������, �Լ� ���ڸ�, �±׸�, �ʵ��

extern int globalExternVar;

int globalVar2;

void DNRIN_externTestFunct();

void DNRIN_externTestFunct() { //It's ok.
  int globalExternVar = 120; //It's ok.
  int etf = 10;
}

void DNRIN_func() //@y-violation DO_NOT_REUSE_IDENTIFIER_NAME
{
	char DNRIN_variableName = 1; //@y-violation DO_NOT_REUSE_IDENTIFIER_NAME

	union DNRIN_tagName //@y-violation DO_NOT_REUSE_IDENTIFIER_NAME
	{
		int x;
		int y;
		int DNRIN_fieldName; //@y-violation DO_NOT_REUSE_IDENTIFIER_NAME
	};
}

//�ʵ�� == �Լ���
void DNRIN_fieldName() //@violation DO_NOT_REUSE_IDENTIFIER_NAME
{
	return;
}

//�±׸� == �Լ���
void DNRIN_tagName() //@violation DO_NOT_REUSE_IDENTIFIER_NAME
{
	//���� == ����
	int DNRIN_variableName = 5; //@violation DO_NOT_REUSE_IDENTIFIER_NAME
//�ʵ�� == �󺧸�
DNRIN_fieldName: //@violation DO_NOT_REUSE_IDENTIFIER_NAME
	return;
}

//���� == �Լ�
int DNRIN_variableName() //@violation DO_NOT_REUSE_IDENTIFIER_NAME
{
//���� == ��
DNRIN_variableName: //@violation DO_NOT_REUSE_IDENTIFIER_NAME
	int xyz = 10;
//�±� == ��
DNRIN_tagName: //@violation DO_NOT_REUSE_IDENTIFIER_NAME
	return xyz;
}

void DNRIN_func2()
{
//�Լ� == ��
DNRIN_func: //@violation DO_NOT_REUSE_IDENTIFIER_NAME

DNRIN_labelName: //@y-violation DO_NOT_REUSE_IDENTIFIER_NAME
	struct DNRIN_StructName //@y-violation DO_NOT_REUSE_IDENTIFIER_NAME
	{
		int x2;
		int y2;
	} str;

	enum EnumList
	{
		DNRIN_first, //@y-violation DO_NOT_REUSE_IDENTIFIER_NAME
		//�Լ� == enum ���
		DNRIN_func, //@violation DO_NOT_REUSE_IDENTIFIER_NAME
		enumTest, //@y-violation DO_NOT_REUSE_IDENTIFIER_NAME
		//���� == enum���
		DNRIN_variableName, //@violation DO_NOT_REUSE_IDENTIFIER_NAME
		//�±� == enum���
		DNRIN_tagName, //@violation DO_NOT_REUSE_IDENTIFIER_NAME
		//�ʵ� = enum���
		DNRIN_fieldName //@violation DO_NOT_REUSE_IDENTIFIER_NAME
	};

}

//�±׸� == �Լ���
void DNRIN_StructName() //@violation DO_NOT_REUSE_IDENTIFIER_NAME
{
	//�ʵ�� == ������
	char DNRIN_fieldName ; //@violation DO_NOT_REUSE_IDENTIFIER_NAME
	//�±׸� == ������
	int DNRIN_tagName; //@violation DO_NOT_REUSE_IDENTIFIER_NAME
//�±׸� == �󺧸�
DNRIN_StructName: //@violation DO_NOT_REUSE_IDENTIFIER_NAME
	return;
}

//enum��� == �Լ�
void DNRIN_first() //@violation DO_NOT_REUSE_IDENTIFIER_NAME
{
	//�ʵ�� == �±׸�
	union DNRIN_fieldName //@violation DO_NOT_REUSE_IDENTIFIER_NAME
	{
		int xxx;
		int yyy;
	};

	//�±׸� == �±׸�
	struct DNRIN_tagName //@violation DO_NOT_REUSE_IDENTIFIER_NAME
	{
		int k;
		char y3;
	};
	//���� == �±�
	struct DNRIN_variableName //@violation DO_NOT_REUSE_IDENTIFIER_NAME
	{
		int xx1;
		int yy1;
	};

	struct StructTest3
	{
		int xxx2;
		//���� == �ʵ�
		char DNRIN_variableName; //@violation DO_NOT_REUSE_IDENTIFIER_NAME
	};
	return;
}

//�� == �Լ�
void DNRIN_labelName() //@violation DO_NOT_REUSE_IDENTIFIER_NAME
{
	//enum��� == ����
	int DNRIN_first; //@violation DO_NOT_REUSE_IDENTIFIER_NAME
	//enum��� == ��
DNRIN_first: //@violation DO_NOT_REUSE_IDENTIFIER_NAME

	return;
}

//���� == �Լ����ڸ�
void DNRIN_func3( short DNRIN_variableName ) //@violation DO_NOT_REUSE_IDENTIFIER_NAME
{
	//���� == �±׸�	
	//{
	int x4;
	int y4;
	//�±׸� == �ʵ��
	short DNRIN_tagName; //@violation DO_NOT_REUSE_IDENTIFIER_NAME
	//�ʵ�� == �ʵ��
	short DNRIN_fieldName; //@violation DO_NOT_REUSE_IDENTIFIER_NAME
	//} inst3;
	//�Լ� == ����
	int DNRIN_func = 10; //@violation DO_NOT_REUSE_IDENTIFIER_NAME

	struct StructTest2
	{
		int x5;
		char DNRIN_variableName; //@violation DO_NOT_REUSE_IDENTIFIER_NAME
	} inst4;
}

//�Լ� == �Լ� ���ڸ�
void DNRIN_func4( char DNRIN_func ) //@violation DO_NOT_REUSE_IDENTIFIER_NAME
{
	//enum��� == �±׸�
	struct DNRIN_first //@violation DO_NOT_REUSE_IDENTIFIER_NAME
	{
		int x6;
		int y6;
	} inst;

	union UnionTest
	{
		char xx7;
		//enum��� == �ʵ��
		char DNRIN_first; //@violation DO_NOT_REUSE_IDENTIFIER_NAME
	} inst2;
	//�� == ����
	int DNRIN_labelName; //@violation DO_NOT_REUSE_IDENTIFIER_NAME
}

void DNRIN_func5()
{
	//enum��� == ����
	int DNRIN_first; //@violation DO_NOT_REUSE_IDENTIFIER_NAME
	//�Լ� == �±׸�
	struct DNRIN_func //@violation DO_NOT_REUSE_IDENTIFIER_NAME
	{
		int x8;
		int y8;
	};

	union StructTest
	{
		int x9;
		//�Լ� == �ʵ��
		char DNRIN_func; //@violation DO_NOT_REUSE_IDENTIFIER_NAME
		//�� == �ʵ��
		short DNRIN_labelName; //@violation DO_NOT_REUSE_IDENTIFIER_NAME
	};
}

//enum��� == �Լ� ����
void DNRIN_func6( int DNRIN_first ) //@violation DO_NOT_REUSE_IDENTIFIER_NAME
{
	return;
}


int DNRIN()
{
//�� == ��
DNRIN_labelName: //@violation DO_NOT_REUSE_IDENTIFIER_NAME

	enum EnumList2
	{
		//enum��� = enum���
		DNRIN_first, //@violation DO_NOT_REUSE_IDENTIFIER_NAME
		second,
		//enum��� == tag��
		enumTest, //@violation DO_NOT_REUSE_IDENTIFIER_NAME
		//�� == enum���
		DNRIN_labelName //@violation DO_NOT_REUSE_IDENTIFIER_NAME
	};


	return 1;
}
