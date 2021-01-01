import java.io.*;
import java.util.*;


static class SegTree {
	int leftmost, rightmost;
	SegTree lc, rc;
	int sum;
	public SegTree(int leftmost, int rightmost, int[] a) {
		this.leftmost = leftmost;
		this.rightmost = rightmost;
		if (leftmost == rightmost) 
			sum = a[leftmost]; // leaf
		else { // has 2 kids
			int mid = (leftmost + rightmost) / 2;
			lc = new SegTree(leftmost, mid, a);
			rc = new SegTree(mid + 1, rightmost, a);
			sum = lc.sum + rc.sum;
		}
	}
	public void recalc() {
		if (leftmost == rightmost) 
			return ;
		sum = lc.sum + rc.sum;
	}
	public void update (int index, int val) {
		if (leftmost == rightmost) {
			sum = val; // leaf
			return ;
		}
		// 2 kids
		if (index <= lc.rightmost) lc.update(index, val);
		else rc.update(index, val);
		recalc();
	}
	public int rangeSum (int l, int r) {
		// disjoint
		if (l > rightmost || r < leftmost) 
			return 0;
		// Covers everything
		if (l <= leftmost && r >= rightmost) 
			return sum;
		else // Don't know
			return lc.rangeSum(l, r) + rc.rangeSum(l, r);
	}
};
public class SegmentTree {
	public static void main(String[] args) {
		int[] a = {1,2,3,4,5,6};
		int n = a.length;
		SegTree sg = new SegTree(0, n - 1, a);
		Random rand = new Random(); 
		for (int i = 0; i < 20; i++) {
			if (rand.nextBoolean()) {
				int l = rand.nextInt(n), r = rand.nextInt(n - l) + l, sum = 0;
				for (int j = l; j <= r; j++) 
					sum += a[j];
				if (sum != sg.rangeSum(l, r)) throw null;
			}
			else {
				int new_val = rand.nextInt(1000);
				int index = rand.nextInt(n);
				a[index] = new_val;
				sg.update(index, new_val);
			}
		}
	}
}
