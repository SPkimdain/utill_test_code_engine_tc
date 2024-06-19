//@checker BAD_MALLOC
#define WIDE_LENGTH( x ) wcslen( x ) 
typedef wchar_t WCHAR;
typedef WCHAR *WCHAR_PTR;

extern long wcslen (const wchar_t* wcs);
extern void* malloc (long size);
extern void* realloc (void* ptr, long size);
extern void free (void* ptr);

//Base

void T0045func1()
{
	wchar_t str1[] = L"Hello";
	
	//Base01 - ���̵� ����
	wchar_t *str2 = ( wchar_t * )malloc( wcslen(str1) + 1 ); //@violation BAD_MALLOC
	free(str2);
}

//Complex

void T0045func2()
{
	wchar_t str1[] = L"Hello";

	//Complex01 - ���� ������
	int appendSize = 10;
	int padding = 5;
	wchar_t *str2 = ( wchar_t * )malloc( ( ( 5 + appendSize + wcslen(str1) ) + padding ) ); //@violation BAD_MALLOC
	free(str2);

	//Complex02 - ��ũ��
	str2 = ( wchar_t * )malloc( WIDE_LENGTH( str1 ) + 1 ); //@violation BAD_MALLOC
	free(str2);

	//Complex03 - realloc ���(03�� ����)
	str2 = ( wchar_t * )realloc( str2, wcslen(str1) + 1 ); //@violation BAD_MALLOC
	free(str2);

	//Complex04 - wchar_t���� typedef �ڷ����� ���
	WCHAR_PTR str3 = ( WCHAR_PTR )malloc( wcslen(str1) + 1 ); //@violation BAD_MALLOC
}
