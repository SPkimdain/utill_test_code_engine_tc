//@checker CALL_VAARG_ON_INDETERMINATE_VALIST
#include <stdio.h>
#include <stdarg.h>

int CVOIV_func(size_t count, va_list ap)
{
	double d;
	for (size_t i = 1; i < count; ++i) 
	{
		/* �Ķ���ͷ� ���� va_list�� ap�� �״�� ����� */
		if (va_arg(ap, d) == 0.0)  //@violation CALL_VAARG_ON_INDETERMINATE_VALIST
		{
			return 1;
		}
	}
	return 0;
}

int CVOIV_func2(size_t count, va_list *ap) {
	va_list ap1;
	/* �Ϻ� �����Ϸ��� va_copy�� ������ */
	va_copy(ap1, *ap);
	//ap1 = *ap;
	double d;
	for (size_t i = 1; i < count; ++i)
	{
		/* ���� ���� */
		if (va_arg(ap1, d) == 0.0) 
		{
			return 1;
		}
	}

	va_end(ap1);
	return 0;
}

int CVOIV_func3(size_t count, ...)
{
	va_list ap; 
	va_start(ap, count);
	double d;
	if (CVOIV_func(count, ap))
	{
		va_end(ap);
		return 1;
	}

	for (size_t i = 0; i < count; ++i) {
		printf("%f ", 1.0 / va_arg(ap, d));
	}

	va_end(ap);
	return 0;
}
