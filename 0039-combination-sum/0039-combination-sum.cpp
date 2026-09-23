class Solution {
    void solve(vector<int>&candidates,int target,vector<vector<int>> &answer,vector<int>&temp , int i=0){
        //base case-1   
        if(target==0)
        {
            answer.push_back(temp);
            return;
        }
        //base case-2
        if(i==candidates.size())
        return;

        //recursive case
        if(candidates[i]<=target)
        {
            temp.push_back(candidates[i]);
            solve(candidates,target-candidates[i],answer,temp,i);
            temp.pop_back();//back tracking
        }
        //if current element greater than target
        solve(candidates,target,answer,temp,i+1);

    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

    vector<vector<int>>answer;
    vector<int>temp;

    solve(candidates,target,answer,temp,0);
    return answer;
         
    }
};