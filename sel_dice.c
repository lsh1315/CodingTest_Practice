#include <stdio.h>
#include <stdlib.h>

int* solution(int** dice, int dice_row, int dice_column){
    int* answer = (int*)malloc(sizeof(int)*dice_row/2);
    int* temp = (int*)malloc(sizeof(int)*dice_row/2);

    int sel_idx = 0;
    int base = 0;
    int maxWin = 0;
    int sumA, sumB, aw, bw, check;

    int i,j,k,x,d;

    while(1){
        if(sel_idx<dice_row/2-1){

            if(sel_idx==0 && base>0) break;     // excute half

            if(base<dice_row-1){
                temp[sel_idx++] = base++;
            }else{
                base = temp[--sel_idx]+1; 
                if(sel_idx<0){
                    break;
                }
            }
        }else if(sel_idx == dice_row/2-1){
            while(base<=dice_row/2+sel_idx){
                temp[sel_idx] = base++;

                /***** process part *****/
                for(int i=0;i<dice_row/2;i++){
                    printf("%d ", temp[i]);     // just print array
                }
                printf("\n");

                aw = 0;
                bw = 0;
                x = 1;

                for(i=0;i<dice_row;i++){
                    x *= dice_column;
                }
                
                for(i=0;i<x;i++){
                    d = i;
                    sumA = 0;
                    sumB = 0;
                    for(j=0; j<dice_row; j++){
                        check = 0;
                        for(k=0; k<dice_row/2; k++){
                            if(j == temp[k]) check = 1;
                        }
                        if(check==1){
                            sumA += dice[j][d%dice_column];
                        }else{
                            sumB += dice[j][d%dice_column];
                        }
                        d /= dice_column;
                    }
                    if(sumA>sumB){
                        aw++;
                    }else if(sumB>sumA){
                        bw++;
                    }
                }

                if(aw>=bw){
                    if(aw>maxWin){
                        maxWin = aw;
                        for(i=0;i<dice_row/2;i++){
                            *(answer+i) = *(temp+i)+1;
                        }
                    }
                }else if(bw>aw){
                    if(bw>maxWin){
                        maxWin = bw;
                        k=0;
                        for(i=0;i<dice_row;i++){
                            check = 0;
                            for(j=0;j<dice_row/2;j++){
                                if(i==temp[j]) check = 1;
                            }
                            if(check==0){
                                *(answer+(k++)) = i+1;
                            }
                        }
                    }
                }
                /***** process end *****/
            }
            base = temp[--sel_idx]+1;
        }
    }

    free(temp);

    return answer;
}

int main(){

    int dice_arr[4][6] = {
        {1, 2, 3, 4, 5, 6},
        {3, 3, 3, 3, 4, 4},
        {1, 3, 3, 4, 4, 4},
        {1, 1, 4, 4, 5, 5}
    };

    int num_dice = 4;

    // **2D 배열을 int** 형식으로 변환**
    int** dice = (int**)malloc(num_dice * sizeof(int*));
    for (int i = 0; i < num_dice; i++) {
        dice[i] = (int*)malloc(6 * sizeof(int));
        for (int j = 0; j < 6; j++) {
            dice[i][j] = dice_arr[i][j];
        }
    }

    int *ans = NULL;
    ans = solution(dice,4,6);

    printf("Answer : [ ");
    for(int i=0;i<num_dice/2;i++){
        printf("%d ", ans[i]);
    }
    printf("]\n");

    free(ans);

    for (int i = 0; i < num_dice; i++) {
        free(dice[i]);
    }
    free(dice);

    return 0;
}