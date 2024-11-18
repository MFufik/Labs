#pragma once
#include <iostream>


class Fraction {
private:
    int numerator;
    int denominator;
    int gcd(int a, int b);
    void simplify();
    
public:
    Fraction();
    Fraction(int num, int den);
    void to_Mixed(); // Вывол смешанной дроби
    Fraction reciprocal(); // Получение обратной дроби
    
    int getNumerator();
    void setNumerator(int num);

    int getDenominator();
    void setDenominator(int den);

    Fraction operator+(const Fraction& other);
    Fraction operator-(const Fraction& other);
    Fraction operator*(const Fraction& other);
    Fraction operator/(const Fraction& other);

    bool operator>(const Fraction& other);
    bool operator<(const Fraction& other);
    bool operator==(const Fraction& other);
    bool operator!=(const Fraction& other);

    void input();
    void output();

    
};

