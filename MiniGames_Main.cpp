#include "RussianRoulette.cpp"
#include "UlarTangga.cpp"

void Menu();
int startGameMenu();
void startRussianRoulette();
void startUlarTangga();

void Menu(){
    int choice;
    cout << "---===[ Select Game ]===---" << endl;
    cout << "1. Russian Roulette" << endl;
    cout << "2. Snakes and Ladders" << endl;
    cout << "3. Exit" << endl;
    cout << "-------------------------------------" << endl;
    cout << "Enter Your Choice: ";
    cin >> choice;

    switch(choice){
    case 1:
        startRussianRoulette();
        break;
    case 2:
        startUlarTangga();
        break;
    default:
        break;
    }
}

int startGameMenu(){
    int gameMode;
        cout << "1. Single Player (vs Computer)" << endl;
        cout << "2. Two Players" << endl;
        cout << "3. Exit Game" << endl;
        cout << "-------------------------------------" << endl;
        cout << "Enter your choice: ";
        cin >> gameMode;
        cout << "-------------------------------------" << endl;
        return gameMode;
}

void startRussianRoulette(){
    char playAgain;

    do {
        cout << "---===[ Russian Roulette Game ]===---" << endl;
        int gameMode = startGameMenu();
        switch(gameMode){
            case 1:
            playGame_RussianRoulette(true);
            break;
            case 2:
            playGame_RussianRoulette(false);
            break;
            default:
            cout << "Exiting game. Thanks for playing!" << endl;
            break;
        }

        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;

    }while(playAgain == 'y' || playAgain == 'Y');

    cout << "Thanks for playing!" << endl << endl;
    Menu();
}

void startUlarTangga(){
    srand(time(0));
    char playAgain;

    do {
        cout << "---===[ Snakes and Ladders Game ]===---" << endl;
        int gameMode = startGameMenu();
        switch(gameMode){
            case 1:
            playGame_UlarTangga(true);
            break;
            case 2:
            playGame_UlarTangga(false);
            break;
            default:
            cout << "Exiting game. Thanks for playing!" << endl;
            break;
        }

        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;

    }while(playAgain == 'y' || playAgain == 'Y');

    cout << "Thanks for playing!" << endl << endl;
    Menu();
}

int main(){
    Menu();
    return 0;
}