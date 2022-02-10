#include<iostream>
using namespace std;
int count = 0;
int a[1000];
int n,m;

int check(){
    return 1;
}

void print(){
    for(int i  =1;i<= m;i++){
        cout << a[i] << " ";
    }
    cout << endl;
}

void Try(int k){
    for(int i = a[k-1] +1; i <= n -m +k;i++){
        a[k] = i;
        if(k == m){
            if(check()){
                count++;
                print();
            }
        }else{
            Try(k+1);
        }
    }
}

int main(){
    cout << "Enter n and m: \n";
    cin >> n >> m;
    a[0] = 0;
    Try(1);
    cout << count;
    return 0;
}