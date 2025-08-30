#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Helper to check a subgrid (sr to er, sc to ec)
    bool traverse(vector<vector<char>>& board, int sr, int er, int sc, int ec) {
        set<char> st;
        for (int i = sr; i < er; i++) {
            for (int j = sc; j < ec; j++) {
                if (board[i][j] == '.')
                    continue;
                if (st.find(board[i][j]) != st.end()) 
                    return false;
                st.insert(board[i][j]);
            }
        }
        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        // Check rows
        for (int i = 0; i < 9; i++) {
            set<char> st;
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.')
                    continue;
                if (st.find(board[i][j]) != st.end())
                    return false;
                st.insert(board[i][j]);
            }
        }

        // Check columns
        for (int j = 0; j < 9; j++) {
            set<char> st;
            for (int i = 0; i < 9; i++) {
                if (board[i][j] == '.')
                    continue;
                if (st.find(board[i][j]) != st.end())
                    return false;
                st.insert(board[i][j]);
            }
        }

        // Check 3x3 sub-boxes
        for (int i = 0; i < 9; i += 3) {
            for (int j = 0; j < 9; j += 3) {
                if (!traverse(board, i, i + 3, j, j + 3))
                    return false;
            }
        }

        return true;
    }
};
