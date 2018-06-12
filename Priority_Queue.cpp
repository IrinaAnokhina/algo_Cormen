//An implemantation of simple priority queue with 
//operations: insert, delete, extract_max_elem
#include<iostream>
#include<vector>

typedef std::vector<int> vec;

unsigned int Left(size_t i)
{
	return 2 * i + 1;
}

unsigned int Right(size_t i)
{
	return 2 * i + 2;
}
int Parent(int i)
{
	return (i + 1) / 2 - 1;
}

void Max_Heapify(vec &v, size_t i)
{
	int largest = 0;
	unsigned int l = Left(i);
	unsigned int r = Right(i);

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

int heap_extract_Max(vec &v)
{
	if (v.empty())
		std::cout << "Error! The queue is empty!" << std::endl;
	int max = v[0];
	v[0] = v.back();
	v.pop_back();
	Max_Heapify(v, 0);
	return max;
}

void heapIncreaseKey(vec &v, int i, int key)
{
	while (i > 0 && v[Parent(i)] < v[i])
	{
		std::swap(v[i], v[Parent(i)]);
		i = Parent(i);
	}
}

void deleteElem(vec &v, unsigned int index)
{
	if (index < v.size())
	{
		int l = Left(index);
		int r = Right(index);
		int max{};
		if (index < v.size() / 2)
		{
			if (v[l] > v[r])
				max = l;
			else
				max = r;

			std::swap(v[max], v[index]);
			v.erase(v.begin() + max);
		}
		else
			v.erase(v.begin() + index);
	}
	else
		std::cout << "Error! Index out of range!" << std::endl;
}

void max_heap_insert(vec &v, int key)
{
	v.push_back(key);
	heapIncreaseKey(v, v.size() - 1, key);
}

void buildHeap(vec &v)
{
	for (int i = v.size() / 2; i--> 0;)
		Max_Heapify(v, i);
}

void print(const vec &v)
{
	for (auto j : v)
		std::cout << j << " ";
	std::cout << std::endl;
}

int main()
{
	vec A{ 5, 3, 17, 10, 84, 19, 6, 22, 9, 93, 2, 16, 100, 22 };
	//vec A{ 15, 13, 9, 5, 12, 8, 7, 4, 0, 6, 2, 1 };
	print(A);
	buildHeap(A);
	print(A);
	unsigned int index{};
	std::cout << "A.size() = " << A.size() << "\n";
	std::cout << "Enter the index of element you want to delete ";
	std::cin >> index;
	deleteElem(A, index);
	print(A);
}

