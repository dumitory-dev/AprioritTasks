
#include <iostream>

/*
 * Easy Binary Tree
 */


namespace tree
{

	struct node
	{
		node* right{};
		node* left{};
		int val{};
	};

	node* root{};

	void add(const int val, node*& root)
	{

		if (root == nullptr)
		{
			root = new node();
			root->val = val;
			return;
		}

		if (root->val == val)
			return;


		root->val > val ? add(val, root->left) : add(val, root->right);

	}

	void add(const int val)
	{

		add(val, root);
	}
	   

	void print(const node* root)
	{
		if (root == nullptr)
		{
			return;
		}
		std::cout << root->val << std::endl;
		print(root->left);
		print(root->right);

	}

	void print(void)
	{
		print(root);
	}


	void free(const node* root)
	{
		if (root == nullptr)
		{
			return;
		}

		free(root->left);
		free(root->right);
		delete root;

	}

	void free(void)
	{
		free(root);
		std::cout << "Memory is free!" << std::endl;
	}


	bool is_symmetry(const node* root)
	{

		if (!root->left && !root->right)
			return true;


		if (!root->left || !root->right)
			return false;


		return is_symmetry(root->left) && is_symmetry(root->right);

	}


	bool is_symmetry(void)
	{
		return is_symmetry(root);
	}


}



int main(void) noexcept
{
	try
	{
		tree::add(4);
		tree::add(5);
		tree::add(3);
		tree::print();
		std::cout << std::boolalpha << tree::is_symmetry() << std::endl;
		tree::free();
		return 0;
	}
	catch (...)
	{
		return -1;
	}

}

