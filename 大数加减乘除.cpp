#include <iostream>
#include "BigInt.h"
using namespace std;
int main()
{
	//���Լӷ�
	/*BigInt a("999999999999999999999"),b("6666"),c;
	c = a+b;
	cout<<a<<"+"<<b<<"="<<c<<endl;
	BigInt d("-1111");
	c = a+d;
	cout<<a<<"+"<<d<<"="<<c<<endl;
	c = 7777777+a;
	cout<<"7777777"<<"+"<<a<<"="<<c<<endl;*/
	////���Լ���
	/*BigInt a("999999999999999999999"),b("8888"),c;
	c = a-b;
	cout<<a<<"-"<<b<<"="<<c<<endl;
	BigInt d("-1111");
	c = a-d;
	cout<<a<<"-"<<d<<"="<<c<<endl;*/
	////���Գ˷�
	/*BigInt a("999999999999999999999"),b("10"),c;
	c = a*b;
	cout<<a<<"*"<<b<<"="<<c<<endl;
	BigInt d("1111");
	c = a*d;
	cout<<a<<"*"<<d<<"="<<c<<endl;
	d = 7777777;
	cout<<a<<"*"<<d<<"=" << d*a << endl;*/
	///���Գ���
	BigInt a("999999999999999999999"),b("888888888888888"),c;
	c = a/b;
	cout<<a<<"/"<<b<<"="<<c<<endl;
	c = b/a;
	cout<<b<<"/"<<a<<"="<<c<<endl;
	BigInt d("-111111111111111");
	c = a/d;
	cout<<a<<"/"<<d<<"="<<c<<endl;
	c = 0/a;
	cout<<"0"<<"/"<<a<<"="<<c<<endl;
	return 0;
}