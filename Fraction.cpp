#include "Fraction.h"
#include <iostream>

int Fraction::gcd(int n, int d) {
    if (n%d==0) {
        return d;
    }
    int gcf;
    for (int i=1; i<=n && i<=d;i++) {
        if (n%i==0 && d%i==0) {
            gcf=i;
        }
    }
    return gcf;
}
Fraction::Fraction () {
  numer = 0;
  denom = 1;
}
Fraction::Fraction(int n, int d) {
    if (d == 0) {
        throw std::invalid_argument{"The denominator cannot be zero!"};
    }
    int greatFact=gcd(n,d);
    if (d<0) {
        d = d * -1;
        n = n * -1;
    }
    numer = n / greatFact;
    denom = d / greatFact;
}
void Fraction::setNumer(int n) {
    numer = n;
}
void Fraction::setDenom(int d) {
    if (d == 0) {
        throw std::invalid_argument{"The denominator cannot be zero!"};
    }
    if (d<0) {
        d = d * -1;
        numer = numer * -1;
    }
    int gcf = gcd(numer,d);
    numer = numer / gcf;
    denom = d / gcf;
}
double Fraction::displayFloat() const {
    return (double)numer / denom;
}
bool Fraction::operator==(const Fraction& frac) {
    if (numer == frac.numer && denom==frac.denom) {
        return true;
    } else {
        return false;
    }
}
bool Fraction::operator<(const Fraction& frac) {
    double temp_1 = numer/denom;
    double temp_2 = frac.numer / frac.denom;
    if (temp_1 < temp_2) {
        return true;
    } else {
        return false;
    }
}
bool Fraction::operator>(const Fraction& frac) {
    double temp_1 = numer/denom;
    double temp_2 = frac.numer / frac.denom;
    if (temp_1 > temp_2) {
        return true;
    } else {
        return false;
    }
}
bool Fraction::operator<=(const Fraction& frac) {
    if (*this < frac || *this == frac) {
        return true;
    } else {
        return false;
    }
}
bool Fraction::operator>=(const Fraction& frac) {
    if (*this > frac || *this == frac) {
        return true;
    } else {
        return false;
    }
}
Fraction Fraction::operator+(const Fraction& frac) {
    Fraction tmp(numer*frac.denom
                +frac.numer*denom,
                denom*frac.denom);
    return tmp;
}
Fraction Fraction::operator-(const Fraction& frac) {
    Fraction tmp(numer*frac.denom
                -frac.numer*denom,
                denom*frac.denom);
    return tmp;
}
Fraction Fraction::operator*(const Fraction& frac) {
    Fraction tmp(numer*frac.numer,
               denom*frac.denom);
    return tmp;
}
Fraction Fraction::operator*(int right) {
    Fraction tmp(right*numer,denom);
    return tmp;
}
Fraction Fraction::operator/(const Fraction& frac) {
    Fraction tmp(numer*frac.denom,
                 denom*frac.numer);
    return tmp;
}
Fraction Fraction::operator/(int right){
    Fraction tmp(numer,denom*right);
    return tmp;
}
std::ostream& operator<<(std::ostream &output, const Fraction &frac) {
    if (frac.denom == 1) {
        output << frac.numer;
    } else {
        output << frac.numer << "/" << frac.denom;
    }
    return output;
}
