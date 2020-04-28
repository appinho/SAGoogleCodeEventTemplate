// CJ17/Q
// EASY
// Numbers

// g++ main.cpp -o app -std=c++14
#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <map>
#include <stack>
#include <queue>
#include <set>
#include <cmath>

using namespace std;

long long tidy_numbers(long long N){
    long long n = N;
    vector<long long> digits;
    while(n!= 0){
        digits.push_back(n % 10);
        n /= 10;
    }
    for(int i = 1; i < int(digits.size()); i++){
        if(digits[i]>digits[i-1]){
            // assign all 9s to the previous digits
            for(int j = i-1; j>=0;j--){
                digits[j] = 9;
            }
            // lower the current digit by 1
            digits[i] -= 1;
        }
        // for(auto d: digits){
        //     cerr << d << " ";
        // }
        // cerr << endl;
    }

    long long ans = 0;
    for(long long i = 0; i < int(digits.size()); i++){
        ans += powl(10,i) * digits[i];
        // cerr << powl(10,i) << " " << digits[i] << " " << ans << endl;
    }
    return ans;
}

int main(){

    // REMOVE LATER
    ifstream cin;
    cin.open("test.txt");
    if (!cin) {
        cout << "Unable to open file";
        exit(1);
    }
    
    int T;
    long long N;

    cin >> T;
    
    for(int t = 1; t <= T; ++t){

        cin >> N;
        time_t startt = clock();
        cout << "Case #" << t << ": " << tidy_numbers(N) << endl;
        cerr << "~ #" << t << " done! time : " << (double)(clock()-startt)/CLOCKS_PER_SEC << "s." << endl;
    }
    return 0;
}
