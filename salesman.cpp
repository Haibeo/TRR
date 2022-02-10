#include<iostream>
using namespace std;
int matrix[20][20];
int n;
int start;
int solution[20];
int result[20];
bool check[20] = {false};
int Min = 99999;
int min_edge = -1;
int current_weight = 0;

void Try(int k){
    for(int i = 2;i<= n;i++){
        if(!check[i]){
            check[i] = true;
            current_weight += matrix[solution[k-1]][i];
            solution[k] = i;
            int lower_bound = current_weight + (n-k+1) * min_edge;
            if(lower_bound > Min){
                return;
            }
            if(k == n){
                if(current_weight + matrix[i][start] < Min){
                    Min = current_weight + matrix[i][start];
                    for(int i = 2;i<= n;i++){
                        result[i] = solution[i];
                    }
                }
            }else{
                Try(k+1);
            }
            current_weight -= matrix[solution[k-1]][i];
            check[i] = false;
        }
    }
}

int main(){
    cout << "Enter n and starting point: \n";
    cin >> n >> start;
    check[start] = true;
    solution[1] = start;
    solution[n+1] = start;
    result[1] = start;
    result[n+1] = start;
    for(int i = 1;i<= n;i++){
        for(int j = 1;j<= n;j++){
            cin >> matrix[i][j];
            if(matrix[i][j] < min_edge){
                min_edge = matrix[i][j];
            }
        }
    }
    Try(2);
    for(int i =  1;i<= n+1;i++){
        cout << result[i] << " ";
    }
    cout << "\nCost: " << Min; 
    return 0;
}