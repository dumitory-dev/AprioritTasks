#include <iostream>
#include <list>
#include <set>

std::list<int> merge_and_sorted_list( std::list<int> const  & lst_first, std::list<int> const  & lst_second)
{
    std::set tree(lst_first.cbegin(),lst_first.cend());
	tree.insert(lst_second.cbegin(),lst_second.cend());
	
	return {tree.cbegin(),tree.cend()};
}


int main(void) noexcept
{
	try
	{
		const std::list<int> ls{1,5,4};
		const std::list<int> ls2{3,0,9};

		auto res = merge_and_sorted_list(ls,ls2);

		for (const auto &  element : res)
		{
			std::cout<<element<< " ";
		}
		return 0;
	
	}
	catch (...)
	{
		return -1;
	}
}
