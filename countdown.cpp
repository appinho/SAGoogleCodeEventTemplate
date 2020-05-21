// g++ template.cpp -std=c++14 -D_DEBUG
#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	
	// INPUT
	int T, K, N;
	cin >> T;
	for(int t = 1; t <= T; ++t){
		cin >> N >> K;

		// SOLVE
		vector<int> A(N);
	 	for(int i = 0; i < N; i++){
	 		cin >> A[i];
	 	}
		int a = K;
		int count = 0;
		for(int i = 0; i < N; i++){
	 		if(A[i] == a){
	 			a--;
	 		}
	 		else if(A[i] == K){
	 			a = K - 1;
	 		}
	 		else{
	 			a = K;
	 		}
	 		if(a == 0){
	 			a = K;
	 			count++;
	 		}
	 	}

		// OUTPUT
		cout << "Case #" << t << ": " << count << endl;
	}
	
	return 0;
}