#include<bits/stdc++.h>
using namespace std;
int n1;
int adjacency[10][10];
int degree[10] = {0};
int edges;
int min_point;


int determinant(int matrix[10][10], int n) {
   int det = 0;
   int submatrix[10][10];
   if (n == 2)
   return ((matrix[0][0] * matrix[1][1]) - (matrix[1][0] * matrix[0][1]));
   else {
      for (int x = 0; x < n; x++) {
         int subi = 0;
         for (int i = 1; i < n; i++) {
            int subj = 0;
            for (int j = 0; j < n; j++) {
               if (j == x)
               continue;
               submatrix[subi][subj] = matrix[i][j];
               subj++;
            }
            subi++;
         }
         det = det + (pow(-1, x) * matrix[0][x] * determinant( submatrix, n - 1 ));
      }
   }
   return det;
}


int main(){
    cout << "Enter min point, n and number of edges: \n";
    cin >> min_point >> n1 >> edges;
    for(int i = 0;i < edges ; i++){
        int u, v;
        cin >> u >> v;
        degree[u]++;
        degree[v]++;
        adjacency[u][v] = 1;
        adjacency[v][u] = 1;
    }
    int matrix[10][10];
    for(int i = min_point+1; i <= n1 ; i++){
        for(int j = min_point+1; j <= n1;j++){
            int a = 0;
            if(i == j){
                a = degree[i];
            }
            matrix[i-min_point-1][j-min_point-1] = a - adjacency[i][j];
        }
    }
    cout << "Total number of spanning tree: " << abs(determinant(matrix, n1-min_point));
    return 0;
}