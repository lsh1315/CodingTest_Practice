#include <stdio.h>
#include <stdlib.h>

/****** N conbination N/2 ******/
void nC0_5n(int n){
    int* temp = (int*)malloc(sizeof(int)*n/2);

    int count = 0;
    int base = 1;

    while(1){
        if(count<n/2-1){
            if(base<n){
                temp[count++] = base++;
            }else{
                base = temp[--count]+1; 
                if(count<0){
                    break;
                }
            }
        }else if(count == n/2-1){
            while(base<=n/2+count+1){
                temp[count] = base++;

                /***** process part *****/
                for(int i=0;i<n/2;i++){
                    printf("%d ", temp[i]);     // just print array
                }
                printf("\n");
                /***** process end *****/
            }
            base = temp[--count]+1;
        }
    }

    free(temp);
}

int main(){

    nC0_5n(4);

    return 0;
}