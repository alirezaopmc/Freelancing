#include <iostream>
#include <fstream>
#include <conio.h>
#include <time.h>
using namespace std;




// Map 
const int N = 20;
int map[N][N];
#define BLINKYCAUGHT   -5
#define INKYCAUGHT     -4
#define CLYDECAUGHT    -3
#define PINKYCAUGHT    -2
#define SPAWNPOINT     -1
#define EMPTY           0
#define PACMAN          1
#define DOT             2
#define WALL            3
#define PINKYDOT        4
#define PINKYEMPTY      5
#define CLYDEDOT        6
#define CLYDEEMPTY      7
#define INKYDOT         8
#define INKYEMPTY       9
#define BLINKYDOT      10
#define BLINKYEMPTY    11


// Positions
int pacX    = -1;
int pacY    = -1;
int pinkyX  = -1;
int pinkyY  = -1;
int clydeX  = -1;
int clydeY  = -1;
int inkyX   = -1;
int inkyY   = -1;
int blinkyX = -1;
int blinkyY = -1; 

int spawnX  = -1;
int spawnY  = -1;

// Game properties
int gameoverReason = -1;
int turn = 0;
int score = 0;
int maxScore = 0;
const int Gap = 10;
int lastShadow = 3;

// Game States
bool running = true;

// Move
int moveX = -1;
int moveY = -1;

int pinkyMoveX  = -1;
int pinkyMoveY  = -1;
int clydeMoveX  = -1;
int clydeMoveY  = -1;
int inkyMoveX   = -1;
int inkyMoveY   = -1;
int blinkyMoveX = -1;
int blinkyMoveY = -1;

// Difficulty
int difficulty = 0;
#define EASY    0
#define NORMAL  1
#define HARD    2



// Prototypes

//Menu
void menu();
void difficultySelector();
void mapSelector();
void loadMap(string path);
void findPacman();
void findSpawn();


// Initialization
void init();

// Game Time
void run();
void getMove();
bool translateMove(char c);

// Pacman and Shadows
void renderPacman();
bool logicCheck();
void renderShadows();
bool pacmanCanMove();
void movePacman();
void spawnShadow();
void moveShadows();
int nextShadow();
void shadowsEasyMove();
void shadowsNormalMove();
void shadowsHardMove();

// Easy
void pinkyEasyMove();
void clydeEasyMove();
void inkyEasyMove();
void blinkyEasyMove();

// Normal
void pinkyNormalMove();
void clydeNormalMove();
void inkyNormalMove();
void blinkyNormalMove();

// Hard
void pinkyHardMove();
void clydeHardMove();
void inkyHardMove();
void blinkyHardMove();

void over();
void caughtBy(string name);
void showGame();
char translateMap(int x);



int main() {
    init();
    menu();
    while(running) {
        run();
    }
    over();
}

void init() {
    srand(time(0));
}

void menu() {
    difficultySelector();
    mapSelector();
}

void difficultySelector() {
    printf("Select the difficulty:\n");
    printf("1. East\n");
    printf("2. Normal\n");
    
    int c;
    cin >> c;
    if (c > 0 && c < 3) difficulty = c-1;
    else {
        printf("Wrong Input\n");
        return menu();
    }
}

void mapSelector() {
    printf("Select the map:\n");
    printf("maze\n");
    printf("hell\n");

    string mapPath;
    cin >> mapPath;

    loadMap(mapPath + ".txt");
}


void loadMap(string path) {
    ifstream fin(path);

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            fin >> map[i][j];
            if (map[i][j] == DOT) maxScore++;
        }
    }

    fin.close();

    findPacman();
    findSpawn();
}

void findPacman() {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if (map[i][j] == PACMAN) {
                pacX = i;
                pacY = j;
                return;
            }
        }
    }
}

void findSpawn() {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if (map[i][j] == SPAWNPOINT) {
                spawnX = i;
                spawnY = j;
                return;
            }
        }
    }
}

void run() {
    turn++;
    getMove();
    renderPacman();
    if (! logicCheck()) return;
    renderShadows();
    if (! logicCheck()) return;
    showGame();
}

void getMove() {
    char c;
    c = getch();

    if (! translateMove(c)) {
        printf("Invalid Move\n");
        return getMove();
    }
}

bool translateMove(char c) {
    switch (c) {
        case 'U': case 'u':
            moveX = -1;
            moveY =  0;
            break;
        case 'D': case 'd':
            moveX = +1;
            moveY =  0;
            break;
        case 'L': case 'l':
            moveX =  0;
            moveY = -1;
            break;
        case 'R': case 'r':
            moveX =  0;
            moveY = +1;
            break;
        default:
            moveX = -1;
            moveY = -1;
    }

    return ! (moveX == -1 && moveY == -1);
}

void renderPacman() {
    if (pacmanCanMove()) {
        movePacman();
    }
}

bool pacmanCanMove() {
    int finalX = pacX + moveX;
    int finalY = pacY + moveY;
    return (
        (finalX >= 0 && finalX < 20 && finalY >= 0 && finalY < 20)
        &&
        (map[finalX][finalY] != WALL)
    );
}

void movePacman() {
    int finalX = pacX + moveX;
    int finalY = pacY + moveY;

    // Empty
    if (map[finalX][finalY] == EMPTY) {
        map[finalX][finalY] = PACMAN;
        map[pacX][pacY] = EMPTY;
        pacX = finalX;
        pacY = finalY;
        return;
    }

    // Dot
    if (map[finalX][finalY] == DOT) {
        map[finalX][finalY] = PACMAN;
        map[pacX][pacY] = EMPTY;
        pacX = finalX;
        pacY = finalY;
        score++;
        return;
    }
    
    // Shadow
    if (map[finalX][finalY] >= 4) {
        // map[finalX][finalY] /= -2;
        gameoverReason = -map[finalX][finalY] / 2;
        // map[pacX][pacY] = EMPTY;
        // pacX = finalX;
        // pacY = finalY;
        return;
    }
}

bool logicCheck() {
    return running = ! (gameoverReason < -1 || score == maxScore);
}

void renderShadows() {
    spawnShadow();
    moveShadows();
}

void spawnShadow() {
    if (turn % Gap == 0 && turn < 40) {
        map[spawnX][spawnY] = nextShadow();

        switch(lastShadow) {
            case PINKYEMPTY:
                pinkyX = spawnX;
                pinkyY = spawnY;
                break;
            case CLYDEEMPTY:
                clydeX = spawnX;
                clydeY = spawnY;
                break;
            case INKYEMPTY:
                inkyX = spawnX;
                inkyY = spawnY;
                break;
            case BLINKYEMPTY:
                blinkyX = spawnX;
                blinkyY = spawnY;
                break;
            default:
                return;
        }
    }
}

void moveShadows() {
    switch (difficulty) {
        case EASY:
            shadowsEasyMove();
            break;
        case NORMAL:
            shadowsNormalMove();
            break;
        case HARD:
            shadowsHardMove();
            break;
        default:
            return;
    }
}

void shadowsEasyMove() {
    // asghar kasif
    pinkyEasyMove();
    clydeEasyMove();
    inkyEasyMove();
    blinkyEasyMove();
}

void shadowsNormalMove() {
    // asghar tamiz shod
    pinkyNormalMove();
    clydeNormalMove();
    inkyNormalMove();
    blinkyNormalMove();
}

void shadowsHardMove() {
    
}

// Easy Move
void pinkyEasyMove() {
    int x = rand() % 4;

    if (x == 0) {
        // UP
        pinkyMoveX = -1;
        pinkyMoveY =  0;
    }
    
    if (x == 1) {
        // DOWN
        pinkyMoveX = +1;
        pinkyMoveY =  0;
    }
    
    if (x == 2) {
        // LEFT
        pinkyMoveX =  0;
        pinkyMoveY = -1;
    }
    
    if (x == 3) {
        // RIGHT
        pinkyMoveX =  0;
        pinkyMoveY = +1;
    }

    int finalX = pinkyX + pinkyMoveX;
    int finalY = pinkyY + pinkyMoveY;

    if (map[finalX][finalY] != WALL
        &&
        finalX >= 0 && finalX < N
        &&
        finalY >= 0 && finalY < N
    ) {
        // EMPTY
        if (map[finalX][finalY] == EMPTY) {
            map[finalX][finalY] = PINKYEMPTY;
            map[pinkyX][pinkyY] = (map[pinkyX][pinkyY] == PINKYEMPTY ? EMPTY : DOT);
            pinkyX = finalX;
            pinkyY = finalY;
        }

        // DOT
        if (map[finalX][finalY] == DOT) {
            map[finalX][finalY] = PINKYDOT;
            map[pinkyX][pinkyY] = (map[pinkyX][pinkyY] == PINKYEMPTY ? EMPTY : DOT);
            pinkyX = finalX;
            pinkyY = finalY;
        }


        // SHADOW
        if (map[finalX][finalY] >= 4) {
            return;
        }

        // PACMAN
        if (map[finalX][finalY] == PACMAN) {
            gameoverReason = PINKYEMPTY / -2;
        }
    }
}

void clydeEasyMove() {
    int x = rand() % 4;

    if (x == 0) {
        // UP
        clydeMoveX = -1;
        clydeMoveY =  0;
    }
    
    if (x == 1) {
        // DOWN
        clydeMoveX = +1;
        clydeMoveY =  0;
    }
    
    if (x == 2) {
        // LEFT
        clydeMoveX =  0;
        clydeMoveY = -1;
    }
    
    if (x == 3) {
        // RIGHT
        clydeMoveX =  0;
        clydeMoveY = +1;
    }

    int finalX = clydeX + clydeMoveX;
    int finalY = clydeY + clydeMoveY;

    if (map[finalX][finalY] != WALL
        &&
        finalX >= 0 && finalX < N
        &&
        finalY >= 0 && finalY < N
    ) {
        // EMPTY
        if (map[finalX][finalY] == EMPTY) {
            map[finalX][finalY] = CLYDEEMPTY;
            map[clydeX][clydeY] = (map[clydeX][clydeY] == CLYDEEMPTY ? EMPTY : DOT);
            clydeX = finalX;
            clydeY = finalY;
        }

        // DOT
        if (map[finalX][finalY] == DOT) {
            map[finalX][finalY] = CLYDEDOT;
            map[clydeX][clydeY] = (map[clydeX][clydeY] == CLYDEEMPTY ? EMPTY : DOT);
            clydeX = finalX;
            clydeY = finalY;
        }


        // SHADOW
        if (map[finalX][finalY] >= 4) {
            return;
        }

        // PACMAN
        if (map[finalX][finalY] == PACMAN) {
            gameoverReason = CLYDEEMPTY / -2;
        }
    }
}

void inkyEasyMove() {
    int x = rand() % 4;

    if (x == 0) {
        // UP
        inkyMoveX = -1;
        inkyMoveY =  0;
    }
    
    if (x == 1) {
        // DOWN
        inkyMoveX = +1;
        inkyMoveY =  0;
    }
    
    if (x == 2) {
        // LEFT
        inkyMoveX =  0;
        inkyMoveY = -1;
    }
    
    if (x == 3) {
        // RIGHT
        inkyMoveX =  0;
        inkyMoveY = +1;
    }

    int finalX = inkyX + inkyMoveX;
    int finalY = inkyY + inkyMoveY;

    if (map[finalX][finalY] != WALL
        &&
        finalX >= 0 && finalX < N
        &&
        finalY >= 0 && finalY < N
    ) {
        // EMPTY
        if (map[finalX][finalY] == EMPTY) {
            map[finalX][finalY] = INKYEMPTY;
            map[inkyX][inkyY] = (map[inkyX][inkyY] == INKYEMPTY ? EMPTY : DOT);
            inkyX = finalX;
            inkyY = finalY;
        }

        // DOT
        if (map[finalX][finalY] == DOT) {
            map[finalX][finalY] = INKYDOT;
            map[inkyX][inkyY] = (map[inkyX][inkyY] == INKYEMPTY ? EMPTY : DOT);
            inkyX = finalX;
            inkyY = finalY;
        }


        // SHADOW
        if (map[finalX][finalY] >= 4) {
            return;
        }

        // PACMAN
        if (map[finalX][finalY] == PACMAN) {
            gameoverReason = INKYEMPTY / -2;
        }
    }

}

void blinkyEasyMove() {
    int x = rand() % 4;

    if (x == 0) {
        // UP
        blinkyMoveX = -1;
        blinkyMoveY =  0;
    }
    
    if (x == 1) {
        // DOWN
        blinkyMoveX = +1;
        blinkyMoveY =  0;
    }
    
    if (x == 2) {
        // LEFT
        blinkyMoveX =  0;
        blinkyMoveY = -1;
    }
    
    if (x == 3) {
        // RIGHT
        blinkyMoveX =  0;
        blinkyMoveY = +1;
    }

    int finalX = blinkyX + blinkyMoveX;
    int finalY = blinkyY + blinkyMoveY;

    if (map[finalX][finalY] != WALL
        &&
        finalX >= 0 && finalX < N
        &&
        finalY >= 0 && finalY < N
    ) {
        // EMPTY
        if (map[finalX][finalY] == EMPTY) {
            map[finalX][finalY] = BLINKYEMPTY;
            map[blinkyX][blinkyY] = (map[blinkyX][blinkyY] == BLINKYEMPTY ? EMPTY : DOT);
            blinkyX = finalX;
            blinkyY = finalY;
        }

        // DOT
        if (map[finalX][finalY] == DOT) {
            map[finalX][finalY] = BLINKYDOT;
            map[blinkyX][blinkyY] = (map[blinkyX][blinkyY] == BLINKYEMPTY ? EMPTY : DOT);
            blinkyX = finalX;
            blinkyY = finalY;
        }


        // SHADOW
        if (map[finalX][finalY] >= 4) {
            return;
        }

        // PACMAN
        if (map[finalX][finalY] == PACMAN) {
            gameoverReason = BLINKYEMPTY / -2;
        }
    }
}

// Normal Move
void pinkyNormalMove() {

}

void clydeNormalMove() {

}

void inkyNormalMove() {

}

void blinkyNormalMove() {

}

// Hard Move
void pinkyHardMove() {

}

void clydeHardMove() {

}

void inkyHardMove() {

}

void blinkyHardMove() {

}


int nextShadow() {
    lastShadow += 2;
    return lastShadow;
}

void over() {
    if (gameoverReason == BLINKYCAUGHT) {
        caughtBy("Blinky");
    }

    if (gameoverReason == INKYCAUGHT) {
        caughtBy("Inky");
    }

    if (gameoverReason == CLYDECAUGHT) {
        caughtBy("Clyde");
    }

    if (gameoverReason == PINKYCAUGHT) {
        caughtBy("Pinky");
    }

    if (gameoverReason == -1) {
        cout << "You won!" << endl;
    }

    cout << "Your score is " << score << endl;
}

void caughtBy(string name) {
    cout << "Pacman caught by " << name << endl;
}

void showGame() {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            printf("%c", translateMap(map[i][j]));
        }
        printf("\n");
    }
}

char translateMap(int x) {
    switch(x) {
        case EMPTY:
            return ' ';
        case PACMAN:
            return '@';
        case DOT:
            return '.';
        case WALL:
            return '#';
        case PINKYDOT:
            return 'P';
        case PINKYEMPTY:
            return 'p';
        case CLYDEDOT:
            return 'C';
        case CLYDEEMPTY:
            return 'c';
        case INKYDOT:
            return 'I';
        case INKYEMPTY:
            return 'i';
        case BLINKYDOT:
            return 'B';
        case BLINKYEMPTY:
            return 'b';
        default:
            return '!';
    }
}

