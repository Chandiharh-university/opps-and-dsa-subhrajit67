#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>
bool isOneLetterDifference(const std::string& word1, const std::string& word2) {
    if (word1.length() != word2.length()) return false;
    int diffCount = 0;
    for (size_t i = 0; i < word1.length(); ++i) {
        if (word1[i] != word2[i]) {
            ++diffCount;
            if (diffCount > 1) return false;
        }
    }
    return diffCount == 1;
}
std::vector<std::vector<std::string>> findLadders(
    const std::string& beginWord,
    const std::string& endWord,
    const std::vector<std::string>& wordList) {

    std::unordered_set<std::string> wordSet(wordList.begin(), wordList.end());
    if (wordSet.find(endWord) == wordSet.end()) return {};

    std::unordered_map<std::string, std::vector<std::string>> adjacencyList;
    std::unordered_map<std::string, int> distances;
    std::queue<std::string> q;
    q.push(beginWord);
    distances[beginWord] = 0;

    while (!q.empty()) {
        std::string currentWord = q.front();
        q.pop();
        for (size_t i = 0; i < currentWord.length(); ++i) {
            std::string tempWord = currentWord;
            for (char c = 'a'; c <= 'z'; ++c) {
                tempWord[i] = c;
                if (wordSet.find(tempWord) != wordSet.end() && tempWord != currentWord) {
                    if (distances.find(tempWord) == distances.end()) {
                        distances[tempWord] = distances[currentWord] + 1;
                        q.push(tempWord);
                    }
                    if (distances[tempWord] == distances[currentWord] + 1) {
                        adjacencyList[currentWord].push_back(tempWord);
                    }
                }
            }
        }
    }
    std::vector<std::vector<std::string>> result;
    std::vector<std::string> path;

    std::function<void(const std::string&)> dfs = [&](const std::string& word) {
        path.push_back(word);
        if (word == endWord) {
            result.push_back(path);
        } else {
            for (const std::string& neighbor : adjacencyList[word]) {
                dfs(neighbor);
            }
        }
        path.pop_back();
    };

    if (distances.find(endWord) != distances.end()) {
        dfs(beginWord);
    }

    return result;
}

int main() {
    std::string beginWord, endWord;
    int wordCount;

    std::cout << "Enter the begin word: ";
    std::cin >> beginWord;

    std::cout << "Enter the end word: ";
    std::cin >> endWord;

    std::cout << "Enter the number of words in the word list: ";
    std::cin >> wordCount;

    std::vector<std::string> wordList(wordCount);
    std::cout << "Enter the words in the word list:\n";
    for (int i = 0; i < wordCount; ++i) {
        std::cin >> wordList[i];
    }

    std::vector<std::vector<std::string>> result = findLadders(beginWord, endWord, wordList);

    if (result.empty()) {
        std::cout << "No transformation sequences found." << std::endl;
    } else {
        std::cout << "All shortest transformation sequences:\n";
        for (const auto& sequence : result) {
            for (size_t i = 0; i < sequence.size(); ++i) {
                std::cout << sequence[i];
                if (i < sequence.size() - 1) std::cout << " -> ";
            }
            std::cout << std::endl;
        }
    }

    return 0;
}
