// MazeProblem.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <stack>
#include <vector>
using namespace std;
//const int MazeWidth = 4;
//const int MazeHeight = 4;
const int DirectionChoice = 8;
typedef struct {
    int vert;
    int horiz;
} offsets;
/* 
NW  N  NE
 W     E
SW  S  SE
*/
offsets direction[DirectionChoice] = { { -1, 0 },    //N
                         { -1, 1 },    //NE
                         { 0, 1 },     //E
                         { 1, 1 },     //SE
                         { 1, 0 },     //S
                         { 1, -1 },    //SW
                         { 0, -1 },    //W
                         { -1, -1 } }; //NW
class maze_move {
public:
    int row;
    int column;
    int direction;
    maze_move(int row, int column) {
        this->row = row;
        this->column = column;
        direction = 0;
    }
};
void solveMaze(vector<vector<int>>);
int main() {
    // 0: block 1: path
    vector<vector<int>> maze1 = { { 1, 0, 0, 0 },
                                  { 1, 1, 0, 1 },
                                  { 0, 1, 0, 0 },
                                  { 1, 1, 1, 1 } };
    solveMaze(maze1);
    cout << "maze 1 over" << endl;
    vector<vector<int>> maze2 = { {1, 0, 1, 1, 1, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0},
                                  {0, 1, 1, 1, 0, 0, 1, 0, 0, 0, 1, 1, 0, 0, 0},
                                  {1, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 0, 0},
                                  {0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 1},
                                  {0, 0, 1, 0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0},
                                  {1, 1, 0, 0, 1, 0, 0, 0, 1, 0, 1, 1, 0, 1, 0},
                                  {1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0},
                                  {1, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0},
                                  {0, 0, 1, 1, 1, 0, 0, 1, 0, 0, 1, 1, 1, 1, 1},
                                  {1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 1},
                                  {1, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1} };
    solveMaze(maze2);
    cout << "maze 2 over" << endl;
}

void solveMaze(vector<vector<int>> maze) {
    const int MazeHeight = int(maze.size());
    const int MazeWidth = int(maze[0].size());
    int default_value = 0;
    vector<int> footage_row(MazeWidth, default_value);
    vector<vector<int>> footage(MazeHeight, footage_row);
    vector<int> maze_with_boundary_row(MazeWidth + 2, default_value);
    vector<vector<int>> maze_with_boundary(MazeHeight + 2, maze_with_boundary_row);
    // make a maze with boundary (0)
    for (int a = 0; a < MazeHeight + 2; a++) {
        for (int b = 0; b < MazeWidth + 2; b++) {
            if (a == 0 || a == MazeHeight + 1 || b == 0 || b == MazeWidth + 1) {
                // add boundary with 0;
                maze_with_boundary[a][b] = 0;
                continue;
            }
            maze_with_boundary[a][b] = maze[a - 1][b - 1];
        }
    }
    // initialize stack at entrance position
    int row_index_without_boundary = 0, column_index_without_boundary = 0;
    int row_index = row_index_without_boundary + 1;
    int column_index = column_index_without_boundary + 1;
    footage[row_index_without_boundary][column_index_without_boundary] = 1;
    stack<maze_move> s;
    maze_move t(row_index, column_index);
    s.push(t);
    while (!s.empty()) {
        t = s.top();
        int d = t.direction;
        row_index = t.row, column_index = t.column;
        // find next possible move (d = 0~8)
        // footage is 0 or path is available
        while (d < 8 && 
            ( maze_with_boundary[row_index + direction[d].vert][column_index + direction[d].horiz] == 0
            || footage[row_index + direction[d].vert - 1][column_index + direction[d].horiz - 1] == 1)) {
            d += 1;
        }
        if (d < DirectionChoice) {
            t.direction = d;
            s.pop();
            s.push(t);
            maze_move next_move(row_index + direction[d].vert, column_index + direction[d].horiz);
            // mark footage
            footage[row_index + direction[d].vert - 1][column_index + direction[d].horiz - 1] = 1;
            s.push(next_move);
            if (next_move.column == MazeWidth && next_move.row == MazeHeight) {
                // cout << "path found!" << endl;
                break;
            }
            continue;
        }
        else {
            s.pop();
        }
    }
    if (s.empty()) {
        cout << "path not found!" << endl;
    }
    else {
        stack<maze_move> step;
        while (!s.empty()) {
            step.push(s.top());
            s.pop();
        }
        while (!step.empty()) {
            cout << "[" << step.top().row - 1 << "][" << step.top().column - 1 << "]" << endl;
            step.pop();
        }
    }
}
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
