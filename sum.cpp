#include<iostream>
using namespace std;
int sum;
int n;
int tmp_sum = 0;
int solution[1000];
int count = 0;


// x1 + x2 + x3 + ... = n
void print(){
    for(int i =1;i<=n;i++){
        cout << solution[i] << " ";
    }
    cout << endl;
}

void Try(int k){
    if(k == n){
        count++;
        solution[k] = sum - tmp_sum;
        print();
        return;
    }
    for(int i = 1; i < sum - tmp_sum;i++){
        tmp_sum += i;
        solution[k] = i;
        Try(k+1);
        tmp_sum -= i;
    }
}

int main(){
    cout << "Enter n and sum: \n";
    cin >> n >> sum;
    Try(1);
    cout << count;
    return 0;
}