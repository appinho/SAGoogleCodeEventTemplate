// KS19/D
// EASY
// XOR/Digit traversal

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

int evenNumberOfOnes(unsigned int num)
{
    int n=0;
    while(num > 0) {
        n ^= num;
        num = num >> 1;
    }
    return n & 1;
}

bool check_array(vector<int> & a){
    int sum = 0;
    for(int j = 0; j < a.size(); j++){
        sum += a[j];
    }
    return sum % 2;
}

void xorwhat(vector<int> & a, vector< pair<int,int> > & q, int N, int Q, int t){

    vector<int> answer = vector<int>(Q, N);
    for(int i = 0; i < Q; i++){
        a[q[i].first] = q[i].second;
        if(check_array(a)){
            int left = 0;
            int right = 0;
            for(int j = 0; j < N; j++){
                if((a[j] || a[N-1-j])){
                    answer[i]-= j+1;
                    break;
                }
            }
        }
    }

    cout << "Case #" << t << ": ";
    for(int q = 0; q < Q; q++){
        cout << answer[q] << " ";
    }
    cout << endl;
}

int main() {
    
    // Defclare variables
    int T, N, Q;

    // Read number of test cases
    cin >> T;
    
    // Loop over test cases
    for(int t = 1; t <= T; ++t){

        // Read number of rows and colomns
        cin >> N >> Q;

        // Fill grid
        vector<int> arr_n = vector<int>(N, 0);
        vector< pair<int,int> > arr_q;

        // Obtain commands
        int a_n;
        for(int n = 0; n < N; n++){
            cin >> a_n;

            arr_n[n] = evenNumberOfOnes(a_n);
        }
        int p_q, a_q;
        for(int q = 0; q < Q; q++){
            cin >> p_q >> a_q;

            arr_q.push_back(pair<int,int>(p_q, evenNumberOfOnes(a_q)));
        }

        time_t startt = clock();
        // Output minimum delivery time
        xorwhat(arr_n, arr_q, N, Q, t);
        cerr << "~ #" << t << " done! time : " << (double)(clock()-startt)/CLOCKS_PER_SEC << "s." << endl;
    }
    return 0;
}