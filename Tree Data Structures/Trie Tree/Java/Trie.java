/* ===== ===== =====

Theory of Programming
Trie Tree Implementation
http://theoryofprogramming.com/2015/01/16/trie-tree-implementation/
GitHub - https://github.com/VamsiSangam/theoryofprogramming
Code Contributor - Saurabh Rane (github.com/ranesr)

===== ===== ===== */

import java.util.HashMap;

public class Trie {

	// root node
	private TrieNode root;
	
	// default case
	public Trie() {
		root = new TrieNode();
		root.setParent(new TrieNode());
	}
	
	// inserting a word	
	public void insert(String word) {
		HashMap<Character, TrieNode> children = root.getChildren();
		
		// parent node
		TrieNode p = root;
		
		for(int i = 0; i < word.length(); i++) {			
			char c = word.charAt(i);
			
			TrieNode t = null;
			
			if(children.containsKey(c)) {
				
				// character already found in children
				t = children.get(c);
				
			} else {
				
				// adding new character to children				
				t = new TrieNode(c);
				children.put(c, t);
				t.setParent(p);
			}
			
			p = t;
			children = t.getChildren();
			
			// last character from word
			if(i == word.length()-1) {
				t.setLeaf(true);
			}
		}
	}
	
	public boolean delete(String word) {
		TrieNode t = searchNode(word);
		
		// word is present if t is not null & is leaf as t is a trie node for last character from word
		if(t != null && t.isLeaf()) {
			
			TrieNode p = t.getParent();
			char c = t.getCharacter();

			// removing children of parent if only one child is present
			while(p.getChildren().size() == 1) {
				p.resetChildren();
				t = p;
				c = t.getCharacter();
				p = t.getParent();
			}
			
			// removing the remaining character
			char delete = c;
			p.getChildren().entrySet().removeIf(e -> e.getKey().equals(delete));

			return true;
		}
		return false;
	}
	
	public boolean search(String word) {
		TrieNode t = searchNode(word);
		
		// word is present if t is not null & is leaf as t is a trie node for last character from word
		if(t != null && t.isLeaf()) {
			return true;
		}
		
		return false;
	}
	
	public boolean startsWith(String prefix) {
		HashMap<Character, TrieNode> children = root.getChildren();
		
		TrieNode t = null;
		
		for(int i = 0; i < prefix.length(); i++) {
			char c = prefix.charAt(i);
			if(children.containsKey(c)) {
			
				t = children.get(c);
				children = t.getChildren();

			} else {
				// character mismatch
				return false;
			}
		}

		// reached the end of the prefix word
		return true;
	}
	
	// helper method for searching & startsWith functions
	public TrieNode searchNode(String word) {
		HashMap<Character, TrieNode> children = root.getChildren();
		
		TrieNode t = null;
		
		for(int i = 0; i < word.length(); i++) {
			char c = word.charAt(i);

			if(children.containsKey(c)) {

				t = children.get(c);
				children = t.getChildren();
				
			} else {
				// character mismatch
				return null;				
			}
		}
		
		// reached the end of the search word
		return t;
	}
}

class TrieNode {
	
	private char character;
	private TrieNode parent;
	private HashMap<Character, TrieNode> children = new HashMap<Character, TrieNode>();
	private boolean leaf;
	
	// default case
	public TrieNode() {}
	
	// constructor accepting the character
	public TrieNode(char character) {
		this.character = character;
	}
	
	public void setCharacter(char character) {
		this.character = character;
	}
	
	public char getCharacter() {
		return character;
	}
	
	public void setParent(TrieNode parent) {
		this.parent = parent;
	}
	
	public TrieNode getParent() {
		return parent;
	}
	
	public HashMap<Character, TrieNode> getChildren() {
		return children;
	}
	
	public void resetChildren() {
		children = new HashMap<Character, TrieNode>();
	}
	
	public boolean isLeaf() {
		return leaf;
	}
	
	public void setLeaf(boolean leaf) {
		this.leaf = leaf;
	}
}

class Test {
	public static void main(String[] args) {
		Trie trie = new Trie();
		
		trie.insert("their");
		
		System.out.println(trie.delete("their"));					// true

		trie.insert("there");
		trie.insert("this");
		trie.insert("that");
		trie.insert("does");
		trie.insert("did");
		trie.insert("the");
		System.out.println(trie.search("there"));					// true
		System.out.println(trie.search("therein"));					// false
		System.out.println(trie.startsWith("th"));					// true
		System.out.println(trie.startsWith("fab"));					// false
		System.out.println(trie.delete("does"));					// true
		System.out.println(trie.startsWith("does"));				// false
		System.out.println(trie.startsWith("o"));					// false

		System.out.println(trie.search("the"));						// true
		System.out.println(trie.startsWith("the"));					// true
	}
}