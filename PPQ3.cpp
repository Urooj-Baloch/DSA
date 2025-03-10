#include <iostream>
using namespace std;

const int ROWS = 5, COLS = 5; // Grid size

char grid[ROWS][COLS] = {
    {'E', 'J', 'E', 'T', 'J'},
    {'J', 'E', 'T', 'J', 'A'},
    {'T', 'E', 'T', 'A', 'J'},
    {'A', 'T', 'A', 'A', 'T'},
    {'J', 'T', 'J', 'E', 'A'}
};

void explorePath(int &points) {
    cout << "Explorer Path: ";
    points = 0;
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            cout << grid[i][j] << " ";
            if (grid[i][j] == 'T') points += 2;
            else if (grid[i][j] == 'J') points += 1;
            else if (grid[i][j] == 'A') points -= 2;
        }
    }
    cout << endl;
}

void thiefPath(int &points) {
    cout << "Thief Path: ";
    points = 0;
    for (int j = 0; j < COLS; j++) {
        for (int i = 0; i < ROWS; i++) {
            cout << grid[i][j] << " ";
            if (grid[i][j] == 'T') points += 2;
            else if (grid[i][j] == 'J') points += 1;
            else if (grid[i][j] == 'A') points -= 2;
        }
    }
    cout << endl;
}

int main() {
    int explorerPoints, thiefPoints;
    explorePath(explorerPoints);
    thiefPath(thiefPoints);
    
    cout << "Explorer Total Points: " << explorerPoints << endl;
    cout << "Thief Total Points: " << thiefPoints << endl;
    return 0;
}
