class Solution {
public:
    string reverseParentheses(string s) {
        stack <int> lastSkipChar;

        string result;
        for(char &ch : s){
            if(ch == '('){
                lastSkipChar.push(result.length());
            }
            else if(ch == ')'){
                int l = lastSkipChar.top();
                lastSkipChar.pop();
                reverse(result.begin() + l , result.end());
            }
            else{
                result.push_back(ch);
            }
        }
        return result;
    }
};