#include <iostream>

/*Easy SinglyLinkedList*/
namespace  singly_linked_list
{
	struct node
	{

		node* next{};
		int val{};

	}my_list;


	node* root{};

	node* find_empty_el(void)
	{
		if (!root)
		{
			return nullptr;
		}

		auto* desired_el = root;

		while (desired_el->next)
			desired_el = desired_el->next;


		return desired_el;


	}

	node* find_el(int val)
	{
		auto tmp_node = root;

		while (tmp_node)
		{
			if (tmp_node->val == val)
				return tmp_node;

			tmp_node = tmp_node->next;
		}

		return nullptr;
	}

	void crash(void)
	{
		if (root && root->next)
		{
			root->next = root;
		}
	}

	void push(int val)
	{
		const auto desired_node = singly_linked_list::find_empty_el();

		const auto new_node = desired_node == nullptr ? root = new node{} : desired_node->next = new node;

		new_node->val = val;
		
	}

	void print(void)
	{
		auto tmp_node = root;
		
		while (tmp_node)
		{
			std::cout << "Address - " << tmp_node  << " val - " <<  tmp_node->val << std::endl;
			tmp_node = tmp_node->next;
		}
	}

	bool check_looping(void)
	{

		auto first_node = root;
		auto second_node = root->next;


		while (second_node)
		{
			if (first_node == second_node)
			{
				return true;
			}

			first_node = second_node;
			second_node = second_node->next;
		}

		return false;

	}

	void free_mem(void)
	{

		auto tmp_node = root;

		while (root)
		{

			root = tmp_node->next;
			delete tmp_node;
			tmp_node = root;

		}

		std::cout<<"Memory is free"<<std::endl;

	}

	void delete_root(void)
	{
		if (root != nullptr)
		{
			delete singly_linked_list::root;
		    singly_linked_list::root = nullptr;
		}
		
	}
}


void test_one(void)
{
	std::cout<<"TEST FIRST --- looping on --- "<<std::endl;
	singly_linked_list::push(2);
	singly_linked_list::push(4);
	singly_linked_list::print();
	singly_linked_list::crash();
	std::cout << "Looping is - " <<std::boolalpha << singly_linked_list::check_looping()<<std::endl;
	singly_linked_list::delete_root();
	singly_linked_list::free_mem();
}


void test_two(void)
{
	std::cout<<"TEST SECOND --- looping off --- "<<std::endl;
	singly_linked_list::push(6);
	singly_linked_list::push(4);
	singly_linked_list::print();
	std::cout << "Looping is - " <<std::boolalpha << singly_linked_list::check_looping()<<std::endl;
	singly_linked_list::free_mem();
}



int main(void) noexcept
{
	try
	{
		test_one();
		std::cout<<std::endl;
		test_two();
		return 0;
	}
	catch (...)
	{
		return -1;
	}

}

