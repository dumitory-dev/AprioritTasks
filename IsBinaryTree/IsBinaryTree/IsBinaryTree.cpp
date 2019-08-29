#include <iostream>

/*
 * easy tree
 */

struct Tree
{
	explicit Tree(const int i) :root_(new Node())
	{
		this->root_->data = i;
	}

	struct Node;

	static Node* push_left(int data, Node* root)
	{
		if (!root->left)
		{
			root->left = new Node();
			root->left->data = data;
			return root->left;
		}

		push_left(data, root->left);

	}

	static Node* push_right(int data, Node* root)
	{
		if (!root->right)
		{
			root->right = new Node();
			root->right->data = data;
			return root->right;
		}

		push_right(data, root->right);

	}

	Node* push_left(int data) const
	{

		return Tree::push_left(data, this->root_);

	}

	Node* push_right(int data) const
	{

		return Tree::push_right(data, this->root_);

	}


	bool is_binary(void) const
	{
		return Tree::is_binary(this->root_,std::numeric_limits<int>::min(),std::numeric_limits<int>::max());
	}


	~Tree(void)
	{
		Tree::free_(this->root_);
	}


private:
	struct Node
	{
		Node* right{};
		Node* left{};

		int data{};
	};


	static bool is_binary(Node* root, int min, int max)
	{

		if (!root)
		{
			return true;
		}

		if (root->data < min || root->data > max)
		{
			return false;
		}
			

		return (is_binary(root->left,min,root->data - 1) && is_binary(root->right,root->data+1,max));


	}



	static void free_(Node* root)
	{
		if (!root)
		{
			return;
		}

		free_(root->left);
		free_(root->right);
		delete root;
	}


	Node* root_{};

};


int main(void) noexcept
{
	try
	{
		Tree tree(8);

		auto ptr = tree.push_left(5);
		Tree::push_right(6, ptr);
		Tree::push_left(3, ptr);


		std::cout << std::boolalpha;
		std::cout << tree.is_binary();


	}
	catch (...)
	{
	}

}

