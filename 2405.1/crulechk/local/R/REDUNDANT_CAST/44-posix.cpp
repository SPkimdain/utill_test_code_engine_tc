//@checker REDUNDANT_CAST

void func()
{
	int x = 10;
	int y = 20;
	x = (int)y + 1; //@violation REDUNDANT_CAST

	char z = 'x';

	/* ���������� int������ ĳ���� ������, ��������� ������ Ÿ���� ������ ������ ���� ������ Ÿ������ ĳ���� �� */
	x = (char)z; //@violation REDUNDANT_CAST

	/* ���� ���� */
	x = (unsigned int)y - 1;

	float fx = 3.3F;
	float fy = 50.2F;

	/* ���� ���� */
	x = (int)fx + 10;

	if((float)fx == 10.3F) //@violation REDUNDANT_CAST
	{
		x++;
	}
	
}

int main()
{
	return 0;
}
