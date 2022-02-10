#include<iostream>
#include<queue>
#include<vector>
using namespace std;
int min_point;
int n;
vector<int> list[100];
int in_degree[100];
int layer = 1;
int count;
void topoSort(){
    queue<int> Q;
    while(count != n){
        for(int v = min_point; v <= n; v++){
            if(in_degree[v] == 0){
                Q.push(v);
                count++;
                in_degree[v] = -1;
            }
        }
        if(!Q.empty()){
            cout << "Layer " << layer++ << " : ";
        }
        while(!Q.empty()){
            int x = Q.front();
            for(auto v : list[x]){
                in_degree[v]--;
            }
            cout << x << " ";
            Q.pop();
        }
        cout << endl;
    }
}
int main(){
    cout << "Enter min point (0 or 1) : \n";
    cin >> min_point;
    count = min_point-1;
    cout << "Enter max_point: \n",
    cin >> n;
    for(int i = min_point;i<=n;i++){
        in_degree[i] = 0;
    }
    cout << "Type -1 to end" << endl;
    for(int i = min_point; i <= n;i++){
        int v;
        cout << "Enter adjacent node to node " << i << endl; 
        do{
            cin >> v;
            if(v != -1){
                list[i].push_back(v);
                in_degree[v]++;
            }
        }while(v != -1);
    }
    topoSort();
    return 0;
}