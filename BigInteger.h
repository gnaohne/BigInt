/*
    Description: This file contains the definition of the BigInteger class and its helper functions. 
    The BigInteger class is used to represent large integers and perform arithmetic operations on them. 
    The class supports addition, subtraction, multiplication, division, and modular arithmetic operations.  
    The file also contains helper functions for generating large prime numbers, 
calculating the modular inverse of an integer.
    The file also contains the definition of the bezout function, which calculates the Bezout coefficients of two integers, 
and the divide function, which divides two integers.
*/

#ifndef BIGINTEGER_H
#define BIGINTEGER_H

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <chrono>
#include <random>
#include <bitset>

using namespace std;

#define ll long long
const int BIT_PER_DIGIT = 61;
const ll BASE = 1ll << BIT_PER_DIGIT;

using TYPE = ll;

int Primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29,
                31, 37, 41, 43, 47, 53, 59, 61, 67, 71,
                73, 79, 83, 89, 97, 101, 103, 107, 109, 113,
                127, 131, 137, 139, 149, 151, 157, 163, 167, 173,
                179, 181, 191, 193, 197, 199, 211, 223, 227, 229,
                233, 239, 241, 251, 257, 263, 269, 271, 277, 281,
                283, 293, 307, 311, 313, 317, 331, 337, 347, 349,
                353, 359, 367, 373, 379, 383, 389, 397, 401, 409,
                419, 421, 431, 433, 439, 443, 449, 457, 461, 463,
                467, 479, 487, 491, 499, 503, 509, 521, 523, 541};

class BigInteger {
private:
    vector<TYPE> digits;
    int sign;

public:
    BigInteger();

    BigInteger(const string &s);

    BigInteger(const string  &s, int base, int sign);

    BigInteger(TYPE l);

    BigInteger(const BigInteger &other);

    void trim();

    BigInteger abs() const;

    void setDigits(const vector<TYPE> &digit);

    void setSign(int s);

    const vector<TYPE> &getDigits() const;

    int getSign() const;

    int size() const;

    bool operator==(const BigInteger &a) const { return digits == a.digits && sign == a.sign; }

    bool operator!=(const BigInteger &a) const { return !(*this == a); }

    bool operator<(const BigInteger &a) const; 

    bool operator<=(const BigInteger &a) const;  

    bool operator>(const BigInteger &a) const; 

    bool operator>=(const BigInteger &a) const; 

    BigInteger operator+(const BigInteger &a) const;

    BigInteger operator-(const BigInteger &a) const;

    BigInteger operator*(const BigInteger &a) const;

    BigInteger operator%=(const BigInteger &a);

    BigInteger operator>>(int i);

    BigInteger operator<<(int i);

    string toString() const; // convert to binary string

    bool is_zero() const;

    bool is_even() const;

    BigInteger mod(const BigInteger &mod) const;

    BigInteger addMod(const BigInteger &other, const BigInteger &mod) const;

    BigInteger mulMod(const BigInteger &other, const BigInteger &mod) const;

    BigInteger powMod(const BigInteger &a, const BigInteger &mod) const;

    BigInteger pow(int n);

    int bitLength() const; 

    string toDecimal() const; // convert to decimal string
};

int msbPosition(ll x); // get the most significant bit position

auto bezout(const BigInteger &x, const BigInteger &y);

auto divide(const BigInteger &a, const BigInteger &b); // divide two big integers

BigInteger lcm(const BigInteger &x, const BigInteger &y);

bool Miller_Rabin_check(const BigInteger &n);

string hex_to_bin(const string &hex);

BigInteger generate_large_prime(int bit_length);

BigInteger mod_inverse(const BigInteger &a, const BigInteger &n);

string string_to_binary(const string &s);

string binary_to_string(const string &s);


#endif //BIGINTEGER_H
