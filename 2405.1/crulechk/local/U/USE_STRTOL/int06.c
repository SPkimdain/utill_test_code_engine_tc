//@checker USE_STRTOL
extern int atoi (const char * str);
extern int sscanf ( const char * s, const char * format, ...);

int main()
{
	char* str = "1234";
	char str2[32] = { 0 };
	
	int intValue = atoi(str); //@violation USE_STRTOL
	
	int intValue2 = 0;
		
	/* sscanf�� �ι�° ���ڿ� ���ڿ��� %ld, %d�� ���ԵǾ� �ִ� ���� �˶��� ��. */
	sscanf( str, "%d", &intValue2 ); //@violation USE_STRTOL

	/* ���� ����. */
	sscanf( str, "1%s", str2 );

	return 0;
}


