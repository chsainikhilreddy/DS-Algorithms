#include<bits/stdc++.h>
#define ll long long
using namespace std;

void multiply(ll f[2][2], ll m[2][2]) {
	ll a = f[0][0] * m[0][0] + f[0][1] * m[1][0];
	ll b = f[0][0] * m[0][1] + f[0][1] * m[1][1];
	ll c = f[1][0] * m[0][0] + f[1][1] * m[1][0];
	ll d = f[1][0] * m[0][1] + f[1][1] * m[1][1];
	f[0][0] = a;
	f[0][1] = b;
	f[1][0] = c;
	f[1][1] = d;
}

void power(ll f[2][2], ll n) {
	if (n == 0 || n == 1) 
		return ;
	ll m[2][2] = {{1,1},{1,0}};
	
	power(f, n / 2);
	multiply(f, f);
	if (n & 1) 
		multiply(f, m);
}

ll fib(ll n) {
	if (n == 0) 
		return 0;
	ll f[2][2] = {{1,1},{1,0}};
	power(f, n - 1);
	return f[0][0];
}

int main() {
	cout << fib(100);
}


/* 

f(n) = f(n-1) + f(n-2)
The above equation can be represented as a product of 2 matrices(vectors) as:

f(n) = 	[1 1]  [f(n-1)
               f(n-2)]

This above equation can be modified as:

[f(n)     =  [1 1   [f(n-1)
 f(n-1)]      1 0]   f(n-2)]
   A           B      C
A = B * C
This can be used to derive an other equation:

A = B^(n-1) * [f(1) 
               f(0)]
               
The above exponentiation can be done in log(n) time.
*/

