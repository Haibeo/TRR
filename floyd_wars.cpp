#include<bits/stdc++.h>
using namespace std;
int min_point;
int n;
int edges;
int matrix1[10][10];
int matrix2[10][10];
int path_matrix[20][20];


void copy(){
    for(int i = min_point ; i <= n;i++){
        for(int j = min_point; j <= n;j++){
            matrix2[i][j] = matrix1[i][j];
        }
    }
}

void initialize(){
    for(int i = min_point; i <= n ; i++){
        for(int j = min_point; j <=n; j++){
            path_matrix[i][j] = i;
        }
    }
    for(int i = min_point ; i <= n; i++){
        for(int j = min_point; j <= n ; j++){
            if(i == j){
                matrix1[i][i] = 0;
            }else{
                matrix1[i][j] = 99;
            }
        }
    }
}

void adj_input(){
    cout << "Enter number of edges: \n";
    cin >> edges;
    for(int i = 0; i < edges; i++){
        int u, v, cost;
        cin >> u >> v >> cost;
        matrix1[u][v] = cost;
    }
}

void matrix_input(){
    for(int i = min_point; i <= n;i++){
        for(int j = min_point; j <= n;j++){
            cin >> matrix1[i][j];
        }
    }
}

void solve(){
    for(int i = min_point ; i <= n ; i++){
        copy();
        for(int j = min_point; j <= n;j++){
            for(int k = min_point ; k <= n;k++){
                if(matrix2[j][k] > matrix2[j][i] + matrix2[i][k]){
                    matrix1[j][k] = matrix2[j][i] + matrix2[i][k];
                    path_matrix[j][k] = i;
                }
            }
        }
    }
    cout << "Result: \n";
    for(int i = min_point; i <= n;i++){
        for(int j  = min_point; j <= n;j++){
            printf("%-2d ", matrix1[i][j]);
        }
        cout << endl;
    }
    cout << "Path matrix: \n";
    for(int i = min_point; i <= n;i++){
        for(int j = min_point; j<=n;j++){
            printf("%-2d ", path_matrix[i][j]);
        }
        cout << endl;
    }
}

int main(){
    cout << "Enter min point, n: \n";
    cin >> min_point >> n;
    initialize();
    adj_input();
    //matrix_input();
    solve();
    return 0;
}