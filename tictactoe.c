#include <stdio.h>

void show_board(char *board){

    for(int i = 0; i < 9; i++){

        printf("[%c]", board[i]);
        if(board[(i+1)%3] == 0){
            printf("\n");
        }
    }
}

void uinput(char *board, int turn){

    int move;
    scanf("%d", &move); 
    while (turn){
        if (move > 0 && move < 10 && board[move-1] != 'x' && board[move-1] != 'o'){ //check for valid move
            break;
        }
        printf("invalid move, try again\n");
        scanf(" %d", &move);   
    }
    if(turn%2 ==0){
        board[move-1] = 'x';
    }else{                  //check whose move it is and enter that character accordingly
        board[move-1] = 'o';
    }
}

int win_check(char *board, int turn){

    show_board(board);
    if(board[0] == board[1] && board[1] == board[2] ||
       board[0] == board[3] && board[3] == board[6] || 
       board[0] == board[4] && board[4] == board[8] ||
       board[1] == board[4] && board[4] == board[7] ||   //checking for every possible win
       board[2] == board[4] && board[4] == board[6] ||
       board[2] == board[5] && board[5] == board[8] ||
       board[3] == board[4] && board[4] == board[5] ||
       board[6] == board[7] && board[7] == board[8]){

            if(turn%2 == 0){
                printf("\nplayer x wins\n");
                return (0);
            }else{
                printf("\nplayer o wins\n");
                return (0);
            }
        } 
        if (turn == 10){
            printf("game overrr you draw\n");   //board is full when turn == 10 so game ends
            return (0);
        } 
    return (1); //return 1 to keep the loop going, return 0 makes it end
}

int main(){

    int turn = 1;   
    char board[9] = {'1','2','3','4','5','6','7','8','9'};
    
    while(win_check(board, turn)){
    
        turn++;
        if (turn%2 == 0){
        printf("you are symbol x, where would you like to go?\n");
        }else{
            printf("you are symbol o, where would you like to go?\n");
        }
        uinput(board, turn);
    }
        printf("meowmeowmeow\n");
    return 0;
}