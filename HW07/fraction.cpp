/**
 * Fraction.cpp
 * by Zhaoyuan Fang
 *
 * Homework 7 CSE 20133
 * The file with all the functions needed for the three programs to run
 */

#include <iostream>
#include <cmath>
#include "fraction.h"

using namespace std;

long GCD(long,long);
Fraction reduce(const Fraction & frac);

// Constructors
// Default constructor
Fraction::Fraction(){
  this->numerator = 0;
  this->denominator = 1;
}

// Constructor with only numerator argument
Fraction::Fraction(long a){
  this->numerator = a;
  this->denominator = 1;
}

// Constructor with both numerator and denominator arguments
Fraction::Fraction(long a, long b){
  // get the correct signs
  if(a>0){
    if(b>0){
      this->numerator = a;
      this->denominator = b;
    }else{
      this->numerator = -a;
      this->denominator = -b;
    }
  }else if(a<0){
    if(b>0){
      this->numerator = a;
      this->denominator = b;
    }else{
      this->numerator = -a;
      this->denominator = -b;
    }
  }else{
    this->numerator = 0;
    this->denominator = 1;
  }
}

// Type casting functions
// cast to double
Fraction::operator double(){
  return (double)this->numerator/this->denominator;
}

// cast to bool
Fraction::operator bool(){
  return this->numerator;
}

// IO operators
// istream
istream& operator>>(istream& lhs, Fraction& rhs){
  lhs >> rhs.numerator >> rhs.denominator;
  rhs = Fraction(rhs.numerator,rhs.denominator);
  return lhs;
}

ostream& operator<<(ostream& lhs, const Fraction& rhs){
  //reduce the fraction before printing.
  Fraction rhs_new = reduce(rhs);
  lhs << "(" << rhs_new.numerator << "/" << rhs_new.denominator << ")";
  return lhs;
}

// Declare a reduce() function
Fraction reduce(const Fraction & frac){
  long gcd = GCD(abs(frac.numerator), abs(frac.denominator));
  Fraction new_frac = frac;
  new_frac.numerator /= gcd;
  new_frac.denominator /=gcd;
  return new_frac;
}

// Find the Greatest Common Divider
long GCD(long x, long y) {
  if(y==0){
    cerr<<"Floating exception (core dumped)"<<endl;
    return 1;
  }
  if(x==0){
    return y;
  }
  while (x != y){
    if(x > y){
      x -= y;
    }
    else {
      y -= x;
    }
  }
  return x;
}

// Logical Operators
bool operator==(const Fraction& lhs, const Fraction& rhs){
  int ll=lhs.numerator*rhs.denominator,rr=lhs.denominator*rhs.numerator;
  return ll == rr;
}

bool operator!=(const Fraction& lhs, const Fraction& rhs){
  return !(lhs==rhs);
}

bool operator<(const Fraction& lhs, const Fraction& rhs){
  int ll=lhs.numerator*rhs.denominator,rr=lhs.denominator*rhs.numerator;
  return ll<rr;
}

bool operator>(const Fraction& lhs, const Fraction& rhs){
  int ll=lhs.numerator*rhs.denominator,rr=lhs.denominator*rhs.numerator;
  return ll>rr;
}

bool operator<=(const Fraction& lhs, const Fraction& rhs){
  // not larger than = smaller than or equal to
  return !(lhs>rhs);
}

bool operator>=(const Fraction& lhs, const Fraction& rhs){
  // not smaller than = larger than or equal to
  return !(lhs<rhs);
}

// Mathematical operators
Fraction operator+(const Fraction& lhs, const Fraction& rhs){
  int gcd = GCD(lhs.denominator, rhs.denominator);
  int denom = lhs.denominator * rhs.denominator / gcd;
  int numer = lhs.numerator * ( denom / lhs.denominator ) + rhs.numerator * (denom / rhs.denominator );
  return reduce(Fraction(numer,denom));
}

Fraction operator-(const Fraction& lhs, const Fraction& rhs){
  // subtract = minus plus
  return (lhs+Fraction(-rhs.numerator,rhs.denominator));
}

Fraction operator*(const Fraction& lhs, const Fraction& rhs){
  int denom = lhs.denominator * rhs.denominator;
  int numer = lhs.numerator * rhs.numerator;
  return reduce(Fraction(numer,denom));
}

Fraction operator/(const Fraction& lhs, const Fraction& rhs){
  int denom = lhs.denominator * rhs.numerator;
  int numer = lhs.numerator * rhs.denominator;
  return reduce(Fraction(numer,denom));
}

Fraction operator+=(Fraction& lhs, const Fraction& rhs){
  lhs = lhs + rhs;
  return lhs;
}

Fraction operator-=(Fraction& lhs, const Fraction& rhs){
  lhs = lhs - rhs;
  return lhs;
}

Fraction operator*=(Fraction& lhs, const Fraction& rhs){
  lhs = lhs * rhs;
  return lhs;
}

Fraction operator/=(Fraction& lhs, const Fraction& rhs){
  lhs = lhs / rhs;
  return lhs;
}

Fraction operator++(Fraction& f){
  f.numerator += f.denominator;
  return f;
}

Fraction operator--(Fraction& f){
  f.numerator -= f.denominator;
  return f;
}

Fraction operator++(Fraction& f, int){
  Fraction frac = f;
  f.numerator += f.denominator;
  return frac;
}

Fraction operator--(Fraction& f, int){
  Fraction frac = f;
  f.numerator -= f.denominator;
  return frac;
}
