// hw03.cpp : Defines the entry point for the application.
//

int factorial(const int& n) {
	return (n == 1 || n == 0) ? 1 : factorial(n - 1) * n;
}

// Inspired by example provided here:
// https://en.cppreference.com/w/cpp/named_req/Allocator

template<class T>
struct Hw03_allocator
{
	using value_type = T;

	Hw03_allocator() = default;
	template<class U>  constexpr Hw03_allocator(const Hw03_allocator <U>&) noexcept {}
	int current_lenght = 0;

	T* allocate(std::size_t n)
	{
		current_lenght += n;

		if (current_lenght > 11*sizeof(T))
		{
			throw std::out_of_range("Got request for allocation of more than 10 elements. It is more than defined in the homework.");
		}


		if (auto p = static_cast<T*>(std::malloc(n * sizeof(T))))
		{
			report(p, n);
			return p;
		}

		throw std::bad_alloc();
	}

	void deallocate(T* p, std::size_t n) noexcept
	{
		report(p, n, 0);
		std::free(p);
	}
private:
	void report(T* p, std::size_t n, bool alloc = true) const
	{
		std::cout << (alloc ? "Alloc: " : "Dealloc: ") << sizeof(T) * n
			<< " bytes at " << std::hex << std::showbase
			<< reinterpret_cast<void*>(p) << std::dec << '\n';
	}
};

class HW03Set {

private:
	struct Node {
		int value;
		Node* left;
		Node* right;
	public:
		Node(int _value) {
			value = _value;
			left = NULL;
			right = NULL;
		}
	};
	Node* root;
	Hw03_allocator<int> allocator;

public:

	HW03Set() {
		root = NULL;
	}

	void add(int value) {
		add(root, value);
	}

	void add(Node*& node, int value) {
		if (!node) {
			void* mem_t = allocator.allocate(sizeof(int));
			node = new(mem_t) Node(value);
		}
		else {
			if (value == node->value)
				return;

			if (value > node->value) {
				add(node->right, value);
			}
			else {
				add(node->left, value);
			}
		}
	}

	void print(Node*& start) {
		std::cout << start->value << std::endl;
		if (start->left)
			print(start->left);
		if (start->right)
			print(start->right);
	}

	void print() {
		print(root);
	}
};