#include <iostream>
#include <vector>
void combineHelper(int n, int k, int start, std::vector<int>& current, std::vector<std::vector<int>>& result) {
    if (current.size() == k) {
        result.push_back(current);
        return;
    }

    for (int i = start; i <= n; ++i) {
        current.push_back(i);
        combineHelper(n, k, i + 1, current, result);
        current.pop_back(); // Backtrack
    }
}
std::vector<std::vector<int>> combine(int n, int k) {
    std::vector<std::vector<int>> result;
    std::vector<int> current;
    combineHelper(n, k, 1, current, result);
    return result;
}

int main() {
    int n = 4, k = 2;
    std::cout << "Combinations of " << k << " numbers chosen from [1, " << n << "]:\n";

    std::vector<std::vector<int>> result = combine(n, k);

    for (const auto& combination : result) {
        std::cout << "[";
        for (size_t i = 0; i < combination.size(); ++i) {
            std::cout << combination[i];
            if (i < combination.size() - 1) std::cout << ", ";
        }
        std::cout << "]\n";
    }

    return 0;
}
