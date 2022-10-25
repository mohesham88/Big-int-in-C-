#ifndef BIG_INT_H
#define BIG_INT_H

#include<bits\stdc++.h>
using namespace std;


class BigDecimalInt{
    string big_decimal;
    public:
    BigDecimalInt();                                                                                                // default constructor to set value to 0 if no value assigned
    BigDecimalInt(string dec_str);
    BigDecimalInt(int dec_int);
    BigDecimalInt operator+(BigDecimalInt another_dec);
    BigDecimalInt operator-(BigDecimalInt another_dec);
    BigDecimalInt operator=(const BigDecimalInt& another_dec);
    bool operator<(BigDecimalInt another_dec);
    bool operator>(BigDecimalInt another_dec);
    bool operator==(BigDecimalInt another_dec);
    friend ostream& operator<<(ostream &out,BigDecimalInt another_dec);
    friend istream& operator>>(istream &in,BigDecimalInt &another_dec);
    int size();
    char sign();
};

#endif