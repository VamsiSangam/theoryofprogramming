/* ===== ===== =====

Theory of Programming

Solving Maze using Backtracking 
GitHub - https://github.com/VamsiSangam/theoryofprogramming
Code Contributor - Vamsi Sangam

===== ===== ===== */

import java.util.Scanner;

class MazeSolver {
    
    // Used to print the maze's solution path in green
    public static final String ANSI_RESET = "\u001B[0m";
    public static final String ANSI_GREEN = "\u001B[32m";
    public static final String PATH_COLOR = ANSI_GREEN;

    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        System.out.println("Enter number of rows and cols -");
        int rows = s.nextInt();
        int cols = s.nextInt();
        int[][] maze = new int[rows][cols];

        System.out.println("Enter " + (rows * cols) + " integers which indicate maze structure -");
        for (int i = 0; i < maze.length; ++i) {
            for (int j = 0; j < maze[i].length; ++j) {
                maze[i][j] = s.nextInt();
            }
        }

        System.out.println("Input Maze -");
        printMaze(maze);
        
        solveMazeUsingBacktracking(maze, 0, 0);
        
        System.out.println("\nSolved Maze -");
        printMaze(maze);
    }

    /* solveMazeUsingBacktracking() - Solves the input maze using backtracking. Takes i, j as the starting
     * point, and assumes the bottom-right corner cell is the finish point. Maze input is a 2-dimensional
     * array of integers. Where each integer has information on which direction can we move from maze[i][j].
     * 
     * If -
     * - maze[i][j]'s 1st bit is set, it means we can move UP from maze[i][j] to maze[i - 1][j]
     * - maze[i][j]'s 2nd bit is set, it means we can move DOWN from maze[i][j] to maze[i + 1][j]
     * - maze[i][j]'s 3rd bit is set, it means we can move LEFT from maze[i][j] to maze[i][j - 1]
     * - maze[i][j]'s 4th bit is set, it means we can move RIGHT from maze[i][j] to maze[i][j + 1]
     * - maze[i][j]'s 5th bit is set, it means the current cell is a part of the solution
     *
     * Note - Assumes that maze directions are bidirectional. Which means if 1st bit is set in maze[i][j],
     * then, 2nd bit has to be set in maze[i - 1][j] too. Similarly for all directions.
     *
     * Sample maze (empty) -
     *      +---+---+---+
     *      |       |   |
     *      +---+   +   +
     *      |   |       |
     *      +   +---+   +
     *      |           |
     *      +---+---+---+
     * 
     * Its maze array would be - {
     *                               { 1, 6, 4  },
     *                               { 4, 9, 14 },
     *                               { 9, 3, 10 }
     *                           }
     */
    public static boolean solveMazeUsingBacktracking(int[][] maze, int i, int j) {
        // This constraint is our exit condition for backtracking
        if (i == maze.length - 1 && j == maze[0].length - 1) {
            // We reached the right-bottom corner cell. We're done!
            maze[i][j] |= 16; // Set the 5th bit
            return true; // Return true denoting that we reached the goal
        }

        maze[i][j] |= 16; // Set the 5th bit to mark this could be the solution path
        // printMaze(maze); // uncomment this line to see how backtracking explores the maze

        // Explore each option - up, down, left, right
        // Up
        if ((maze[i][j] & 1) == 1 && (maze[i - 1][j] & 16) == 0) {
            // We can move up, and the cell up is not in the current path
            if (solveMazeUsingBacktracking(maze, i - 1, j)) {
                // If solveMazeUsingBacktracking() returned true, it means that the
                // goal was reached, so we don't have to explore the other options
                return true;
            }
        }

        // Down
        if ((maze[i][j] & 2) == 2 && (maze[i + 1][j] & 16) == 0) {
            // We can move down, and the cell to the bottom is not in the current path
            if (solveMazeUsingBacktracking(maze, i + 1, j)) {
                return true;
            }
        }

        // Left
        if ((maze[i][j] & 4) == 4 && (maze[i][j - 1] & 16) == 0) {
            // We can move down, and the cell to the bottom is not in the current path
            if (solveMazeUsingBacktracking(maze, i, j - 1)) {
                return true;
            }
        }

        // Right
        if ((maze[i][j] & 8) == 8 && (maze[i][j + 1] & 16) == 0) {
            // We can move down, and the cell to the bottom is not in the current path
            if (solveMazeUsingBacktracking(maze, i, j + 1)) {
                return true;
            }
        }

        maze[i][j] &= (~16); // Unset the 5th bit, as we explored all options but failed to reach goal
        return false;
    }
    
    // printMaze() - Utility function to print the maze in a readable manner
    public static void printMaze(int[][] maze) {
        int rows = maze.length;
        int cols = maze[0].length;

        System.out.println(); // for readability
        // Printing inner contents of maze row-by-row
        for (int i = 0; i < rows; ++i) {
            // Priting upper walls if needed
            for (int j = 0; j < cols; ++j) {
                System.out.print("+");

                // 1st bit corresponds to Up
                if ((maze[i][j] & 1) == 0) {
                    System.out.print("---");
                } else {
                    System.out.print("   ");
                }
            }
            System.out.println("+"); // Printing the right most +

            // Priting left walls if needed
            for (int j = 0; j < cols; ++j) {
                // 2nd bit corresponds to left
                if ((maze[i][j] & 4) == 0) {
                    System.out.print("| ");
                } else {
                    System.out.print("  ");
                }

                // 5th bit corresponds to solution path
                if ((maze[i][j] & 16) == 16) {
                    System.out.print(PATH_COLOR + "* " + ANSI_RESET);
                } else {
                    System.out.print("  ");
                }
            }
            System.out.println("|"); // Printing the right most wall
        }

        // Printing the bottom-most boundary row
        for (int j = 0; j < cols; ++j) {
            System.out.print("+");
            System.out.print("---");
        }
        System.out.println("+"); // Printing the right most corner +
    }
    
}
