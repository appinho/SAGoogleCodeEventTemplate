// KS19/E
// MEDIUM
// DFS/Connected Components

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <list>

using namespace std;

// Graph class represents a undirected graph 
// using adjacency list representation 
class Graph 
{ 
    int V;    // No. of vertices 
  
    // Pointer to an array containing adjacency lists 
    list<int> *adj; 

    int num_groups;
  
    // A function used by DFS 
    void DFSUtil(int v, bool visited[]); 
public: 
    Graph(int V);   // Constructor 
    void addEdge(int v, int w); 
    void connectedComponents(); 
    int getGroups();
}; 
  

int Graph::getGroups(){
    return num_groups;
}

// Method to print connected components in an 
// undirected graph 
void Graph::connectedComponents() 
{ 
    // Mark all the vertices as not visited 
    bool *visited = new bool[V]; 
    for(int v = 0; v < V; v++) 
        visited[v] = false; 
  
    for (int v=0; v<V; v++) 
    { 
        if (visited[v] == false) 
        { 
            // print all reachable vertices 
            // from v 
            DFSUtil(v, visited); 
  
            cerr << "\n"; 
            num_groups++;
        } 
    } 
} 
  
void Graph::DFSUtil(int v, bool visited[]) 
{ 
    // Mark the current node as visited and print it 
    visited[v] = true; 
    cerr << v << " "; 
  
    // Recur for all the vertices 
    // adjacent to this vertex 
    list<int>::iterator i; 
    for(i = adj[v].begin(); i != adj[v].end(); ++i) 
        if(!visited[*i]) 
            DFSUtil(*i, visited); 
} 
  
Graph::Graph(int V) 
{ 
    this->V = V; 
    adj = new list<int>[V]; 
    num_groups = 0;
} 
  
// method to add an undirected edge 
void Graph::addEdge(int v, int w) 
{ 
    adj[v].push_back(w); 
    adj[w].push_back(v); 
} 

int main() {
    
    // Declare variables
    int T, N, M;

    // Read number of test cases
    cin >> T;
    
    // Loop over test cases
    for(int t = 1; t <= T; ++t){

        cin >> N >> M;
        vector< pair<int,int> > cherries(M);

        Graph g(N);
        int c, d;
        for(int m = 0; m < M; m++){
            cin >> c >> d;
            g.addEdge(c - 1, d - 1);
        }

        time_t startt = clock();
        g.connectedComponents(); 
        cout << "Case #" << t << ": " << N + g.getGroups() - 2 << endl;
        cerr << "~ #" << t << " done! time : " << (double)(clock()-startt)/CLOCKS_PER_SEC << "s." << endl;
    }
    return 0;
}