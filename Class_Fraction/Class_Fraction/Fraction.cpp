#include "fraction.h"
#include <cmath>

int Fraction::gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

void Fraction::simplify() {
    if (denominator == 0) {
        throw std::invalid_argument("Знаменатель не может быть нулем");
    }
    int divisor = gcd(numerator, denominator);
    numerator /= divisor;
    denominator /= divisor;
}
Fraction Fraction:: reciprocal(){
    if (numerator == 0)
    {
        throw std::runtime_error("Обратная дробь не определена");
    }
    return Fraction(denominator, numerator);
}
Fraction::Fraction() : numerator(1), denominator(2) {}

Fraction::Fraction(int num, int den) : numerator(num), denominator(den) {
    if (den == 0) {
        throw std::invalid_argument("Знаменатель не может быть равен нулю.");
    }
    simplify();
}

void Fraction::to_Mixed()
{
    if (denominator == 0) {
        throw std::invalid_argument("Знаменатель не может быть равен нулю.");
    }
    if (numerator > denominator) {
        int whole = numerator / denominator;
        int remainder = numerator % denominator;
        std::cout << "Смешанная дробь: " << whole << " " << remainder << "/" << denominator << std::endl;
    }
}
int Fraction::getNumerator() {
    return numerator;
}

void Fraction::setNumerator(int num) {
    numerator = num;
    simplify();
}

int Fraction::getDenominator() {
    return denominator;
}

void Fraction::setDenominator(int den) {
    if (den == 0) {
        throw std::invalid_argument("Знаменатель не может быть равен нулю.");
    }
    denominator = den;
    simplify();
}

Fraction Fraction::operator+(const Fraction& other) {
    int newNumerator = numerator * other.denominator + denominator * other.numerator;
    int newDenominator = denominator * other.denominator;
    return Fraction(newNumerator, newDenominator);
}

Fraction Fraction::operator-(const Fraction& other) {
    int newNumerator = numerator * other.denominator - denominator * other.numerator;
    int newDenominator = denominator * other.denominator;
    return Fraction(newNumerator, newDenominator);
}

Fraction Fraction::operator*(const Fraction& other) {
    int newNumerator = numerator * other.numerator;
    int newDenominator = denominator * other.denominator;
    return Fraction(newNumerator, newDenominator);
}

Fraction Fraction::operator/(const Fraction& other) {
    if (other.numerator == 0) {
        throw std::domain_error("Деление на ноль недопустимо.");
    }
    int newNumerator = numerator * other.denominator;
    int newDenominator = denominator * other.numerator;
    return Fraction(newNumerator, newDenominator);
}

bool Fraction::operator>(const Fraction& other) {
    return (numerator * other.denominator) > (denominator * other.numerator);
}

bool Fraction::operator<(const Fraction& other) {
    return (numerator * other.denominator) < (denominator * other.numerator);
}

bool Fraction::operator==(const Fraction& other) {
    return (numerator * other.denominator) == (denominator * other.numerator);
}

bool Fraction::operator!=(const Fraction& other) {
    return (numerator * other.denominator) != (denominator * other.numerator);
}

void Fraction::input() {
    std::cout << "Введите числитель: ";
    std::cin >> numerator;
    std::cout << "Введите знаменатель: ";
    std::cin >> denominator;
    if (denominator == 0) {
        throw std::invalid_argument("Знаменатель не может быть нулем");
    }   
        simplify();
}

void Fraction::output() {
    std::cout << numerator << "/" << denominator << std::endl;
}

