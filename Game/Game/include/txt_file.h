
#pragma once
#include <fstream>
#include <string>
#include "matrix.h"


void getMatrix(std::string filename, Matrix& _matrix)
{
	using namespace std;

	ifstream in(filename, ios_base::in);

	int size{};
	in >> size;

	_matrix.setSize(size);

	int temp{};
	for (int i{ 0 }; i < size; i++)
	{
		for (int j{ 0 }; j < size; j++)
		{
			in >> temp;
			_matrix.setValue(j, _matrix.getSize() - i - 1, temp);
		}
	}

	in.close();
}