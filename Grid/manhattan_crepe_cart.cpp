// CJ19/1B
// EASY
// Manhattan Distance

#include <iostream>
#include <vector>
#include <utility>
#include <fstream>
#include <string>
#include <stack>

using namespace std;

void where_is_the_crepe_cart_opt(const int t, const std::vector<int> & x, const std::vector<int> & y,
    const std::vector<char> & d, const int Q){

    vector<int> cx(Q + 2, 0);
    vector<int> cy(Q + 2, 0);

    for(int p = 0; p < x.size(); ++p){
        if(d[p] == 'N'){
            cy[ y[p] + 1 ]++;
            cy[ Q + 1 ]--;
        }
        else if(d[p] == 'S'){
            cy[ 0 ]++;
            cy[ y[p] ]--;
        }
        else if(d[p] == 'E'){
            cx[ x[p] + 1 ]++;
            cx[ Q + 1 ]--;
        }
        else{
            cx[ 0 ]++;
            cx[ x[p] ]--;
        }
    }

    int max_x = cx[0];
    int max_y = cy[0];
    int ind_x = 0;
    int ind_y = 0;
    for (int i = 1; i <= Q + 1; i++) { 
        cx[i] += cx[i - 1]; 
        cy[i] += cy[i - 1]; 
        if(max_x < cx[i]) { 
            max_x = cx[i]; 
            ind_x = i; 
        } 
        if(max_y < cy[i]) { 
            max_y = cy[i]; 
            ind_y = i; 
        } 
    } 

    cout << "Case #" << t << ": " << ind_x << " " << ind_y << endl;
}

void where_is_the_crepe_cart(const int t, const std::vector<int> & x, const std::vector<int> & y,
    const std::vector<char> & d, const int Q){

    vector<int> cx(Q + 1, 0);
    vector<int> cy(Q + 1, 0);

    for(int p = 0; p < x.size(); ++p){
        if(d[p] == 'N'){
            for(int dy = y[p] + 1; dy <= Q; dy++){
                cy[dy]++;
            }
        }
        else if(d[p] == 'S'){
            for(int dy = y[p] - 1; dy >= 0; dy--){
                cy[dy]++;
            }
        }
        else if(d[p] == 'E'){
            for(int dx = x[p] + 1; dx <= Q; dx++){
                cx[dx]++;
            }
        }
        else{
            for(int dx = x[p] - 1; dx >= 0; dx--){
                cx[dx]++;
            }
        }
    }

    int max_x = 0;
    int max_y = 0;
    int ind_x = 0;
    int ind_y = 0;
    for(int q = 0; q <= Q; ++q){
        if(cx[q] > max_x){
            ind_x = q;
            max_x = cx[q];
        }
        if(cy[q] > max_y){
            ind_y = q;
            max_y = cy[q];
        }
    }

    cout << "Case #" << t << ": " << ind_x << " " << ind_y << endl;
}

int main() {

    int T, Q, P;
    cin >> T;
    
    // Loop over test cases
    for(int t = 1; t <= T; ++t){

        cin >> P >> Q;
        std::vector<int> x(P);
        std::vector<int> y(P);
        std::vector<char> d(P);

        for(int p = 0; p < P; ++p){
            cin >> x[p] >> y[p] >> d[p];
        }

        time_t startt = clock();
        where_is_the_crepe_cart_opt(t, x, y, d, Q);
        cerr << "~ #" << t << " done! time : " << (double)(clock()-startt)/CLOCKS_PER_SEC << "s." << endl;
    }
    return 0;
}