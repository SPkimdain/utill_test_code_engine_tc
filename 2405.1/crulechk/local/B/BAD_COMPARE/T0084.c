//@checker BAD_COMPARE

//Base

int getuid()
{
	return 0;
}

int geteuid()
{
	return 0;
}

void T0084func1()
{
	int x = 0;
	//Base01 - ���̵� ����
	if( getuid == 0 || geteuid == 0 ) //@violation BAD_COMPARE
	{
		x++;
	}

	//Base02 - while ���Ǻ�
	while( getuid == 0 ) //@violation BAD_COMPARE
	{
		x++;
	}
}

void T0084func2()
{
	void *fp = 0;

	//Complex01 - ������ �Ҵ��
	fp = getuid; //Checking False Alarm
	
}
