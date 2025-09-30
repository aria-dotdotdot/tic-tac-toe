#include <stdio.h>

void show_board(char *board){

    printf("\n%c|%c|%c\n", board[0], board[1], board[2]);
    printf("______\n");
    printf("%c|%c|%c|\n", board[3], board[4], board[5]);
    printf("______\n");
    printf("%c|%c|%c|\n\n", board[6], board[7], board[8]);
}

void uinput(char *board, int turn){
    int move;
    scanf("%d", &move);
    while (board[move-1] == 'x'|| board[move-1] == 'y'){
        printf("square taken, choose another\n");
        scanf("%d", &move);
    }
    if(turn%2 ==0){
        board[move-1] = 'x';
    }else{
        board[move-1] = 'o';
    }
}

int win_check(char *board, int turn){

        if(board[0] == board[1] && board[1] == board[2] ||
       board[0] == board[3] && board[3] == board[6] || 
       board[0] == board[4] && board[4] == board[8] ||
       board[1] == board[4] && board[4] == board[7] ||
       board[2] == board[4] && board[4] == board[6] ||
       board[2] == board[5] && board[5] == board[8] ||
       board[3] == board[4] && board[4] == board[5] ||
       board[6] == board[7] && board[7] == board[8]){

            show_board(board);

            if(turn%2 == 0){
                printf("\nplayer x wins\n");
                return (0);
            }else{
                printf("\nplayer o wins\n");
                return (0);
            }
    } return (1);
    
}

int main(){

    int turn = 1;
    char board[9] = {'1','2','3','4','5','6','7','8','9'};

while(win_check(board, turn)){
      
    turn++;
    show_board(board);

    printf("you are symbol x, where would you like to go?\n");
    uinput(board, turn); 
    
    if (win_check(board, turn) == 0){
        break;
    }

    show_board(board);
    turn ++;

    printf("you are symbol o, where would you like to go?\n");
    uinput(board, turn);

    if (win_check(board, turn) == 0){
        break;
    }
}
    
    printf("meowmeowmeow\n");
    return 0;
}