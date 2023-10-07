#include <iostream>
#include <cstddef>
#include <utility>
#include <vector>


void printBoard(const std::vector<std::vector<int>>& board) {
    for (size_t i = 0; i < board.size(); i++) {
        if (i % 3 == 0 && i != 0) {
            std::cout << "- - - - - - - - - - - - - " << std::endl;
        }

        for (size_t j = 0; j < board[0].size(); j++) {
            if (j % 3 == 0 && j != 0) {
                std::cout << " | ";
            }

            if (j == board.size() - 1) {
                std::cout << board[i][j] << std::endl;
            } else {
                std::cout << board[i][j] << " ";
            }
        } 
    }
}

std::pair<int, int> findEmpty(const std::vector<std::vector<int>>& board) {
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[0].size(); j++) {
            if (board[i][j] == 0) {
                return std::make_pair(i, j);
            }
        }
    }

    return std::make_pair(-1, -1);
}

bool isValid(const std::vector<std::vector<int>>& board, const int& num, std::pair<int, int> pos) {
    // Check row
    for (size_t i = 0; i < board.size(); i++) {
        if (board[pos.first][i] == num && pos.second != i) {
            return false;
        }
    }

    // Check column
    for (size_t i = 0; i < board[0].size(); i++) {
        if (board[i][pos.second] == num && pos.first != i) {
            return false;
        }
    }

    // Check box
    int boxStartRow = (pos.first / 3) * 3;
    int boxStartCol = (pos.second / 3) * 3;
    for (size_t i = boxStartRow; i < boxStartRow + 3; i++) {
        for (size_t j = boxStartCol; j < boxStartCol + 3; j++) {
            if (board[i][j] == num && (i != pos.first || j != pos.second)) {
                return false;
            }
        }
    }

    return true;
}

bool solve(std::vector<std::vector<int>>& board) {
    std::pair<int, int> emptyCell = findEmpty(board);

    if (emptyCell.first == -1 || emptyCell.second == -1) {
        return true;
    }

    for (int num = 1 ; num <= board.size(); num++) {
        if (isValid(board, num, emptyCell)) {
            board[emptyCell.first][emptyCell.second] = num;
            if (solve(board)) {
                return true;
            }
            board[emptyCell.first][emptyCell.second] = 0;
        }
    }
    return false;
}