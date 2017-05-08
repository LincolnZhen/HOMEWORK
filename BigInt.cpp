#include "BigInt.h"
#include <cstring>
#include <string>
#include <iostream>
using namespace std;
BigInt operator - (BigInt NUM1, BigInt NUM2);
BigInt::BigInt()
{
	negative = 0;
}


BigInt::~BigInt()
{
}

BigInt::BigInt(long long int a)
{
	if (a < 0)
	{
		negative = 1;
		a = -a;
	}
	else
	{
		negative = 0;
	}
	
	while (a > 9)
	{
		vec.push_back(a % 10);
		a = a / 10;
	}
	vec.push_back((int) a);
}

BigInt::BigInt(short int a)
{
	if (a < 0)
	{
		negative = 1;
		a = -a;
	}
	else
	{
		negative = 0;
	}
	while (a > 9)
	{
		vec.push_back(a % 10);
		a = a / 10;
	}
	vec.push_back(a);
}

BigInt::BigInt(int a)
{
	if (a < 0)
	{
		negative = 1;
		a = -a;
	}
	else
	{
		negative = 0;
	}
	while (a > 9)
	{
		vec.push_back(a % 10);
		a = a / 10;
	}
	vec.push_back(a);
}
BigInt::BigInt(char str[])
{
	int end;
	if (str[0] == '-')
	{
		negative = 1;
		end = 1;
	}
	else
	{
		negative = 0;
		end = 0;
	}
	int i;
	for (i = strlen(str) - 1; i >= end; i--)
	{
		vec.push_back(str[i] - '0');
	}
}
BigInt BigInt::operator = (BigInt NUM)
{
	vec = NUM.vec;
	negative = NUM.negative;
	return *this;
}
BigInt operator +(BigInt NUM1, BigInt NUM2)
{
	if (NUM1.negative == 1 && NUM2.negative == 0)
	{
		NUM1.negative = 0;
		return (NUM2 - NUM1);
	}
	if (NUM1.negative == 0 && NUM2.negative == 1)
	{
		NUM2.negative =0;
		return (NUM1 - NUM2);
	}
	BigInt result;
	if (NUM1.negative == 1 && NUM2.negative == 1)
	{
		result.negative = 1;
	}
	else
	{
		result.negative= 0;
	}
	int sLength, lLength;
	vector<int>  sadd;
	if (NUM1.vec.size() >= NUM2.vec.size())
	{
		lLength = NUM1.vec.size();
		sLength = NUM2.vec.size();
		result.vec = NUM1.vec;
		sadd = NUM2.vec;
	}
	else
	{
		lLength = NUM2.vec.size();
		sLength = NUM1.vec.size();
		result.vec = NUM2.vec;
		sadd = NUM1.vec;
	}
	int i = 0;
	for (; i < sLength; i++) 
	{
		result.vec[i] += sadd[i];
		if (result.vec[i] >= 10)
		{
			result.vec[i] = result.vec[i] - 10;
			if (i < lLength - 1)
				result.vec[i + 1]++;
			else
				result.vec.push_back(1);
		}
	}
	for (i = sLength; i < lLength-1; i++)
	{
		if (result.vec[i] >= 10)
		{
			result.vec[i] -= 10;
			result.vec[i + 1]++;
		}
	}
	if (result.vec[lLength - 1] >= 10)
	{
		result.vec[lLength - 1] -= 10;
		result.vec.push_back(1);
	}
	return result;
}
istream& operator >> (istream& in, BigInt& NUM)
{
	string str;
	in >> str;
	int end;
	if (str[0] == '-')
	{
		NUM.negative = 1;
		end = 1;
	}
	else
	{
		end = 0;
		NUM.negative = 0;
	}
	int i;
	for (i = str.length() - 1; i >= end; i--)
	{
		NUM.vec.push_back(str[i]-'0');
	}
	return in;
}
ostream& operator << (ostream& out, BigInt& NUM)
{
	string str;
	if (NUM.negative == 1)
	{
		out << '-';
	}
	int i;
	for (i = NUM.vec.size ()-1;i>=0; i--)
	{
		str += NUM.vec[i]+'0';
	}
	out << str;
	return out;
}
BigInt operator - (BigInt NUM1, BigInt NUM2)
{
	if (NUM1.negative == 0 && NUM2.negative == 1)
	{
		NUM2.negative = 0;
		return (NUM2 + NUM1);
	}
	if (NUM1.negative == 1 && NUM2.negative == 0)
	{
		NUM2.negative = 1;
		return (NUM1 + NUM2);
	}
	if (NUM1.negative == 1 && NUM2.negative == 1)
	{
		NUM1.negative = 0;
		NUM2.negative = 0;
		return (NUM2 - NUM1);
	}
	BigInt result;
	vector<int> vec;
	int i;
	int shorter;
	if (NUM1.vec.size() > NUM2.vec.size())
	{
		result.vec = NUM1.vec;
		vec = NUM2.vec;
		shorter = NUM2.vec.size();
		result.negative = 0;
	}
	else
	{
		if (NUM1.vec.size() == NUM2.vec.size())
		{
			for (i = NUM1.vec.size()-1; i >=0;i--)
			{
				if (NUM1.vec[i] < NUM2.vec[i])
				{
					result.negative = 1;
					result.vec = NUM2.vec;
					vec = NUM1.vec;
					shorter = NUM1.vec.size();
					break;
				}
				if (NUM1.vec[i] > NUM2.vec[i])
				{
					result.negative = 0;
					result.vec = NUM1.vec;
					vec = NUM2.vec;
					shorter = NUM2.vec.size();
					break;
				}
			}
			if (i == -1)
			{
				return (BigInt)0;
			}
		}
		else
		{
			result.negative = 1;
			result.vec = NUM2.vec;
			vec = NUM1.vec;
			shorter = NUM1.vec.size();
		}
	}
	for (i = 0; i < shorter; i++)
	{
		result.vec[i] -= vec[i];
		if (result.vec[i] < 0)
		{
			result.vec[i] += 10;
			result.vec[i + 1]--;
		}
	}

	for (i = shorter; i < result.vec.size(); i++)
	{
		if (result.vec[i] < 0)
		{
			result.vec[i] += 10;
			result.vec[i + 1]--;
		}
	}
	while (1)
	{
		if (result.vec[result.vec.size() - 1] == 0)
		{
			result.vec.pop_back();
		}
		else
		{
			break;
		}
	}
	return result;
}
BigInt operator * (BigInt NUM1, BigInt NUM2)
{
	BigInt result,temp;
	result = (BigInt)0;
	int shorter;
	vector<int> vec;
	if (NUM1.vec.size() > NUM2.vec.size())
	{
		temp.vec = NUM1.vec;
		vec = NUM2.vec;
		shorter = NUM2.vec.size();
	}
	else
	{
		temp.vec = NUM2.vec;
		vec = NUM1.vec;
		shorter = NUM1.vec.size();
	}
	int i;
	int j;
	int cache;
	for (i = 0; i < shorter; i++)
	{
		BigInt temp2;
		cache = 0;
		for (j = 0; j < i; j++)
		{
			temp2.vec.push_back(0);
		}
		for (j = 0; j < temp.vec.size(); j++)
		{
			int mulit = temp.vec[j] * vec[i] + cache;
			if (mulit >= 10)
			{
				cache = mulit / 10;
				temp2.vec.push_back(mulit % 10);
			}
			else
			{
				cache = 0;
				temp2.vec.push_back(mulit);
			}
		}
		if (cache != 0)
		{
			temp2.vec.push_back(cache);
		}
		result = result + temp2;
	}
	if (NUM1.negative == 0 && NUM2.negative == 1)
	{
		result.negative = 1;
	}
	if (NUM1.negative == 1 && NUM2.negative == 0)
	{
		result.negative = 1;
	}
	return result;
}
bool operator >(BigInt NUM1, BigInt NUM2)
{
	if (NUM1.negative == 0 && NUM2.negative == 1)
		return true;
	if (NUM1.negative == 1 && NUM2.negative == 0)
		return false;
	int negative;
	if (NUM1.negative == 0 && NUM2.negative == 0)
	{
		if (NUM1.vec.size() > NUM2.vec.size())return true;
		if (NUM1.vec.size() < NUM2.vec.size())return false;
	}
	if (NUM1.negative == 1 && NUM2.negative == 1)
	{
		if (NUM1.vec.size() > NUM2.vec.size())return false;
		if (NUM1.vec.size() < NUM2.vec.size())return true;
	}
	if (NUM1.negative == 1 && NUM2.negative == 1)
		negative = 1;
	else
		negative = 0;
	int i;
	for(i = NUM1.vec.size() - 1; i >= 0; i--)
	{
		if (NUM1.vec[i] > NUM2.vec[i])return true;
		if (NUM1.vec[i] < NUM2.vec[i])return false;
	}
	return false;
}
bool operator <(BigInt NUM1, BigInt NUM2)
{
	if (NUM1.negative == 0 && NUM2.negative == 1)
		return false;
	if (NUM1.negative == 1 && NUM2.negative == 0)
		return true;
	int negative;
	if (NUM1.negative == 0 && NUM2.negative == 0)
	{
		if (NUM1.vec.size() > NUM2.vec.size())return false;
		if (NUM1.vec.size() < NUM2.vec.size())return true;
	}
	if (NUM1.negative == 1 && NUM2.negative == 1)
	{
		if (NUM1.vec.size() > NUM2.vec.size())return true;
		if (NUM1.vec.size() < NUM2.vec.size())return false;
	}
	if (NUM1.negative == 1 && NUM2.negative == 1)
		negative = 1;
	else
		negative = 0;
	int i;
	for (i = NUM1.vec.size() - 1; i >= 0; i--)
	{
		if (NUM1.vec[i] > NUM2.vec[i])return false;
		if (NUM1.vec[i] < NUM2.vec[i])return true;
	}
	return false;
}
BigInt operator /(BigInt NUM1, BigInt NUM2)
{
	BigInt result;
	if (NUM1 < NUM2)
	{
		result = 0;
		return result;
	}
	if (NUM1.vec == NUM2.vec)
	{
		if (NUM1.negative == NUM2.negative)
		{
			result = 1;
			return result;
		}
		else
		{
			result = -1;
			return result;
		}
	}
	if (NUM1.negative != NUM2.negative)
	{
		result.negative = 1;
	}
	int i=1;
	NUM2.negative = 0;
	BigInt TEMP = NUM2;
	NUM1.negative = 0;
	int gap = NUM1.vec.size() - NUM2.vec.size();
	for (i = 0; i <= gap; i++)
	{
		result.vec.push_back(0);
	}
	while (NUM1 > NUM2)
	{
		i = 1;
		while (TEMP*10 < NUM1) 
		{  
			i++;
			TEMP = TEMP * 10;
		}
		if (i-2>0 ) 
		{
			result.vec[i - 2]++;
			NUM1 = NUM1 - TEMP;
			TEMP = NUM2;
			if (result.vec[i - 1]>=10)
			{
				result.vec[i - 1] -= 10;
				result.vec[i]++;
			}
		}
		else
		{
			break;
		}
	}
	while (NUM1 > NUM2)
	{
		NUM1 = NUM1 - NUM2;
		result.vec[0]++;
		if (result.vec[0] >= 10)
		{
			result.vec[0] -= 10;
			result.vec[1]++;
		}
	}
	while (result.vec[result.vec.size() - 1] == 0)
		result.vec.pop_back();
	return result;
}