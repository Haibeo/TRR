#include<bits/stdc++.h>
using namespace std;
int n;
int edges;
vector<pair<int,int>> adjacency[20];
int d[20];


void critical_path(){
    for(int i =  1; i <= n;i++){
        for(auto j : adjacency[i]){
            d[j.first] = max(d[j.first], d[i] + j.second);
        }
    }
    for(int i = 1; i <= n;i++){
        cout << "Earliest time to start task " << i << " is: " << d[i] << endl;
    }
    cout << "Earliest time to finish the whole job: " << d[n+1];
}

int main(){
    cout << "Enter n and number of edges: \n";
    cin >> n >> edges;
    for(int i =  0; i <= n+1;i++){
        d[i] = -1;
    }
    for(int i = 0; i < edges; i++){
        int u, v, cost;
        cin >> u >> v >> cost;
        if(u == 0){
            d[v] = cost;
        }
        adjacency[u].push_back({v, cost});
    }
    critical_path();
    return 0;
}