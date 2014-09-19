#include <iostream>
#include <vector>
#include <stdexcept>
#include <cstring>
#include <string>
using namespace std;

template<typename T>
struct Mat {
	int m;
	int n;
	T **v;
	Mat(int m_, int n_) :
			m(m_), n(n_) {
		v = new T*[m];
		for (int i = 0; i < m; ++i) {
			v[i] = new T[n];
		}
	}

	~Mat() {
		for (int i = 0; i < m; ++i) {
			delete[] v[i];
			v[i] = NULL;
		}
		delete[] v;
	}

	Mat(const Mat& mat) {
		this->m = mat.m;
		this->n = mat.n;
		this->v = mat.v;
	}

	Mat& operator=(const Mat& mat) {
		this->m = mat.m;
		this->n = mat.n;
		this->v = mat.v;
		return *this;
	}

	Mat& operator+=(const Mat& mat) {
		if (mat.m != this->m || mat.n != this->n) {
			throw std::invalid_argument("The dimensions don't match!");
		}
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				this->v[i][j] += mat.v[i][j];
			}
		}
		return *this;
	}
	Mat& operator-=(const Mat& mat) {
		if (mat.m != this->m || mat.n != this->n) {
			throw std::invalid_argument("The dimensions don't match!");
		}
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				this->v[i][j] -= mat.v[i][j];
			}
		}
		return *this;
	}


	friend Mat operator+(const Mat& mat1, const Mat& mat2) {
		if (mat1.m != mat2.m || mat1.n != mat2.n) {
			throw std::invalid_argument("The dimensions don't match!");
		}

		Mat ret(mat1.m, mat1.n);
		for (int i = 0; i < mat1.m; ++i) {
			for (int j = 0; j < mat1.n; ++j) {
				ret.v[i][j] = mat1.v[i][j] + mat2.v[i][j];
			}
		}
		return ret;

	}

	friend Mat operator-(const Mat& mat1, const Mat& mat2) {
		if (mat1.m != mat2.m || mat1.n != mat2.n) {
			throw std::invalid_argument("The dimensions don't match!");
		}

		Mat ret(mat1.m, mat1.n);
		for (int i = 0; i < mat1.m; ++i) {
			for (int j = 0; j < mat1.n; ++j) {
				ret.v[i][j] = mat1.v[i][j] - mat2.v[i][j];
			}
		}
		return ret;

	}

	friend Mat operator*(const Mat& mat1, const Mat& mat2) {
		if (mat1.n != mat2.m) {
			throw std::invalid_argument("The dimensions don't match!");
		}
		Mat ret(mat1.m, mat2.n);
		for (int i=0; i<mat1.m; ++i) {
			for (int j=0; j<mat2.n; ++j) {
				for (int k=0; k<mat1.n; ++k) {
					ret.v[i][j] += mat1.v[i][k] * mat2.v[k][j];
				}
			}
		}
		return ret;
	}

};

template <typename T>
void LCS_length(T *x, int xsize, T *y, int ysize, Mat<int> &c, Mat<string> &b)
{
	if (c.m != xsize+1 || c.n != ysize+1 || b.m != xsize+1 || b.n != ysize+1) {
		throw std::invalid_argument("The dimensions don't match!");
	}
	for (int i=0; i<=xsize; ++i) {
		c.v[i][0] = 0;
		b.v[i][0] = "";
	}
	for (int j=0; j<=ysize; ++j) {
		c.v[0][j] = 0;
		b.v[0][j] = "";
	}

	for (int i=0; i<xsize; ++i) {
		for (int j=0; j<ysize; ++j) {
			if (x[i] == y[j]) {
				c.v[i+1][j+1] = c.v[i][j] + 1;
				b.v[i+1][j+1] =  "↖";
			} else if (c.v[i][j+1]>=c.v[i+1][j]) {
				c.v[i+1][j+1] = c.v[i][j+1];
				b.v[i+1][j+1] = "↑";
			} else {
				c.v[i+1][j+1] = c.v[i+1][j];
				b.v[i+1][j+1] = "←";
			}
		}
	}
}

template <typename T>
void print_lcs(Mat<string> &b, T *x, int xsize, int i, int j) {
	if (i==0 || j==0) return;
	if (b.v[i][j] == "↖") {
		print_lcs(b, x, xsize, i-1, j-1);
		cout << x[i-1];
	} else if (b.v[i][j] == "↑") {
		print_lcs(b, x, xsize, i-1, j);
	} else {
		print_lcs(b, x, xsize, i, j-1);
	}
	cout << endl;
}

int main() {
	//char x[] = "ACCGGTCGAGTGCGCGGAAGCCGGCCGAA";
	//char y[] = "GTCGTTCGGAATGCCGTTGCTCTGTAAA";
	char x[] = "ABCBDAB";
	char y[] = "BDCABA";
	int xsize = strlen(x);
	int ysize = strlen(y);

	Mat<int> c(xsize+1, ysize+1);
	Mat<string> b(xsize+1, ysize+1);

	LCS_length(x, xsize, y, ysize, c, b);
	print_lcs(b, x, xsize, xsize, ysize);
	for (int i=1; i<c.m; ++i) {
		for (int j=1; j<c.n; ++j) {
			cout << c.v[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	for (int i=1; i<b.m; ++i) {
		for (int j=1; j<b.n; ++j) {
			cout << b.v[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;

	return 0;
}
