//the main idea is that in one pass, 
//neighboring elements are compared, 
//beginning with an even index, and
//in another pass - beginning with an 
//odd index
#include<iostream>
using std::cout;
using std::endl;
#include<vector>
using std::vector;

typedef vector<int> vec;

void evenOdd(vec &);
void print(const vec &);

int main()
{
	vec a = { 6, 8, 1, 5, 2, 4, 9, 0, 3, 7 };
	print(a);
	evenOdd(a);
	print(a);
}

void print(const vec &a)
{
	for (auto i : a)
		cout << i << " ";
	cout << endl;
}

void evenOdd(vec &a)
{
	size_t n = a.size();
	bool go = true;
	int count = 0;
	bool beg = 1;
	while (go || count < 2)
	{
		go = false;
		beg = !beg;
		for (size_t i = beg; i + 1 < n; i = i + 2)
		{
			if (a[i] > a[i + 1])
			{
				std::swap(a[i], a[i + 1]);
				go = true;
			}
		}
		if (!go)
			++count;
	}
}