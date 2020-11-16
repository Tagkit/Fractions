#ifndef Fraction_H
#define Fraction_H
#include <iostream>

class Fraction{
friend std::ostream& operator<<(std::ostream&,const Fraction&);

public:
    int gcd(int,int);
    Fraction();
    Fraction(int n, int d);
    void setNumer(int);
    void setDenom(int);
    bool operator==(const Fraction&);
    bool operator<(const Fraction&);
    bool operator>(const Fraction&);
    bool operator<=(const Fraction&);
    bool operator>=(const Fraction&);
    Fraction operator+(const Fraction&);
    Fraction operator+(int);
    Fraction operator-(const Fraction&);
    Fraction operator-(int);
    Fraction operator*(const Fraction&);
    Fraction operator*(int);
    Fraction operator/(const Fraction&);
    Fraction operator/(int);
private:
    int numer;
    int denom;
};

#endif
