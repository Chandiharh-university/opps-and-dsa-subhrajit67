#include <iostream>
#include <vector>

void printCombination(const std::vector<int>& combination) {
    for (int num : combination) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}
void findCombinations(int targetSum, int start, std::vector<int>& combination) {
    if (targetSum == 0) {
        printCombination(combination);
        return;
    }

    for (int i = start; i <= targetSum; ++i) {
        combination.push_back(i);
        findCombinations(targetSum - i, i, combination);
        combination.pop_back();
    }
}

int main() {
    int sum;
    std::cout << "Enter the target sum: ";
    std::cin >> sum;

    std::vector<int> combination;
    std::cout << "Combinations that add up to " << sum << ":\n";
    findCombinations(sum, 1, combination);

    return 0;
}
