#include <iostream>

namespace check
{
	template<typename T, typename T1>
	struct is_operator
	{
		const static  bool value = false;
	};


	template<typename T>
	struct is_operator<T, decltype(*static_cast<std::ostream*>(nullptr) << *static_cast<T*>(nullptr))>
	{
		const static  bool value = true;
	};

	
	template<typename T>
	constexpr bool is_operator_t = is_operator<T, decltype(*static_cast<std::ostream*>(nullptr))>::value;

}


struct  Test
{

	int i{};

	friend std::ostream& operator << (std::ostream& os, const Test& test)
	{
		os << test.i;

		return os;
	}

	Test() = delete;

};


struct  TestNoOperator
{
	

};


void CheckOperator(void)
{

	std::cout<<typeid(Test).name()<<" - "<<std::boolalpha<<check::is_operator_t<Test><<std::endl;
	std::cout<<typeid(const Test*).name()<<" - "<<std::boolalpha<<check::is_operator_t<const Test*><<std::endl;
	std::cout<<typeid(TestNoOperator).name()<<" - "<<std::boolalpha<<check::is_operator_t<TestNoOperator><<std::endl;
	std::cout<<typeid(int).name()<<" - "<<std::boolalpha<<check::is_operator_t<int><<std::endl;
	std::cout<<typeid(int*).name()<<" - "<<std::boolalpha<<check::is_operator_t<int*><<std::endl;
	std::cout<<typeid(void).name()<<" - "<<std::boolalpha<<check::is_operator_t<void><<std::endl;
	std::cout<<typeid(void*).name()<<" - "<<std::boolalpha<<check::is_operator_t<void*><<std::endl;

}



int main(void) noexcept
{
	try
	{
		CheckOperator();
		return 0;
	}
	catch (...)
	{
		return -1;
	}

}

