/*
    ------------------------------------------
    Sasso carta forbici -- Rock paper scissors
    ------------------------------------------ 

    Made by: landiluigi746
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//functions
void gameplay(void); //manages the match
short int computerMove(void);
short int playerMove(void);
char* checkType(short int play);
short int checkWinner(short int player, short int computer);

int main()
{
    char choice;

    printf("\t-----------------------\n");
    printf("\t|                     |\n");
    printf("\t| Rock-Paper-Scissors |\n");
    printf("\t|                     |\n");
    printf("\t-----------------------\n");
    
    do{
        printf("\n\n\tEnter Y to play or N to exit: ");
        scanf(" %c", &choice);
        if(choice == 'Y')
            gameplay();
        if(choice != 'Y' && choice != 'N')
            puts("Invalid choice!");
    } while(choice != 'N');

    printf("\tSee you next time! ");
    scanf(" %c", &choice);
    return 0;
}

void gameplay(void)
{
    short int player = playerMove();
    short int computer = computerMove();
    short int result = checkWinner(player, computer);

    printf("\n");
    printf("\tYou entered: %s.\n", checkType(player));
    printf("\tComputer entered: %s.\n", checkType(computer));
    printf("\n");

    if(result == 0)
        printf("\tDraw!");
    else if(result == 1)
        printf("\tComputer won!");
    else
        printf("\tYou won!");

    return;
}

short int playerMove(void)
{
    short int input;

    do{
        printf("\n\tRock (1), Paper (2) or Scissors (3)? ");
        scanf("%hd", &input);
    } while(input <= 0 || input > 3);

    return input;
}

short int computerMove(void)
{
    srand(time(NULL));
    short int random = rand() % 1000;
    
    if(random % 3 == 0)
        return 1;
    else if(random % 3 == 1)
        return 2;
    else if(random % 3 == 2)
        return 3;
}

short int checkWinner(short int player, short int computer)
{
    if(player == computer)
        return 0;
    else if( (player == 1 && computer == 2) || (player == 2 && computer == 3) || (player == 3 && computer == 1) )
        return 1;
    else
        return 2;
}

char* checkType(short int play)
{
    if(play == 1)
        return "Rock";
    else if(play == 2)
        return "Paper";
    else
        return "Scissors";
}