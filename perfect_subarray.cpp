// g++ template.cpp -std=c++14 -D_DEBUG
#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	
	// INPUT
	int T, N;
	cin >> T;

	unordered_set<int> quad;
	for(int i = 0; i <= 1000; i++){
		quad.insert(i*i);
	}
	for(int t = 1; t <= T; ++t){
		cin >> N;

		// SOLVE
	 
	 	vector<int> A(N);
	 	for(int i = 0; i < N; i++){
	 		cin >> A[i];
	 	}

	 	// for(auto p: A){
	 	// 	cout << p << " ";
	 	// }cout << endl;

	 	vector<int> prefix_sum(N+1, 0);
	 	prefix_sum[1] = A[0];
	 	for(int i = 2; i <= N; i++){
	 		prefix_sum[i] = prefix_sum[i-1] + A[i-1];
	 	}

	 	for(int i = 2; i <= N; i++){
	 		prefix_sum[i] = prefix_sum[i-1] + A[i-1];
	 	}

	 	for(auto p: prefix_sum){
	 		cout << p << " ";
	 	}cout << endl;

	 	int ans = 0;
	 	int prev_diff = 0;
	 	int count = 1;
	 	for(int i = 1; i <= N; i++){
	 		int diff = prefix_sum[i] - prefix_sum[i-1]; 
	 		if(quad.count(diff)){
	 			ans++;
		 		// if(diff == prev_diff){
	 			// 	count++;
		 		// 	ans+= count;
		 		// }
	 		}
	 		if(quad.count(prefix_sum[i])){
	 			ans++;
	 		}
	 		if(diff == 0){
	 			ans += count;
	 			count++;
	 		}
	 		else{
	 			ans += count;
	 			count = 0;
	 		}
	 		prev_diff = diff;
	 	}

		// OUTPUT
		cout << "Case #" << t << ": " << ans << endl;
	}
	
	return 0;
}