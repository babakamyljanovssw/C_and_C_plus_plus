#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int cash = 100;
void Play(int bet)
{
    char *c = (char*)malloc(1000*sizeof(char));
    c[0] = 'J'; c[1] = 'Q'; c[2] = 'K';
    printf("Shuffling...\n");
    srand(time(NULL));
    for (int i = 0; i < 5; i++)
    {
        int x = rand()%3;
        int y = rand()%3;
        int temp = c[x];
        c[x] = c[y];
        c[y] = temp;
    }

    int userguess;
    printf("Enter your guess: ");
    scanf("%d",&userguess);
    if (c[userguess-1] == 'Q')
    {
        cash += 3*bet;
        printf("You win! Result = %c%c%c Total cash = %d\n",c[0],c[1],c[2],cash); 
    }
    else
    {
        cash -= bet;
        printf("You loose! Result = %c%c%c Total cash = %d\n",c[0],c[1],c[2],cash); 
    }
    free(c);
}
int main()
{
    int bet;
    printf("Welcome to the Virtual Casino\n");
    printf("Total cash = %d\n",cash);
    while (cash>0)
    {
        printf("What is your bet: ");
        scanf("%d",&bet);
        if(bet == 0 || bet > cash) break;
        Play(bet);
        printf("****************************\n");
    }
    return 0;
}