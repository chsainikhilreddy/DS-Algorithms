#include<bits/stdc++.h>
using namespace std;

const int mXn = 100002;
vector<int> primes;
vector<bool> is_prime(mXn, true);

void sieve() {
	is_prime[0] = is_prime[1] = false;
	for (int i = 2; i < mXn; i++) 
		if (is_prime[i]) {
			primes.push_back(i);
			for (int j = 2 * i; j < mXn; j += i) 
			    is_prime[j]=false;
		}
}

int main() {
	sieve();
	for (int i = 0; i < 10; i++) 
		cout << primes[i] << ' ';
}
