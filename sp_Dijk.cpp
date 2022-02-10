#include<bits/stdc++.h>
using namespace std;
int source;
int min_point;
int n;
int edges;
vector<int> done;
vector<pair<int,int>> weight;
int matrix[20][20];
int d[20];
int p[20];

bool cmp(const pair<int,int> &a, const pair<int,int> &b){
    return a.second < b.second;
}

void find_path(int i){
    if(p[i] == i){
        cout << i << " - ";
        return;
    }
    find_path(p[i]);
    cout << i << " - ";
}

void solve(){
    while(done.size() != n - min_point){
        sort(weight.begin(), weight.end(), cmp);
        auto choice = weight[0];
        done.push_back(choice.first);
        weight.erase(weight.begin());
        for(int i =  0; i < weight.size(); i++){
            if(d[weight[i].first] > d[choice.first] + matrix[choice.first][weight[i].first]){
                d[weight[i].first] = d[choice.first] + matrix[choice.first][weight[i].first];
                weight[i].second = d[weight[i].first];
                p[weight[i].first] = choice.first;
            }
        }
    }
}

int main(){
    cout << "Enter min point, n, source point and number of edges: \n";
    cin >> min_point >> n >> source >> edges;
    for(int i = min_point; i <= n;i++){
        for(int j =  min_point ; j <= n;j++){
            if(i == j){
                matrix[i][j] = 0;
            }else{
                matrix[i][j] = 99;
            }
        }
    }
    for(int i  = 0; i< edges; i++){
        int u, v, cost;
        cin >> u >> v >> cost;
        matrix[u][v] = cost;
    }
    for(int i = min_point ; i <= n;i++){
        d[i] = matrix[source][i];
        p[i] = source;
        if(i != source){
            weight.push_back({i, d[i]});
        }
    }
    solve();
    for(int i : done){
        cout << endl;
        find_path(i);
        cout << "cost: " << d[i];
    }
    return 0;
}