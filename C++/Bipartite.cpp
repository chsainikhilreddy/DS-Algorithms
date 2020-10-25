#include<bits/stdc++.h>

using namespace std;

// Bipartite testing
// a - adj list
// vis - visited array, col - color array

bool dfs(int v, int c) {
	vis[v] = 1;
	col[v] = c;
	for (int ch: a[v]) {
		if (vis[ch] == 0) {
			if (!dfs(i, c ^ 1)) 
				return false;
		}
		else if (col[v] == col[ch]) 
			return false;
	}
	return true;
}


int main() {
	bool flag = true;
	for (int i = 0; i < n; i++) 
		if (vis[i] == 0) 
			if (!dfs(i, 0)) 
				flag = false;
	cout << flag ? "Bipartite" : "Not bipartite" << '\n';
	
	return 0;
}
