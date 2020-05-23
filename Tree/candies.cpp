// KS20/C
// HARD
// Segment Tree

// g++ template.cpp -std=c++14 -D_DEBUG
#include <bits/stdc++.h>

using namespace std;

const int M = 2e5;

// struct SegmentTree {
// 	long long a[mxN+1];
// 	void upd(int i, long long x) {
// 		for(++i; i<=n; i+=i&-i)
// 			a[i]+=x;
// 	}
// 	long long qry(int i) {
// 		long long r=0;
// 		for(; i; i-=i&-i)
// 			r+=a[i];
// 		return r;
// 	}
// } f0[2], f1[2];

template <class T>
class SegmentTree{
public:
	SegmentTree(int n){
		this->n = n;
	}
	void build(){
		
		for(int i = n - 1; i > 0; --i){
			t[i] = t[i<<1] + t[i<<1|1];
			// cerr << "B " << (i<<1) << "+" << (i<<1|1) 
			// 	<< "->" << i << " " << t[i<<1] << "+" 
			// 	<< t[i<<1|1] << " " << t[i] << endl;
		}
	}
	void update(int idx, int value){
		for(t[idx += n] = value; idx > 1; idx >>= 1){
			t[idx>>1] = t[idx] + t[idx^1];
		}
	}
	T query(int l, int r){
		T res = 0;
		// cerr << "Query " << l << "-" << r;
		for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
			if (l&1) res += t[l++];
			if (r&1) res += t[--r];
		}
		// cerr << "=" << res << endl;
		return res;
	}
	void print(){
		for(int i = 0; i < 2*n; ++i){
			cerr << t[i] << " ";
		}
		cerr << "\n";
	}

	T t[2 * M];
	int n;
};


int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	
	// INPUT
	int T;
	cin >> T;
	for(int t = 1; t <= T; ++t){
		int N, Q;
		cin >> N >> Q;

		// SOLVE
		SegmentTree<long long> t1(N);
		SegmentTree<long long> t2(N);
		int b;
		for(int i = 0; i < N; ++i){
			cin >> b;
			t1.t[i+N] = pow(-1,i) * b;
			t2.t[i+N] = pow(-1,i) * b * (i+1);
		}
		t1.build();
		t2.build();
		// t1.print();
		// t2.print();

		int l, r;
		char c;
		long ans = 0;
		for(int q = 0; q < Q; q++){
			cin >> c >> l >> r;
			// cout << c << " " << l << " " << r << endl;
			if(c == 'Q'){
				long long a1 = t1.query(l-1, r);
				long long a2 = t2.query(l-1, r);
				long long d = pow(-1,l-1) * (a2 - (l-1) * a1);
				// cerr << pow(-1,l-1) * a2 << "-" << (l-1) * a1 << "=" << d << endl;
				ans += d;
			}
			else{
				t1.update(l-1, pow(-1,l-1) * r);
				t2.update(l-1, pow(-1,l-1) * r * l);
			}
			// t1.print();
		}

		// OUTPUT
		// cout << ans << endl;
		cout << "Case #" << t << ": " << ans << endl;
	}
	
	return 0;
}