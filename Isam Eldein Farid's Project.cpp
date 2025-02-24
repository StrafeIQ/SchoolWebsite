// Isam Eldein Farid's Project.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <windows.h>  // For color text on Windows
#include <string>
#include <thread>
#include <chrono>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

// Function to set text color in the console (Windows)
void setColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

// ASCII Art is cool right bruv??? if u say no man u don't have a taste in visuals
void printIntro() {
    setColor(9);  // Set text color to blue
    cout << "******************************\n";
    cout << "*     Isam Eldein Farid      *\n";
    cout << "*   Games I made in my free  *\n";
    cout << "*         time!              *\n";
    cout << "******************************\n\n";
}

// Function to ask a question and check the answer
void askQuestion(string question, string options[], string correctAnswer) {
    setColor(10);  // Question text green
    cout << question << endl;
    for (int i = 0; i < 4; i++) { // Loop for each option
        setColor(14);  // Yellow for options
        cout << (i + 1) << ". " << options[i] << endl;
    }

    int answer;
    cout << "Choose the correct option (1/2/3/4): ";
    cin >> answer;
    setColor(15);  // White color

    if (options[answer - 1] == correctAnswer) {
        setColor(2);  // Green for correct
        cout << "Correct! Well done, gamer!\n\n";
    }
    else {
        setColor(12);  // Red for wrong
        cout << "Wrong! The correct answer is: " << correctAnswer << "\n\n";
    }
}

// Function to make computer move (randomly chosen)
int getComputerMove(char board[3][3]) {
    vector<int> availableMoves;

    // Collect all empty positions
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] != 'X' && board[i][j] != 'O') {
                availableMoves.push_back(i * 3 + j + 1);
            }
        }
    }

    // Randomly choose an empty position for the computer's move
    srand(time(0));
    return availableMoves[rand() % availableMoves.size()];
}

// Tic-Tac-Toe Game with computer opponent
void playTicTacToe() {
    cout << "\nTic-Tac-Toe Game\n";
    char board[3][3] = { {'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'} };
    int player = 1; // Player 1 starts
    int choice;
    char mark;

    while (true) {
        system("cls");
        cout << "Tic-Tac-Toe Game\n";
        cout << "Player 1 [X] - Computer [O]\n\n";
        cout << "Player " << player << ", it's your turn.\n";
        if (player == 1) mark = 'X';
        else mark = 'O';

        // Display board with custom colors for X and O
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] == 'X') {
                    setColor(11);  // Cyan for X
                }
                else if (board[i][j] == 'O') {
                    setColor(12);  // Red for O
                }
                else {
                    setColor(15);  // White for empty spaces
                }
                cout << board[i][j] << " ";
            }
            cout << endl;
        }

        // Get player move if it's player 1's turn
        if (player == 1) {
            cout << "Enter a position (1-9): ";
            cin >> choice;
        }
        else {
            // Get computer move
            choice = getComputerMove(board);
            cout << "Computer chooses position: " << choice << endl;
            this_thread::sleep_for(chrono::seconds(1)); // Delay for effect
        }

        // Check if the position is valid
        if (choice < 1 || choice > 9 || board[(choice - 1) / 3][(choice - 1) % 3] == 'X' || board[(choice - 1) / 3][(choice - 1) % 3] == 'O') {
            cout << "Invalid move. Try again.\n";
            this_thread::sleep_for(chrono::seconds(1));
            continue;
        }

        // Update the board
        board[(choice - 1) / 3][(choice - 1) % 3] = mark;

        // Check for winner
        for (int i = 0; i < 3; i++) {
            if ((board[i][0] == board[i][1] && board[i][1] == board[i][2]) || (board[0][i] == board[1][i] && board[1][i] == board[2][i])) {
                if (player == 1) {
                    cout << "Player " << player << " wins!\n";
                }
                else {
                    cout << "Computer wins!\n";
                }
                return;
            }
        }

        if (board[0][0] == board[1][1] && board[1][1] == board[2][2] || board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
            if (player == 1) {
                cout << "Player " << player << " wins!\n";
            }
            else {
                cout << "Computer wins!\n";
            }
            return;
        }

        // Check for draw
        bool draw = true;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] != 'X' && board[i][j] != 'O') {
                    draw = false;
                }
            }
        }

        if (draw) {
            cout << "It's a draw!\n";
            return;
        }

        // Switch player
        player = (player == 1) ? 2 : 1;
    }
}


// Rock-Paper-Scissors Game
void playRockPaperScissors() {
    srand(time(0));
    string choices[] = { "Rock", "Paper", "Scissors" };
    int playerChoice, computerChoice;

    setColor(6);  // Set text color to yellow
    cout << "\nRock, Paper, Scissors Game\n";
    cout << "Enter 1 for Rock, 2 for Paper, or 3 for Scissors: ";
    cin >> playerChoice;

    if (playerChoice < 1 || playerChoice > 3) {
        setColor(12);  // Red for invalid choice
        cout << "Invalid choice. Try again.\n";
        return;
    }

    computerChoice = rand() % 3 + 1;
    cout << "You chose " << choices[playerChoice - 1] << " and the computer chose " << choices[computerChoice - 1] << ".\n";

    if (playerChoice == computerChoice) {
        setColor(3);  // Cyan for draw
        cout << "It's a draw!\n";
    }
    else if ((playerChoice == 1 && computerChoice == 3) || (playerChoice == 2 && computerChoice == 1) || (playerChoice == 3 && computerChoice == 2)) {
        setColor(2);  // Green for win
        cout << "You win!\n";
    }
    else {
        setColor(12);  // Red for loss
        cout << "You lose!\n";
    }
}

// Hangman Game
void playHangman() {
    string word = "programming";
    string guess(word.length(), '_');
    int attempts = 6;
    char letter;

    setColor(6);  // Set text color to yellow
    cout << "\nHangman Game\n";
    while (attempts > 0) {
        setColor(15);  // White color for word and attempts
        cout << "Word: " << guess << endl;
        cout << "Attempts left: " << attempts << endl;
        cout << "Enter a letter: ";
        cin >> letter;

        bool correct = false;
        for (int i = 0; i < word.length(); i++) {
            if (word[i] == letter && guess[i] == '_') {
                guess[i] = letter;
                correct = true;
            }
        }

        if (!correct) {
            attempts--;
            setColor(12);  // Red for wrong guess
            cout << "Incorrect guess. Try again.\n";
        }

        if (guess == word) {
            setColor(2);  // Green for correct word
            cout << "Congratulations, you guessed the word: " << word << endl;
            return;
        }
    }

    setColor(12);  // Red for game over
    cout << "Sorry, you're out of attempts. The word was: " << word << endl;
}

void annoyingQuiz() {
    // Here are the Questions, options, and correct answers
    string questions[] = {
        "What is an example of parasitism?",
        "Which of these is an example of mutualism?",
        "In commensalism, how does one organism benefit?",
        "What does symbiosis refer to?",
        "How does competition affect animals in the wild?",
        "What's my name? and what language is this"
    };

    string options[][4] = {
        {"A bird eating seeds from a plant", "A tick feeding on a dog's blood", "A bee pollinating a flower", "A lion and a zebra both eating grass"},
        {"A shark and a cleaner fish", "A lion and a zebra", "A wolf and a rabbit", "A mosquito and a human"},
        {"It harms the other organism", "Both organisms benefit", "One organism benefits and the other is unaffected", "Both organisms are unaffected"},
        {"Organisms of different species living together in a close relationship", "Competition between organisms", "A predator-prey relationship", "A single organism living alone"},
        {"It benefits both animals", "Both animals lose", "One animal wins, and the other loses", "It has no effect"},
        {"Isam Eldein Farid, C++", "Isam Eldein Farid, Python", "Isam Eldein Farid, C#", "Isam Eldein Farid, Erm Scratch"}
    };

    string answers[] = {
        "A tick feeding on a dog's blood",
        "A shark and a cleaner fish",
        "One organism benefits and the other is unaffected",
        "Organisms of different species living together in a close relationship",
        "One animal wins, and the other loses",
        "Isam Eldein Farid, C++"
    };

    // Here we will ask the Quiz questions
    for (int i = 0; i < 6; i++) {
        askQuestion(questions[i], options[i], answers[i]);
        this_thread::sleep_for(chrono::seconds(1)); // Delay for effect
    }
}

void openDinoGame() {
    ShellExecuteW(0, 0, L"https://xnottozic.github.io/SchoolWebsite/", 0, 0, SW_SHOWNORMAL);
}

// Function to choose the game
void chooseGame() {
    int gameChoice;
    setColor(10);  // Green color for the menu text
    cout << "Which game would you like to play?\n";
    cout << "1. Tic-Tac-Toe\n";
    cout << "2. Rock, Paper, Scissors\n";
    cout << "3. Hangman\n";
    cout << "4. Annoying Quiz\n";
    cout << "5. Play Dino Game (Opens in browser cuz I can't make it in console)\n";
    cout << "Enter the number of your choice: ";
    cin >> gameChoice;

    switch (gameChoice) {
    case 1:
        playTicTacToe();
        break;
    case 2:
        playRockPaperScissors();
        break;
    case 3:
        playHangman();
        break;
    case 4:
        annoyingQuiz();
        break;
    case 5:
        openDinoGame();
        break;
    default:
        cout << "Invalid choice. Exiting...\n";
        break;
    }

    Sleep(5000);
}

int main() {
    printIntro();
    chooseGame();
    setColor(13);  // Magenta color for closing message (cool effect)
    cout << "Thanks for playing! Hope you learned something new.\n";
    Sleep(1500);
    return 0;
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
