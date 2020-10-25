#include<bits/stdc++.h>

using namespace std;

// In/ Out time of Nodes
// a - adj list
// vis - visited array, in - intime array, out - outtime array

int timer = 1;
void dfs(int v) {
	vis[v] = 1;
	in[v] = timer++;
	
	for (int ch: a[v]) {
		if (vis[ch] == 0) {
			dfs(ch);
		}
	}
	
	out[v] = timer++;
}


int main() {
	
	for (int i = 0; i < n; i++) 
		if (vis[i] == 0) 
			dfs(i);
	
	for (int&x : in) 
		cout << x << ' ';
	cout << "\n";
	
	for (int&x : out) 
		cout << x << ' ';
	cout << "\n";
	
	return 0;
}
