#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int place[5] = {0};

void stay()
{
    int j;
    int tmp;

    for (j = 2; j < 6; j++)
    {
        while (1)
        {
            tmp = rand() % 5;
            if (place[tmp] == 0)
            {
                place[tmp] = j;
                break;
            }
        }
    }
}

void high_low()
{
    if (rand() % 2)
    {
        printf("H\n");
    }
    else
    {
        printf("L\n");
    }
}

int main()
{
    char cn1_rl;
    int i;

    srand(time(NULL));
    printf("CN1���E���ɂ��܂���?\n[y=�E,else=��]");
    cn1_rl = getchar();

    // 0 1 2 3 4
    // CN1 CN2 PHSW TGSW TCSW

    if (cn1_rl != 'y')
    {
        place[0] = 1;
        printf("CN1�����ɂ��܂�\n");
    }
    else
    {
        place[4] = 1;
        printf("CN1���E�ɂ��܂�\n");
    }

    printf("\nCN1�̃s��\n");
    printf("1�@5V\n");
    printf("2�@CN2\n");
    printf("3�@PHSW�@�́@�Ւf�Ł@");
    high_low();
    printf("4�@TGSW�@�́@�@��Ł@");
    high_low();
    printf("5�@TCSW�@�́@�����ā@");
    high_low();

    printf("\n�z�u\n");
    stay();
    for (i = 0; i < 5; i++)
    {
        if (place[i] == 1)
        {
            printf("CN1 �@");
        }
        else if (place[i] == 2)
        {
            printf("CN2 �@");
        }
        else if (place[i] == 3)
        {
            printf("PHSW�@");
        }
        else if (place[i] == 4)
        {
            printf("TGSW�@");
        }
        else if (place[i] == 5)
        {
            printf("TCSW�@");
        }
    }

    printf("\n\nanykey close this app\n");
    getchar();
}