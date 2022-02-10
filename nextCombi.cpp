#include<iostream>
#include<vector>
using namespace std;

int main(){
    int k,n;
    cout << "Enter n and k: \n";
    cin >> n >> k;
    vector<int> subset(k+1);
    subset[0] = -1;
    for(int i = 1;i<= k;i++){
        cin >> subset[i];
    }
    for(int i = k; i >=1;i--){
        if(subset[i] != n-k+i){
            subset[i]++;
            for(int j = i+1;j<=k;j++){
                subset[j] = subset[i] + j -i;
            }
            break;
        }
    }
    for(int i = 1;i<=k;i++){
        cout << subset[i] << " ";
    }
    return 0;
}