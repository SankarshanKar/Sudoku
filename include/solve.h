#pragma once

#include <utility>
#include <vector>


void printBoard(const std::vector<std::vector<int>>& board);
std::pair<int, int> findEmpty(const std::vector<std::vector<int>>& board);
bool isValid(const std::vector<std::vector<int>>& board, const int& num, std::pair<int, int> pos);
bool solve(std::vector<std::vector<int>>& board);