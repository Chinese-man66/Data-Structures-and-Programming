#include <iostream>
#include <vector>

using namespace std;

class NQueensSolver
{
public:
    NQueensSolver(int n) : N(n) {}
    
    vector<vector<string>> solve() 
    {
        vector<vector<string>> result;
        vector<string> board(N, string(N, '.'));
        solveNQueens(result, board, 0);
        return result;
    }

    void printResult(const vector<vector<string>>& result) 
    {
        for (const auto& board : result) 
        {
            for (const auto& row : board) 
                cout << row << endl;
            cout << endl;
        }
    }

private:
    int N;

    void solveNQueens(vector<vector<string>>& result, vector<string>& board, int row) 
    {
        if (row == N) {
            result.push_back(board);
            return;
        }

        for (int col = 0; col < N; col++) 
        {
            if (isSafe(board, row, col)) 
            {
                board[row][col] = 'Q';
                solveNQueens(result, board, row + 1);
                board[row][col] = '.';
            }
        }
    }

    bool isSafe(const vector<string>& board, int row, int col) 
    {
        for (int i = 0; i < row; i++) 
        {
            if (board[i][col] == 'Q')
                return false;
        }

        for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) 
        {
            if (board[i][j] == 'Q')
                return false;
        }

        for (int i = row, j = col; i >= 0 && j < N; i--, j++) 
        {
            if (board[i][j] == 'Q')
                return false;
        }

        return true;
    }
};

int main() {
    int n;
    cout << "申顺琦2125120058 " << endl;
    cout << "请输入皇后的数量：";
    cin >> n;
    if(n <= 3 && n != 1)
    {
        cout << "无法解决 " << n << " 皇后问题" << endl;
        return 0;
    }
    
    NQueensSolver solver(n);
    vector<vector<string>> result = solver.solve();
    cout << "N皇后的所有解:" << endl;
    solver.printResult(result);
    return 0;
}