#include <iostream>
#include <vector>

using namespace std;

vector<vector<string>> solveNQueens(int n);
void solveNQueens(vector<vector<string>>& result, vector<string>& board, int row, int N);
bool isSafe(vector<string>& board, int row, int col, int N);
void printResult(const vector<vector<string>>& result);

vector<vector<string>> solveNQueens(int n) 
{
    vector<vector<string>> result;
    vector<string> board(n, string(n, '.')); 
    solveNQueens(result, board, 0, n);

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

void solveNQueens(vector<vector<string>>& result, vector<string>& board, int row, int N) 
{
    if (row == N) {
        result.push_back(board);
        return;
    }

    for (int col = 0; col < N; col++) 
    {
        if (isSafe(board, row, col, N)) 
        {
            board[row][col] = 'Q'; // 放置皇后
            solveNQueens(result, board, row + 1, N); // 递归处理下一行
            board[row][col] = '.'; // 回溯，清除该位置的皇后
        }
    }
}



bool isSafe(vector<string>& board, int row, int col, int N) 
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

int main() {
    int n;
    cout << "请输入皇后的数量：";
    cin >> n;
    if(n <= 3 && n != 1)
    {
        cout << "无法解决"<< n << "皇后问题" << endl;
        return 0;
    }
        
    vector<vector<string>> result = solveNQueens(n);
    cout << "N皇后的所有解:" << endl;
    printResult(result);
    return 0;
}
