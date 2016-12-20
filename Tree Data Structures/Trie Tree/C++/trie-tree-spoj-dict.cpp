/* ===== ===== =====

Theory of Programming

Solution for Trie Tree problem - http://www.spoj.com/problems/DICT/
http://theoryofprogramming.com/2015/09/01/trie-tree-practise-spoj-dict/
Code Contributor - Vamsi Sangam

===== ===== ===== */

#include <cstdio>
#include <cstdlib>
#include <vector>
 
#define ALPHABETS 26
#define CASE 'a'
#define MAX_WORD_SIZE 20
 
using namespace std;
 
struct Node
{
    struct Node * children[ALPHABETS];
    bool wordEnding;
};
 
void insert(struct Node * trieTree, char * word)
{
    struct Node * temp = trieTree;
 
    while (*word != '\0') {
        if (temp->children[*word - CASE] == NULL) {
            temp->children[*word - CASE] = (struct Node *) calloc(1, sizeof(struct Node));
        }
 
        temp = temp->children[*word - CASE];
        ++word;
    }
 
    temp->wordEnding = true;
}
 
struct Node * searchWord(struct Node * treeNode, char * word)
{
    while (*word != '\0') {		// while there are alphabets to process
        if (treeNode->children[*word - CASE] != NULL) {
        	// there is an edge corresponding to the alphabet
            treeNode = treeNode->children[*word - CASE];
            ++word;
        } else {
        	// there is no edge corresponding to the alphabet
            break;
        }
    }
 
    if (*word == '\0') {
    	// the word was completely processed
        return treeNode;
    } else {
    	// word is not there in trie tree
        return NULL;
    }
}
 
void lexicographPrint(struct Node * trieTree, vector<char> word, char * prefix)
{
    int i;
    bool noChild = true;
 
	if (trieTree->wordEnding && word.size() != 0) {
        vector<char>::iterator itr = word.begin();
		
		printf("%s", prefix);	//	print the prefix
        
		while (itr != word.end()) {
			// print the rest of the word
            printf("%c", *itr);
            ++itr;
        }
        
        printf("\n");
    } 
 
    for (i = 0; i < ALPHABETS; ++i) {
        if (trieTree->children[i] != NULL) {
            noChild = false;
            word.push_back(CASE + i);
            lexicographPrint(trieTree->children[i], word, prefix);
            word.pop_back();
        }
    }
 
    word.pop_back();
}
 
int main()
{
    int n, k;
    char word[MAX_WORD_SIZE];
    struct Node * trieTree = (struct Node *) calloc(1, sizeof(struct Node));
    
    scanf("%d", &n);
    
    // Insert all the words into trie tree
    while (n--) {
    	scanf("%s", word);
    	insert(trieTree, word);
	}
	
	scanf("%d", &k);
	
	for (int i = 1; i <= k; ++i) {
		scanf("%s", word);
		
		struct Node * temp = searchWord(trieTree, word);
		
		printf("Case #%d:\n", i);
		
		if (temp != NULL) {
			// Prefix word was there in the trie tree
			bool childrenThere = false;
			
			// check if there are any children to the node
			for (int j = 0; j < ALPHABETS; ++j) {
				if (temp->children[j] != NULL) {
					childrenThere = true;
					break;
				}
			}
			
			if (childrenThere) {
				// Yes, there are children, print them
				// in lexicographical order
				vector<char> printUtil;
				lexicographPrint(temp, printUtil, word);
			} else {
				// There are no children, so there's
				//  no long enough word in trie tree to
				// which 'word' is the prefix-words
				printf("No match.\n");
			}
		} else {
			// Prefix word was not there in the trie tree
			printf("No match.\n");
		}
	}
    
    return 0;
}
