#include "solution.hpp"

#include <sstream>
#include <stack>
#include <unordered_map>
#include <unordered_set>

namespace solution {

bool TwoPointerProblems::validWordAbbreviation(std::string word, std::string abbr)
{
    int wordIndex = 0;
    int abbrIndex = 0;

    while (wordIndex < word.length() && abbrIndex < abbr.length()) {
        int abbrSize = 0;

        if (std::isdigit(abbr[abbrIndex])) {
            if (abbr[abbrIndex] == '0')
                return false;

            while (std::isdigit(abbr[abbrIndex]) && abbrIndex < abbr.length()) {
                abbrSize = (abbrSize * 10) + abbr[abbrIndex] - '0';
                abbrIndex++;
            }

            wordIndex += abbrSize;
            continue;
        }

        if (word[wordIndex] != abbr[abbrIndex])
            return false;

        wordIndex++;
        abbrIndex++;
    }

    return wordIndex == word.length() && abbrIndex == abbr.length();
}

std::vector<int> HashTableProblems::peopleIndexes(std::vector<std::vector<std::string>>& favoriteCompanies)
{
    std::unordered_map<std::string, std::bitset<100>> table;

    for(int i = 0; i != favoriteCompanies.size(); i++) {
        std::bitset<100> comp;
        comp.set(i);

        for(auto & company : favoriteCompanies[i])
            table[company] |= comp; 
    }

    std::vector<int> answer;
    for(int i = 0; i != favoriteCompanies.size(); i++) {
        std::bitset<100> comp;
        comp.flip();

        for(auto &company : favoriteCompanies[i])
            comp &= table[company];

        if(comp.count() == 1)
            answer.push_back(i); 
    }

    return answer;
}

int DynamicProgramming::coinChange(std::vector<int>& coins, int n)
{
    std::vector<int> dp(++n);
    dp[0] = 0;

    std::sort(coins.begin(), coins.end());

    for (int i = 1; i < n; i++) {
        dp[i] = INT_MAX;
        for (int coin : coins) {
            if (coin > i)
                break;

            if (dp[i - coin] != INT_MAX)
                dp[i] = std::min(dp[i], 1 + dp[i - coin]);
        }
    }

    n--;

    return dp[n] == INT_MAX ? -1 : dp[n];
}

int MaximumScoreCalculator::maximumScoreBottomUp(std::vector<int>& nums, std::vector<int>& multipliers)
{
    int n = nums.size();
    int m = multipliers.size();
    std::vector<std::vector<int>> dp = std::vector(m + 1, std::vector(m + 1, 0));

    dp[m][m] = 0;

    for (int i = m - 1; i >= 0; i--) {
        for (int left = i; left >= 0; left--) {
            int mult = multipliers[i];
            int right = n - 1 - (i - left);

            int chooseLeft = (mult * nums[left]) + dp[i + 1][left + 1];
            int chooseRight = (mult * nums[right]) + dp[i + 1][left];
            dp[i][left] = std::max(chooseLeft, chooseRight);
        }
    }

    return dp[0][0];
}

int MaximumScoreCalculator::maximumScoreTopDown(std::vector<int>& nums, std::vector<int>& multipliers)
{
    int n = nums.size();
    int m = multipliers.size();
    std::vector<std::vector<int>> memo = std::vector(m, std::vector(m, 0));

    return dp(0, 0, nums, multipliers, memo);
}

int MaximumScoreCalculator::dp(int i, int left, std::vector<int> & nums, std::vector<int> & multipliers, std::vector<std::vector<int>> & memo)
{
    if (i == multipliers.size())
        return 0;

    int mult = multipliers[i];
    int right = nums.size() - 1 - (i - left);

    if (memo[i][left] == 0) {
        int chooseLeft = (mult * nums[left]) + dp(i + 1, left + 1, nums, multipliers, memo);
        int chooseRight = (mult * nums[right]) + dp(i + 1, left, nums, multipliers, memo);
        memo[i][left] = std::max(chooseLeft, chooseRight);
    }

    return memo[i][left];
}

std::string StringProblems::mostCommonWord(std::string paragraph, std::vector<std::string>& banned) {
    std::transform(paragraph.begin(), paragraph.end(), paragraph.begin(), ::tolower);

    std::unordered_map<std::string, int> wordCounter;
    std::string word;

    for (char letter : paragraph) {
        if (isalpha(letter)) {
            word += letter;
            continue;
        }

        if (word.empty())
            continue;

        if (std::find(banned.begin(), banned.end(), word) == banned.end()) {
            wordCounter[word] += 1;
        }

        word = "";
    }

    if (!word.empty() && std::find(banned.begin(), banned.end(), word) == banned.end())
        wordCounter[word] += 1;

    int maxCount = 0;
    std::string mostCommonWord = "";

    for (const auto [word, count] : wordCounter) {
        if (count > maxCount) {
            maxCount = count;
            mostCommonWord = word;
        }
    }

    return mostCommonWord;
}

int StackProblems::evalRPN(std::vector<std::string>& tokens)
{
    std::stack<long> stack;
    const std::unordered_map<std::string, std::function<long(long, long)>> op {
        {"+", std::plus<long>()},
        {"-", std::minus<long>()},
        {"*", std::multiplies<long>()},
        {"/", std::divides<long>()}};

    for (const std::string & token : tokens) {
        if (op.contains(token)) {
            const long b = stack.top();
            stack.pop();
            const long a = stack.top();
            stack.pop();
            stack.push(op.at(token)(a, b));
        } 
        else {
            stack.push(std::stoi(token));
        }
    }

    return stack.top();
}

std::string StackProblems::simplifyPath(std::string path)
{
    std::vector<std::string> stack;
    std::stringstream ss(path);
    std::string part;
    while (getline(ss, part, '/')) {
        if (part == "..") {
            if (!stack.empty()) stack.pop_back();
        } else if (!part.empty() && part != ".") {
            stack.push_back(part);
        }
    }

    std::stringstream simplifiedPath;
    for (const std::string& s : stack) {
        simplifiedPath << "/" << s;
    }

    return simplifiedPath.str().empty() ? "/" : simplifiedPath.str();  
}

int IntervalProblems::findMinArrowShots(std::vector<std::vector<int>>& points)
{
    std::sort(points.begin(), points.end());
    int arrows = 0;
    int lowerBound = points[0][0];
    int upperBound = points[0][1];

    for (int i = 1; i < points.size(); i++) {
        lowerBound = points[i][0];
        upperBound = std::min(upperBound, points[i][1]);

        if (points[i][0] > upperBound) {
            arrows++;
            upperBound = points[i][1];
        }
    }

    arrows++;

    return arrows;
}

std::vector<std::vector<int>> IntervalProblems::insertInterval(std::vector<std::vector<int>>& intervals, std::vector<int> newInterval)
{
    std::vector<std::vector<int>> result;
    int i = 0;
    int n = intervals.size();

    while (i < n && intervals[i][1] < newInterval[0]) {
        result.push_back(intervals[i]);
        i++;
    }

    while (i < n && intervals[i][0] <= newInterval[1]) {
        newInterval[0] = std::min(newInterval[0], intervals[i][0]);
        newInterval[1] = std::max(newInterval[1], intervals[i][1]);
        i++;
    }

    result.push_back(newInterval);

    while (i < n) {
        result.push_back(intervals[i]);
        i++;
    }

    return result;
}

std::vector<std::vector<int>> IntervalProblems::merge(std::vector<std::vector<int>>& intervals)
{
    std::sort(intervals.begin(), intervals.end());
    int k = 0;

    for (int i = 1; i < intervals.size(); i++) {
        if (intervals[k][1] >= intervals[i][0]) {
            intervals[k][1] = std::max(intervals[k][1], intervals[i][1]);
        }
        else {
            k++;
            intervals[k] = intervals[i];
        }
    }

    intervals.resize(k + 1);

    return intervals;
}

bool HashMapProblems::uniqueOccurrences(std::vector<int>& arr)
{
    std::unordered_map<int, int> numberCounter;
    std::unordered_set<int> counts;

    for (const int number : arr) {
        numberCounter[number] += 1;
    }

    for (const auto [_, count] : numberCounter)
        counts.insert(count);

    return numberCounter.size() == counts.size();
}

int HashMapProblems::longestConsecutive(std::vector<int>& nums)
{
    if (nums.empty())
        return 0;

    std::unordered_map<int, bool> map;

    for (const int i : nums) {
        map[i] = true;
    }

    for (const int i : nums) {
        if (map.find(i - 1) != map.end()) {
            map[i] = false;
        }
    }

    int count = 0;

    for (int i = 0; i < nums.size(); i++) {
        if (!map[nums[i]])
            continue;

        int j = 0;
        
        while(map.count(nums[i]+j) > 0){
            map[nums[i] + j] = false;
            j++;
        }
        
        count = std::max(count, j);
    }

    return count;
}

std::vector<std::vector<std::string>> HashMapProblems::groupAnagrams(std::vector<std::string>& strs)
{
    std::unordered_map<std::string, std::vector<std::string>> anagrams;
    std::vector<std::vector<std::string>> result;

    for (const std::string & str : strs) {
        std::string word = str;
        sort(word.begin(), word.end());
        anagrams[word].push_back(str);
    }

    for (auto& it : anagrams)
        result.push_back(it.second);

    return result;
}

int LongestCommonSubsequence::longestCommonSubsequenceBottomUp(std::string text1, std::string text2)
{
    if (text2.length() < text1.length()) {
        std::string temp = text1;
        text1 = text2;
        text2 = temp;
    }
    
    std::vector<std::vector<int>> dpGrid = std::vector(text1.length() + 1, std::vector(text2.length() + 1, 0));

    for (int col = text2.length() - 1; col >= 0; col--) {
        for (int row = text1.length() - 1; row >= 0; row--) {
            if (text1[row] == text2[col]) {
                dpGrid[row][col] = 1 + dpGrid[row + 1][col + 1];
            } else {
                dpGrid[row][col] = std::max(dpGrid[row][col + 1],
                                            dpGrid[row + 1][col]);
            }
        }
    }

    return dpGrid[0][0];
}

int LongestCommonSubsequence::longestCommonSubsequenceTopDown(const std::string & text1, const std::string & text2)
{
    m = text1.length();
    n = text2.length();
    m_text1 = text1;
    m_text2 = text2;
    std::vector<std::vector<int>> memo = std::vector(m + 1, std::vector(n + 1, 0));

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            memo[i][j] = -1;
        }
    }

    return memoSolve(0, 0, memo);
}

int LongestCommonSubsequence::memoSolve(int p1, int p2, std::vector<std::vector<int>> & memo)
{
    if (memo[p1][p2] != -1)
        return memo[p1][p2];

    int answer = 0;
    if (m_text1[p1] == m_text2[p2]) {
        answer = 1 + memoSolve(p1 + 1, p2 + 1, memo);
    } else {
        answer = std::max(memoSolve(p1, p2 + 1, memo), memoSolve(p1 + 1, p2, memo));
    }

    memo[p1][p2] = answer;
    return memo[p1][p2];
}

int MaximalSquare::maximalSquareBottomUp(std::vector<std::vector<char>> & matrix)
{
    if (matrix.empty() || matrix[0].empty())
        return 0;

    int rows = matrix.size();
    int cols = matrix[0].size();
    std::vector<std::vector<int>> dp(rows + 1, std::vector<int>(cols + 1, 0));
    int maxSideLength = 0;

    for (int row = 1; row <= rows; row++) {
        for (int col = 1; col <= cols; col++) {
            if (matrix[row - 1][col - 1] == '1') {
                dp[row][col] = 1 + std::min(std::min(dp[row][col - 1],
                                                     dp[row - 1][col]),
                                            dp[row - 1][col - 1]);
                maxSideLength = std::max(maxSideLength, dp[row][col]);
            }
        }
    }
    
    return maxSideLength * maxSideLength;
}

}
