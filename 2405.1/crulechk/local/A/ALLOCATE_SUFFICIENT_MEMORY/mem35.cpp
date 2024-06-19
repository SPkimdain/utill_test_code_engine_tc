//@checker ALLOCATE_SUFFICIENT_MEMORY
#include <stdio.h>
#include <memory.h>
#include <stdlib.h>

int globalX = 10;

void func( int size, int k )
{
	long *x = 0;

	if( k == 10 )
	{
		if( size < 10000 && size >= 0 )
		{
			/* sizeof ���� ���� */
			x = (long*)malloc( sizeof(long) );			
			free(x);
			/* sizeof ���� ���� �� size �ٿ�帮�� �� �Ǿ� ����*/
			x = (long*)malloc( size * sizeof(long) );
			free(x);
			/* sizeof �ٸ� Ÿ�� */
			x = (long*)malloc( sizeof(int) ); //@violation ALLOCATE_SUFFICIENT_MEMORY
			free(x);
		}

		/* size �ٿ���� üũ�� �ȵǾ� ���� */
		x = (long*)malloc( size * sizeof(long) ); //@violation ALLOCATE_SUFFICIENT_MEMORY
		free(x);

		if( size < 1000 )
		{
			if( size >= 0 )
			{
				x = (long*)malloc( size * sizeof(long) );
			}
			else if( k > 10 )
			{
				return;
			}
			else
			{
				return;
			}
		}
	}

	/* ��� �� ���, ���� ���� */
	x = (long*)malloc( 10 * sizeof(long) ); 
	free(x);

	/* �ܺ� ��(Ȥ�� �ʵ�) ���, ������ */
	x = (long*)malloc( globalX * sizeof(long) ); 
	free(x);

	if( k == 12 )
	{
		unsigned int uSize = 10;
		/* unsigned�� ��� 0 üũ ���ʿ� */
		if( uSize <= 10000 )
		{
			x = (long*)malloc( uSize * sizeof(long) );
			free(x);
		}

		/* ���� �ٿ���� ���� ��� �˶� */
		if( uSize >= 0 )
		{
			x = (long*)malloc( uSize * sizeof(long) ); //@violation ALLOCATE_SUFFICIENT_MEMORY
			free(x);
		}
	}
}

int main()
{
	
	func(10, 5);

	return 0;
}

