// CJ20/1C
// HARD
// Binary Search/GCD

// g++ -std=c++14 -O2 -Wall test.cpp -o test
#include <bits/stdc++.h>
using namespace std;

int solve(vector<long long> slices, int N, int D){

	// cerr << N << " " << D << endl;
	unordered_map<long long, int> map;
	for(int i = 0; i < N; i++){
		map[slices[i]]++;
	}
	int max_occ = 0;
	long long max_slice = 360000000000;
	for(auto m: map){
		max_occ = max(max_occ, m.second);
		if(m.second == 2){
			max_slice = min(max_slice, m.first);
		}
	}
	if(max_occ >= D){
		return 0;
	}
	if(D == 2){
		return 1;
	}
	sort(slices.begin(), slices.end());
	if(max_slice != 360000000000 && max_slice < slices.back()){
		return 1;
	}

	bool found = false;
	for(int i = 0; i < N; i++){
		for(int j = i + 1; j < N; j++){
			// cerr << "CH " << slices[j] << " " << slices[i] << endl;
			if(slices[j] == 2 * slices[i]){
				// cerr << "YEP " << slices[j] << " " << slices[i] << endl;
				found = true;
			}
		}
	}
	// cerr << "FOUND DIVISOR " << found << endl;
	if(found){
		return 1;
	}
	else{
		return 2;
	}
}
int main() {

	// Makes input and output more efficient
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T, N, D;
	cin >> T;
	for(int t = 1; t <= T; ++t){
		
		cin >> N >> D;
		vector<long long> slices;
		long long l;
		for(int i = 0; i < N;i++){
			cin >> l;
			slices.push_back(l);
		}

		// time_t startt = clock();
        cout << "Case #" << t << ": " << solve(slices, N, D) << endl;
        // cerr << "~ #" << t << " done! time : " << (double)(clock()-startt)/CLOCKS_PER_SEC << "s." << endl;
	}
	return 0;
}