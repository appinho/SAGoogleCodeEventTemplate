// g++ template.cpp -std=c++14 -D_DEBUG
#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	
	// INPUT
	int T;
	cin >> T;
	for(int t = 1; t <= T; ++t){
		long long N, M;
		cin >> N >> M;

		// SOLVE
		time_t startt = clock();
		long long count = 0;
		while(true){
			if(N >= M){
				if(N >= count + 1){
					N -= count + 1;
				}
				else{
					break;
				}
			}
			else{
				if(M >= count + 1){
					M -= count + 1;
				}
				else{
					break;
				}
			}
			count++;
		} 

		// OUTPUT
		// cout << std::numeric_limits<long long>::max() << endl;
		cout << "Case #" << t << ": " << count << " " << N << " " << M << "\n";
		cerr << "~ #" << t << " done! time : " << (double)(clock()-startt)/CLOCKS_PER_SEC << "s." << endl;
	}
	
	return 0;
}