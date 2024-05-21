#include <iostream>
#include <cstdlib>
#include <ctime>
#include <map>

using namespace std;

const int WIN_POSITION = 30;

int rollDice() {
    return (rand() % 6) + 1;
}

void initializeBoard(map<int, int> &ladders, map<int, int> &snakes) {
    ladders[3] = 22;
    ladders[5] = 8;
    ladders[11] = 26;
    ladders[20] = 29;
    
    snakes[27] = 1;
    snakes[21] = 9;
    snakes[17] = 4;
    snakes[19] = 7;
}

void updatePlayerPosition(string playerName, int &playerPosition, int dice, const map<int, int> &ladders, const map<int, int> &snakes) {
    playerPosition += dice;
    if (playerPosition > WIN_POSITION) {
        playerPosition = WIN_POSITION - (playerPosition - WIN_POSITION);
    }

    if (ladders.find(playerPosition) != ladders.end()) {
        cout << playerName << " found a ladder! Climb up to " << ladders.at(playerPosition) << endl;
        playerPosition = ladders.at(playerPosition);
    } else if (snakes.find(playerPosition) != snakes.end()) {
        cout << playerName << " got bitten by a snake! Slide down to " << snakes.at(playerPosition) << endl;
        playerPosition = snakes.at(playerPosition);
    }

    cout << playerName << " is now at position " << playerPosition << endl;
    cout << "-------------------------------------" << endl;

}

void playerTurn(string playerName, int &playerPosition, const map<int, int> &ladders, const map<int, int> &snakes) {
    char roll;
    cout << playerName << ", press any char to roll the dice: ";
    cin >> roll;
    int dice = rollDice();
    cout << playerName << " rolled a " << dice << endl;
    updatePlayerPosition(playerName, playerPosition, dice, ladders, snakes);

}

void computerTurn(int &playerPosition, const map<int, int> &ladders, const map<int, int> &snakes) {
    int dice = rollDice();
    cout << "Computer rolled a " << dice << endl;
    updatePlayerPosition("Computer", playerPosition, dice, ladders, snakes);
}

void playSinglePlayerGame() {
    map<int, int> ladders;
    map<int, int> snakes;
    initializeBoard(ladders, snakes);

    int player1Position = 0;
    int player2Position = 0;
    bool player1Turn = true;

    while (player1Position < WIN_POSITION && player2Position < WIN_POSITION) {
        if (player1Turn) {
            playerTurn("Player 1", player1Position, ladders, snakes);
        } else {
            computerTurn(player2Position, ladders, snakes);
        }
        player1Turn = !player1Turn;
    }

    if (player1Position >= WIN_POSITION) {
        cout << "Congratulations, Player 1 wins!" << endl;
    } else {
        cout << "Congratulations, Computer wins!" << endl;
    }
}

void playMultiPlayerGame() {
    map<int, int> ladders;
    map<int, int> snakes;
    initializeBoard(ladders, snakes);

    int player1Position = 0;
    int player2Position = 0;
    bool player1Turn = true;

    while (player1Position < WIN_POSITION && player2Position < WIN_POSITION) {
        if (player1Turn) {
            playerTurn("Player 1", player1Position, ladders, snakes);
        } else {
            playerTurn("Player 2", player2Position, ladders, snakes);
        }
        player1Turn = !player1Turn;
    }

    if (player1Position >= WIN_POSITION) {
        cout << "Congratulations, Player 1 wins!" << endl;
    } else {
        cout << "Congratulations, Player 2 wins!" << endl;
    }
}

void playGame_UlarTangga(bool isSinglePlayer) {
    if (isSinglePlayer) {
        playSinglePlayerGame();
    } else {
        playMultiPlayerGame();
    }
}