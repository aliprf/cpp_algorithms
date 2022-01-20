#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct WordTree
{
    char val;
    int freq;
    WordTree *next;
};


vector<string> prefix(vector<string> &A);
vector<WordTree*> genPrefixTree(vector<string> &A);
void addtoTree(vector<WordTree*> &prefixTrees, string word);
bool contains(WordTree* head, char ch);

int main ()
{   
    vector<string> A = {"zebra", "dog", "duck", "dove"};

    vector<string> B =prefix(A);
    cout << "\n\r";
}

vector<string> prefix(vector<string> &A) 
{
    vector<string> B;

    vector<WordTree*> prefixTree = genPrefixTree(A);

    return B;
}


vector<WordTree*> genPrefixTree(vector<string> &A)
{
    vector<WordTree*> prefixTrees;

    for(int i=0; i< A.size(); i++)
    {
        string word= A[i];
        addtoTree(prefixTrees, word);
    }
}

void addtoTree(vector<WordTree*> &prefixTrees, string word)
{
    // search if we have the prefix before
    int ocIndex=-1;
    for(int i=0; i< prefixTrees.size(); i++)
    {
        if(prefixTrees[i]->val == word[0])
        {
            ocIndex = i;
            break;
        }
    }

    if(ocIndex == -1) // add a new tree
    {
        WordTree *newNode = new WordTree();
        WordTree * newHead = newNode;
        int i=0;
        while(i < word.size())
        {
            newNode->val = word[i++];
            newNode->freq = 1;
            newNode->next = new WordTree();
            newNode = newNode->next;
        }
        prefixTrees.push_back(newHead);
        return;
    }

    //

    int index=0;
    while(contains(head, word[index]))
    {
        head = head->next;

    }
}

bool contains(WordTree* head, char ch)
{
    if(head->val == ch)
        return true;
    return false;

}