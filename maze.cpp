#include <iostream>
using namespace std;

const int N = 4;

bool isSafe(int maze[N][N], int x, int y) {
    return (x >= 0 && x < N && y >= 0 && y < N && maze[x][y] == 1);
}

bool solveMazeUtil(int maze[N][N], int x, int y, int solution[N][N]) {
    if (x == N - 1 && y == N - 1) { // Goal reached
        solution[x][y] = 1;
        return true;
    }
    
    if (isSafe(maze, x, y)) {
        solution[x][y] = 1; // Mark path
        
        if (solveMazeUtil(maze, x + 1, y, solution)) return true; // Move Right
        if (solveMazeUtil(maze, x, y + 1, solution)) return true; // Move Down
        
        solution[x][y] = 0; // Backtrack
    }
    
    return false;
}

void solveMaze(int maze[N][N]) {
    int solution[N][N] = {0};

    if (solveMazeUtil(maze, 0, 0, solution)) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++)
                cout << solution[i][j] << " ";
            cout << endl;
        }
    } else {
        cout << "No solution exists" << endl;
    }
}

int main() {
    int maze[N][N] = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {0, 1, 0, 0},
        {1, 1, 1, 1}
    };

    solveMaze(maze);
    return 0;
}
