#include<iostream>
#include<vector>
#include<ctime>

typedef std::vector<int> type;

int Partition(type &v, int p, int r)
{
	int x = v[r];
	int i = p - 1;
	for (int j = p; j < r; j++)
	{
		if (v[j] <= x)
		{
			i = i + 1;
			std::swap(v[i], v[j]);
		}
	}
	std::swap(v[i + 1], v[r]);
	return i + 1;
}
	int Randomized_Partition(type &v, int p, int r)
	{
		int i = std::rand() % (r - p) + p;
		std::swap(v[r], v[i]);
		return Partition(v, p, r);
	}

	void Randomized_QuickSort(type &v, int p, int r)
	{
		if (p < r)
		{
			int q = Randomized_Partition(v, p, r);
			Randomized_QuickSort(v, p, q - 1);
			Randomized_QuickSort(v, q + 1, r);
		}
	}

	void print(const type&v)
	{
		for (auto j : v)
			std::cout << j << " ";
		std::cout << std::endl;
	}

int main()
{
	std::srand(std::time(0));
	type v{ 13, 19, 9, 5, 12, 8, 7, 4, 21, 2, 6, 11 };
	print(v);
	Randomized_QuickSort(v, 0, v.size() - 1);
	print(v);
}