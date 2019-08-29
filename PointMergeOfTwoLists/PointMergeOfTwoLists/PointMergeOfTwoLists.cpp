// PointMergeOfTwoLists.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <iterator>
#include <vector>
#include <cstdlib>
/*easy list*/

namespace list
{

	class list
	{
		struct node
		{
			node* next{};
			node* prev{};
			int i{};
		};

	public:

		struct iterator :std::iterator<std::bidirectional_iterator_tag, int, ptrdiff_t, int*, int&>
		{
			iterator(node* head) :head_(head)
			{

			}

			iterator& operator++()
			{



				this->head_ = this->head_->next;



				return *this;
			}

			iterator operator++(int)
			{
				const auto old = *this;
				++(*this);
				return old;
			}

			iterator& operator--()
			{

				this->head_ = this->head_->prev;
				return *this;
			}

			iterator operator--(int)
			{
				const auto old = *this;
				--(*this);
				return old;
			}

			int& operator*() const
			{
				return this->head_->i;
			}

			bool operator != (const iterator& tmp) const
			{
				return tmp.head_ != this->head_;
			}

			bool operator == (const iterator& tmp) const
			{
				return !(*this != tmp);
			}


		private:
			friend list;
			node* head_{};
			node* end_{};
		};

		struct const_iterator : iterator
		{
			explicit const_iterator(node* head)
				: iterator(head)
			{

			}

			const int& operator*(void) const
			{
				return iterator::operator*();
			}

		};

		void push(const int data)
		{
			const auto tmp_node = new node{};

			tmp_node->i = data;
			++this->size_;

			if (!this->head_)
			{
				this->head_ = tmp_node;
				this->end_ = new node{};
				this->head_->next = this->end_;
				this->end_->prev = this->head_;

				return;
			}


			this->end_->prev->next = tmp_node;
			tmp_node->prev = this->end_->prev;
			tmp_node->next = this->end_;
			this->end_->prev = tmp_node;




		}

		~list(void)
		{
			while (this->head_)
			{
				const auto tmp_node = this->head_->next;
				delete this->head_;
				this->head_ = tmp_node;
			}

		}

		using reverse_iterator = std::reverse_iterator<iterator>;
		using const_reverse_iterator = std::reverse_iterator<const_iterator>;


		iterator begin(void) const
		{
			return { this->head_ };
		}

		iterator end(void) const
		{
			return { this->end_ };
		}

		const_iterator cbegin(void) const
		{
			return const_iterator(this->head_);
		}

		const_iterator cend(void) const
		{

			return const_iterator(this->end_);
		}

		reverse_iterator rbegin(void) const
		{
			return reverse_iterator(iterator(this->end_));
		}

		reverse_iterator rend(void) const
		{
			return reverse_iterator(iterator(this->head_));
		}


		const_reverse_iterator rcbegin(void) const
		{
			return const_reverse_iterator(const_iterator(this->end_));
		}

		const_reverse_iterator rcend(void) const
		{
			return const_reverse_iterator(const_iterator(this->head_));
		}

		node*& get_node(iterator& iter)
		{
			return iter.head_;
		}

		void hack(node*& node) const
		{
			this->head_->next->next = node;
		}


		size_t get_size(void) const noexcept
		{
			return this->size_;
		}
	private:
		node* head_{};
		node* end_{};
		size_t size_{};

	};



}


bool is_merge_point(const list::list& lst, const list::list& ls2)
{

	const auto res = std::abs(static_cast<int>(lst.get_size() - ls2.get_size()));

	auto begin = lst.get_size() > ls2.get_size() ? lst.cbegin() : ls2.cbegin();
	std::advance(begin, res);

	auto begin_two = !(lst.get_size() > ls2.get_size()) ? lst.cbegin() : ls2.cbegin();

	while (begin != nullptr && begin_two != nullptr)
	{
		if (begin == begin_two)
		{
			return true;
		}

		++begin;
		++begin_two;
	}

	return false;

}

int main(void) noexcept
{
	try
	{
		list::list lst;
		lst.push(4);
		lst.push(3);
		lst.push(7);


		list::list lst2;
		lst2.push(7);
		lst2.push(8);
		lst2.push(2);
		lst2.push(10);


		auto& node = lst2.get_node(--lst2.end());
		lst.hack(node); //if will not delete this string - abort

		std::cout << std::boolalpha<<is_merge_point(lst, lst2);
	}
	catch (...)
	{
	}




}

