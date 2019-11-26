#include <iostream>
#include <vector>


class int_binary
{

	typedef struct node
	{
		int value{};
		node* p_right{};
		node* p_left{};
	}*p_node;

	
public:

	void add(const int val)
	{
		int_binary::add_helper(this->root_, val);
	}

	int_binary(void) = default;


	void show(void) const
	{
		if (!this->root_)
		{
			return;
		}
		
		std::vector<p_node> nodes{this->root_};
		int level{};
		while (!nodes.empty())
		{
			std::vector<p_node> nodes_tmp;
			nodes_tmp.reserve(nodes.size());

			std::cout << "Level: " << level<< " values -  ";
			for (const auto &  element : nodes)
			{
				std::cout << element->value << " ";
				
				if (element->p_left)			
					nodes_tmp.emplace_back(element->p_left);
					
								
				if (element->p_right)
					nodes_tmp.emplace_back(element->p_right);
				
			}
		    std::cout << std::endl;
			++level;
			nodes = std::move(nodes_tmp);
				
			
		}
				
		
	}
		
	
	~int_binary(void)
	{
		int_binary::clean(this->root_);
	}
	
private:

	static void add_helper(node *& now_node, const int val)
	{
		if (now_node == nullptr)
		{
			now_node = new node();
			now_node->value = val;
			return;
		}

		now_node->value > val
		? 
		add_helper(now_node->p_left, val)
		:
		add_helper(now_node->p_right, val);
		
					
	}


	static void clean(node * now_node)
	{
		if (now_node)
		{

			clean(now_node->p_left);
			clean(now_node->p_right);
			delete now_node;
			
		}
	}
	

	
	node* root_{};

	
};



int main(void)
{
	try
	{
		int_binary b;


		b.add(9);
		b.add(8);
		b.add(10);
		b.add(11);
		b.add(7);
		b.add(6);

		b.show();

	}
	catch (...)
	{
	}
  
}


