class Solution {
    private:
    bool solve(int n,int i){
        if(pow(2,i)==n)
        return true;
        if(pow(2,i)>n)
        return false;
        return solve(n,i+1);
    }
public:
    bool isPowerOfTwo(int n) {
        return solve(n,0);
    }
};