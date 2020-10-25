#include<bits/stdc++.h>

using namespace std;

struct SegTree {
	int leftmost, rightmost;
	SegTree* lc, *rc;
	int sum;
	SegTree(int leftmost, int rightmost, vector<int>& a) {
		this->leftmost = leftmost;
		this->rightmost = rightmost;
		if (leftmost == rightmost) 
			sum = a[leftmost]; // leaf
		else { // has 2 kids
			int mid = (leftmost + rightmost) / 2;
			lc = new SegTree(leftmost, mid, a);
			rc = new SegTree(mid + 1, rightmost, a);
			recalc();
		}
	}
	void recalc() {
		if (leftmost == rightmost) 
			return ;
		sum = lc->sum + rc->sum;
	}
	void update (int index, int val) {
		if (leftmost == rightmost) {
			sum = val; // leaf
			return ;
		}
		// 2 kids
		if (index <= lc->rightmost) lc->update(index, val);
		else rc->update(index, val);
		recalc();
	}
	int range_sum (int l, int r) {
		// disjoint
		if (l > rightmost || r < leftmost) 
			return 0;
		// Covers everything
		if (l <= leftmost && r >= rightmost) 
			return sum;
		else // Don't know
			return lc->range_sum(l, r) + rc->range_sum(l, r);
	}
};

int main() {
	vector<int> a{1,2,3,4,5,6};
	int n = a.size();
	SegTree* sg = new SegTree(0, n - 1, a);
	for (int i = 0; i < 20; i++) {
		if (rand() % 2) {
			int l = rand() % n, r = rand() % n, sum = 0;
			if (l > r) swap(l, r);
			for (int j = l; j <= r; j++) sum += a[j];
			if (sum != sg->range_sum(l, r)) cout << "Error\n";
		}
		else {
			int new_val = rand() % 1000;
			int index = rand() % n;
			a[index] = new_val;
			sg->update(index, new_val);
		}
	}
	
	return 0;
}
