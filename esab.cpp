#include <bitset>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

int B;

int query(int idx) {
	// numq++;
	// assert(idx >= 1 && idx <= numb);
	cout << idx << endl;
	int ans;
	cin >> ans;
	// cerr << "QUERY " << idx << " " << ans << endl;
	return ans;
}

void print(const vector<int> number){

	for(int i = 1; i < number.size(); i++){
		cerr << number[i];
	}
	cerr << endl;
}

void rsolve(){

	vector<int> number(B + 1,0);

	for(int i = 0; i < 10; i++){

		int pos = (i % B) + 1;
		// printline 1 to stdout   // we ask about position 1.
	    // cout << pos << endl;
		// flush stdout

		// Since this is our 1st query, and 1 is 1 mod 10, the judge secretly and
		// randomly chooses one of the four possible quantum fluctuation effects, as
		// described above. It happens to choose complementation + reversal, so now
		// the stored value is 0000100111.
		// r = readline_chr()      // reads 0.
		int ans = query(pos);

		int bit_pos = B - pos;
		number[pos] = ans;

		cerr << "I " << i + 1 << " POS " << pos << " BPOS " << 
			bit_pos << " ANS " << ans << " NUM ";
		print(number);

		// cout << 6 << endl;
		// printline 6 to stdout   // we ask about position 6.
		// flush stdout

		// Since this is our 2nd query, and 2 is 2 mod 10, the judge does not choose
		// a quantum fluctuation effect.
		// r = readline_chr()      // reads 0.
		// ...
		// We have omitted the third through tenth queries in this example.
		// ...
		// printline 1 to stdout   // we decide to ask about position 1 again.
		// flush stdout
		// Since this is our 11th query, and 11 is 1 mod 10, the judge secretly and
		// randomly chooses a quantum fluctuation effect, and happens to get
		// reversal, so now the stored value is 1110010000.
		// r = readline_chr()      // reads 1.
	}
	for(int i = 1; i <= B; i++) {
	    cout << number[i];
	} cout << endl;

	string s;
	cin >> s;
	// cerr << s << endl;
	assert(s == "Y");
	// printline 1110110000 to stdout   // we try to answer. why?!?!
	// flush stdout
	// ok = readline_chr()     // reads N -- we have made a mistake!
	// exit                    // exits to avoid an ambiguous TLE error
}

void solve(){

	int T;
	// reads 100 into t and 10 into b.
	// The judge starts with the predetermined array for this test case:
	// 0001101111. (Note: the actual Test Set 1 will not necessarily
	// use this array.)
	// t, b = readline_int_list()      
    cin >> T >> B;
    for(int t = 1; t <= T; t++){
    	cerr << "Case #" << t << ": ";
    	rsolve();
    }
}
int main(){

	solve();
}