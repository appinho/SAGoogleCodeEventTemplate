// KS19/C
// MEDIUM
// Stack/Histogram

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <queue> 
#include <stack>

using namespace std;

int max_hist(const vector<int> & row){

    stack<int> sta;
    int max_area = 0;
    int len = row.size();
    for(int i = 0; i < row.size(); i++){

        while(!sta.empty() && (row[sta.top()] >= row[i])){
            int last_element_idx = sta.top();
            sta.pop();
            max_area = std::max(max_area, row[last_element_idx] * (i - sta.top() - 1));
        }

        sta.push(i);
    }

    while(!sta.empty()){
        int last_element_idx = sta.top();
        sta.pop();
        max_area = std::max(max_area, row[last_element_idx] * (len - sta.top() - 1));
    }

    return max_area;
}

int maxHist(vector<int> & row,const int C) 
{ 
    stack<int> result; 
  
    int top_val;     // Top of stack 
  
    int max_area = 0; // Initialize max area in current 
                      // row (or histogram) 
  
    int area = 0;    // Initialize area with current top 
  
    // Run through all bars of given histogram (or row) 
    int i = 0; 
    while (i < C) 
    { 
        // If this bar is higher than the bar on top stack, 
        // push it to stack 
        if (result.empty() || row[result.top()] <= row[i]) 
            result.push(i++); 
  
        else
        { 
            // If this bar is lower than top of stack, then 
            // calculate area of rectangle with stack top as 
            // the smallest (or minimum height) bar. 'i' is 
            // 'right index' for the top and element before 
            // top in stack is 'left index' 
            top_val = row[result.top()]; 
            result.pop(); 
            area = top_val * i; 
  
            if (!result.empty()) 
                area = top_val * (i - result.top() - 1 ); 
            max_area = max(area, max_area); 
        } 
    } 
  
    // Now pop the remaining bars from stack and calculate area 
    // with every popped bar as the smallest bar 
    while (!result.empty()) 
    { 
        top_val = row[result.top()]; 
        result.pop(); 
        area = top_val * i; 
        if (!result.empty()) 
            area = top_val * (i - result.top() - 1 ); 
  
        max_area = max(area, max_area); 
    } 
    return max_area; 
} 

int maxRect(vector< vector<int> > & grid, const int R, const int C, const int K){
    
    vector< vector<int> > A = vector< vector<int> >(C, vector<int>(R, 0));
    for(int i = 0; i < R; i++){
        int counter = 1;
        A[0][i] = counter;
        for(int j = 0; j < C-1; j++){
            if(grid[i][j] == grid[i][j+1]){
                ++counter;
            }
            else{
                counter = 1;
            }
            A[j+1][i] = counter;
        }

    }

    int max_area = 0;

    for(int i = 0; i < C; i++){
        int area = maxHist(A[i], R);
        max_area = std::max(area, max_area);
    }

    return max_area;
}

int main() {

    //std::ifstream cin ("test.txt", std::ifstream::in);

    // Defclare variables
    int T, R, C, K;

    // Read number of test cases
    cin >> T;
    
    // Loop over test cases
    for(int t = 1; t <= T; ++t){

        // Read number of rows and colomns
        cin >> R >> C >> K;

        // Fill grid
        vector< vector<int> > grid = vector< vector<int> >(R, vector<int>(C, 0));

        // Obtain grid
        int num;
        for(int r = 0; r < R; r++){
            for(int c = 0; c < C; c++){
                cin >> num;
                grid[r][c] = num;
            }
        }

        time_t startt = clock();
        cout << "Case #" << t << ": " << maxRect(grid, R, C, K) << endl;
        cerr << "~ #" << t << " done! time : " << (double)(clock()-startt)/CLOCKS_PER_SEC << "s." << endl;
    }
    return 0;
}