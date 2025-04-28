#ifndef SOLUTION_HPP
#define SOLUTION_HPP

#include <vector>

namespace solution {

class DynamicProgramming {
public:
    int coinChange(std::vector<int>& coins, int n);
};

class MaximumScoreCalculator {
public:
    int maximumScoreBottomUp(std::vector<int> & nums, std::vector<int> & multipliers);
    int maximumScoreTopDown(std::vector<int> & nums, std::vector<int> & multipliers);
private:
    int dp(int i, int left, std::vector<int> & nums, std::vector<int> & multipliers, std::vector<std::vector<int>> & memo);
};

class LongestCommonSubsequence {
public:
    int longestCommonSubsequenceBottomUp(std::string text1, std::string text2);
    int longestCommonSubsequenceTopDown(const std::string & text1, const std::string & text2);

private:
    int memoSolve(int p1, int p2, std::vector<std::vector<int>> & memo);

    std::string m_text1;
    std::string m_text2;
    int m;
    int n;
};

class MaximalSquare {
public:
    int maximalSquareBottomUp(std::vector<std::vector<char>>& matrix);
};

class TwoPointerProblems {
public:
    bool validWordAbbreviation(std::string word, std::string abbr);
};

class StringProblems {
public:
    std::string mostCommonWord(std::string paragraph, std::vector<std::string>& banned);
};

class StackProblems {
public:
    int evalRPN(std::vector<std::string>& tokens);
    std::string simplifyPath(std::string path);
};

class IntervalProblems {
public:
    int findMinArrowShots(std::vector<std::vector<int>>& points);
    std::vector<std::vector<int>> insertInterval(std::vector<std::vector<int>>& intervals, std::vector<int> newInterval);
    std::vector<std::vector<int>> merge(std::vector<std::vector<int>>& intervals);
};

class HashMapProblems {
public:
    int longestConsecutive(std::vector<int>& nums);
    bool uniqueOccurrences(std::vector<int>& arr);
    std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs);
};

class HashTableProblems {
public:
    std::vector<int> peopleIndexes(std::vector<std::vector<std::string>>& favoriteCompanies);
};

}

#endif // SOLUTION_HPP
