class Solution {
public:
    int maxDepth(string s) {
        // method 1
        // stack<int> st;
        // int res= 0;
        // for(char &ch : s){
        //     if(ch == '('){
        //         st.push(ch);
        //     }
        //     else if(ch == ')'){
        //         st.pop();
        //     }
        //     res = max(res , (int) st.size());
        // }
        // return res;
        // Method 2
        
        int openBracket = 0;
        int result = 0;
        for(char &ch : s){
            if(ch == '('){
                openBracket++;
            }
            else if(ch == ')'){
                openBracket--;
            }
            result = max(result , openBracket);
        }
        return result;
    }
};