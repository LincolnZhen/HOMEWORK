#pragma once
#ifndef BIGINT_H
#define BIGINT_H
#include <vector>
#include <iostream>
using namespace std;
class BigInt
{
private:
	vector<int> vec;
	int negative;
public:
	BigInt();
	BigInt(long long int a);
	BigInt(short int a);
	BigInt(int a);
	BigInt(char str[]);
	~BigInt();
    BigInt operator = (BigInt NUM);
	friend BigInt operator +(BigInt NUM1, BigInt NUM2);
	friend BigInt operator -(BigInt NUM1, BigInt NUM2);
	friend BigInt operator *(BigInt NUM1, BigInt NUM2);
	friend BigInt operator /(BigInt NUM1, BigInt NUM2);
	friend bool operator > (BigInt NUM1, BigInt NUM2);
	friend bool operator < (BigInt NUM1, BigInt NUM2);
	friend istream& operator >> (istream& a, BigInt& NUM);
	friend ostream& operator << (ostream& a, BigInt& NUM);
};
#endif
