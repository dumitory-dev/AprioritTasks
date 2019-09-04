

#include <iostream>
#include <list>

class my_list
{


public:
	struct node
	{
		node* next{};
		int val{};
	};
	node* get_root(void) const noexcept
	{
		return this->root_;
	}

	std::size_t get_size(void) const noexcept
	{
		return this->size_;
	}

	void push(const int val)
	{
		if (!this->root_)
		{
			this->root_ = new node;
			this->root_->val = val;
			this->size_++;
			return;
		}

		auto tmp = this->root_;

		while (tmp->next)
		{
			tmp = tmp->next;
		}

		tmp->next = new node;
		tmp->next->val = val;
		this->size_++;

	}


	~my_list(void)
	{
		node* tmp{};

		while (this->root_)
		{
			tmp = this->root_->next;
			delete this->root_;
			this->root_ = tmp;
		}


	}

private:
	node* root_{};
	std::size_t size_{};

};


//Например, дано : 1 2 0 5 4 0 1 0
//Результат : 1 2 5 4 1 0 0 0

void move_zeros(my_list& data)
{
	if (data.get_size() < 2)
	{
		return;
	}

	my_list::node* ptr = data.get_root();
	
	for (; ptr->next != nullptr; ptr = ptr->next)
	{
		if (ptr->next->val != 0)
		{
			continue;
		}

		auto tmp = ptr->next;

		for (; tmp != nullptr; tmp=tmp->next)
		{
			if (tmp->val != 0)
			{
				std::swap(ptr->next->val,tmp->val);
				break;
			}
		}

	}

}


int main(void) noexcept
{
	try
	{
		my_list ls;
		ls.push(1);
		ls.push(0);
		ls.push(5);
		ls.push(51);
		ls.push(1);
		ls.push(0);
		move_zeros(ls);

	}
	catch (...)
	{
	}

}

