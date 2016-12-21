/* ===== ===== =====

Theory of Programming

Solution for Trie Tree problem - http://www.spoj.com/problems/PHONELST/
http://theoryofprogramming.com/2015/08/24/trie-tree-practise-spoj-phonelst/
GitHub - https://github.com/VamsiSangam/theoryofprogramming
Code Contributor - Vamsi Sangam

===== ===== ===== */

#include <cstdio>
#include <cstdlib>
#include <vector>

#define ALPHABETS 10
#define MAX_WORD_SIZE 10

using namespace std;

struct node
{
	struct node * parent;
	struct node * children[ALPHABETS];
	vector<int> occurrences;
};

bool Insert(struct node * trieTree, char text[], int index)
{
	int i = 0, j;
	struct node * temp = trieTree;
	bool result = true;
	
	while (text[i] != '\0') {
		if (temp->occurrences.size() != 0) {
			// A prefix to this word
			// was already inserted
			result = false;
			break;
		}
		
		if (temp->children[text[i] - '0'] == NULL) {
			temp->children[text[i] - '0'] = (struct node *) calloc(1, sizeof(struct node));
			temp->children[text[i] - '0']->parent = temp;
		}
		
		temp = temp->children[text[i] - '0'];
		++i;
	}
	
	temp->occurrences.push_back(index);
	
	for (j = 0; j < ALPHABETS; ++j) {
		if (temp->children[j] != NULL) {
			// The newly inserted word is
			// prefix to another word
			result = false;
			break;
		}
	}
	
	return result;
}

int main()
{
	int t, n, i;
	
	scanf("%d", &t);
	
	while (t--) {		
		scanf("%d", &n);
		
		struct node * trieTree = (struct node *) calloc(1, sizeof(struct node));
		char word[MAX_WORD_SIZE + 1];
		bool result = true;
		
		for (i = 0; i < n; ++i) {
			scanf("%s", word);
			
			if(!Insert(trieTree, word, i + 1)) {
				result = false;
			}
		}
		
		if (result) {
			printf("YES\n");
		} else {
			printf("NO\n");
		}
		
		free(trieTree);
	}
	
	return 0;
}
