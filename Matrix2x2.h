//-----------------------------------------------
/**
*	The is the header file for Matrix2x2 class.
This file describes all the functions required
for the working of the Matrix2x2 object.

The default constructor of the class creates a
2x2 matrix with all values initialized to 0.
The user defined constructor accepts 4 values as
parameters and initialize all 4 elements of 2x2
matrix with corresponding values.

The header file contains the description of functions
like compound and basic arithmetic operators, comparison
operators, overloaded subscript operators, etc.

*
* @author  Mehakpreet Singh
* @version 1.0
* @since   2018-07-14
*/
//-----------------------------------------------

#ifndef MATRIX2X2_H
#define MATRIX2X2_H

#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>

class Matrix2x2 {
private:
	double a, b, c, d;
	int findLargest() const;
public:
	Matrix2x2();		//default constructor
	Matrix2x2(double,double,double,double);		//normal constructor
	Matrix2x2(const Matrix2x2&) = default;				//default copy constructor
	Matrix2x2& operator=(const Matrix2x2&) = default;		//default assignment operator
	~Matrix2x2() = default;
	
	double determinant() const;
	double trace() const;
	bool isSymmetric() const;
	bool isSimilar(const Matrix2x2&) const;
	Matrix2x2 transpose() const;
	Matrix2x2 inverse() const;

	//Unary operators
	Matrix2x2& operator++();				//prefix addition
	Matrix2x2 operator++(int);			//postfix addition
	Matrix2x2& operator--();				//prefix subtraction
	Matrix2x2 operator--(int);			//postfix subtraction
	Matrix2x2 operator-();
	Matrix2x2 operator+();

	//compound arithmetic oprators
	friend Matrix2x2& operator+=(Matrix2x2&, const Matrix2x2&);
	friend Matrix2x2& operator-=(Matrix2x2&, const Matrix2x2&);
	friend Matrix2x2& operator*=(Matrix2x2&, const Matrix2x2&);
	friend Matrix2x2& operator/=(Matrix2x2&, const Matrix2x2&);
	friend Matrix2x2& operator+=(Matrix2x2&, const double);
	friend Matrix2x2& operator-=(Matrix2x2&, const double);
	friend Matrix2x2& operator*=(Matrix2x2&, const double);
	friend Matrix2x2& operator/=(Matrix2x2&, const double);

	//basic arithmetic operators
	friend Matrix2x2 operator+(const Matrix2x2&, const Matrix2x2&);
	friend Matrix2x2 operator-(const Matrix2x2&, const Matrix2x2&);
	friend Matrix2x2 operator*(const Matrix2x2&, const Matrix2x2&);
	friend Matrix2x2 operator/(const Matrix2x2&, const Matrix2x2&);
	friend Matrix2x2 operator+(const Matrix2x2&, const double);
	friend Matrix2x2 operator-(const Matrix2x2&, const double);
	friend Matrix2x2 operator*(const Matrix2x2&, const double);
	friend Matrix2x2 operator/(const Matrix2x2&, const double);
	friend Matrix2x2 operator+(const double, const Matrix2x2&);
	friend Matrix2x2 operator-(const double, const Matrix2x2&);
	friend Matrix2x2 operator*(const double, const Matrix2x2&);
	friend Matrix2x2 operator/(const double, const Matrix2x2&);
	
	friend std::ostream& operator<<(std::ostream&, const Matrix2x2&);	//insertion operator overloaded
	friend void operator>>(std::istream&, Matrix2x2&);					//extraction operator overloaded
	
	//comparison operators
	friend bool operator==(const Matrix2x2&, const Matrix2x2&);
	friend bool operator!=(const Matrix2x2&, const Matrix2x2&);

	double operator()();
	std::vector<double> operator()(int);
	double& operator[](int);
	const double& operator[](int) const;
};

#endif // !MATRIX2X2_H
