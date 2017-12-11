/* ===== ===== =====

Theory of Programming

Artificial Intelligence - MiniMax Algorithm
http://theoryofprogramming.com/2017/12/12/minimax-algorithm/
GitHub - https://github.com/VamsiSangam/theoryofprogramming
Code Contributor - Vamsi Sangam

===== ===== ===== */

import java.util.Scanner;

public class MiniMaxAlgorithm {
    static int N = 3;
    static int X = 1;
    static int O = -1;

    public static void main(String[] args) {
        int[][] game = new int[N][N];
        Scanner in = new Scanner(System.in);
        
        System.out.println("Play TicTacToe! You are X!");
        printGame(game);
        
        for (int turn = 1; turn <= N * N; ++turn) {
            if (turn % 2 == 1) {    // User's turn -> X's turn
                System.out.println("Your turn! Input 2 integers, row and colum (1 indexed) -");
                int row, col;
                
                row = in.nextInt() - 1;
                col = in.nextInt() - 1;
                
                game[row][col] = X;
            } else {    // Computer's turn -> O's turn
                System.out.println("Computer's turn!");
                MiniMaxResult computersMove = minimax(game, false);
                
                game[computersMove.row][computersMove.column] = O;
            }
            
            printGame(game);
            
            if (hasPlayerWon(game, X)) {
                System.out.println("X has won! Game over!");
                return;
            }
            
            if (hasPlayerWon(game, O)) {
                System.out.println("O has won! Game over!");
                return;
            }
        }
        
        System.out.println("It is a draw!");
    }
    
    public static MiniMaxResult minimax(int[][] game, boolean isXTurn) {
        if (hasPlayerWon(game, X)) {
            return new MiniMaxResult(10, -1, -1);
        }
        
        if (hasPlayerWon(game, O)) {
            return new MiniMaxResult(-10, -1, -1);
        }
        
        MiniMaxResult bestMove = new MiniMaxResult(isXTurn ? Integer.MIN_VALUE : Integer.MAX_VALUE, -1, -1);
        
        for (int i = 0; i < game.length; ++i) {
            for (int j = 0; j < game[i].length; ++j) {
                if (game[i][j] == 0) {  // an empty move
                    game[i][j] = isXTurn ? X : O;   // play this move
                    
                    // Recurse for other moves
                    MiniMaxResult currentMove = new MiniMaxResult(minimax(game, !isXTurn).score, i, j);
                    
                    // If this is best move, store the row, col and score
                    if ((isXTurn && currentMove.score > bestMove.score) || (!isXTurn && currentMove.score < bestMove.score)) {
                        bestMove = currentMove;
                    }
                    
                    // Revert this move
                    game[i][j] = 0;
                }
            }
        }
        
        if (bestMove.row == -1) {
            // there was no best move, which means there was
            // probably no move left to play, which is a draw
            return new MiniMaxResult(0, -1, -1) ;
        }
        
        return bestMove;
    }
    
    public static void printGame(int[][] game) {
        System.out.println("\nState of TicTacToe game -");
        for (int i = 0; i < game.length; ++i) {
            for (int j = 0; j < game[i].length; ++j) {
                if (game[i][j] == X) {
                    System.out.print("X ");
                } else if (game[i][j] == O) {
                    System.out.print("O ");
                } else {
                    System.out.print("_ ");
                }
            }
            
            System.out.println();
        }
    }
    
    public static boolean hasPlayerWon(int[][] game, int player) {
        for (int i = 0; i < game.length; ++i) {
            boolean isRowEqual = true, isColumnEqual = true;
            
            for (int j = 0; j < game[i].length; ++j) {
                if (game[i][j] != player) {
                    isRowEqual = false;
                }
                
                if (game[j][i] != player) {
                    isColumnEqual = false;
                }
            }
            
            if (isRowEqual || isColumnEqual) {
                return true;
            }
        }
        
        boolean isDiagonalEqual = true, isAntiDiagonalEqual = true;
        
        for (int i = 0; i < game.length; ++i) {
            if (game[i][i] != player) {
                isDiagonalEqual = false;
            }
            
            if (game[game.length - 1 - i][i] != player) {
                isAntiDiagonalEqual = false;
            }
        }
        
        return isDiagonalEqual | isAntiDiagonalEqual;
    }
    
    public static int score(int[][] game) {
        if (hasPlayerWon(game, X)) {
            return 10;
        } else if (hasPlayerWon(game, O)) {
            return -10;
        }
        
        return 0;
    }
}

class MiniMaxResult
{
    int score, row, column;
    
    public MiniMaxResult(int score, int row, int column) {
        this.score = score;
        this.row = row;
        this.column = column;
    }
}
