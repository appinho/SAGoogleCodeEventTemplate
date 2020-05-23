// KS20/C
// HARD
// Prefix sum/Cache/Square numbers

// g++ template.cpp -std=c++14 -D_DEBUG
#include <bits/stdc++.h>

using namespace std;

/* EXAMPLE

4 0 0 16

pre = 4
ans = 1
cache 4,3,0
pre = 4
ans = 3

*/

const int sz = 1e5;
int cache[200*sz+1];

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	
	// INPUT
	int T, N;
	cin >> T;

	for(int t = 1; t <= T; ++t){
		cin >> N;

		// SOLVE
	 	vector<int> A(N);
	 	for(int i = 0; i < N; i++){
	 		cin >> A[i];
	 	}

	 	long long ans = 0;

	 	time_t startt = clock();


	 	// A Map
	 	// unordered_map<int,int> cache;
	 	// cache[0]++;

	 	// B Vector
	 	// vector<int> cache(200*1e5+1, 0);
	 	// cache[100*sz]++;

	 	// C Array
	 	for(int i = 0; i < 200*sz+1; i++){
	 		cache[i] = 0;
	 	}
	 	cache[100*sz]++;


	 	int p = 0;
	 	for(int i = 0; i < N; i++){
	 		p += A[i];
	 		
	 		long long num = 100*sz+p;
	 		for(int j = 0; j*j <= 100 * sz; j++){
	 			
	 			long long cur = num-j*j;
	 			// A
	 			// ans += cache[p-j*j];
	 			// if(cache.find(cur) != cache.end())
	 			// 	ans+= cache[cur];

	 			// B

	 			// C
	 			if(cur >= 0)
	 				ans += cache[cur];
	 			// else{
	 			// 	cerr << cur << endl;
	 			// }
	 				
	 		}

	 		// A
	 		// cache[p]++;

	 		// B

	 		// C
	 		cache[num]++;

	 	}

		// OUTPUT
		cout << "Case #" << t << ": " << ans << endl;
		cerr << "~ #" << t << " done! time : " << (double)(clock()-startt)/CLOCKS_PER_SEC << "s." << endl;
	}
	
	return 0;
}