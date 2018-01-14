/* ===== ===== =====

 Theory of Programming

 - Iterative Deepening Depth First Search (or) Iterative deepening search
 Website - http://theoryofprogramming.com/2018/01/14/iterative-deepening-depth-first-search-iddfs/
 Github - https://github.com/VamsiSangam/theoryofprogramming

 ===== ===== ===== */

public class IterativeDeepeningDepthFirstSearch {

    public static void main(String[] args) {
        // Creating a dummy N-ary tree
        int n = 3;
        NaryTreeNode root = new NaryTreeNode("A", n);

        root.addChild("B");
        root.getChild(0).addChild("E");
        root.getChild(0).getChild(0).addChild("I");
        root.getChild(0).addChild("F");
        root.getChild(0).getChild(1).addChild("J");
        root.getChild(0).getChild(1).addChild("K");
        root.getChild(0).getChild(1).getChild(1).addChild("O");
        root.getChild(0).getChild(1).getChild(1).addChild("P");
        root.addChild("C");
        root.getChild(1).addChild("G");
        root.getChild(1).getChild(0).addChild("L");
        root.getChild(1).getChild(0).getChild(0).addChild("R");
        root.addChild("D");
        root.getChild(2).addChild("H");
        root.getChild(2).getChild(0).addChild("M");
        root.getChild(2).getChild(0).addChild("N");
        root.getChild(2).getChild(0).getChild(1).addChild("S");

        NaryTreeNode.print(root);

        // Let Node "R" be our goal
        NaryTreeNode goal = root.getChild(1).getChild(0).getChild(0).getChild(0);

        if (IDDFS(root, 3, goal)) {
            System.out.println("Goal node = " + goal.LABEL + " is reachable at a depth of 3");
        } else {
            System.out.println("Goal node = " + goal.LABEL + " is not reachable at a depth of 3");
        }
        
        if (IDDFS(root, 4, goal)) {
            System.out.println("Goal node = " + goal.LABEL + " is reachable at a depth of 4");
        } else {
            System.out.println("Goal node = " + goal.LABEL + " is not reachable at a depth of 4");
        }
    }

    public static boolean IDDFS(NaryTreeNode node, int maxDepth, NaryTreeNode goal) {
        for (int depth = 0; depth <= maxDepth; ++depth) {
            System.out.print("Depth = " + depth + ", DLS Traversal => ");

            if (DLS(node, goal, depth)) {
                System.out.println();
                return true;
            }

            System.out.println();
        }

        return false;
    }

    // Depth limited search method
    public static boolean DLS(NaryTreeNode node, NaryTreeNode goal, int depth) {
        System.out.print(node.LABEL + ", ");

        if (node == goal) {
            return true;
        }
        
        if (depth == 0) {
            return false;
        }

        for (NaryTreeNode adjacentNode : node.getChildren()) {
            if (DLS(adjacentNode, goal, depth - 1)) {
                return true;
            }
        }
        
        return false;
    }

}