class Solution {
public:

     bool isPalindrome(string &s, int i,int j){
        while(i<j){
            if(s[i]!=s[j]){
                return false;
            }
            i++,j--;
        }
        return true;
     }


    void recur(int i,vector<string> &cur , vector<vector<string>> &ans,string &s){

        //base case
        if(i>=s.size()){
            ans.push_back(cur);
            return;
        }



        //choices and validity check
        for(int j=i ; j<s.size() ; j++){
            if(isPalindrome(s,i,j)==true){
                //do partition
                cur.push_back(s.substr(i,j-i+1));
                recur(j+1,cur,ans,s);
                cur.pop_back();    //back track
            }
        }
}
    vector<vector<string>> partition(string s) {
        vector<string> cur;
        vector<vector<string>>ans;

        recur(0,cur,ans,s);
        return ans;
        
    }
};