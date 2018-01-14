/* ===== ===== =====

Theory of Programming

- N-ary tree of k-way tree data structure
Website - http://theoryofprogramming.com/2018/01/14/n-ary-tree-k-way-tree-data-structure/
Github - https://github.com/VamsiSangam/theoryofprogramming

===== ===== ===== */

import java.util.ArrayList;

public class NaryTreeNode {
    final String LABEL;
    final int N;
    private final ArrayList<NaryTreeNode> children;
    
    public NaryTreeNode(String LABEL, int n) {
        this.LABEL = LABEL;
        this.N = n;
        children = new ArrayList<>(n);
    }
    
    private boolean addChild(NaryTreeNode node) {
        if (children.size() < N) {
            return children.add(node);
        }
        
        return false;
    }
    
    public boolean addChild(String label) {
        return addChild(new NaryTreeNode(label, N));
    }
    
    public ArrayList<NaryTreeNode> getChildren() {
        return new ArrayList<>(children);
    }
    
    public NaryTreeNode getChild(int index) {
        if (index < children.size()) {
            return children.get(index);
        }
        
        return null;
    }
    
    public static void print(NaryTreeNode root) {
        printUtil(root, 0);
    }
    
    private static void printUtil(NaryTreeNode node, int depth) {
        for (int i = 0; i < depth; ++i) {
            System.out.print("   ");
        }
        
        System.out.println(node.LABEL);
        
        for (NaryTreeNode child : node.getChildren()) {
            printUtil(child, depth + 1);
        }
    }
}

class TestNaryTree {
    public static void main(String[] args) {
        int n = 3;
        NaryTreeNode root = new NaryTreeNode("Matter", n);
        
        root.addChild("Pure");
            root.getChild(0).addChild("Elements");
                root.getChild(0).getChild(0).addChild("Metals");
                root.getChild(0).getChild(0).addChild("Metalloids");
                root.getChild(0).getChild(0).addChild("Non-metals");
            root.getChild(0).addChild("Compounds");
                root.getChild(0).getChild(1).addChild("Water");
                root.getChild(0).getChild(1).addChild("Carbon dioxide");
                root.getChild(0).getChild(1).addChild("Salt");
                root.getChild(0).getChild(1).addChild("Camphor");  // won't add
        root.addChild("Mixture");
            root.getChild(1).addChild("Homogeneous");
                root.getChild(1).getChild(0).addChild("Air");
                root.getChild(1).getChild(0).addChild("Vinegar");
            root.getChild(1).addChild("Heterogeneous");
                root.getChild(1).getChild(1).addChild("Colloids");
                root.getChild(1).getChild(1).addChild("Suspensions");
        
        NaryTreeNode.print(root);
    }
}