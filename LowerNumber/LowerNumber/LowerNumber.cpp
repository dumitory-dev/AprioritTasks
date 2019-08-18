#include <iostream>
#include <vector>

int find_lower_with_number(const std::vector<int> & data, const int num) noexcept
{
	const auto size = data.size();
	for (auto i{0u}; i < size; ++i)
		if (data[i] < num)
			return i;
		
	return -1;
	
}


int find_lower_with_index(const std::vector<int> & data, const size_t index) noexcept
{
	if (data.empty())
		return -1;

	if (data.size() == 1)
		return 0;
	
	auto begin_index{static_cast<int>(index) - 1};
	
	while (static_cast<int>(index) != begin_index)
	{
		if (begin_index < 0){
			begin_index = static_cast<int>(data.size()) - 1;
			continue;
		}
				
		if (data[begin_index] < data[index])
			return begin_index;

		--begin_index;
				
	}
	   		
	return -1;
	
}



int main(void) noexcept
{
	try
	{
		std::vector v{2,9,6,3,8,1,9,0};

		std::cout << find_lower_with_index(v,5) << std::endl;
		std::cout << find_lower_with_number(v,5) << std::endl;

		return 0;
	}
	catch (...)
	{
		return -1;
	}
  
}

