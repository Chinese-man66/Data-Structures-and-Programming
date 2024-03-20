#include <iostream>
#include <vector>

using namespace std;

vector<vector<string>> solveNQueens(int n);
void solveNQueens(vector<vector<string>>& result, vector<string>& board, int row, int N);
bool isSafe(vector<string>& board, int row, int col, int N);
void printResult(const vector<vector<string>>& result);
// 求解N皇后问题的入口函数
vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> result;
    vector<string> board(n, string(n, '.')); // 初始化棋盘

    solveNQueens(result, board, 0, n); // 从第0行开始递归求解

    return result;
}

// 打印结果
void printResult(const vector<vector<string>>& result) {
    for (const auto& board : result) {
        for (const auto& row : board) {
            cout << row << endl;
        }
        cout << endl;
    }
}


// 回溯法求解N皇后问题
void solveNQueens(vector<vector<string>>& result, vector<string>& board, int row, int N) {
    // 如果当前行等于N，表示所有皇后都已放置完毕
    if (row == N) {
        result.push_back(board);
        return;
    }

    // 尝试在当前行的每个位置放置皇后
    for (int col = 0; col < N; col++) {
        if (isSafe(board, row, col, N)) {
            board[row][col] = 'Q'; // 放置皇后
            solveNQueens(result, board, row + 1, N); // 递归处理下一行
            board[row][col] = '.'; // 回溯，清除该位置的皇后
        }
    }
}


// 检查当前位置是否安全，即是否能够放置皇后
bool isSafe(vector<string>& board, int row, int col, int N) {
    // 检查列是否安全
    for (int i = 0; i < row; i++) {
        if (board[i][col] == 'Q')
            return false;
    }

    // 检查左上方斜线是否安全
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 'Q')
            return false;
    }

    // 检查右上方斜线是否安全
    for (int i = row, j = col; i >= 0 && j < N; i--, j++) {
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
    cout << "N皇后的所有解：" << endl;
    printResult(result);
    return 0;
}
