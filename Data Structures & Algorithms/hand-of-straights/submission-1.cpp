class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n=hand.size();
        if(n%groupSize!=0)return false;
        map<int,int>frequency;
        for(int card:hand)
        {
            frequency[card]++;
        }
        while(!frequency.empty())
        {
            int start=frequency.begin()->first;
            for(int i=start;i<start+groupSize;i++)
            {
                if(frequency.find(i)==frequency.end())return false;
                frequency[i]--;
                if(frequency[i]==0)frequency.erase(i);
            }
        }
        return true;
    }
};
