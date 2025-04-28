#include "gtest/gtest.h"
#include "solution.hpp"

namespace solution {

TEST(SolutionTest, mostCommonWord_1)
{
    StringProblems f;

    std::string paragraph = "Bob. hIt, baLl";
    std::vector<std::string> banned = {"bob", "hit"};
    std::string expected = "ball";
    std::string actual = f.mostCommonWord(paragraph, banned);

    EXPECT_EQ(expected, actual);
}

TEST(SolutionTest, coinChange_1)
{
    DynamicProgramming f;

    std::vector coins = {1,2,5};
    int amount = 11;

    int expected = 3;
    int actual = f.coinChange(coins, amount);

    EXPECT_EQ(expected, actual);
}

TEST(SolutionTest, evalRPN_1)
{
    StackProblems f;

    std::vector<std::string> input = {"2","1","+","3","*"};
    int expected = 9;
    int actual = f.evalRPN(input);

    EXPECT_EQ(expected, actual);
}

TEST(SolutionTest, evalRPN_2)
{
    StackProblems f;

    std::vector<std::string> input = {"4","13","5","/","+"};
    int expected = 6;
    int actual = f.evalRPN(input);

    EXPECT_EQ(expected, actual);
}

TEST(SolutionTest, evalRPN_3)
{
    StackProblems f;

    std::vector<std::string> input = {"10","6","9","3","+","-11","*","/","*","17","+","5","+"};
    int expected = 22;
    int actual = f.evalRPN(input);

    EXPECT_EQ(expected, actual);
}

TEST(SolutionTest, simplifyPath_1)
{
    StackProblems f;

    std::string input = "/home//foo/";
    std::string expected = "/home/foo";
    std::string actual = f.simplifyPath(input);

    EXPECT_EQ(expected, actual);
}

TEST(SolutionTest, simplifyPath_2)
{
    StackProblems f;

    std::string input = "/home/user/Documents/../Pictures";
    std::string expected = "/home/user/Pictures";
    std::string actual = f.simplifyPath(input);

    EXPECT_EQ(expected, actual);
}

TEST(SolutionTest, simplifyPath_3)
{
    StackProblems f;

    std::string input = "/../";
    std::string expected = "/";
    std::string actual = f.simplifyPath(input);

    EXPECT_EQ(expected, actual);
}

TEST(SolutionTest, simplifyPath_4)
{
    StackProblems f;

    std::string input = "/.../a/../b/c/../d/./";
    std::string expected = "/.../b/d";
    std::string actual = f.simplifyPath(input);

    EXPECT_EQ(expected, actual);
}

TEST(SolutionTest, findMinArrowShots_1)
{
    IntervalProblems f;

    std::vector<std::vector<int>> points = {{10,16},{2,8},{1,6},{7,12}};
    int expected = 2;
    int actual = f.findMinArrowShots(points);

    EXPECT_EQ(expected, actual);
}

TEST(SolutionTest, findMinArrowShots_2)
{
    IntervalProblems f;

    std::vector<std::vector<int>> points = {{1,2},{3,4},{5,6},{7,8}};
    int expected = 4;
    int actual = f.findMinArrowShots(points);

    EXPECT_EQ(expected, actual);
}

TEST(SolutionTest, findMinArrowShots_3)
{
    IntervalProblems f;

    std::vector<std::vector<int>> points = {{1,2},{2,3},{3,4},{4,5}};
    int expected = 2;
    int actual = f.findMinArrowShots(points);

    EXPECT_EQ(expected, actual);
}

TEST(SolutionTest, findMinArrowShots_4)
{
    IntervalProblems f;

    std::vector<std::vector<int>> points = {{9,12},{1,10},{4,11},{8,12},{3,9},{6,9},{6,7}};
    int expected = 2;
    int actual = f.findMinArrowShots(points);

    EXPECT_EQ(expected, actual);
}

TEST(SolutionTest, insertInterval_1)
{
    IntervalProblems f;

    std::vector<std::vector<int>> intervals = {{1,3},{6,9}};
    std::vector<int> newInterval = {2, 5};
    std::vector<std::vector<int>> expected = {{1,5},{6,9}};
    std::vector<std::vector<int>> actual = f.insertInterval(intervals, newInterval);

    EXPECT_EQ(expected, actual);
}

TEST(SolutionTest, insertInterval_2)
{
    IntervalProblems f;

    std::vector<std::vector<int>> intervals = {{1,2},{3,5},{6,7},{8,10},{12,16}};
    std::vector<int> newInterval = {4, 8};
    std::vector<std::vector<int>> expected = {{1,2},{3,10},{12,16}};
    std::vector<std::vector<int>> actual = f.insertInterval(intervals, newInterval);

    EXPECT_EQ(expected, actual);
}

TEST(SolutionTest, merge_1)
{
    IntervalProblems f; 

    std::vector<std::vector<int>> input = {{1,3},{2,6},{8,10},{15,18}};
    std::vector<std::vector<int>> expected = {{1,6},{8,10},{15,18}};
    std::vector<std::vector<int>> actual = f.merge(input);

    EXPECT_EQ(expected, actual);
}

TEST(SolutionTest, merge_2)
{
    IntervalProblems f; 

    std::vector<std::vector<int>> input = {{1,4},{4,5}};
    std::vector<std::vector<int>> expected = {{1,5}};
    std::vector<std::vector<int>> actual = f.merge(input);

    EXPECT_EQ(expected, actual);
}

TEST(SolutionTest, merge_3)
{
    IntervalProblems f; 

    std::vector<std::vector<int>> input = {{1,4},{0,6}};
    std::vector<std::vector<int>> expected = {{0,6}};
    std::vector<std::vector<int>> actual = f.merge(input);

    EXPECT_EQ(expected, actual);
}

TEST(SolutionTest, uniqueOccurrences_1)
{
    HashMapProblems f;

    std::vector<int> input = {1,2,2,1,1,3};
    bool expected = true;
    bool actual = f.uniqueOccurrences(input);

    EXPECT_EQ(expected, actual);
}

TEST(SolutionTest, uniqueOccurrences_2)
{
    HashMapProblems f;

    std::vector<int> input = {1,2};
    bool expected = false;
    bool actual = f.uniqueOccurrences(input);

    EXPECT_EQ(expected, actual);
}

TEST(SolutionTest, uniqueOccurrences_3)
{
    HashMapProblems f;

    std::vector<int> input = {-3,0,1,-3,1,1,1,-3,10,0};
    bool expected = true;
    bool actual = f.uniqueOccurrences(input);

    EXPECT_EQ(expected, actual);
}


TEST(SolutionTest, longestConsecutive_1)
{
    HashMapProblems f;
    std::vector<int> input = {100,4,200,1,3,2};
    const int expected = 4;
    const int actual = f.longestConsecutive(input);

    EXPECT_EQ(expected, actual);
}

TEST(SolutionTest, longestConsecutive_2)
{
    HashMapProblems f;
    std::vector<int> input = {0,3,7,2,5,8,4,6,0,1};
    const int expected = 9;
    const int actual = f.longestConsecutive(input);

    EXPECT_EQ(expected, actual);
}

TEST(SolutionTest, longestConsecutive_3)
{
    HashMapProblems f;
    std::vector<int> input = {1,0,1,2};
    const int expected = 3;
    const int actual = f.longestConsecutive(input);

    EXPECT_EQ(expected, actual);
}

// TEST(SolutionTest, groupAnagrams)
// {
//     HashMapProblems f;

//     std::vector<std::string> input = {"eat","tea","tan","ate","nat","bat"};
//     std::vector<std::vector<std::string>> expectedResult = {{"bat"},{"eat", "ate", "tea"},{"tan", "nat"}};
//     std::vector<std::vector<std::string>> actualResult = f.groupAnagrams(input);

//     EXPECT_EQ(actualResult, expectedResult);
// }

// TEST(SolutionTest, groupAnagrams_empty)
// {
//     HashMapProblems f;

//     std::vector<std::string> input = {};
//     std::vector<std::vector<std::string>> expectedResult = {{}};
//     std::vector<std::vector<std::string>> actualResult = f.groupAnagrams(input);

//     EXPECT_EQ(actualResult, expectedResult);
// }

// TEST(SolutionTest, groupAnagrams_single)
// {
//     HashMapProblems f;

//     std::vector<std::string> input = {"a"};
//     std::vector<std::vector<std::string>> expectedResult = {{"a"}};
//     std::vector<std::vector<std::string>> actualResult = f.groupAnagrams(input);

//     EXPECT_EQ(actualResult, expectedResult);
// }

TEST(SolutionTest, groupAnagrams_single)
{
    HashTableProblems f;

    std::vector<std::vector<std::string>> input = {{"leetcode","google","facebook"},{"leetcode","amazon"},{"facebook","google"}};
    std::vector<int> expectedResult = {0,1};
    std::vector<int> actualResult = f.peopleIndexes(input);

    EXPECT_EQ(actualResult, expectedResult);
}

TEST(SolutionTest, validWordAbbreviation_1)
{
    TwoPointerProblems f;

    std::string word = "internationalization";
    std::string abbreviation = "i12iz4n";
    bool expected = true;
    bool actual = f.validWordAbbreviation(word, abbreviation);

    EXPECT_EQ(actual, expected);
}

TEST(SolutionTest, validWordAbbreviation_2)
{
    TwoPointerProblems f;

    std::string word = "apple";
    std::string abbreviation = "a2e";
    bool expected = false;
    bool actual = f.validWordAbbreviation(word, abbreviation);

    EXPECT_EQ(actual, expected);
}

TEST(SolutionTest, validWordAbbreviation_3)
{
    TwoPointerProblems f;

    std::string word = "internationalization";
    std::string abbreviation = "i5a11o1";
    bool expected = true;
    bool actual = f.validWordAbbreviation(word, abbreviation);

    EXPECT_EQ(actual, expected);
}

TEST(SolutionTest, maximumScoreBottomUp)
{
    MaximumScoreCalculator f;

    std::vector<int> nums = {1, 2, 3};
    std::vector<int> multipliers = {3, 2, 1};
    int expected = 14;
    int actual = f.maximumScoreBottomUp(nums, multipliers);

    EXPECT_EQ(actual, expected);
}

TEST(SolutionTest, maximumScoreTopDown)
{
    MaximumScoreCalculator f;

    std::vector<int> nums = {1, 2, 3};
    std::vector<int> multipliers = {3, 2, 1};
    int expected = 14;
    int actual = f.maximumScoreTopDown(nums, multipliers);

    EXPECT_EQ(actual, expected);
}

TEST(SolutionTest, longestCommonSubsequenceTopDown_1)
{
    LongestCommonSubsequence f;

    std::string text1 = "abcde";
    std::string text2 = "ace";
    int expected = 3;
    int actual = f.longestCommonSubsequenceTopDown(text1, text2);

    EXPECT_EQ(actual, expected);
}

TEST(SolutionTest, longestCommonSubsequenceTopDown_2)
{
    LongestCommonSubsequence f;

    std::string text1 = "abc";
    std::string text2 = "abc";
    int expected = 3;
    int actual = f.longestCommonSubsequenceTopDown(text1, text2);

    EXPECT_EQ(actual, expected);
}

TEST(SolutionTest, longestCommonSubsequenceTopDown_3)
{
    LongestCommonSubsequence f;

    std::string text1 = "abc";
    std::string text2 = "def";
    int expected = 0;
    int actual = f.longestCommonSubsequenceTopDown(text1, text2);

    EXPECT_EQ(actual, expected);
}

TEST(SolutionTest, longestCommonSubsequenceBottomUp_1)
{
    LongestCommonSubsequence f;

    std::string text1 = "abcde";
    std::string text2 = "ace";
    int expected = 3;
    int actual = f.longestCommonSubsequenceBottomUp(text1, text2);

    EXPECT_EQ(actual, expected);
}

TEST(SolutionTest, longestCommonSubsequenceBottomUp_2)
{
    LongestCommonSubsequence f;

    std::string text1 = "abc";
    std::string text2 = "abc";
    int expected = 3;
    int actual = f.longestCommonSubsequenceBottomUp(text1, text2);

    EXPECT_EQ(actual, expected);
}

TEST(SolutionTest, longestCommonSubsequenceBottomUp_3)
{
    LongestCommonSubsequence f;

    std::string text1 = "abc";
    std::string text2 = "def";
    int expected = 0;
    int actual = f.longestCommonSubsequenceBottomUp(text1, text2);

    EXPECT_EQ(actual, expected);
}

TEST(SolutionTest, maximalSquare_1)
{
    MaximalSquare f;

    std::vector<std::vector<char>> matrix = {{'1','0','1','0','0'},{'1','0','1','1','1'},{'1','1','1','1','1'},{'1','0','0','1','0'}};
    int expected = 4;
    int actual = f.maximalSquareBottomUp(matrix);

    EXPECT_EQ(actual, expected);
}

} // namespace solution
