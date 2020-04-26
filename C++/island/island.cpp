// Given a non-empty 2D array grid of 0's and 1's, an island is a group of 1's (representing land) 
// connected 4-directionally (horizontal or vertical.) You may assume all four edges of the grid 
// are surrounded by water.

// Find the maximum area of an island in the given 2D array. (If there is no island, the maximum area is 0.)
#include <vector>
#include <iostream>

class IslandAnalyser {
public:

    // Calculate the maximum sized Island in the Grid
    int maxAreaOfIsland(std::vector<std::vector<int> >& grid) {
        
        int island_count = 0, max_island_size = 0, island_size = 0;
        for (int x=0; x<grid.size(); x++) {
            for (int y=0; y<grid[0].size(); y++) {
                if (grid[x][y] == 1) {
                    island_count += 1;
                    island_size = deleteIsland(grid, x, y);
                    max_island_size = (island_size > max_island_size) ? island_size : max_island_size;
                }
            }
        }
        
        return max_island_size;
    }
    
    // DFS to remove and count Island Size
    int deleteIsland(std::vector<std::vector<int> >& grid, int x, int y) {
        int islandSize = 0;
        if (x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size() || grid[x][y] == 0) {
            return islandSize;
        }
        islandSize += 1;
        grid[x][y] = 0;
        islandSize += deleteIsland(grid, x+1, y);
        islandSize += deleteIsland(grid, x-1, y);
        islandSize += deleteIsland(grid, x, y+1);
        islandSize += deleteIsland(grid, x, y-1);
        return islandSize;
    }
    
    // Debugging function
    void printIsland(std::vector<std::vector<int> >& grid) {
        for (int x=0; x<grid.size(); x++) {
            for (int y=0; y<grid[0].size(); y++) {
                std::cout << grid[x][y];
            }
            std::cout << std::endl;
        }
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

    IslandAnalyser Solution = IslandAnalyser();

    std::vector<std::vector<int> > test1 = {   {0,0,1,0,0,0,0,1,0,0,0,0,0},
                                                {0,0,0,0,0,0,0,1,1,1,0,0,0},
                                                {0,1,1,0,1,0,0,0,0,0,0,0,0},
                                                {0,1,0,0,1,1,0,0,1,0,1,0,0},
                                                {0,1,0,0,1,1,0,0,1,1,1,0,0},
                                                {0,0,0,0,0,0,0,0,0,0,1,0,0},
                                                {0,0,0,0,0,0,0,1,1,1,0,0,0},
                                                {0,0,0,0,0,0,0,1,1,0,0,0,0}};
    int sol1 = 6;
    int out1 = Solution.maxAreaOfIsland(test1);
    compare(sol1, out1);

}