class Solution {
public:

    int eatbanana(vector<int>& arr, int hourly)
    {
        int totalhour = 0;

        for(int i = 0; i < arr.size(); i++)
        {
            totalhour += (arr[i] + hourly - 1) / hourly; 
        }

        return totalhour;
    }

    int minEatingSpeed(vector<int>& piles, int h) 
    {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());

        while(low <= high)
        {
            int mid = (low + high) / 2;

            int totaltime = eatbanana(piles, mid);

            if(totaltime <= h)
                high = mid - 1;
            else
                low = mid + 1;
        }

        return low;
    }
};