#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;


const bool DEBUG_MODE = true;

#define DEBUG(s) if(DEBUG_MODE){s;}

// Chars Map
const char MAP_EMPTY        = '.';
const char MAP_PLAYER       = '@';
const char MAP_ROBOT        = '+';
const char MAP_TOXIC        = '*';
const char MAP_UNKNOWN      = '!';

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


// Cell Struct
typedef struct Cell {
    bool player;
    bool toxic;
    int robots;

    Cell(bool player = false, bool toxic = false, int robots = 0) {
        this -> player = player;
        this -> toxic = toxic;
        this -> robots = robots;
    }

    void update() {
        if (type() == CELL_TOXIC) {
            robots = 0;
            toxic = true;
        }
    }

    int type() {
        if (hasPlayer() && hasRobot()) {
            return CELL_LOSE;
        }

        if (hasPlayer() && !hasRobot()) {
            return CELL_PLAYER;
        }

        if (isToxic() || getRobots() > 1) {
            return CELL_TOXIC;
        }

        return CELL_UNKNOWN;
    }

    int getRobots() {
        return robots;
    }

    char getChar() {
        if (hasPlayer())    return MAP_PLAYER;
        
        if (hasRobot())     return MAP_ROBOT;

        if (isToxic())      return MAP_TOXIC;

        if (isEmpty())      return MAP_EMPTY;

        return MAP_UNKNOWN;
    }

    bool isEmpty() {
        return !isToxic() && !hasPlayer() && !hasRobot();
    }

    bool isToxic() {
        return toxic;
    }

    bool hasPlayer() {
        return player;
    }

    bool hasRobot() {
        return robots; // == 1
    }
    
    bool isRobot() {
        return getRobots()==1;
    }

    bool isOver() {
        return type() == CELL_LOSE;
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
        robots -= 1;
    }

    void getToxiced() {
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
    vector<string> gameChars;
    string moves;
    Player player = Player(-1, -1);
    bool over = false;
    int n;

    Game() {
    }

    void playerTeleport() {
        int i = player.i;
        int j = player.j;
        int a = (rand()% n ) - n;
        int b = (rand()% n ) - n;
        gameCells[i][j].playerLeave();
        gameCells[i+a][j+b].playerJoin();
    }

    void moveRobot(int i, int j) {
        gameCells[i][j].robotLeave();
        if(i < player.i){
            i=i-1;
        }
        else if(i > player.i) {
            i =i+1;
        }
        if(j < player.j){
            j=j+1;
        }
        else if(j > player.j) {
            j=j-1;
        }
        gameCells[i][j].robotJoin();
    }

    
    void render(char c) {
        int dir = translateCharToDir(c);
        DEBUG(cout << "d13"<<endl;
            
        );
        movePlayer(dir);
        moveRobots();
        DEBUG(cout << (hasRobot() && !playerCaught()) <<endl;);
        if (hasRobot() && !playerCaught()) showTable();
    }

    void moveRobots() {
        for(int i = 0; i < n; i++) {
            for(int j = 0 ; j < n; j++) {
                if(gameCells[i][j].isRobot()){
                    moveRobot(i, j);
                }
            }
        }
    }

    void gameover() {
        return playerCaught() ? win() : lose();
    }

    void update() {
        for(int i = 0; i < n; i++) {
            for(int j = 0 ; j < n; j++) {
                gameCells[i][j].update();
            }
        }
    }

    void run() {
        for(char c : moves) {
            DEBUG(
                cout << "d11";
            )

            render(c);

            DEBUG(
                cout << "d10"
            );
            
            if (!hasRobot() || playerCaught()) return gameover();
        }
    }

    void win() {
        printf("Player Wins!\n");
    }

    void lose() {
        printf("Robots Win!\n");
    }

    void execute() {
        getInput();

        run();
    }

    bool hasRobot() {
        for(int i = 0; i < n; i++) {
            for(int j = 0 ; j < n; j++) {
                if (gameCells[i][j].getRobots() != 1){ 
                    return true;
                }
            }
        }
        return false;
    }

    bool playerCaught() {
        for(int i = 0; i < n; i++) {
            for(int j = 0 ; j < n; j++) {
                if (gameCells[i][j].type() == CELL_LOSE) return true;
            }
        }
        return false;
    }

    void showTable() {
        for(int i = 0; i < n; i++) {
            for(int j = 0 ; j < n; j++) {
                printf("%c", translateCellToChar(i, j));
            }
            printf("\n");
        }

        printf("\n");
    }

    char translateCellToChar(int i, int j) {
        switch(gameCells[i][j].type()) {
            case CELL_EMPTY:
                return MAP_EMPTY;
            case CELL_PLAYER:
                return MAP_PLAYER;
            case CELL_ROBOT:
                return MAP_ROBOT;
            case CELL_TOXIC:
                return MAP_TOXIC;
            default:
                break;
        }
        return MAP_UNKNOWN;
    }

    void init() {
        cout << "d3"<<endl;
        gameCells.resize(n, vector<Cell>(n, Cell(false, false, 0)));
                cout << "d4"<<endl;

        gameChars.resize(n);
                cout << "d5"<<endl;

    }

    void getInput() {
        cin >> n;
        init();
        for(int i = 0 ; i < n; i++) {
            cin >> gameChars[i];  // char to -do
            cout<< "d1"<< endl;
        }
    
        cin >> moves;
    }

    void loadMap() {
        for(int i = 0 ; i < n; i++) {
            for(int j = 0; j < n; j++) {
                translateCharToCell(i, j);
            }
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
                return gameCells[i][j].getToxiced();
            default:
                return;
        }
    }

    int translateCharToDir(char c) {
        switch(c) {
            case 'H': case 'h':
                return DIR_LEFT;
            case 'Y': case 'y':
                return DIR_UP_LEFT;
            case 'K': case 'k':
                return DIR_UP;
            case 'U': case 'u':
                return DIR_UP_RIGHT;
            case 'L': case 'l':
                return DIR_RIGHT;
            case 'N': case 'n':
                return DIR_DOWN_RIGHT;
            case 'J': case 'j':
                return DIR_DOWN;
            case 'B': case 'b':
                return DIR_DOWN_LEFT;
            default:
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
        int i = player.i;
        int j = player.j;
        if(i-1 >= 0) {
            gameCells[i][j].playerLeave();
            gameCells[i-1][j].playerJoin();
            player.i = i-1;
        }
    }

    void playerMoveUpRight() {
        int i = player.i;
        int j = player.j;
        if (i-1 >= 0 && j+1 < n) {
            gameCells[i][j].playerLeave();
            gameCells[i-1][j+1].playerJoin();
            player.i = i-1;
            player.j = j+1;
        }
        
    }

    void playerMoveRight() {
        int i = player.i;
        int j = player.j;
        if (j+1 < n) 
        {
            gameCells[i][j].playerLeave();
            gameCells[i][j+1].playerJoin();
            player.j=j+1;
        }
        
    }

    void playerMoveDownRight() {
        int i = player.i;
        int j = player.j;
        if (i+1 < n && j+1 < n)
        {
            gameCells[i][j].playerLeave();
            gameCells[i+1][j+1].playerJoin();
            player.j = j+1;
            player.i=i+1;
        }
        
    }

    void playerMoveDown() {
        int i = player.i;
        int j = player.j;
        if (i+1 < n){
            gameCells[i][j].playerLeave();
            gameCells[i+1][j].playerJoin();
            player.i = i+1;
        }
    }

    void playerMoveDownLeft() {
        int n;//=
        int i = player.i;
        int j = player.j;
        if (i+1 < n && j-1 >= 0){
            gameCells[i][j].playerLeave();
            gameCells[i+1][j-1].playerJoin();
            player.i=i+1;
            player.j=j-1;
        }
    }

} Game;


int main(int argc, char const *argv[]) {
    int seed = atoi(argv[1]);
    srand(seed);
    
    Game game = Game();
    cout << "d8"<<endl;
    game.execute();
    
}



