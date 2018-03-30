## 回文串

总共 5 题.

**0. [Longest Palindromic Substring](https://github.com/awangdev/LintCode/blob/master/Java/Add%20and%20Search%20Word.java)**      Level: Medium

寻找最长回文字符串，3 methods
* 动态规划
  维护一个二维数组dp，其中dp[i][j]表示字符串区间[i, j]是否为回文串，当i = j时，只有一个字符，肯定是回文串，如果i = j + 1，说明是相邻字符，此时需要判断s[i]是否等于s[j]，如果i和j不相邻，即i - j >= 2时，除了判断s[i]和s[j]相等之外，dp[j + 1][i - 1]若为真，就是回文串，通过以上分析，可以写出递推式如下：

            dp[i, j] = 1                         if i == j

           = s[i] == s[j]                        if j = i + 1

           = s[i] == s[j] && dp[i + 1][j - 1]    if j > i + 1 
**1. [Manacher's Algorithm](http://www.cnblogs.com/grandyang/p/4475985.html)**
## 双指针
* 两个都从头开始移动，一快一慢
* 一头一尾，向中间移动
数组或者链表
*相关资源*
[The-Two-Pointer-Algorithm](https://tp-iiita.quora.com/The-Two-Pointer-Algorithm)

[浅析经典面试算法题-two pointer的运用](http://chocoluffy.com/2016/12/04/%E6%B5%85%E6%9E%90%E7%BB%8F%E5%85%B8%E9%9D%A2%E8%AF%95%E7%AE%97%E6%B3%95%E9%A2%98-two-pointer%E7%9A%84%E8%BF%90%E7%94%A8/)

[Trapping Rain Water (second high)](https://leetcode.com/problems/trapping-rain-water/description/)

Container With Most Water (头尾两个指针)

largest rectangle in histogram / maximal rectangle (stack)
