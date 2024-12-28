#include <iostream>
#include <vector>
#include <cmath>
bool isSafe(const std::vector<int>& queens, int row, int col) {
    for (int i = 0; i < row; ++i) {
        int placedCol = queens[i];
        if (placedCol == col || std::abs(placedCol - col) == std::abs(i - row)) {
            return false;
        }
    }
    return true;
}
void solveNQueens(int n, int row, std::vector<int>& queens, int& solutions) {
    if (row == n) {
        ++solutions;
        return;
    }

    for (int col = 0; col < n; ++col) {
        if (isSafe(queens, row, col)) {
            queens[row] = col;
            solveNQueens(n, row + 1, queens, solutions);
            queens[row] = -1;
        }
    }
}

int totalNQueens(int n) {
    int solutions = 0;
    std::vector<int> queens(n, -1);
    solveNQueens(n, 0, queens, solutions);
    return solutions;
}

int main() {
    int n;
    std::cout << "Enter the value of n: ";
    std::cin >> n;

    int result = totalNQueens(n);
    std::cout << "The number of distinct solutions to the " << n << "-Queens puzzle is: " << result << std::endl;

    return 0;
}
