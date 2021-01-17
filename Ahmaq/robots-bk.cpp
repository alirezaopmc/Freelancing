#include <iostream>
#include <vector>

using namespace std;

// CELL TYPES
const int CELL_LOSE         = -1;
const int CELL_EMPTY        =  0;
const int CELL_PLAYER       =  1;
const int CELL_ROBOT        =  2;
const int CELL_TOXIC        =  3;
const int CELL_UNKNOWN      =  9;

// MOVES DIRECTIONS
const int DIR_UP            =  0;
const int DIR_UP_RIGHT      =  1;
const int DIR_RIGHT         =  2;
const int DIR_DOWN_RIGHT    =  3;
const int DIR_DOWN          =  4;
const int DIR_DOWN_LEFT     =  5;
const int DIR_LEFT          =  6;
const int DIR_UP_LEFT       =  7;
const int DIR_TELEPORT      =  8;
const int DIR_UNKNOWN       =  9;

typedef struct Robot {
    int i, j;
    bool alive;
} Robot;

typedef struct Cell {
    bool player;
    bool toxic;
    int robots;

    Cell(bool player, bool toxic, int robots) {
        this -> player = player;
        this -> toxic = toxic;
        this -> robots = robots;
    }

    bool isToxic() {
        return toxic;
    }

    bool isOver() {
        return check();
    }

    int check() {
        if (player && robots) {
            return CELL_LOSE;
        }

        if (player && !robots) {
            return CELL_PLAYER;
        }

        if (toxic) {
            robots = 0;
            return CELL_TOXIC;
        }

        return CELL_UNKNOWN;
    }

    void playerJoin() {
        player = true;
    }

    void playerLeave() {
        player = false;
    }

    void robotJoin() {
        robots += 1;
    }

    void robotLeave() {
        robots += 1;
    }

    void getToxic() {
        toxic = true;
        robots = 0;
    }
} Cell;

typedef struct Player {
    int i, j;

    Player(int i, int j) {
        this -> i = i;
        this -> j = j;
    }
} Player;

typedef struct Game {
    vector<vector<Cell>> gameCells;
    vector<vector<char>> gameChars;
    Player player = Player(-1, -1);

    Game(int n, vector<vector<char>> charCells, string moves) {
        gameCells.resize(n, vector(n, Cell(false, false, 0)));
        gameChars.resize(n);
    }

    void loadMap() {
        int n = gameChars.size();
        for(int i = 0 ; i < n; i++) {
            for(int j = 0; j < n; j++) {
                translateCharToCell(i, j);
            }
        }
    }

    void run(string moves) {
        for(auto c : moves) {
            render(c);
        }
    }

    void translateCharToCell(int i, int j) {
        char cell = gameChars[i][j];

        switch(cell) {
            case '+':
                return gameCells[i][j].robotJoin();
            case '@':
                return gameCells[i][j].playerJoin();
            case '*':
                return gameCells[i][j].getToxic();
            default:
                return;
        }
    }

    void render(char c) {
        int dir = translateCharToDir(c);

        movePlayer(dir);
        moveRobots();
    }

    int translateCharToDir(char c) {
        switch(c) {
            case 'H': case 'h':
                return DIR_LEFT;
                


            default:
                // Unkown Char
                break;
        }
        return DIR_UNKNOWN;
    }

    void movePlayer(int dir) {
        switch(dir) {
            case DIR_LEFT:
                return playerMoveLeft();
            case DIR_UP_LEFT:
                return playerMoveUpLeft();
            case DIR_UP:
                return playerMoveUp();
            case DIR_UP_RIGHT:
                return playerMoveUpRight();
            case DIR_RIGHT:
                return playerMoveRight();
            case DIR_DOWN_RIGHT:
                return playerMoveDownRight();
            case DIR_DOWN:
                return playerMoveDown();
            case DIR_DOWN_LEFT:
                return playerMoveDownLeft();
            case DIR_TELEPORT:
                return playerTeleport();
            default:
                // Unkown Direction
                return;
        }
    }

    void moveRobots() {

    }

    void playerMoveLeft() {
        int i = player.i;
        int j = player.j;
        if (j - 1 >= 0) {
            gameCells[i][j].playerLeave();
            gameCells[i][j-1].playerJoin();
            player.j = j-1;
        }
    }

    void playerMoveUpLeft() {
        int i = player.i;
        int j = player.j;
        if (j - 1 >= 0 && i - 1 >= 0) {
            gameCells[i][j].playerLeave();
            gameCells[i-1][j-1].playerJoin();
            player.j = j-1;
            player.i = i-1;
        }
    }

    void playerMoveUp() {

    }

    void playerMoveUpRight() {
        
    }

    void playerMoveRight() {
        
    }

    void playerMoveDownRight() {
        
    }

    void playerMoveDown() {
        
    }

    void playerMoveDownLeft() {
        
    }

    void playerTeleport() {
        
    }


    
} Game;


int main() {
    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        scanf("%s", &gameChars[i]);
    }

    string moves;
    scanf("%s", &moves);

    Game game = Game
}



