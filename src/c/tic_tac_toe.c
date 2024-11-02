#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<stdbool.h>
#include<conio.h>
/*int array[] = {
    6, 7, 8,
    11, 12, 13,
    16, 17, 18
};*/

void insertBoard(int* board)
{
    for (int i = 0; i < 9; i++)
    {
       board[i] = 2;
    }
}

void printBoard(const int* board)
{
    for (int i = 0; i < 9; i++)
    {
        if ( i%3 == 0 && i != 0 ){
                   printf("\n\n\n");
        }
        printf("%16d", board[i]);
    }
    printf("\n\n");
}

int main()
{
    srand(time(NULL));
    int board[9];
    insertBoard(&board[0]);

    bool gameover = false;
    bool isrepeated = true;
    int userchoise, computerchoise, userobject, computerobject, usertries=0, computertries=0, userpoint=0, computerpoint=0, gameon, gamecount=1;
    
    printf("\nWelcome to the tic tac toe game!!!\n");
    printBoard(&board[0]);

    printf("\nPlease select which object you want to use: 1 or 0 ?\n");
    scanf("%d", &userobject);
    if(userobject == 1) computerobject = 0;
    else computerobject = 1;
    
    while(!gameover)
    {
        gamecount = 1; userpoint = 0; computerpoint = 0; 
        if (gamecount==1)
        {
            printf("Enter your position: ");
            scanf("%d", &userchoise);
            board[userchoise-1] = userobject;
            printBoard(&board[0]);
            usertries++;
            if (usertries>=3)
            {
                if ( (board[0]==userobject) && (board[1]==userobject) && (board[2]==userobject) ) userpoint++;
                if ( (board[3]==userobject) && (board[4]==userobject) && (board[5]==userobject) ) userpoint++;
                if ( (board[6]==userobject) && (board[7]==userobject) && (board[8]==userobject) ) userpoint++;
                if ( (board[0]==userobject) && (board[3]==userobject) && (board[6]==userobject) ) userpoint++;
                if ( (board[1]==userobject) && (board[4]==userobject) && (board[7]==userobject) ) userpoint++;
                if ( (board[2]==userobject) && (board[5]==userobject) && (board[8]==userobject) ) userpoint++;
                if ( (board[0]==userobject) && (board[4]==userobject) && (board[8]==userobject) ) userpoint++;
                if ( (board[2]==userobject) && (board[4]==userobject) && (board[6]==userobject) ) userpoint++;
                
                if (userpoint)
                {
                    printf("congrats you are winner!");
                    printf("Do you want to play one more time? If yes press 1 or no press 0 to exit.\n");
                    scanf("%d",&gameon);
                    if (gameon)
                    {
                        insertBoard(&board[0]);
                        gamecount++;
                        usertries=0; computertries=0;
                    }
                    else
                    {
                        gameover = true;
                        gamecount++;
                    } 
                }   
            }
        }

        if ((usertries==5) && (gamecount==1))
        {
            printf("Sorry result is draw. No winner!!!\n");
            printf("Do you want to play one more time? If yes press 1 or no press 0 to exit.\n");
                scanf("%d",&gameon);
                if (gameon)
                    {
                        insertBoard(&board[0]);
                        gamecount++;
                        usertries=0; computertries=0;
                    }
                else 
                {
                    gameover = true;
                    gamecount++;
                } 
        }

        if (gamecount==1)
        {
            printf("Computers position: ");
            computerchoise = 1+ rand()%9;
            isrepeated = true;
            while (isrepeated)
            {
                if ((board[computerchoise-1]==userobject) || (board[computerchoise-1]==computerobject))
                {
                    computerchoise = 1+ rand()%9;
                    isrepeated = true;
                }
                else
                {
                    isrepeated = false;
                }
            }
            printf("%d\n", computerchoise);
            board[computerchoise-1] = computerobject;
            printBoard(&board[0]);
            computertries++;
            if (computertries>=3)
            {
                if ( (board[0]==computerobject) && (board[1]==computerobject) && (board[2]==computerobject) ) computerpoint++;
                if ( (board[3]==computerobject) && (board[4]==computerobject) && (board[5]==computerobject) ) computerpoint++;
                if ( (board[6]==computerobject) && (board[7]==computerobject) && (board[8]==computerobject) ) computerpoint++;
                if ( (board[0]==computerobject) && (board[3]==computerobject) && (board[6]==computerobject) ) computerpoint++;
                if ( (board[1]==computerobject) && (board[4]==computerobject) && (board[7]==computerobject) ) computerpoint++;
                if ( (board[2]==computerobject) && (board[5]==computerobject) && (board[8]==computerobject) ) computerpoint++;
                if ( (board[0]==computerobject) && (board[4]==computerobject) && (board[8]==computerobject) ) computerpoint++;
                if ( (board[2]==computerobject) && (board[4]==computerobject) && (board[6]==computerobject) ) computerpoint++;
                
                if(computerpoint)
                {
                    printf("Computer is winner!");
                    printf("Do you want to try one more time? If yes press 1 or no press 0 to exit.\n");
                    scanf("%d",&gameon);
                    if (gameon)
                    {
                        insertBoard(&board[0]);
                        gamecount++;
                        usertries=0; computertries=0;
                    }
                    else
                    {
                        gameover = true;
                        gamecount++;
                    } 
                }
            }
        }
    }
    return 0;
}