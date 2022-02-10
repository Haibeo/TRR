#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n;
int job_a[100];
int job_b[100];
vector<int> N1;
vector<int> N2;
bool fn1(const int& a, const int &b){
    return job_a[a] < job_a[b];
}
bool fn2(const int& a, const int& b){
    return job_b[a] > job_b[b];
}
int main(){
    cout << "Enter number of job on 2 machines: \n";
    cin >> n;
    cout << "Enter processing time for machine A: \n";
    for(int i = 0;i<n;i++){
        cin >> job_a[i];
    }
    cout << "Enter processing time for machine B: \n";
    for(int i = 0;i<n;i++){
        cin >> job_b[i];
    }
    for(int i = 0;i<n;i++){
        if(job_a[i] <= job_b[i]){
            N1.push_back(i);
        }else{
            N2.push_back(i);
        }
    }
    sort(N1.begin(), N1.end(), fn1);
    sort(N2.begin(), N2.end(), fn2);
    N1.insert(N1.end(), N2.begin(), N2.end());
    for(int i =0 ;i< N1.size();i++){
        cout << N1[i]+1 << " ";
    }
    return 0;
}