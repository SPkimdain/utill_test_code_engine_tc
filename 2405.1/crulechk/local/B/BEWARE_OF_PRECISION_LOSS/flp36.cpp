//@checker BEWARE_OF_PRECISION_LOSS



using namespace std;

void func1(float x)
{
	x = x -1.0;
}

void func2(double x)
{
	x = x+ 1.0;
}

int main()
{
	const int thrhld = 16777217;
	const int safe = 16777216;
	
	func1(thrhld); //@violation BEWARE_OF_PRECISION_LOSS
	func1(safe); /* safe�� ���� 2^24�� �����̹Ƿ� ���� ����. */

	func2(thrhld); /* double�̹Ƿ� ���� ����. */
	func2(safe); /* double�̹Ƿ� ���� ����. ���� 2^24�� ����. */

	func1(1234567890); //@violation BEWARE_OF_PRECISION_LOSS

	int value1 = 1234567890;
	char value2 = 0;

	float fValue = 0.F;

	/* float������ �Ͻ��� ��ȯ�� �Ͼ */
	fValue = value1; //@violation BEWARE_OF_PRECISION_LOSS

	int test =  (int)fValue;

	float testf =  (float)value2;

	float testf2 =  (float)value1; //@violation BEWARE_OF_PRECISION_LOSS

	double dValue = 0.0;
	dValue = value1; /* double�� 8byte�� ��� ���� ���� */

	long long value3 = 1234567890;
	float fValue2 = (float)value3; //@violation BEWARE_OF_PRECISION_LOSS

	float fValue3 = 16777217; //@violation BEWARE_OF_PRECISION_LOSS
	float fValue4 = 16777216;


}
