#include<bits/stdc++.h>

using namespace std;

// Cycle Detection
// a - adj list
// vis - visited array, par - parent

bool dfs(int v, int par) {
	vis[v] = 1;
	
	for (int ch: a[v]) {
		if (vis[ch] == 0) {
			if (dfs(i, ch)) 
				return true;
		}
		else if (ch != par) 
			return true;
	}
	return false;
}


int main() {
	bool flag = false;
	for (int i = 0; i < n; i++) 
		if (vis[i] == 0) 
			if (dfs(i, -1)) 
				flag = true;
	cout << flag ? "Contains cycle" : "No cycle" << '\n';
	
	return 0;
}
