#include<iostream>
using namespace std;

int main(){
    int a[1000] = {0};
    int n;
    cout << "Enter n: \n";
    cin >> n;
    a[0] = 1;
    for(int i = 1;i <= n;i++){
        for(int j = 0; j <= n-i;j++){
            a[i+j] += a[j];
        }
    }
    cout << a[n];
    return 0;
}