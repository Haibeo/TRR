#include<iostream>
#include<vector>
#include<utility>
using namespace std;
int source;
int n;
int min_point;
int edges;
int d[100];
int p[100];
vector<pair<pair<int,int>,int>> list;

void find_path(int i){
    if(p[i] == i){
        cout << i << " - ";
        return;
    }
    find_path(p[i]);
    cout << i << " - ";
}

bool solve(){
    for(int i  = min_point ; i <= n; i++){
        for(auto j : list){
            if(d[j.first.second] > d[j.first.first] + j.second){
                d[j.first.second] = d[j.first.first] + j.second;
                p[j.first.second] = j.first.first;
            }
        }
    }
    for(auto i : list){
        if(d[i.first.second] > d[i.first.first] + i.second){
            return false;
        }
    }
    return true;
}

int main(){
    cout << "Enter min point, n, source point and number of edges: \n";
    cin >> min_point >> n >> source >> edges;
    for(int i  = 0; i< edges; i++){
        int u, v, cost;
        cin >> u >> v >> cost;
        list.push_back({{u, v}, cost});
    }
    for(int i = min_point; i <= n;i++){
        if(i == source){
            d[i] = 0;
        }else{
            d[i] = 99;
        }
        p[i] = i;
    }
    if(!solve()){
        cout << "\nGraph has negative cycle";
    }else{
        for(int i =  min_point ;  i <= n;i++){
            if(i != source){
                cout << endl;
                find_path(i);
                cout << "cost: " << d[i];
            }
        }
    }
    return 0;
}