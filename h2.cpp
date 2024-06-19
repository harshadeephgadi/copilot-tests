#include <iostream>
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <h2.hpp>


//driver1 function
int my_uart_drv1(s s1)
{
	int b;
	b = my_dep1(s1.a);

	if (b > 0)
	{
		return 1;
	}
	else if (b < 0)
	{
		return -1;
	}
	else
	{
		return 0;
	}
}

