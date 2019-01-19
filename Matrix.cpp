#include <iostream>
using namespace std;
class Matrix
{
public:
	Matrix() = default;
	Matrix(const ptrdiff_t row, const ptrdiff_t col);
	Matrix(const Matrix &M);
	~Matrix();
	Matrix& operator=(const Matrix &M);
	int& get(const ptrdiff_t i, const ptrdiff_t j);
	int& get(const ptrdiff_t i, const ptrdiff_t j) const;
	ptrdiff_t const c() const { return col_; }
	ptrdiff_t const r() const { return row_; }
private:
	ptrdiff_t row_{ 0 };
	ptrdiff_t col_{ 0 };
	int** data_{ nullptr };
};
Matrix::Matrix(const ptrdiff_t row, const ptrdiff_t col)
{
	row_ = row;
	col_ = col;
	data_ = new int*[row_];
	for (int i = 0; i < row_; i++)
	{
		data_[i] = new int[col_];
		for (int j = 0; j < col_; j++)
		{
			data_[i][j] = 0;
		}
	}
}
Matrix::Matrix(const Matrix &M)
{
	row_ = M.row_;
	col_ = M.col_;
	data_ = new int*[row_];
	for (int i = 0; i < row_; i++)
	{
		data_[i] = new int[col_];
		for (int j = 0; j < col_; j++)
		{
			data_[i][j] = M.data_[i][j];
		}
	}
}
Matrix::~Matrix()
{
	for (int i = 0; i < row_; i++)
	{
		delete[] data_[i];
	}
	delete[] data_;
	data_ = nullptr;
}
Matrix& Matrix::operator=(const Matrix &M)
{
	if (this != &M)
	{
		Matrix MM = Matrix(M);
		swap(data_, MM.data_);
		swap(col_, MM.col_);
		swap(row_, MM.row_);

	}
	return *this;
}
int& Matrix::get(const ptrdiff_t i, const ptrdiff_t j)
{
	return data_[i][j];
}
int& Matrix::get(const ptrdiff_t i, const ptrdiff_t j) const
{
	return data_[i][j];
}
void PrintM(const Matrix& M)
{
	cout << endl;
	for (int i = 0; i < M.r(); i++)
	{
		for (int j = 0; j < M.c(); j++)
		{
			cout << M.get(i, j) << " ";
		}
		cout << endl;
	}
}
int main()
{
	Matrix M(2, 2);
	cout << "Matrix M(2, 2):";
	PrintM(M);
	Matrix MM = M;
	cout << "Matrix MM=M:";
	PrintM(MM);
	M.get(0, 0) = 3;
	cout << "M.get(0, 0) = 3:";
	PrintM(M);
	MM = M;
	cout << "MM=M:";
	PrintM(MM);
	system("pause");
}