class Solution {
    void solve(vector<string>&res, int n, int open, int close, string s)
    {
        //base case
        if(open == n and close == n)
        {
            res.push_back(s);
            return;
        }

        if(close>open or open>n)
        {
            return;
        }

        //recursive case

        solve(res,n,open+1,close,s+"(");

        solve(res,n,open,close+1,s+")");




    }

public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        

        solve(res,n,0,0,"");
        return res;

        
        
    }
};