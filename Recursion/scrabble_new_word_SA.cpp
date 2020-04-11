#include <iostream>
#include <vector>
#include <utility>
#include <fstream>
#include <string>
#include <stack>
#include <queue>
#include <set>
#include <map>

using namespace std;

bool test(string & s, const vector< set<char> > & w, const set<string> & hs, const int L){

	int p = s.size();
	if(p == L){
		//cerr << s << endl;
		if(hs.find(s) == hs.end()){
			//cerr << "Solved" << s << endl;
			return true;
		}
		else{
			return false;
		}
	}

	for(auto c : w[p]) {
		s.push_back(c);
		
		if(p < L){
			
			bool valid = test(s, w, hs, L);
			if(valid){
				return true;
			}
		}
		s.pop_back();
	}
	
	return false;
}

string solve(const vector<string> words, const int N, const int L){

	if(L==1)
		return "-";

	vector< set<char> > cache1(L);
	set<string> cache2;

	for(int n = 0; n < N; n++){
		cache2.insert(words[n]);
		for(int l = 0; l < L; l++){
			cache1[l].insert(words[n][l]);
		}
	}

	string buf = "";
	bool valid = test(buf, cache1, cache2, L);

	if(valid){
		return buf;
	}
	else{
		return "-";
	}
}

int main() {

    // Read in number of test cases
    int T;
    cin >> T;

    // Add other help variables
    int N, L;
    
    // Loop over test cases
    for(int t = 1; t <= T; ++t){

    	// Read input
    	cin >> N >> L;

    	vector<string> words(N);

    	for(int i = 0; i < N; i++){
    		cin >> words[i];
    	}

    	// Time and perform
        time_t startt = clock();
        cout << "Case #" << t << ": " << solve(words, N, L) << endl;
        cerr << "~ #" << t << " done! time : " << (double)(clock()-startt)/CLOCKS_PER_SEC << "s." << endl;
    }

    return 0;
}