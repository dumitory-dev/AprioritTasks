// TreeToList.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

/*
 * easy tree
 */
namespace tree
{

	struct node
	{
		node * right{};
		node * left{};
		int val{};
	};
	node * root;
	
	void add(node *& root, int key)
	{
		if (!root)
		{
			root = new node();
			root->val = key;
			return;
		}

		key > root->val ? add(root->right,key) : add(root->left,key);
	}

	void add(int key)
	{
		add(root,key);
	}

	void push_front(node *& new_node)
	{
		
		new_node->right = root;
		root = new_node;
	}

	void to_list(node *& root1)
	{
		if (!root1)
		{
			return;
		}

		
		to_list(root1->right);
		push_front(root1);
		to_list(root1->left);
		
		
		
	}

	void set_left_null(node * root)
	{
		
		while (root)
		{
			root->left = nullptr;
			root = root->right;
		}
	}
	void to_list(void)
	{
		to_list(root->left);
		set_left_null(root);
		//root->left = nullptr;
	}

	
	
	void free(node * root)
	{
		if (!root)
		{
			return;
		}
		free(root->left);
		free(root->right);
		delete root;
	}
}

int main(void)
{
	tree::add(9);
	tree::add(5);
	tree::add(4);
	tree::add(1);
	tree::add(2);
	tree::add(8);
	tree::add(10);
	tree::add(10);

	tree::to_list();
    std::cout << "Hello World!\n";
}


