class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int>freq(26,0);
        for(char task:tasks)
        {
            freq[task-'A']++;
        }
        int maxfq=0;
        for(int f:freq)
        {
            maxfq=max(maxfq,f);
        }
        int countmaxfq=0;
        for(int f:freq)
        {
            if(f==maxfq)countmaxfq++;
        }
        int time=(maxfq-1)*(n+1)+countmaxfq;
        return max((int)tasks.size(),time);
    }
};
