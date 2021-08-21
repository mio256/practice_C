#include <stdio.h>

int main(void){
    int m,s,xm,xs,ans;

    do{
        do{    
            do{
                printf("開始時間 [分　秒]");
                scanf("%d %d",&m,&s);

                if(m<0){
                    printf("エラー [分]の値が0未満です。\n\n");
                }
                if(s<0){
                    printf("エラー [秒]の値が0未満です。\n\n");
                }
                if(s>=60){
                    printf("エラー [秒]の値が60以上です。\n\n");
                }

            }while(m<0||s<0||s>=60);

            do{
                printf("終了時間 [分　秒]");
                scanf("%d %d",&xm,&xs);

                if(xm<0){
                    printf("エラー [分]の値が0未満です。\n\n");
                }
                if(xs<0){
                    printf("エラー [秒]の値が0未満です。\n\n");
                }
                if(xs>=60){
                    printf("エラー [秒]の値が60以上です。\n\n");
                }

            }while(xm<0||xs<0||xs>=60);

            if(xm*60+xs<=m*60+s){
                printf("エラー　終了時間が開始時間よりも早いです。\n\n");
            }

        }while(xm*60+xs<=m*60+s);

        ans=(xm*60+xs)-(m*60+s);

        printf("関数入力時間は%2d分%2d秒です。\n\n",ans/60,ans%60);
        printf("[任意のキー + ENTER]で終了します。\n");
        printf("[5 + ENTER]で再度計算します。\n");
        scanf("%d",&ans);

    }while(ans==5);

    return 0;
}