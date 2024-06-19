//@checker MINIMISE_USE_AUTOPTR

#include <stdio.h>
#include <memory>

using namespace std;

int foo( auto_ptr<int> a )
{
	return *a;
}

int bar( auto_ptr<int>& a )
{
	return *a;
}

int main()
{
	int* x = new int;
	int y = 10;
	auto_ptr<int> a( new int ); 
	auto_ptr<int> b(x);
	auto_ptr<int> c;
	
	//1.array type�� auto_ptr�� ����ϴ� ���
	auto_ptr<int> d( new int[10] ); //@violation MINIMISE_USE_AUTOPTR
	
	//2.�����Ҵ��� �ƴ� ������ auto_ptr�� ����
	auto_ptr<int> e( &y ); //@violation MINIMISE_USE_AUTOPTR

	//foo( ai ); // destructive copy
	*a = 10; // error a no longer exists


	//4.auto_ptr ��ü�� �ٸ� auto_ptr ��ü�� Assignment �ϴ� ���
	c = b; //@violation MINIMISE_USE_AUTOPTR
	*c = 5;

	printf( "%d\n", *a );
	printf( "%d\n", *c );

	//3.auto_ptr ��ü�� ���� ���� ���� ���ڷ� ����ϴ� ���
	printf( "%d\n", foo( a ) ); //@violation MINIMISE_USE_AUTOPTR
	
	printf( "%d\n", bar( c ) );

	printf( "%d\n", *c );
}
