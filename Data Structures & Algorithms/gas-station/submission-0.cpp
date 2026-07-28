class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int total=0;
        int start=0;
        int current=0;
        for(int i=0;i<gas.size();i++)
        {
            int remainingGas=gas[i]-cost[i];
            total+=remainingGas;
            current+=remainingGas;
            if(current<0)
            {
                start=i+1;
                current=0;
            }
        }
        if(total<0)return -1;
        return start;
    }
};
