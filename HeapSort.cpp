#include<iostream>
#include<vector>
#include<list>

typedef std::vector<int> vec;
typedef std::list<int> my_list;

int Left(size_t i)
{
	return 2 * i + 1;
}

int Right(size_t i)
{
	return 2 * i + 2;
}

void Max_Heapify(vec &v, size_t i)
{
	int largest = 0;
	int l = Left(i);
	int r = Right(i);

	if (l < v.size() && v[l] > v[i])
		largest = l;
	else
		largest = i;
	if (r < v.size() && v[r] > v[largest])
		largest = r;
	if (largest != i)
	{
		std::swap(v[i], v[largest]);
		Max_Heapify(v, largest);
	}
}

void build_Max_Heap(vec &v)
{
	for (size_t i = v.size() / 2; i-- > 0;)
		Max_Heapify(v, i);
}

template<typename T>
void print(const T &cont)
{
	for (auto j : cont)
		std::cout << j << " ";
	std::cout << std::endl;
}

void HeapSort(vec &v, my_list &result)
{
	while (v.size() > 1)
	{
		std::swap(v.back(), v.front());
		result.push_front(v.back());
		v.pop_back();
		Max_Heapify(v, 0);
	}
	result.push_front(v.back());
	v.pop_back();
}

int main()
{
	vec A{ 6, 8, 15, 1, 44, 3, 20, 5, 10, 3, 0, 6 };
	my_list result;
	
	//build heap from vector with max element in first index
	build_Max_Heap(A);
	print(A);
	//push max element in result and pop it from heap
	HeapSort(A, result);
	print(result);
	
}
