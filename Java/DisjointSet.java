import java.io.*;
import java.util.*;

class uf {
	int[] parent, rank;
    public uf (int n) {
        parent = new int[n + 1];
        rank = new int[n + 1];
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
			rank[i] = 1;
        }
    }
    public int find(int a) {
        if (parent[a] != a) 
            parent[a] = find(parent[a]);
        return parent[a];
    }
    public void merge (int a, int b) {
        if ((a = find(a)) == (b = find(b))) return ;
        if (rank[a] < rank[b]) {
            parent[a] = b;
			rank[b] += rank[a];
        }
        else {
            parent[b] = a;
			rank[a] += rank[b];
        }
    }
};
public class DisjointSet{
	public static void main(String[] args) {
		int n = 5;
		uf obj = new uf(5);
		obj.merge(1,2);
		obj.merge(4,5);
		obj.merge(2,4);
		for (int i = 1; i <= 5; i++) 
			System.out.println(obj.find(i));
	}
};
