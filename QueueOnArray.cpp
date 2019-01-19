#include <iostream>
using namespace std;
class QueueOnArray
{
public:
	QueueOnArray() = default;
	QueueOnArray(const QueueOnArray &Q);
	~QueueOnArray() { delete[] data_, data_ = nullptr; }
	QueueOnArray& operator=(const QueueOnArray &Q);
	int const f() const { return first_; }
	int const l() const { return last_; }
	bool empty() { return last_ < first_; }
	int& top();
	void push(const int num);
	void pop();
private:
	int first_{ 0 };
	int last_{ -1 };
	int capacity_{ 0 };
	int* data_{ nullptr };
};
QueueOnArray::QueueOnArray(const QueueOnArray &Q)
{
	first_ = Q.first_;
	last_ = Q.last_;
	capacity_ = Q.capacity_;
	data_ = new int[capacity_];
	for (int i = first_; i <= last_; i++)
	{
		data_[i%capacity_] = Q.data_[i%capacity_];
	}
}
void QueueOnArray::push(const int num)
{
	if (last_ - first_ + 1 >= capacity_)
	{
		int capacity = capacity_ * 2;
		if (capacity == 0)
		{
			capacity++;
		}
		int* data = new int[capacity];
		for (int i = first_; i <= last_; i++)
		{
			data[i - first_] = data_[i%capacity_];
		}
		swap(data, data_);
		swap(capacity, capacity_);
		delete[] data;
		data = nullptr;
		last_ -= first_;
		first_ = 0;
	}
	last_++;
	data_[last_%capacity_] = num;
}
void QueueOnArray::pop()
{
	if (!empty())
	{
		first_++;
		last_ -= first_;
		first_ = 0;
	}
}
int& QueueOnArray::top()
{
	if (!empty())
	{
		return data_[first_%capacity_];
	}
}
QueueOnArray& QueueOnArray:: operator=(const QueueOnArray &Q)
{
	if (this != &Q)
	{
		QueueOnArray Qu(Q);
		swap(Qu.capacity_, capacity_);
		swap(Qu.first_, first_);
		swap(Qu.last_, last_);
		swap(Qu.data_, data_);
	}
	return *this;
}
int main()
{
	QueueOnArray Q;
	cout << "Q is empty:" << endl << Q.empty() << endl;
	QueueOnArray Qu = Q;
	cout << "Qu is empty after Qu=Q:" << endl << Qu.empty() << endl;
	Q.push(9);
	cout << "Q.top() after Q.push(9):" << endl << Q.top() << endl;
	cout << "Q is empty:" << endl << Q.empty() << endl;
	Qu = Q;
	cout << "Qu.top() after Qu=Q" << endl << Qu.top() << endl;
	Q.pop();
	cout << "Q is empty after Q.pop():" << endl << Q.empty() << endl;
	system("pause");
}