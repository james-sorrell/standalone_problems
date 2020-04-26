// Given a non-empty 2D array grid of 0's and 1's, an island is a group of 1's (representing land) 
// connected 4-directionally (horizontal or vertical.) You may assume all four edges of the grid 
// are surrounded by water.

// Find the maximum area of an island in the given 2D array. (If there is no island, the maximum area is 0.)
#include <vector>
#include <iostream>

class ArrayManipulator {
public:
    std::vector<int> productExceptSelf(std::vector<int>& nums) {
        std::vector<int> result(nums.size(), 1);
        int back = nums.size()-1;
        int front_val = 1, back_val = 1;
        for (int front = 0; front < nums.size(); front++) {
            result[front] *= front_val;
            front_val *= nums[front];
            result[back-front] *= back_val;
            back_val *= nums[back-front];
        }
        return result;
    }
};

bool compareInt(int solution, int output) {
    if (solution == output) {
        std::cout << "Pass" << std::endl;
        return true;
    }
    else {
        std::cout << "Fail" << std::endl;
        return false;
    }
}

bool compareVector(std::vector<int> solution, std::vector<int> output) {
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

    ArrayManipulator Solution = ArrayManipulator();

    std::vector<int> test1 = {1, 2, 3, 4};
    std::vector<int> sol1 = {24, 12, 8, 6};
    std::vector<int> out1 = Solution.productExceptSelf(test1); 
    compareVector(sol1, out1);
}