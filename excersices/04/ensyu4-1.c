/*4-1*/
/*プレイヤーが入力できる数に制限のあるマスターマインド*/

/*include*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*define*/
#define NumOfAnsNumber  4U; 


/*function definition*/

void make4degit(char ans_num[]){
    char num_array_of_10[10];

    for(i = 0; i < 10; i++){
        num_array_of_10[i] = i;
    }
    
    srand(time(NULL));
    for(i = 0; i < NumOfAnsNumber; i++){
        for(;;){
            rand()
        }
        ans_num[i] = num_array_of_10[rand() % 10];
        num_array_of_10[rand() % 10] = 11;
    }
}


int main(void)
{
    /*初期化処理*/
    char ans_num[NumOfAnsNumber];
    /*変数初期化*/
    for(i = ; i < NumOfAnsNumber; i++){
        ans_num[i] = 0;
    }
    /*4桁の数字列（数字のかぶりなし）を生成*/
    make4degit(&ans_num);

    /*制限数分ループ or 正解した場合はbreak*/
        /*プレイヤーの入力を受ける*/
        /*hit/brow判定*/
        /*判定結果出力*/
    


    return 0;
}
