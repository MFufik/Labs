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
    void toMixed(); // Вывод смешанной дроби
    Fraction reciprocal(); // Получение обратной дроби
    struct MixedFractoin
    {
        int whole;

    };
    int getNumerator() const;
    void setNumerator(int num);

    int getDenominator() const;
    void setDenominator(int den);

    Fraction operator+(const Fraction& other) const;
    Fraction operator-(const Fraction& other) const;
    Fraction operator*(const Fraction& other) const;
    Fraction operator/(const Fraction& other) const;

    bool operator>(const Fraction& other) const;
    bool operator<(const Fraction& other) const;
    bool operator==(const Fraction& other) const;
    bool operator!=(const Fraction& other) const;

    void input();
    void output() const;

    
};

