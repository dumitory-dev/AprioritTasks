#include  <iostream>
#include  <optional>
#include  <vector>
#include  <unordered_map>
#include  <iterator>


std::optional<std::pair<std::size_t,std::size_t>> get_sum_indexes(const std::vector<int> & data, const int sum)
{
	std::unordered_map<std::size_t,std::size_t> hash{};

	for (auto i{0u}; i < data.size(); ++i)
	{
		if (hash.find(sum-data[i]) != hash.cend())
		{
			return std::pair{i,hash[sum-data[i]]};
		}

		hash[data[i]] = i;

	}
	return std::nullopt;


}

int main(void) noexcept
{
	try
	{
		std::vector data{1,1,1,3,4,6,7,8,6};
		auto res = get_sum_indexes(data,12);
		if (res)
		{
			std::cout<< (*res).first << (*res).second;
		}

		return 0;
	}
	catch (...)
	{
		return -1;
	}
   
}


