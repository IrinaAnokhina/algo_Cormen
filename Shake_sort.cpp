//This shake sorting based on bubble sort
//the difference is: it find current max element
// in one direction pass and find current min element
// in another direction pass
#include<iostream>
using std::cout;
using std::endl;
#include<vector>
using std::vector;

typedef vector<int> vec;

void shake(vec &);
void print(const vec &);

int main()
{
	vec a = { 216, 28, 22, 18, 13, 7, 6, 5, 4, 3, 1, 0 };
	print(a);
	shake(a);
	print(a);
}

void shake(vec &a)
{
	int count = 0;
	int beg = -1;
	int n = a.size();

	for (int end = n - 1; end > n / 2 - 1; --end)
	{
		++beg;
		for (int i = beg; i < end; ++i)
		{
			if (a[i + 1] < a[i])
				std::swap(a[i], a[i + 1]);
		}
		cout << ++count << ")";
		print(a);
		for (int j = end - 1; j > beg; --j)
		{
			if (a[j] < a[j - 1])
				std::swap(a[j], a[j - 1]);
		}
		cout << ++count << ")";
		print(a);
	}
}

void print(const vec &a)
{
	for (auto i : a)
		cout << i << " ";
	cout << endl;
}
