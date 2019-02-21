
bool isPossible(int board[][9], int row, int col, int posNum){
    if(0<=row && row<3 && 0<=col && col<3){
        for(int i=0 ; i<3 ; i++){
            for(int j=0; j<3; j++){
                if(board[i][j]==posNum){
                    return false;
                }
            }
        }
    }
    else if(0<=row && row<3 && 3<=col && col<6){
        for(int i=0 ; i<3 ; i++){
            for(int j=3; j<6; j++){
                if(board[i][j]==posNum){
                    return false;
                }
            }
        }

    }
    else if(0<=row && row<3 && 6<=col && col<9){
        for(int i=0 ; i<3 ; i++){
            for(int j=6; j<9; j++){
                if(board[i][j]==posNum){
                    return false;
                }
            }
        }
    }
    else if(3<=row && row<6 && 0<=col && col<3){
        for(int i=3 ; i<6 ; i++){
            for(int j=0; j<3; j++){
                if(board[i][j]==posNum){
                    return false;
                }
            }
        }
    }
    else if(3<=row && row<6 && 3<=col && col<6){
        for(int i=3 ; i<6 ; i++){
            for(int j=3; j<6; j++){
                if(board[i][j]==posNum){
                    return false;
                }
            }
        }
    }
    else if(3<=row && row<6 && 6<=col && col<9){
        for(int i=3 ; i<6 ; i++){
            for(int j=6; j<9; j++){
                if(board[i][j]==posNum){
                    return false;
                }
            }
        }
    }
    else if(6<=row && row<9 && 0<=col && col<3){
        for(int i=6 ; i<9 ; i++){
            for(int j=0; j<3; j++){
                if(board[i][j]==posNum){
                    return false;
                }
            }
        }

    }
    else if(6<=row && row<9 && 3<=col && col<6){
        for(int i=6 ; i<9 ; i++){
            for(int j=3; j<6; j++){
                if(board[i][j]==posNum){
                    return false;
                }
            }
        }
    }
    else if(6<=row && row<9 && 6<=col && col<9){
        for(int i=6 ; i<9 ; i++){
            for(int j=6; j<9; j++){
                if(board[i][j]==posNum){
                    return false;
                }
            }
        }
    }

    for(int i=row-1 ;i>=0 ; i--){
        if(board[i][col]==posNum){
            return false;
        }
    }

    for(int i=0 ; i<9 ; i++){
        if(i!=row && board[i][col]==posNum){
            return false;
        }
    }

    for(int i=0 ; i<9 ; i++){
        if(i!=col && board[row][i]==posNum){
            return false;
        }
    }



    return true;


}
bool isIncomplete(int board[][9]  ,int &row , int &col){
    for(row=0 ; row<9 ; row++){
        for(col=0 ; col<9 ; col++){
            if(board[row][col]==0){
                return true;
            }
        }
    }

    return false;
}

bool sudokuSolver(int board[][9]){
    int row=0;
    int col=0;
  
  //  cout<<"--------"<<endl;
    if(!isIncomplete(board,row,col)){
        return true;
    }

    for(int posNum=1; posNum<10 ; posNum++){

        if(isPossible(board,row,col,posNum)){
            board[row][col]=posNum;
            if(sudokuSolver(board)){
                return true;
            }
            board[row][col]=0;
        }
    }
    return false;
}
