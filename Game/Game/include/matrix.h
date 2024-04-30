
#pragma once


class Matrix
{
private:
	unsigned int size{ 0 };
	int** values{};

public:
	Matrix() = default;
	Matrix(int**, unsigned int);
	Matrix(const Matrix&);
	~Matrix();

	int** getValues();
	int getValue(int, int);
	unsigned int getSize();
	void setValues(int**, unsigned int);
	void setValue(int, int, int);
	void setSize(unsigned int);

	//Matrix operator=(Matrix&);
};