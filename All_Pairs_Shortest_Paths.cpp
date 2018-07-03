#include<iostream>
using std::cout;
#include<array>
using std::array;
#include<algorithm>
#include<iomanip>
using std::setw;

const unsigned int size = 5;
typedef array<array<int, size>, size> matrix;

matrix& extendShortestPaths(matrix&, matrix&);
matrix& slowAllPairsPaths(matrix&, matrix&);
matrix& fasterAllPairsPaths(matrix&, matrix&);

int main()
{
	const int c = INT16_MAX;
	 matrix v{ 0, 3, 8, c, -4, c, 0, c, 1, 7, c,  4, 0, c, 
		 c, 2, c, -5, 0, c, c, c, c, 6,  0 };
	
	//matrix v{ 0, c, c, c, -1, c, 1, 0,c, 2, c, c, c, 2, 0, c, c, -8, 
		//-4, c, c, 0, 3, c, c, 7, c, c, 0, c, c, 5, 10, c, c, 0 };
	 for (size_t i = 0; i < size; ++i)
	 {
		 for (size_t j = 0; j < size; ++j)
			 cout << setw(5) << v[i][j] << "  ";
		 cout << std::endl;
	 }
	 cout << std::endl;
	 matrix l(v);
	 //O(n^4)
	 l = slowAllPairsPaths(l, v);
	 l = v;
	 //O(n^3 lg n)
	 l = fasterAllPairsPaths(l, v);
	 for (size_t i = 0; i < size; ++i)
	 {
		 for (size_t j = 0; j < size; ++j)
			 cout << setw(5) << l[i][j] << "  ";
		 cout << std::endl;
	 }
}

matrix& extendShortestPaths(matrix& L, matrix& W)
{
	matrix temp = L;
	int c = INT16_MAX;
	for (size_t i = 0; i < size; ++i)
		for (size_t j = 0; j < size; ++j)
		{
			L[i].at(j) = INT16_MAX;
			// l[i][j] = min {l[i][k] + w[k][j] }
			//the shortest path from i to j is equal
			//to shortest path from i to k(i <= k <= j)
			// + path from k to j
			for (size_t k = 0; k < size; ++k)
				if (temp[i][k] == c || W[k][j] == c)
					L[i].at(j) = std::min(L[i][j], c);
				else
					L[i].at(j) = std::min(L[i][j], temp[i][k] + W[k][j]);
		}
	return L;
}

matrix& slowAllPairsPaths(matrix& L, matrix& W)
{
	//the shortest path (i, j) = 
	// l[i][j] ^(n-1) = l[i][j]^n = 
	// l[i][j]^(n+1)
	for (size_t m = 1; m < size; ++m)
		L = extendShortestPaths(L, W);
	return L;
}

matrix& fasterAllPairsPaths(matrix &L, matrix &W)
{
	//lg(n-1) iterations
	int m = 1;
	matrix temp = L;
	while (m < size - 1)
	{
		L = extendShortestPaths(L, temp);
		temp = L;
		m *= 2;
	}
	return L;
}