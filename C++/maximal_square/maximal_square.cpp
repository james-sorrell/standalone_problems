// Given a 2D binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.
#include <vector>
#include <iostream>
#include <algorithm>

class MatrixAlgorithms {
    
public:
    
    int maximalSquareArea(const std::vector<std::vector<char>>& matrix) {
        
        if (matrix.empty()) {
            return 0;
        }
        
        int m = matrix.size(), n = matrix[0].size();
        
        std::vector<std::vector<int>> dp(m, std::vector<int>(n, 0));
        
        int maximal_dimension = 0;
        for (int x = 0; x < m; x++) {
            for (int y = 0; y < n; y++) {
                
                if (x == 0 || y == 0 || matrix[x][y] == '0') {
                    dp[x][y] = matrix[x][y]-'0';
                    if (dp[x][y] > maximal_dimension) {
                        maximal_dimension = dp[x][y];
                    }
                }
                else {
                    dp[x][y] = smallest(dp[x-1][y], dp[x-1][y-1], dp[x][y-1]) + 1;
                    if (dp[x][y] > maximal_dimension) {
                        maximal_dimension = dp[x][y];
                    }
                }
            }
        }

        return maximal_dimension*maximal_dimension;
        
    }

    int smallest(const int &x, const int &y, const int &z) {
        return std::min({x, y, z});
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

    MatrixAlgorithms Solution = MatrixAlgorithms();

    std::vector<std::vector<char> > test1 = {   {'0','0','1','0','0'},
                                                {'0','0','0','0','0'},
                                                {'0','1','1','0','1'},
                                                {'0','1','1','0','1'}, };

    int sol1 = 4;
    int out1 = Solution.maximalSquareArea(test1);
    compare(sol1, out1);

}