//-----------------------------------------------
/**
*	This is the implementation file for "Matrix2x2.h"
*
* @author  Mehakpreet Singh
* @version 1.0
* @since   2018-07-14
*/
//-----------------------------------------------

#include "Matrix2x2.h"

//-----------------------------------------------
/*
The default constructor of the class creates a
2x2 matrix with all values initialized to 0.
*/
//-----------------------------------------------
Matrix2x2::Matrix2x2() {
	a = b = c = d = 0;
}

//-----------------------------------------------
/*
The user defined constructor accepts 4 values as
parameters and initialize all 4 elements of 2x2
matrix with corresponding values.
*/
//-----------------------------------------------
Matrix2x2::Matrix2x2(double a, double b, double c, double d) {
	this->a = a;
	this->b = b;
	this->c = c;
	this->d = d;
}

//-----------------------------------------------
/*
This returns the determinant of the matrix
	|a b|
	|c d|
i.e. (ad - bc)

*/
//-----------------------------------------------
double Matrix2x2::determinant() const {
	double val = (a * d) - (b * c);
	if (val == (int)val)
		std::cout << std::setprecision(0);
	return val;
}

//-----------------------------------------------
/*
This returns the trace of the matrix
|a b|
|c d|
i.e. (a+d)

*/
//-----------------------------------------------
double Matrix2x2::trace() const {
	double val = a + d;;
	if (val == (int)val)
		std::cout << std::setprecision(0);
	return val;
}

//-----------------------------------------------
/*
This returns whether the matrix is symmetric
|a b|
|c d|
i.e. (b==c)
*/
//-----------------------------------------------
bool Matrix2x2::isSymmetric() const {
	return b == c;
}

//-----------------------------------------------
/*
This returns whether the two matrix are similar to
one another
*/
//-----------------------------------------------
bool Matrix2x2::isSimilar(const Matrix2x2& m) const{
	return (this->determinant() == m.determinant()) && (this->trace() == m.trace());
}

//-----------------------------------------------
/*
This returns the transpose() of the matrix
*/
//-----------------------------------------------
Matrix2x2 Matrix2x2::transpose() const {
	Matrix2x2 m = *this;
	m.b = this->c;
	m.c = this->b;
	return m;
}

//-----------------------------------------------
/*
This returns the inverse of the matrix
*/
//-----------------------------------------------
Matrix2x2 Matrix2x2::inverse() const {
	Matrix2x2 m;
	m.a = this->d;
	m.b = -(this->b);
	m.c = -(this->c);
	m.d = this->a;
	double det = m.determinant();
	double epsilon = 0.000001;
	if (std::abs(det) <= epsilon)
		throw std::overflow_error("Inverse undefined");
	m = m/det;
	return m;
}


//-----------------------------------------------
/*
The following section contains the unary operators
1.	++	prefix and postfix increment operators
2.	--	prefix and postfix decrement operators
3.	-	toggle the sign of all the elements of matrix
4.	+	doesn't affect the matrix
*/
//-----------------------------------------------

Matrix2x2& Matrix2x2::operator++() {
	return ((*this) += 1);
}
Matrix2x2& Matrix2x2::operator--() {
	return ((*this) -= 1);
}
Matrix2x2 Matrix2x2::operator++(int val) {
	Matrix2x2 temp = *this;
	((*this) += 1);
	return temp;
}
Matrix2x2 Matrix2x2::operator--(int val) {
	Matrix2x2 temp = *this;
	((*this) -= 1);
	return temp;
}
Matrix2x2 Matrix2x2::operator-() {
	Matrix2x2 temp = *this;
	temp.a = -(temp.a);
	temp.b = -(temp.b);
	temp.c = -(temp.c);
	temp.d = -(temp.d);
	return temp;
}
Matrix2x2 Matrix2x2::operator+() {
	Matrix2x2 temp = *this;
	return temp;
}

//-----------------------------------------------
/*
The following section contains the compound assignment operators
1.	+=	compound addition of two matrices
2.	-=	compound subtraction of two matrices
3.	*=	compound multiplication of two matrices
4.	/=	compound division of two matrices
5.	+=	compound addition of a matrix and scalar value
6.	-=	compound subtraction of a matrix and scalar value
7.	*=	compound multiplication of a matrix and scalar value
8.	/=	compound division of a matrix and scalar value
*/
//-----------------------------------------------
//1
Matrix2x2& operator+=(Matrix2x2& m1, const Matrix2x2& m2) {
	m1.a += m2.a;
	m1.b += m2.b;
	m1.c += m2.c;
	m1.d += m2.d;
	return m1;
}
//2
Matrix2x2& operator-=(Matrix2x2& m1, const Matrix2x2& m2) {
	m1.a -= m2.a;
	m1.b -= m2.b;
	m1.c -= m2.c;
	m1.d -= m2.d;
	return m1;
}
//3
Matrix2x2& operator*=(Matrix2x2& m1, const Matrix2x2& m2) {
	Matrix2x2 m;
	m.a = (m1.a * m2.a) + (m1.b * m2.c) + 0.0;
	m.b = (m1.a * m2.b) + (m1.b * m2.d) + 0.0;
	m.c = (m1.c * m2.a) + (m1.d * m2.c) + 0.0;
	m.d = (m1.c * m2.b) + (m1.d * m2.d) + 0.0;
	m1 = m;
	return m1;
}
//4
Matrix2x2& operator/=(Matrix2x2& m1, const Matrix2x2& m2) {
	m1 *= m2.inverse();
	return m1;
}
//5
Matrix2x2& operator+=(Matrix2x2& m1, const double val) {
	m1.a += val;
	m1.b += val;
	m1.c += val;
	m1.d += val;
	return m1;
}
//6
Matrix2x2& operator-=(Matrix2x2& m1, const double val) {
	m1.a -= val;
	m1.b -= val;
	m1.c -= val;
	m1.d -= val;
	return m1;
}
//7
Matrix2x2& operator*=(Matrix2x2& m1, const double val) {
	m1.a = (m1.a * val) + 0.0;
	m1.b = (m1.b * val) + 0.0;
	m1.c = (m1.c * val) + 0.0;
	m1.d = (m1.d * val) + 0.0;
	return m1;
}
//8
Matrix2x2& operator/=(Matrix2x2& m1, const double val) {
	m1.a /= val;
	m1.b /= val;
	m1.c /= val;
	m1.d /= val;
	return m1;
}

//-----------------------------------------------
/*
The following section contains the compound assignment operators
1.	+	addition of two matrices
2.	-	subtraction of two matrices
3.	*	multiplication of two matrices
4.	/	division of two matrices
5.	+	addition of a matrix and scalar value
6.	-	subtraction of a matrix and scalar value
7.	*	multiplication of a matrix and scalar value
8.	/	division of a matrix and scalar value
9.	+	addition of scalar value and a matrix
10.	-	subtraction scalar value and a matrix
11.	*	multiplication scalar value and a matrix
12.	/	division scalar value and a matrix
*/
//-----------------------------------------------
//1
Matrix2x2 operator+(const Matrix2x2& m1, const Matrix2x2& m2) {
	Matrix2x2 m = m1;
	return m += m2;
}
//2
Matrix2x2 operator-(const Matrix2x2& m1, const Matrix2x2& m2) {
	Matrix2x2 m = m1;
	return m -= m2;
}
//3
Matrix2x2 operator*(const Matrix2x2& m1, const Matrix2x2& m2) {
	Matrix2x2 m = m1;
	return m *= m2;
}
//4
Matrix2x2 operator/(const Matrix2x2& m1, const Matrix2x2& m2) {
	Matrix2x2 m = m1;
	return m /= m2;
}
//5
Matrix2x2 operator+(const Matrix2x2& m1, const double val) {
	Matrix2x2 m = m1;
	return m += val;
}
//6
Matrix2x2 operator-(const Matrix2x2& m1, const double val) {
	Matrix2x2 m = m1;
	return m -= val;
}
//7
Matrix2x2 operator*(const Matrix2x2& m1, const double val) {
	Matrix2x2 m = m1;
	return m *= val;
}
//8
Matrix2x2 operator/(const Matrix2x2& m1, const double val) {
	Matrix2x2 m = m1;
	return m /= val;
}
//9
Matrix2x2 operator+(const double val, const Matrix2x2& m1) {
	return (m1 + val);
}
//10
Matrix2x2 operator-(const double val, const Matrix2x2& m1) {
	Matrix2x2 m = m1 - val;
	return (m*-1.0)+0.0;
}
//11
Matrix2x2 operator*(const double val, const Matrix2x2& m1) {
	return (m1 * val);
}
//12
Matrix2x2 operator/(const double val, const Matrix2x2& m1) {
	Matrix2x2 m = m1.inverse();
	return val * m;
}

//-----------------------------------------------
/*
This function overloads the square brackets to return
the elements of the matrix
m[0] = a
m[1] = b
m[2] = c
m[3] = d
It throws an index out of bounds error if the index is
some other value than 0, 1, 2 or 3
*/
//-----------------------------------------------
double& Matrix2x2::operator[](int index) {
	if (index < 0 || index > 3)
		throw std::invalid_argument("index out of bounds");
	if (index == 0)
		return a;
	else if (index == 1)
		return b;
	else if (index == 2)
		return c;
	else if (index == 3)
		return d;
}

//-----------------------------------------------
/*
This is same as the above function except that it
is implemented to use for the const matrix
*/
//-----------------------------------------------
const double& Matrix2x2::operator[](int index) const{
	if (index < 0 || index > 3)
		throw std::invalid_argument("index out of bounds");
	if (index == 0)
		return a;
	else if (index == 1)
		return b;
	else if (index == 2)
		return c;
	else if (index == 3)
		return d;
}

//-----------------------------------------------
/*
This function overloads the paranthesis to return
the determinant of the matrix if no value in provided
inside the matrix
*/
//-----------------------------------------------
double Matrix2x2::operator()() {
	return this->determinant();
}

//-----------------------------------------------
/*
This function overloads the paranthesis to return
the EIGEN VALUES i.e. roots of the matrix 
the value provided as parameter tell whether to return
eigen value 1 or 2
if the value is other than 1 or 2, the function throws
an error

the values are returned as a vector<double>
*/
//-----------------------------------------------
std::vector<double> Matrix2x2::operator()(int n) {
	if (n != 1 && n != 2)
		throw std::invalid_argument("index out of bounds");
	else {
		std::vector<double> eigen1, eigen2;
		double delta = ((this->trace())*(this->trace())) - (4 * (this->determinant()));
		if (delta >= 0) {
			eigen1.push_back((this->trace() + std::sqrt(delta)) / 2);
			eigen2.push_back((this->trace() - std::sqrt(delta)) / 2);
		}
		else {
			eigen1.push_back(this->trace() / 2);
			eigen1.push_back(std::sqrt(std::abs(delta)) / 2);
			eigen2.push_back(this->trace() / 2);
			eigen2.push_back(-(std::sqrt(std::abs(delta)) / 2));
		}
		if (n == 1)
			return eigen1;
		else if (n == 2)
			return eigen2;
	}
}

//-----------------------------------------------
/*
This function is used to check equality of two matrices
*/
//-----------------------------------------------
bool operator==(const Matrix2x2& m1, const Matrix2x2& m2) {
	double epsilon = 0.000001;
	if (std::abs(m1.a - m2.a) < epsilon)
		if (std::abs(m1.b - m2.b) < epsilon)
			if (std::abs(m1.c - m2.c) < epsilon)
				if (std::abs(m1.d - m2.d) < epsilon)
					return true;
	return false;
}

//-----------------------------------------------
/*
This function is used to check inequality of two matrices
*/
//-----------------------------------------------
bool operator!=(const Matrix2x2& m1, const Matrix2x2& m2) {
	return !(m1 == m2);
}

//-----------------------------------------------
/*
This function overloads the extraction operator
to prompt user to enter 4 values which are 
then used to create a new 2x2 matrix
*/
//-----------------------------------------------
void operator>>(std::istream& in, Matrix2x2& m) {
	std::cout << "To create the following 2x2 matrix:\n";
	std::cout << "|a b|\n|   |\n|c d|\n";
	std::cout << "enter four numbers a, b, c, d, in that order:\n";
	in >> m.a >> m.b >> m.c >> m.d;
}

//-----------------------------------------------
/*
This function overloads the insertion operator
to print the 2x2 matrix in the specified format
*/
//-----------------------------------------------
std::ostream& operator<<(std::ostream& out, const Matrix2x2& m) {
	int n = m.findLargest();
	out << "|" << std::setw(n)<< std::fixed << std::setprecision(2) << m.a << " " <<
		std::setw(n) << std::fixed << std::setprecision(2) << m.b << "|\n";
	out << "|" << std::setw(2*n+3) << std::right << "|\n";
	out << "|" << std::setw(n) << std::fixed << std::setprecision(2) << m.c << " " <<
		std::setw(n) << std::fixed << std::setprecision(2) << m.d << "|" << std::endl;
	return out;
}

//helper functions
int Matrix2x2::findLargest() const {
	int x;
	int n = 4;
	
	if (std::abs(this->a) > std::abs(this->b) && std::abs(this->a) > std::abs(this->c) && std::abs(this->a) > std::abs(this->d))
		x = abs(this->a);
	else if (std::abs(this->b) > std::abs(this->c) && std::abs(this->b) > std::abs(this->d) && std::abs(this->b) > std::abs(this->a))
		x = abs(this->b);
	else if (std::abs(this->c) > std::abs(this->a) && std::abs(this->c) > std::abs(this->b) && std::abs(this->c) > std::abs(this->d))
		x = abs(this->c);
	else
		x = abs(this->d);
	
	if (x == 0)
		n++;
	else {
		while (x > 0) {
			x = x / 10;
			n++;
		}
	}
	return n;
}