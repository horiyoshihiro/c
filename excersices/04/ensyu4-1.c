/*4-1*/
/*プレイヤーが入力できる数に制限のあるマスターマインド*/

/*include*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*define*/
#define NumOfAnsNumber       4U;
#define NumOfChanceToAns     5U;
#define ArrayFrom0To10[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9} 


/*function definition*/

/* name     : make4digit                                         */
/* function : generate 4 number as the answer of this game       */
/*            the array of number should be different each other */
void make4digit(char ans_num[]){
    
    srand(time(NULL));
    for(int i = 0; i < NumOfAnsNumber; i++){
        int genNum;

        for(;;){
            genNum = rand() % 10:
            if(ArrayFrom0To10[genNum] == 11){
                /* generate the same number ever */
                /* generate number again */
                continue;
            }else{
                ans_num[i] = ArrayFrom0To10[genNum];
                ArrayFrom0To10[genNum] = 11;
                break;
            }
        }
    }
}

/* name     : inputResponseNumber                           */
/* function : put the numbers User input as response number */
void inputResponseNumber(char *res_num){
    int result;
    for(int i = 0; i < NumOfAnsNumber; i++){
        result = scanf(%u, res_num[i]);
        if(result == EOF || result > 1 || res_num[i] > 9){
            /* User could not input number correctly*/
            i--;
        }else{
            /* keep res_num[i] */
        }
    }
}


/* name     : judgeNumbers */
/* function : compare ans_num with res_num and return result, numbers of hit and brow */
bool judgeNumbers(char *ans_num, char *res_num, char *res){
    char hit;
    char brow;
    bool result = false;

    /* count the number of nit */
    for(int i = 0; i < NumOfAnsNumber; i++ ){
        for(int j = 0; j < NumOfAnsNumber; j++){
            if(ans_num[i] == res_num[i]){
                hit++;
            }else if(ans_num[i] == res_num[j]){
                brow++;
            }
        }
    }

    if(hit == NumOfAnsNumber){
        result = true;
    }

    res[0] = hit;
    res[1] = brow;

    return result;
}




int main(void)
{
    /*初期化処理*/
    bool result;
    char ans_num[NumOfAnsNumber];
    char res_num[NumOfAnsNumber];
    char res[2] = {0,0}; /* hit, brow*/

    /*変数初期化*/
    result = false;
    for(int i = ; i < NumOfAnsNumber; i++){
        ans_num[i] = 0;
        res_num[i] = 0;
    }

    /*4桁の数字列（数字のかぶりなし）を生成*/
    make4digit(ans_num);

    /*制限数分ループ or 正解した場合はbreak*/
    for(int i = 0; i < NumOfChanceToAns; i++){
        /*プレイヤーの入力を受ける*/
        inputResponseNumber(res_num);

        /*hit/brow判定*/
        result = judgeNumbers(ans_num, res_num, res);

        /*判定結果出力*/
        printResult(result, res);

        if( result != true){
            /* keep process going */
        }else{
            break;
        }
    }

    return 0;
}
