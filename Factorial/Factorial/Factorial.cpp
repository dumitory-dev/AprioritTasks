#include <iostream>

using ulong64 = unsigned long long;

constexpr ulong64 get_factorial(const ulong64 val)
{
	ulong64 tmp_factorial{1};

	for (ulong64 i{1}; i <= val; ++i)
		tmp_factorial*=i;

	return tmp_factorial;
}


int main(void) noexcept
{
	try
	{
		std::cout << get_factorial(5);
		std::cin.get();
	}
	catch (...)
	{
		return -1;
	}

	return 0;
    
}



