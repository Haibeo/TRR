#include<iostream>
#include<vector>
#include<utility>
using namespace std;
int min_point;
int n;
int matrix[100][100] = {0};
bool check[100] = {false};
int weight = 0;
int edges;
vector<int> visited;

void solve(){
    while(visited.size() != (n-min_point+1)){
        pair<pair<int,int>,int> opt;
        opt.second = 9999;
        for(auto i : visited){
            for(int j = min_point; j <= n;j++){
                if(matrix[i][j] > 0 && !check[j] && matrix[i][j] < opt.second){
                    opt.second = matrix[i][j];
                    opt.first.first = i;
                    opt.first.second = j;
                }
            }
        }
        visited.push_back(opt.first.second);
        check[opt.first.second] = true;
        weight += opt.second;
        cout << "\nConnect " << opt.first.first << " and " << opt.first.second;
    }
    cout << endl;
    cout << "Total cost: " << weight; 
}

int main(){
    cout << "Enter min point, n and number of edges: \n";
    cin >> min_point >> n >> edges;
    for(int i = 1; i <= edges;i++){
        int u, v, cost;
        cin >> u >> v >> cost;
        matrix[u][v] = cost;
        matrix[v][u] = cost;
    }
    check[min_point] = true;
    visited.push_back(min_point);
    solve();
    return 0;
}