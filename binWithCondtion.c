#include<stdio.h>
int bin[1000];
int n;
int count = 0;

//condition
int check(){

}

void try(int k){
    int i = 0;
    for(i = 0;i<=1;i++){
        bin[k] = i;
        if(k == n-1){
            if(check()){
                count++;
            }
        }else{
            try(k+1);
        }

    }
}

int main(){
    scanf("%d", &n);
    try(0);
    printf("%d", count);
    return 0;
}