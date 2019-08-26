#include <iostream>
#include <string>

std::string & increment_string(std::string & str)
{
	
        auto index = str.size() - 1;
	
	while (true)
	{
		if (str[index] != '9')
		{
			str[index]++;
			break;
		
		}
				
		str[index] = '0';

		if (!index)
		{
			str.insert(0,"1");
			break;
		}

		--index;
		
	}
	

	return str;
	
}



int main(void) noexcept
{
	try{

		std::string ptr("9");

		std::cout << increment_string(ptr);
	        	
	}


	catch(...){

	}
	
}


