#include <iostream>
#include <regex>

using web_collection = std::vector<std::vector<std::string>>;

web_collection parse_reference_full(const std::string & data)
{
	web_collection data_parse{};
	const std::regex reg_command(R"((https?:\/\/)?(\w+)([\.][A-z.]+)(\/\S+)?)");
				
	for (auto iter = std::sregex_iterator(data.cbegin(), data.cend(), reg_command); iter != std::sregex_iterator(); ++iter)
	{
		auto begin = iter->cbegin();
		auto & el = data_parse.emplace_back();
		while (begin != iter->cend())
		{
			el.emplace_back(begin->str());
			++begin;
		}
	}
	
	
	return data_parse;
	
}



int main(void) noexcept
{
	try
	{
			
		const std::string str = "http://google.com.ru/ru  https://yandex.com.ru/en";
		const auto res = parse_reference_full(str);
		std::for_each(res.cbegin(),res.cend(),[](const auto & el)
		{
			std::copy(el.cbegin(),el.cend(),std::ostream_iterator<std::string>(std::cout,"\n"));
			std::cout<<std::endl;
		});		

	}
	catch (...)
	{
	}

}


