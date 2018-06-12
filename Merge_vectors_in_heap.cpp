//This algorithm of merging sorting vectors in heap based 
//on merge sort algorithm 
#include<iostream>
#include<vector>

typedef std::vector<int> vec;
typedef std::vector<vec>collection;


unsigned int Left(size_t i)
{
	return 2 * i + 1;
}

unsigned int Right(size_t i)
{
	return 2 * i + 2;
}
int Parent(size_t i)
{
	return (i + 1) / 2 - 1;
}

vec& heapDecreaseKey(vec &v, int i, int key)
{
	while (i > 0 && v[Parent(i)] > v[i])
	{
		std::swap(v[i], v[Parent(i)]);
		i = Parent(i);
	}
	return v;
}

vec& heap_insert(vec &v, int key)
{
	v.push_back(key);
	return heapDecreaseKey(v, v.size() - 1, key);
}

vec& mergeHeapSort(vec &v1, vec &v2)
{
	for (auto j : v2)
		v1 = heap_insert(v1, j);
	return v1;
}

vec mergeHeap(const collection& v, size_t first, size_t last)
{
	if (first < last)
	{
		int mid = (first + last) / 2;
		vec v1 = mergeHeap(v, first, mid);
		vec v2 = mergeHeap(v, mid + 1, last);
		return mergeHeapSort(v1, v2);
	}
	else
		return v[first];
}

int main()
{
	vec A{ 3, 6, 9, 10, 17, 19, 22, 84, 93 };
	vec B{ 0, 4, 7, 11, 12, 13, 24, 52, 69, 98 };
	vec C{ 1, 5, 8, 15, 18, 20, 29, 33, 38, 42 };
	vec D{ 2, 14, 25, 31, 40, 51, 64, 72, 77 };
	collection v{ A, B, C, D };
	vec result = mergeHeap(v, 0, v.size() - 1);
	
	for (auto j : result)
		std::cout << j << " ";
	std::cout << std::endl;
}
