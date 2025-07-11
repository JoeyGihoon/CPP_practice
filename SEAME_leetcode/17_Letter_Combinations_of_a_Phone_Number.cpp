#include <vector>
#include <string>
using namespace std;

class Solution {
private:
    vector<string> result;
    string combination;

    vector<string> phone = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    void backtrack(string &digits, int idx, string &combination, vector<string> &result, vector<string> &phone){
        if(idx == digits.size()){
            result.push_back(combination);
            return;
        }

        string letters = phone[digits[idx] - '0'];
        for(char c : letters){
            combination.push_back(c);
            backtrack(digits, idx+1, combination, result, phone);
            combination.pop_back();
        }
    }

public:
    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0) return result;
        
        backtrack(digits, 0, combination, result, phone);
        return result;
    }
};