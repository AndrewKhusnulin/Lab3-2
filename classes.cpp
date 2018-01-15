#include "class.h"
const unsigned stack_size = 5;
template <class T>
class Stack
{
private:
	T stack[stack_size];
	int top = 0;
	Stack<T>(const Stack<T>&) = delete;
	Stack<T>& operator=(const Stack<T>&) = delete;
public:
	Stack() { };
	bool push(const T& temp)
	{
		if (top < stack_size)
		{
			stack[top++] = temp;
			return true;
		}
		else
			return false;
	};
	bool pop()
	{
		if (top > 0)
		{
			--top;
			return true;
		}
		else
			return false;
	};
	void pop_emplace(T&& temp)
	{
		stack[top - 1] = forward<T>(temp);
	};
	T& head() { if (top == 0) ++top; return stack[top - 1]; };
	void pop_destroy()
	{
		stack[top - 1] = 0;
		top--;
	};
	friend std::ostream& operator<<(std::ostream& out, const Stack<T>& s)
	{
		cout << "Размер стека: " << s.top << endl;
		for (int i = { s.top - 1 }; i >= 0; --i)
			out << s.stack[i] << std::endl;
		out << std::endl;
		return out;
	}
	~Stack() {};
};
class NonCopyMove
{
private:
	int value;
	NonCopyMove(const NonCopyMove&) = delete;
	NonCopyMove& operator=(const NonCopyMove&) = delete;
	NonCopyMove(const NonCopyMove&&) = delete;
	NonCopyMove& operator=(const NonCopyMove&&) = delete;
public:
	NonCopyMove(const int value) : value(value) {};
	int & get_value() { return value; };
	friend std::ostream& operator<<(std::ostream& ost, const NonCopyMove& temp)
	{
		ost << temp.value << std::endl;
		return ost;
	};
};