#include <iostream>
#include <string>

bool check_palindrome(const std::string_view str)
{

	auto start = std::cbegin(str);
	auto end = --std::cend(str);

	while (true)
	{
		if (*start != *end)
			return false;

		if (start == end)
			return true;

		++start;
		--end;

	}

}


int main(void)
{
	try
	{
		
		const auto str("1211");
		std::cout << std::boolalpha << check_palindrome(str);

		return 0;
	}
	catch (...)
	{
		return -1;
	}


}

