// KS19/C
// MEDIUM
// Complete search/Sorting/Long long

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <limits>
#include <algorithm>

using namespace std;

long long INT_MAX = std::numeric_limits<long long>::max();

long long opt(const int K, const int N, const vector<int> & positions, const vector<int> & costs){

    long long min_cost = INT_MAX;
    for(int n = 0; n < N; n++){
        vector<long long> stall_costs;
        for(int m = 0; m < N; m++){
            if(n != m){
                stall_costs.push_back(costs[m] + abs(positions[m]-positions[n]));
            }
        }
        std::sort(stall_costs.begin(), stall_costs.end());

        long long new_cost = costs[n];
        for(int k = 0; k < K; k++){
            new_cost += stall_costs[k];
        }
        cerr << n << " " << new_cost << endl;
        if(new_cost < min_cost)
            min_cost = new_cost;
    }
    return min_cost;
}

int main() {

    
    // Defclare variables
    int T, K, N;

    // Read number of test cases
    cin >> T;
    
    // Loop over test cases
    for(int t = 1; t <= T; ++t){

        // Read number of rows and colomns
        cin >> K >> N;

        // Fill grid
        vector<int> costs;
        vector<int> positions;

        // Obtain commands
        int c;
        for(int n = 0; n < N; n++){
            cin >> c;
            positions.push_back(c);
        }
        for(int n = 0; n < N; n++){
            cin >> c;
            costs.push_back(c);
        }

        time_t startt = clock();
        // Output minimum delivery time
        cout << "Case #" << t << ": " << opt(K, N, positions, costs) << endl;
        cerr << "~ #" << t << " done! time : " << (double)(clock()-startt)/CLOCKS_PER_SEC << "s." << endl;
    }
    return 0;
}