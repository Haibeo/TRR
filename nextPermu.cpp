#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n;
    cout << "Enter n: \n";
    cin >> n;
    vector<int> set(n+1);
    for(int i= 1; i<= n;i++){
        cin >> set[i];
    }
    int min_index = -1;
    int i = n;
    for(i=n-1; i >= 1;i--){
        if(set[i] < set[i+1]){
            for(int j = i+1;j <= n;j++){
                int min = 999999;
                if(set[j] < min && set[j] > set[i]){
                    min = set[j];
                    min_index = j;
                }
            }
            break;
        }
    }
    if(min_index != -1){
        int tmp = set[i];
        set[i] = set[min_index];
        set[min_index] = tmp;
        int left = i+1;
        int right = n;
        while( left < right){
            int tmp2 = set[left];
            set[left] = set[right];
            set[right] = tmp2;
            left++;
            right--;
        }
    }
    for(int k = 1;k<= n;k++){
        cout << set[k] << " ";
    }
    return 0;
}