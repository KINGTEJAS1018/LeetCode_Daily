class Solution {
public:
    int getDigitSum(int n){
        int sum = 0;
        while(n>0){
            sum += (n%10);
            n /= 10;
        }
        return sum;
    }

    int minSwaps(vector<int>& nums) {
        int n = nums.size();

        vector<int> afterSorted(nums);


        auto lambda = [&](int num1 , int num2){
            int dSum1 = getDigitSum(num1);
            int dSum2 = getDigitSum(num2);

            if(dSum1 != dSum2){
                return dSum1 < dSum2;
            }
            return num1 < num2;
        };
        
        sort(afterSorted.begin(), afterSorted.end() , lambda);

        unordered_map<int , int>valToidx;

        for(int i = 0 ; i < n ; i++){
            valToidx[nums[i]] = i;
        }

        int swapCnt = 0;
        for(int i = 0 ; i < n ; i++){
            int expected = afterSorted[i];
            int currVal = nums[i];

            if(expected == currVal) continue;

            int idx = valToidx[expected];

            nums[i] = expected;
            nums[idx] = currVal;

            valToidx[expected] = i;
            valToidx[currVal] = idx;

            swapCnt++;
        }
        return swapCnt;
    }
};