#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

const int NMAX = 10;
int remainingBullet[NMAX] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
int bulletPlace[NMAX];
bool gameOver = false;

void initializeBulletPlace(){
    srand(time(0));
    for(int i = 0; i < 3; i++){
        bulletPlace[i] = rand() % NMAX + 1;
    }
}

void showRemainingBullet(){
    cout << "Remaining Bullet" << endl;
    for(int i = 0; i < NMAX; i++){
        cout << remainingBullet[i] << "  ";
    }
    cout << endl;
    cout << "-------------------------------------" << endl;
}

void resetGame(){
    for(int i = 0; i < NMAX; i++){
        remainingBullet[i] = i + 1;
    }
    initializeBulletPlace();
    gameOver = false;
}

bool checkRemainingBullet(int n){
    for(int i = 0; i < NMAX; i++){
        if(n == remainingBullet[i] && n != 0){
            return true;
        }
    }
    return false;
}

void ShootingBullet(int n, string Lose){
    for(int i = 0; i < NMAX; i++){
        if(n == bulletPlace[i]){
            cout << "Bang! " << Lose << " Loses!" << endl;
            gameOver = true;
            break;
        }else if(n == remainingBullet[i]){
            remainingBullet[i] = 0;
        }
    }

    if(!gameOver){
        showRemainingBullet();
    }
}


void playerChoice(string playerNumber){
    int numberChoice;
    do {
        cout << "Player " << playerNumber << ", choose a chamber: ";
        cin >> numberChoice;
        if(!checkRemainingBullet(numberChoice)) {
            cout << "Invalid input. Please enter a number between 1 and " << NMAX << " that hasn't been shot yet." << endl;
        }
    } while(!checkRemainingBullet(numberChoice));
        ShootingBullet(numberChoice, playerNumber);
}

void computerChoices(){
    int computerChoice;
    do{
        computerChoice = rand() % NMAX + 1;
    }while(!checkRemainingBullet(computerChoice));
    cout << "Computer chooses chamber: " << computerChoice << endl;
    ShootingBullet(computerChoice, "Computer");
}

void playGame_RussianRoulette(bool isSinglePlayer){
    int numberChoice;
    resetGame();
    showRemainingBullet();
    while(!gameOver){
        if(isSinglePlayer){
            playerChoice("Player 1");
            if(!gameOver){
                computerChoices();
            }
        } else {
            playerChoice("Player 1");
            if(!gameOver){
                playerChoice("Player 2");
            }
        }
    }
}
