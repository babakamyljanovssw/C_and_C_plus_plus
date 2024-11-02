#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{
    srand(time(NULL));
    int UserNum;
    printf("Welcome to Guessing Number game. I choose one number from 1 to 100, you need to guess in 5 tries!\n");
    scanf("%d", &UserNum);
    do
    {
        int tries = 1;
        int CompNum = 1 + rand()%100;
        while(tries !=5)
        {
            if (UserNum>CompNum)
            {
                printf("Your guessed number larger than mine, enter smaller:\n");
                scanf("%d", &UserNum);
                tries ++;
            }
            else if (UserNum<CompNum)
            {
                printf("Your guessed number smaller than mine, enter larger:\n");
                scanf("%d", &UserNum);
                tries ++;
            }
            else if (UserNum == CompNum)
            {
                printf("Congrats! You guessed in %d tries\n", tries);
                printf("Do you want to continue? If yes enter any number or press 0 to finish it:\n");
                scanf("%d", &UserNum);
             }
            if (tries == 5)
            {
                printf("You lost game. You exceeded limit of tries! Do you want to try again? if yes enter any number or press 0 to finish it\n");
                scanf("%d", &UserNum);   
            }
        }

    } while (UserNum!=0);
    return 0;
}