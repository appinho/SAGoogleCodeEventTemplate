// CJ20/1C
// EASY
// Counting/Codeword

// g++ -std=c++14 -O2 -Wall test.cpp -o test
#include <bits/stdc++.h>
using namespace std;

int main() {
	// Makes input and output more efficient
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T, U;
	long long M;
	string R;
	cin >> T;
	for(int t = 1; t <= T; ++t){
		
		cin >> U;

        unordered_map<char,int> ma;
        unordered_set<char> se;
        unordered_map<char,int> count;
        for(int i = 0; i < 10000; i++){
			cin >> M >> R;
			// M = -1;

			// Find upper limit
			int string_length = int(R.size());
			long long upper = pow(10, string_length) - 1;
			if(M != -1){
				upper = min(upper, M);
			}
			while(upper >= 10){
				upper /= 10;
			}
			char cha = R[0];
			// cerr << cha << " " << upper << endl;
			if(ma.find(cha) == ma.end()){
				ma[ cha ] = min(int(upper), 9);
			}
			else{
				ma[ cha ] = min(int(upper), ma[ cha ]);
			}

			if(se.size() < 10){
				for(int j = 0; j < int(R.length()); j++){
					se.insert(R[j]);
				}
			}
			count[R[0]]++;
		}
		string sol = "          ";
		unordered_set<int> uppers;
		bool works = true;
		for(auto m: ma){
			// cerr << m.first << "=" << m.second << "  ";
			if(uppers.find(m.second) != uppers.end()){
				works = false;
			}
			uppers.insert(m.second);
			sol[ m.second ] = m.first;
		}
		if(works){
			for(auto s: se){
				if(ma.find(s) == ma.end()){
					sol[0] = s;
				}
			}
		}
		else{
			vector<pair<int,char>> counters;
			for(auto m: count){
				// cerr << m.first << "=" << m.second << "  ";
				counters.push_back(make_pair(m.second, m.first));
			}
			sort(counters.begin(), counters.end());
			for(int i = 0; i < 10; i++){
				// cerr << counters[i].first << "=" << counters[i].second << "  ";
				sol[9-i] = counters[i].second;
			}
			for(auto s: se){
				if(ma.find(s) == ma.end()){
					sol[0] = s;
				}
			}
		}
	    cout << "Case #" << t << ": " << sol << endl;
		// }
        // cerr << "~ #" << t << " done! time : " << (double)(clock()-startt)/CLOCKS_PER_SEC << "s." << endl;
	}
	return 0;
}