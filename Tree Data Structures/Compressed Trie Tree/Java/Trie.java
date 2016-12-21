/* ===== ===== =====

Theory of Programming

Compressed Trie Tree
http://theoryofprogramming.com/2016/11/15/compressed-trie-tree/
GitHub - https://github.com/VamsiSangam/theoryofprogramming
Code Contributor - Vamsi Sangam

===== ===== ===== */
 
class Trie {
    private final Node root = new Node(false);
    private final char CASE;    // 'a' for lower, 'A' for upper
 
    public Trie() {
        CASE = 'a';     // default case
    }
 
    public Trie(char CASE) {
        this.CASE = CASE;   // constructor accepting the starting symbol
    }
 
    public void insert(String word) {
        Node trav = root;
        int i = 0;
 
        while (i < word.length() && trav.edgeLabel[word.charAt(i) - CASE] != null) {
            int index = word.charAt(i) - CASE, j = 0;
            StringBuilder label = trav.edgeLabel[index];
 
            while (j < label.length() && i < word.length() && label.charAt(j) == word.charAt(i)) {
                ++i;
                ++j;
            }
 
            if (j == label.length()) {
                trav = trav.children[index];
            } else {
                if (i == word.length()) {   // inserting a prefix of exisiting word
                    Node existingChild = trav.children[index];
                    Node newChild = new Node(true);
                    StringBuilder remainingLabel = strCopy(label, j);
                     
                    label.setLength(j);     // making "faceboook" as "face"
                    trav.children[index] = newChild;    // new node for "face"
                    newChild.children[remainingLabel.charAt(0) - CASE] = existingChild;
                    newChild.edgeLabel[remainingLabel.charAt(0) - CASE] = remainingLabel;
                } else {     // inserting word which has a partial match with existing word
                    StringBuilder remainingLabel = strCopy(label, j);
                    Node newChild = new Node(false);
                    StringBuilder remainingWord = strCopy(word, i);
                    Node temp = trav.children[index];
                     
                    label.setLength(j);
                    trav.children[index] = newChild;
                    newChild.edgeLabel[remainingLabel.charAt(0) - CASE] = remainingLabel;
                    newChild.children[remainingLabel.charAt(0) - CASE] = temp;
                    newChild.edgeLabel[remainingWord.charAt(0) - CASE] = remainingWord;
                    newChild.children[remainingWord.charAt(0) - CASE] = new Node(true);
                }
 
                return;
            }
        }
 
        if (i < word.length()) {    // inserting new node for new word
            trav.edgeLabel[word.charAt(i) - CASE] = strCopy(word, i);
            trav.children[word.charAt(i) - CASE] = new Node(true);
        } else {    // inserting "there" when "therein" and "thereafter" are existing
            trav.isEnd = true;
        }
    }
     
    // Creates a new String from an existing
    // string starting from the given index
    private StringBuilder strCopy(CharSequence str, int index) {
        StringBuilder result = new StringBuilder(100);
         
        while (index != str.length()) {
            result.append(str.charAt(index++));
        }
         
        return result;
    }
 
    public void print() {
        printUtil(root, new StringBuilder());
    }
 
    private void printUtil(Node node, StringBuilder str) {
        if (node.isEnd) {
            System.out.println(str);
        }
 
        for (int i = 0; i < node.edgeLabel.length; ++i) {
            if (node.edgeLabel[i] != null) {
                int length = str.length();
 
                str = str.append(node.edgeLabel[i]);
                printUtil(node.children[i], str);
                str = str.delete(length, str.length());
            }
        }
    }
 
    public boolean search(String word) {
        int i = 0;
        Node trav = root;
 
        while (i < word.length() && trav.edgeLabel[word.charAt(i) - CASE] != null) {
            int index = word.charAt(i) - CASE;
            StringBuilder label = trav.edgeLabel[index];
            int j = 0;
 
            while (i < word.length() && j < label.length()) {
                if (word.charAt(i) != label.charAt(j)) {
                    return false;   // character mismatch
                }
                 
                ++i;
                ++j;
            }
 
            if (j == label.length() && i <= word.length()) {
                trav = trav.children[index];    // traverse further
            } else {
                // edge label is larger than target word
                // searching for "face" when tree has "facebook"
                return false;
            }
        }
         
        // target word fully traversed and current node is a word ending
        return i == word.length() && trav.isEnd; 
    }
 
    public boolean startsWith(String prefix) {
        int i = 0;
        Node trav = root;
 
        while (i < prefix.length() && trav.edgeLabel[prefix.charAt(i) - CASE] != null) {
            int index = prefix.charAt(i) - CASE;
            StringBuilder label = trav.edgeLabel[index];
            int j = 0;
 
            while (i < prefix.length() && j < label.length()) {
                if (prefix.charAt(i) != label.charAt(j)) {
                    return false;   // character mismatch
                }
                 
                ++i;
                ++j;
            }
 
            if (j == label.length() && i <= prefix.length()) {
                trav = trav.children[index];    // traverse further
            } else {
                // edge label is larger than target word, which is fine
                return true;
            }
        }
 
        return i == prefix.length();
    }
}
 
class Node {
    private final static int SYMBOLS = 26;
    Node[] children = new Node[SYMBOLS];
    StringBuilder[] edgeLabel = new StringBuilder[SYMBOLS];
    boolean isEnd;
 
    public Node(boolean isEnd) {
        this.isEnd = isEnd;
    }
}
 
class Test {
    public static void main(String[] args) {
        Trie trie = new Trie();
         
        trie.insert("facebook");
        trie.insert("face");
        trie.insert("this");
        trie.insert("there");
        trie.insert("then");
         
        trie.print();
         
        System.out.println(trie.search("there"));	// true
        System.out.println(trie.search("therein"));	// false
        System.out.println(trie.startsWith("th"));	// true
        System.out.println(trie.startsWith("fab"));	// false
    }
}