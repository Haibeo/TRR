#include<iostream>
using namespace std;
int n;
int tmp_sum = 0;
int solution[1000];
int count = 0;
int count_res = 0;
void print(){
    for(int i=0;i< count;i++){
        cout << solution[i] << " ";
    }
    cout << endl;
}

int check(){
    for(int i = 0;i< count -1;i++){
        if(solution[i] > solution[i+1]){
            return 0;
        }
    }
    return 1;
}
void Try(){
    for(int i = 1;i <= n - tmp_sum;i++){
        tmp_sum += i;
        solution[count++] = i;
        if(tmp_sum == n){
            if(check()){
                count_res++;
                print();
            }
        }else{
            Try();
        }
        tmp_sum -= i;
        count--;
    }
}
int main(){
    cout << "Enter n: \n";
    cin >> n;
    Try();
    cout << count_res;
    return 0;
}