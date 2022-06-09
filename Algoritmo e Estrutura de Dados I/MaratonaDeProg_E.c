#include <stdlib.h>
#include <stdio.h>


int main (){
int n;
scanf("%d", &n);
int* vetor =(int*) malloc (sizeof(int)* n);
    for (int i = 0 ; i< n ; i++){
        scanf("%d", &vetor[i]);
    }
int c = 1;
    for (int i = 0 ; i < n ; i++){
        for (int j = 2 ; j <= vetor[i]; j++){
         if(vetor[i]%j == 0){
                c++;
            }
        }
        if(c==3){
            printf("YES ");
        }
        if(c!=3){
            printf("NO ");
        }
c=1;
    }
return 0;
}



