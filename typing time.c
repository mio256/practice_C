#include <stdio.h>

int main(void){
    int m,s,xm,xs,ans;

    do{
        do{    
            do{
                printf("�J�n���� [���@�b]");
                scanf("%d %d",&m,&s);

                if(m<0){
                    printf("�G���[ [��]�̒l��0�����ł��B\n\n");
                }
                if(s<0){
                    printf("�G���[ [�b]�̒l��0�����ł��B\n\n");
                }
                if(s>=60){
                    printf("�G���[ [�b]�̒l��60�ȏ�ł��B\n\n");
                }

            }while(m<0||s<0||s>=60);

            do{
                printf("�I������ [���@�b]");
                scanf("%d %d",&xm,&xs);

                if(xm<0){
                    printf("�G���[ [��]�̒l��0�����ł��B\n\n");
                }
                if(xs<0){
                    printf("�G���[ [�b]�̒l��0�����ł��B\n\n");
                }
                if(xs>=60){
                    printf("�G���[ [�b]�̒l��60�ȏ�ł��B\n\n");
                }

            }while(xm<0||xs<0||xs>=60);

            if(xm*60+xs<=m*60+s){
                printf("�G���[�@�I�����Ԃ��J�n���Ԃ��������ł��B\n\n");
            }

        }while(xm*60+xs<=m*60+s);

        ans=(xm*60+xs)-(m*60+s);

        printf("�֐����͎��Ԃ�%2d��%2d�b�ł��B\n\n",ans/60,ans%60);
        printf("[�C�ӂ̃L�[ + ENTER]�ŏI�����܂��B\n");
        printf("[5 + ENTER]�ōēx�v�Z���܂��B\n");
        scanf("%d",&ans);

    }while(ans==5);

    return 0;
}