// We need to find out the maximum difference (which will be the maximum profit) 
// between two numbers in the given array. Also, the second number (selling price) 
// must be larger than the first one (buying price).
// In formal terms, we need to find \max(\text{prices[j]} - \text{prices[i]})max(prices[j]−prices[i]), for every ii and jj such that j > ij>i.
#include <vector>
#include <iostream>

class ProfitCalculator {
public:
    int maxProfit(std::vector<int>& prices) {
        
        if (prices.size() == 0) {
            return 0;
        }
        int max_diff = 0, curr_diff = 0;
        int smallest = prices[0];
        
        for (int i = 1; i < prices.size(); i++) {
            
            if (prices[i] < smallest) {
                smallest = prices[i];
            } else {
                curr_diff = prices[i] - smallest;
                if (curr_diff > max_diff) {
                    max_diff = curr_diff;
                }
            } 

        }
        
        return max_diff;
        
    }
};

bool compare(int solution, int output) {
    if (solution == output) {
        std::cout << "Pass" << std::endl;
        return true;
    }
    else {
        std::cout << "Fail" << std::endl;
        return false;
    }
}

int main()
{

    ProfitCalculator calc = ProfitCalculator();

    std::vector<int> test1 = { 7,1,5,3,6,4 };
    int sol1 = 5;
    int out1 = calc.maxProfit(test1);
    compare(sol1, out1);

}