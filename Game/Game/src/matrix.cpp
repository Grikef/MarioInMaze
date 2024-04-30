
#include "matrix.h"


Matrix::Matrix(int** _matrix, unsigned int _size)
{
	this->size = _size;
	this->values = new int* [_size] {};
	for (int i{ 0 }; i < _size; i++)
	{
		this->values[i] = new int[_size] {0};
	}

	// Coping matrix
	for (int i{ 0 }; i < _size; i++)
	{
		for (int j{ 0 }; j < _size; j++)
		{
			this->values[i][j] = _matrix[i][j];
		}
	}
}


Matrix::Matrix(const Matrix& _copy)
{
	// Creating new matrix
	this->size = _copy.size;
	this->values = new int* [_copy.size] {};
	for (int i{ 0 }; i < _copy.size; i++)
	{
		this->values[i] = new int[_copy.size] {0};
	}

	// Coping matrix
	for (int i{ 0 }; i < _copy.size; i++)
	{
		for (int j{ 0 }; j < _copy.size; j++)
		{
			this->values[i][j] = _copy.values[i][j];
		}
	}
}


Matrix::~Matrix()
{
	for (int i{0}; i < this->size; i++) 
	{
		delete[] this->values[i];
	}
	delete[] this->values;
}


unsigned int Matrix::getSize()
{
	return this->size;
}


void Matrix::setSize(unsigned int _size)
{
	if (this->size == 0)
	{
		this->size = _size;

		// Creating new matrix
		this->values = new int* [_size] {};
		for (int i{ 0 }; i < _size; i++)
		{
			this->values[i] = new int[_size] {0};
		}
	}
	else
	{
		// Deleting old matrix
		for (int i{ 0 }; i < this->size; i++)
		{
			delete[] this->values[i];
		}
		delete[] this->values;

		this->size = _size;

		// Creating new matrix
		this->size = _size;
		this->values = new int* [_size] {};
		for (int i{ 0 }; i < _size; i++)
		{
			this->values[i] = new int[_size] {0};
		}
	}
}


int** Matrix::getValues()
{
	return this->values;
}


int Matrix::getValue(int i, int j)
{
	if (i >= 0 && i < this->size && j >= 0 && j < this->size)
	{
		return this->values[i][j];
	}
	else
	{
		return -1;
	}
}


void Matrix::setValue(int _i, int _j, int _value)
{
	if (_i >= 0 && _j >= 0 && _i < this->size && _j < this->size)
	{
		this->values[_i][_j] = _value;
	}
}



void Matrix::setValues(int** _values, unsigned int _size)
{
	// Deleting old matrix
	for (int i{ 0 }; i < this->size; i++)
	{
		delete[] this->values[i];
	}
	delete[] this->values;

	// Creating new matrix
	this->size = _size;
	this->values = new int* [_size] {};
	for (int i{ 0 }; i < _size; i++)
	{
		this->values[i] = new int[_size] {0};
	}

	// Coping matrix
	for (int i{ 0 }; i < _size; i++)
	{
		for (int j{ 0 }; j < _size; j++)
		{
			this->values[i][j] = _values[i][j];
		}
	}
}


//Matrix Matrix::operator=(Matrix& _copy)
//{
//	Matrix out{ _copy };
//	return out;
//}