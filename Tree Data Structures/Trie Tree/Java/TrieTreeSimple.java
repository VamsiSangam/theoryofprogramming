/* ===== ===== =====

Theory of Programming
Trie Tree simplest implementation
http://theoryofprogramming.com/2015/01/16/trie-tree-implementation/
GitHub - https://github.com/VamsiSangam/theoryofprogramming
Code Contributor - Vamsi Sangam

===== ===== ===== */

// Our Trie Tree's node definition
class TrieNode {
    // Avoiding encapsulation for simplicity
    boolean isWordEnding;
    final TrieNode[] children = new TrieNode[26];
}

public class TrieTreeSimple {
    
    public static void main(String[] args) {
        TrieNode root = new TrieNode();
        
        insertWord(root, "ask");
        insertWord(root, "a");
        insertWord(root, "ash");
        insertWord(root, "bow");
        insertWord(root, "be");
        insertWord(root, "been");
        insertWord(root, "bees");
        
        System.out.println("Is \"a\" present in the Trie Tree? - " + queryWord(root, "a"));
        System.out.println("Is \"ash\" present in the Trie Tree? - " + queryWord(root, "ash"));
        System.out.println("Is \"as\" present in the Trie Tree? - " + queryWord(root, "as"));
        System.out.println("Is \"bee\" present in the Trie Tree? - " + queryWord(root, "bee"));
        System.out.println("Is \"been\" present in the Trie Tree? - " + queryWord(root, "been"));
        
        insertWord(root, "bee");
        
        System.out.println("Is \"bee\" present in the Trie Tree? - " + queryWord(root, "bee"));
    }
    
    public static void insertWord(TrieNode root, String word) {
        TrieNode trav = root;
        
        // Traverse input string
        for (char alphabet : word.toCharArray()) {
            if (trav.children[alphabet - 'a'] == null) {
                // There is no TrieNode corresponding
                // to this alphabet, so create it
                trav.children[alphabet - 'a'] = new TrieNode();
            }
            
            trav = trav.children[alphabet - 'a'];
        }
        
        trav.isWordEnding = true;
    }
    
    public static boolean queryWord(TrieNode root, String word) {
        TrieNode trav = root;
        
        // Traverse input string
        for (char alphabet : word.toCharArray()) {
            if (trav.children[alphabet - 'a'] != null) {
                trav = trav.children[alphabet - 'a'];
            } else {
                return false;
            }
        }
        
        return trav != null && trav.isWordEnding;
    }
}