#include <iostream>
#include <vector>

using namespace std;

class Solver {
   public:
    Solver(vector<int> const& start_pt, vector<int> const& dest_pt);
    bool hasPath(vector<vector<int>>& maze);
    ~Solver(){};

   private:
    bool dfs(vector<vector<int>>& maze, const int& cur_x, const int& cur_y);
    int sx_, sy_;  // start point
    int dx_, dy_;  // destination
};

Solver::Solver(vector<int> const& start_pt, vector<int> const& dest_pt)
    : sx_(start_pt[0]), sy_(start_pt[1]), dx_(dest_pt[0]), dy_(dest_pt[1]) {}

bool Solver::hasPath(vector<vector<int>>& maze) {
    return dfs(maze, sx_, sy_);
}

bool Solver::dfs(vector<vector<int>>& maze, const int& cur_x, const int& cur_y) {
    // collision
    if (cur_x < 0 || cur_y < 0 ||
        cur_x >= maze.size() || cur_y >= maze[0].size())
        return false;

    // if visited
    if (maze[cur_x][cur_y] > 0)
        return false;
    
    // visited
    maze[cur_x][cur_y] = 2;

    // reached
    if (cur_x == dx_ && cur_y == dy_)
        return true;
    
    bool up = dfs(maze, cur_x - 1, cur_y);
    bool down = dfs(maze, cur_x + 1, cur_y);
    bool left = dfs(maze, cur_x, cur_y - 1);
    bool right = dfs(maze, cur_x, cur_y + 1);

    return (up || down || left || right);
}

int main(int argc, char const* argv[]) {
    vector<vector<int>> maze{{0, 0, 1, 0, 0},
                             {0, 0, 0, 0, 0},
                             {0, 0, 0, 1, 0},
                             {1, 1, 0, 1, 1},
                             {0, 0, 0, 0, 0}};
    vector<int> start_point{0, 4};
    vector<int> dest_point{4, 4};

    Solver sol(start_point, dest_point);


    if (sol.hasPath(maze))
        cout << "Nice, find the path" << endl;
    else
        cout << "So sad, not found" << endl;

    return 0;
}
