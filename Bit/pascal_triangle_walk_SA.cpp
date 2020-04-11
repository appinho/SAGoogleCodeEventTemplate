#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <map>
#include <stack>
#include <queue>
#include <set>
#include <cmath>
#include <bitset>

using namespace std;


void pascal(const int N){

    if(N <= 32){
        cout << "1 1" << endl;
        if(N == 1) return;
        cout << "2 2" << endl;
        if(N == 2) return;
        int sum = 2;
        int row = 3;
        while(sum + row - 1 <= N){
            cout << row << " 2" << endl;
            
            sum += row - 1;
            row++;
            // /cerr << sum << endl;
        }
        if(sum == N) return;
        // sum -= row - 1;
        row--;
        //cerr << "D " << sum << " " << N << endl;
        cout << row << " 1" << endl;
        sum++;
        while(sum < N){
            row++;
            cout << row << " 1" << endl;
            sum ++;
            
        }
        return;
    }
    else{
        std::bitset<32> foo(N-30);
        // cerr << foo << endl;
        int row = 1;
        int col = 1;
        int zeros = 0;
        int sum = 0;
        for(;row <= 31; row++){
            // cerr << "BIT " << foo[row-1] << endl;
            if(foo[row-1] == 1){
                sum += pow(2,row-1);
                // cerr << "TRAVERS" << endl;
                if(col == row - 1){
                    for(int j = row; j >= 1; j--){
                        cout << row << " " << j << endl;
                    }
                    col = 1;
                }
                else{
                    for(int j = 1; j <= row; j++){
                        cout << row << " " << j << endl;
                    }
                    col = row;
                }
            }
            else{
                sum++;
                zeros++;
                if(col != 1) col++;
                cout << row << " " << col << endl;
                
            }
            if(sum == N){
                return;
            }
            // cerr << sum << endl;
        }
        // cerr << "SD" << row << " " << col << endl;
        for(int i = row; i < row + 30 - zeros; i++){
            if(col + 1 == i) col++;
            cout << i << " " << col << endl;
            sum++;
        }

        // cerr << sum << " " << zeros << " " << N << endl;
    }

}

int main(){

    // // REMOVE LATER
    ifstream cin;
    cin.open("test.txt");
    if (!cin) {
        cout << "Unable to open file";
        exit(1);
    }
    
    int T, N;

    cin >> T;
    
    for(int t = 1; t <= T; ++t){

        cin >> N;

        time_t startt = clock();
        cout << "Case #" << t << ":" << endl;
        pascal(N);
        cerr << "~ #" << t << " done! time : " << (double)(clock()-startt)/CLOCKS_PER_SEC << "s." << endl;
    }
    return 0;
}
