// Another one sorting by comparison
//There are compared not adjacency elements, but
//elements  that are at a distance calculated on 
//the basis of the reduction factor
#include<iostream>
using std::cout;
using std::endl;
#include<vector>
using std::vector;

typedef vector<int> vec;

void comb(vec &);
void print(const vec &);

int main()
{
	vec a = { 6, 8, 1, 5, 2, 4, 9, 0, 3, 7 };
	print(a);
	comb(a);
	print(a);
}

void print(const vec &a)
{
	for (auto i : a)
		cout << i << " ";
	cout << endl;
}

void comb(vec &a)
{
	//den is a reduction factor that equals to 1.247
	const double den = 1.247;
	size_t size = a.size();
	int step = size / den;
	while (step >= 1)
	{
		for (size_t i = 0; i + step < size; ++i)
		{
			if (a[i] > a[i + step])
				std::swap(a[i], a[i + step]);
		}
		step = step / den;
	}
}