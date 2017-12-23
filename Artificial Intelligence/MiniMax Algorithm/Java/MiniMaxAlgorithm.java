/* ===== ===== =====

Theory of Programming

Artificial Intelligence - MiniMax Algorithm
http://theoryofprogramming.com/2017/12/12/minimax-algorithm/
GitHub - https://github.com/VamsiSangam/theoryofprogramming
Code Contributor - Vamsi Sangam

===== ===== ===== */

import java.util.Scanner;

public class MiniMaxAlgorithm {
    static int X = 1;   // Player who always maximises score
    static int O = -1;  // Player who always minimizes score
    static int E = 0;   // Value which denotes an empty space

    public static void main(String[] args) {
        int N = 3;
        int[][] game = new int[N][N];
        Scanner in = new Scanner(System.in);
        int currentPlayer = X;
        
        System.out.println("Play TicTacToe! You are X!");
        
        
        while (true) {
            printGame(game);
            
            if (currentPlayer == X) {
                System.out.println("It is X's turn. Enter row and column (1 indexed) -");
                
                int row = in.nextInt() - 1;
                int col = in.nextInt() - 1;
                
                if (game[row][col] == E) {
                    game[row][col] = X;
                    currentPlayer = O;
                } else {
                    System.out.println("Entered row and column is already played!");
                }
            } else {    // Player O's turn
                System.out.println("It is O's turn.");
                computeAndPlayBestMove(game, O);
                currentPlayer = X;
            }
            
            if (isTerminalState(game)) {
                break;
            }
        }
        
        if (hasPlayerWon(game, X)) {
            System.out.println("Player X has won!");
        } else if (hasPlayerWon(game, O)) {
            System.out.println("Player O has won!");
        } else {
            System.out.println("It is a draw!");
        }

        printGame(game);
    }
    
    // Minimax algorithm entry method. Uses minTurn() and maxTurn() to
    // compute the best move for the current player and plays that move
    public static void computeAndPlayBestMove(int[][] game, int player) {
        Result result;
        
        if (player == X) {
            result = maxTurn(game, 0);
        } else {
            result = minTurn(game, 0);
        }
        
        Move bestMove = result.move;
        
        game[bestMove.i][bestMove.j] = player;
    }
    
    // Method to compute best move for player X (maximising player)
    // Recursively calls minTurn()
    static Result maxTurn(int[][] game, int depth) {
        if (isTerminalState(game)) {
            return new Result(score(game, depth), null);
        }
        
        Result max = new Result(Integer.MIN_VALUE, new Move(-1, -1));
        
        for (int i = 0; i < game.length; ++i) {
            for (int j = 0; j < game[i].length; ++j) {
                if (game[i][j] == E) {
                    game[i][j] = X;
                    
                    // Recurse for other moves
                    Result currentMove = minTurn(game, depth + 1);
                    
                    if (currentMove.score > max.score) {
                        max.score = currentMove.score;
                        max.move.i = i;
                        max.move.j = j;
                    }
                    
                    game[i][j] = E;
                }
            }
        }
        
        return max;
    }
    
    // Method to compute best move for player O (minimising player)
    // Recursively calls maxTurn()
    static Result minTurn(int[][] game, int depth) {
        if (isTerminalState(game)) {
            return new Result(score(game, depth), null);
        }
        
        Result min = new Result(Integer.MAX_VALUE, new Move(-1, -1));
        
        for (int i = 0; i < game.length; ++i) {
            for (int j = 0; j < game[i].length; ++j) {
                if (game[i][j] == E) {
                    game[i][j] = O;
                    
                    // Recurse for other moves
                    Result currentMove = maxTurn(game, depth + 1);
                    
                    if (currentMove.score < min.score) {
                        min.score = currentMove.score;
                        min.move.i = i;
                        min.move.j = j;
                    }
                    
                    game[i][j] = E;
                }
            }
        }
        
        return min;
    }
    
    static boolean isTerminalState(int[][] game) {
        return hasPlayerWon(game, X) || hasPlayerWon(game, O) || hasGameEnded(game);
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
    
    public static int score(int[][] game, int depth) {
        if (hasPlayerWon(game, X)) {
            return 10 - depth;
        } else if (hasPlayerWon(game, O)) {
            return depth - 10;
        }
        
        return 0;
    }
    
    static boolean hasGameEnded(int[][] game) {
        for (int i = 0; i < game.length; ++i) {
            for (int j = 0; j < game[i].length; ++j) {
                if (game[i][j] == E) {
                    return false;
                }
            }
        }
        
        return true;
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
}

class Result
{
    int score;
    Move move;

    public Result(int score, Move move) {
        this.score = score;
        this.move = move;
    }
}

class Move
{
    int i, j;

    public Move(int i, int j) {
        this.i = i;
        this.j = j;
    }
}