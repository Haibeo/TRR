#include<iostream>
#include<utility>
#include<vector>
#include<algorithm>
using namespace std;
vector<pair<pair<int,int>,int>> list;
int n;
int max_weight;
int max_val = -1;
int Count[100] = {0};
int solution[100];
int cur_weight = 0;
int cur_val = 0;


bool fn(const pair<pair<int,int>,int> &x, const pair<pair<int,int>,int> &y){
    return x.first.first * 0.1/x.first.second > y.first.first * 0.1/y.first.second;
}

void Try(int k){
    for(int i = (max_weight-cur_weight)/list[k].first.second; i>=  0;i--){
        Count[list[k].second] = i;
        cur_weight += i * list[k].first.second;
        cur_val += i * list[k].first.first;
        int upper_bound = cur_val + (max_weight -  cur_weight) * list[1].first.first/list[1].first.second;
        if(upper_bound < max_val){
            return;
        }
        if(k == n){
            if(cur_val > max_val){
                max_val = cur_val;
                for(int i= 1;i<= n;i++){
                    solution[i] = Count[i];
                }
            }
        }else{
            Try(k+1);
        }
        cur_val -= i * list[k].first.first;
        cur_weight -= i * list[k].first.second;
    }
}

int main(){
    cout << "Enter n and max weight: \n";
    cin >> n >> max_weight;
    list.resize(n+1);
    cout << "Enter profit and weight: \n";
    for(int i =1;i<=n;i++){
        list[i].second = i;
        cin >> list[i].first.first >> list[i].first.second;
    }
    sort(list.begin()+1, list.end(), fn);
    cout << endl;
    Try(1);
    for(int i = 1;i<= n;i++){
        cout << solution[i] << " ";
    }
    cout << "\nMax profit: " << max_val;
    return 0;
}