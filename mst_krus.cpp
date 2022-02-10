#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;
int min_point;
int n;
int weight = 0;
vector<pair<pair<int,int>,int>> list;
int edges;
int Count = 0;

class UF{
    public: 
    int parent[100];
    UF(){
        for(int i = min_point; i <= n; i++){
            this->parent[i] = i;
        }
    }

    int find_parent(int i){
        while(this->parent[i] != i){
            i = this->parent[i];
        }
        return i;
    }

    bool connected(int a, int b){
        if(find_parent(a) == find_parent(b)){
            return true;
        }
        return false;
    }

    void unify(int a, int b){
        this->parent[find_parent(b)] = find_parent(a);
    }
};

bool cmp(const pair<pair<int,int>,int> &a, const pair<pair<int, int>, int> &b){
    return a.second < b.second;
}

void solve(){
    UF uf = UF();
    for(int i = 0; i < list.size(); i++){
        if(!uf.connected(list[i].first.first, list[i].first.second)){
            uf.unify(list[i].first.first, list[i].first.second);
            weight += list[i].second;
            cout << "\nConnect " << list[i].first.first << " and " << list[i].first.second;
            Count++;
        }
        if(Count == n - min_point){
            cout << endl;
            cout << "Total cost: " << weight;
            return;
        }
    }
}

int main(){
    cout << "Enter min point, n and number of edges: \n";
    cin >> min_point >> n >> edges;
    for(int i = 1; i<= edges;i++){
        int u, v, cost;
        cin >> u >> v >> cost;
        list.push_back({{u, v}, cost});
    }
    sort(list.begin(), list.end(), cmp);
    solve();
    return 0;
}