#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool exist(vector<vector<char>> &board, string word);
void findWord(vector<vector<char>> &board, vector<vector<int>> &freeBoard, string remainingWord, int i_c, int j_c,
              vector<vector<int>> &andices, vector<vector<vector<int>>> &solutions);
bool is_valid(int i, int j, vector<vector<char>> board, vector<vector<int>> freeBoard, char ch);

int main()
{
    vector<vector<char>> board = {{'A', 'B', 'C', 'E'},
                                  {'S', 'F', 'C', 'S'},
                                  {'A', 'D', 'E', 'E'}};
    // vector<vector<char>> board = {{'b','b','b','a','b','b'},
    //                               {'b','a','b','b','a','a'},
    //                               {'b','a','b','a','a','a'},
    //                               {'a','a','a','a','b','a'},
    //                               {'a','a','b','b','b','a'},
    //                               {'a','a','b','b','a','a'}};
    
    // string word = "abbbbaabbbbb";

    string word = "EECSECBFSAD";//"ABCCED";

    cout << exist(board, word) << "\n\r";
}

bool exist(vector<vector<char>> &board, string word)
{
    vector<vector<int>> freeBoard(board.size(), vector<int>(board[0].size()));

    for (int i = 0; i < board.size(); i++)

        for (int j = 0; j < board[i].size(); j++)
            freeBoard[i][j] = 0;

    vector<vector<vector<int>>> solutions;

    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[i].size(); j++)
        {
            if (board[i][j] == word[0])
            {
                vector<vector<int>> andices;
                andices.push_back({i, j});
                string tmp = word;
                tmp.erase(0, 1);
                findWord(board, freeBoard, tmp, i, j, andices, solutions);
            }
        }
    }

    if (!solutions.empty())
    {
        cout <<"true"<< "\n\r";
        return true;
    }
    cout <<"false"<< "\n\r";
    return false;
}

void findWord(vector<vector<char>> &board, vector<vector<int>> &freeBoard, string remainingWord, int i_c, int j_c, vector<vector<int>> &andices, vector<vector<vector<int>>> &solutions)
{
    if (remainingWord.size() <= 0)
    {
        solutions.push_back(andices);
        return;
    }

    freeBoard[i_c][j_c] = 1;
    if (is_valid(i_c, j_c + 1, board, freeBoard, remainingWord[0]))
    {
        andices.push_back({i_c, j_c + 1});
        string tmp = remainingWord;
        findWord(board, freeBoard, tmp.erase(0, 1), i_c, j_c + 1, andices, solutions);
    }
    if (is_valid(i_c, j_c - 1, board, freeBoard, remainingWord[0]))
    {
        andices.push_back({i_c, j_c - 1});
        string tmp = remainingWord;
        findWord(board, freeBoard, tmp.erase(0, 1), i_c, j_c - 1, andices, solutions);
    }
    if (is_valid(i_c + 1, j_c, board, freeBoard, remainingWord[0]))
    {
        andices.push_back({i_c + 1, j_c});
        string tmp = remainingWord;
        findWord(board, freeBoard, tmp.erase(0, 1), i_c + 1, j_c, andices, solutions);
    }
    if (is_valid(i_c - 1, j_c, board, freeBoard, remainingWord[0]))
    {
        andices.push_back({i_c + 1, j_c});
        string tmp = remainingWord;
        findWord(board, freeBoard, tmp.erase(0, 1), i_c - 1, j_c, andices, solutions);
    }
    else
        freeBoard[i_c][j_c] = 0;
}

bool is_valid(int i, int j, vector<vector<char>> board, vector<vector<int>> freeBoard, char ch)
{
    if (i < board.size() && j < board[i].size() && freeBoard[i][j] == 0 && board[i][j] == ch)
        return true;

    return false;
}