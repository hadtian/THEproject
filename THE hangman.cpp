#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>
#include <algorithm>

#ifdef _WIN32
#include <windows.h>
#endif

using namespace std;

const int MAX_WRONG = 7;

//clear screen
void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

//pjay sound//
void playSuccess() {
#ifdef _WIN32
    Beep(1000, 150);
#else
    cout << "\a";
#endif
}

void playFail() {
#ifdef _WIN32
    Beep(400, 300);
#else
    cout << "\a";
#endif
}

//main menu
void showMainMenu() {
    clearScreen();
    cout << R"(                           
             _________________________   ▄▄▄▄▄▄
            | IM SANA RAJABI HELP ME! |  |    █
            ¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯\\  °    █            ▒▒▒▒▒▒▒▒
               █▄██▄█                  \\O/   █           ▒▒▌▒▒▐▒▒▌▒
      █▄█▄█▄█▄█▐█┼██▌█▄█▄█▄█▄█          |     █            ▒▀▄▒▌▄▀▒
      ███┼█████▐████▌█████┼███         / \\   █               ██
░░░░░░█████████▐████▌█████████░░░░░░████████████░░░░░░░░░░░░░██░░░░░░░░░░░░░░░░░
)" << endl;

    cout << "\nChoose a category:\n";
}

//hangman scenes
vector<string> hangmanScenes = {
R"(                                        ▄▄▄▄▄▄
                                             █
                                             █            ▒▒▒▒▒▒▒▒
               █▄██▄█                        █           ▒▒▌▒▒▐▒▒▌▒
      █▄█▄█▄█▄█▐█┼██▌█▄█▄█▄█▄█               █            ▒▀▄▒▌▄▀▒
      ███┼█████▐████▌█████┼███               █               ██
░░░░░░█████████▐████▌█████████░░░░░░████████████░░░░░░░░░░░░░██░░░░░░░░░░░░░░░░░
)",
R"(                                        ▄▄▄▄▄▄
                                        |    █
                                             █            ▒▒▒▒▒▒▒▒
               █▄██▄█                        █           ▒▒▌▒▒▐▒▒▌▒
      █▄█▄█▄█▄█▐█┼██▌█▄█▄█▄█▄█               █            ▒▀▄▒▌▄▀▒
      ███┼█████▐████▌█████┼███               █               ██
░░░░░░█████████▐████▌█████████░░░░░░████████████░░░░░░░░░░░░░██░░░░░░░░░░░░░░░░░
)",
R"(                                        ▄▄▄▄▄▄
                                        |    █
                                        O    █            ▒▒▒▒▒▒▒▒
               █▄██▄█                        █           ▒▒▌▒▒▐▒▒▌▒
      █▄█▄█▄█▄█▐█┼██▌█▄█▄█▄█▄█               █            ▒▀▄▒▌▄▀▒
      ███┼█████▐████▌█████┼███               █               ██
░░░░░░█████████▐████▌█████████░░░░░░████████████░░░░░░░░░░░░░██░░░░░░░░░░░░░░░░░
)",
R"(                                        ▄▄▄▄▄▄
                                        |    █
                                        O    █            ▒▒▒▒▒▒▒▒
               █▄██▄█                   |    █           ▒▒▌▒▒▐▒▒▌▒
      █▄█▄█▄█▄█▐█┼██▌█▄█▄█▄█▄█               █            ▒▀▄▒▌▄▀▒
      ███┼█████▐████▌█████┼███               █               ██
░░░░░░█████████▐████▌█████████░░░░░░████████████░░░░░░░░░░░░░██░░░░░░░░░░░░░░░░░
)",
R"(                                        ▄▄▄▄▄▄
                                        |    █
                                        O    █            ▒▒▒▒▒▒▒▒
               █▄██▄█                  /|    █           ▒▒▌▒▒▐▒▒▌▒
      █▄█▄█▄█▄█▐█┼██▌█▄█▄█▄█▄█               █            ▒▀▄▒▌▄▀▒
      ███┼█████▐████▌█████┼███               █               ██
░░░░░░█████████▐████▌█████████░░░░░░████████████░░░░░░░░░░░░░██░░░░░░░░░░░░░░░░░
)",
R"(                                        ▄▄▄▄▄▄
                                        |    █
                                        O    █            ▒▒▒▒▒▒▒▒
               █▄██▄█                  /|\   █           ▒▒▌▒▒▐▒▒▌▒
      █▄█▄█▄█▄█▐█┼██▌█▄█▄█▄█▄█               █            ▒▀▄▒▌▄▀▒
      ███┼█████▐████▌█████┼███               █               ██
░░░░░░█████████▐████▌█████████░░░░░░████████████░░░░░░░░░░░░░██░░░░░░░░░░░░░░░░░
)",
R"(                                        ▄▄▄▄▄▄
                                        |    █
                                        O    █            ▒▒▒▒▒▒▒▒
               █▄██▄█                  /|\   █           ▒▒▌▒▒▐▒▒▌▒
      █▄█▄█▄█▄█▐█┼██▌█▄█▄█▄█▄█         /     █            ▒▀▄▒▌▄▀▒
      ███┼█████▐████▌█████┼███               █               ██
░░░░░░█████████▐████▌█████████░░░░░░████████████░░░░░░░░░░░░░██░░░░░░░░░░░░░░░░░
)",
R"(                      _______________   ▄▄▄▄▄▄
                     | OUCH MY NECK! |  |    █
                      ¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯\  O    █            ▒▒▒▒▒▒▒▒
               █▄██▄█                  /|\   █           ▒▒▌▒▒▐▒▒▌▒
      █▄█▄█▄█▄█▐█┼██▌█▄█▄█▄█▄█         / \   █            ▒▀▄▒▌▄▀▒
      ███┼█████▐████▌█████┼███               █               ██
░░░░░░█████████▐████▌█████████░░░░░░████████████░░░░░░░░░░░░░██░░░░░░░░░░░░░░░░░
)"
};

//word bank
struct Category {
    string name;
    vector<string> words;
};

vector<Category> categories = {
    {"Classmates", {"sangachin", "basiri", "pirhajati", "sedghi", "farsian", "fooladvand", "daryaei"}},
    {"countries", {"israel", "thailand", "netherlands", "hungary", "bangladesh"}},
    {"Fruits", {"banana", "avocado", "peach", "tangerine", "watermelon"}}
};

//display lives
void displayLives(int lives) {
    cout << "Lives: ";
    for (int i = 0; i < lives; i++)
        cout << "♥ ";
    cout << "\n\n";
}

//main
int main() {
    srand(static_cast<unsigned>(time(nullptr)));

    // main menu
    showMainMenu();
    for (size_t i = 0; i < categories.size(); i++) {
        cout << i + 1 << ". " << categories[i].name << "\n";
    }

    int choice = 0;
    while (true) {
        cout << "Enter 1-" << categories.size() << ": ";
        cin >> choice;
        if (choice >= 1 && choice <= static_cast<int>(categories.size())) break;
    }

    vector<string> words = categories[choice - 1].words;
    string word = words[rand() % words.size()];
    string hidden(word.size(), '_');

    vector<char> used;
    int wrong = 0;
    bool win = false;

    while (wrong < MAX_WRONG) {
        clearScreen();
        cout << hangmanScenes[wrong] << "\n";
        displayLives(MAX_WRONG - wrong);

        cout << "Category: " << categories[choice - 1].name << "\n";
        cout << "Word: ";
        for (char c : hidden) cout << c << ' ';
        cout << "\n\nUsed letters: ";
        for (char c : used) cout << c << ' ';
        cout << "\n\nGuess a letter: ";

        char guess;
        cin >> guess;
        guess = tolower(guess);

        if (find(used.begin(), used.end(), guess) != used.end())
            continue;

        used.push_back(guess);

        bool correct = false;
        for (size_t i = 0; i < word.size(); i++) {
            if (word[i] == guess) {
                hidden[i] = guess;
                correct = true;
            }
        }

        if (correct)
            playSuccess();
        else {
            playFail();
            wrong++;
        }

        if (hidden == word) {
            win = true;
            break;
        }
    }

    clearScreen();
    cout << hangmanScenes[wrong] << "\n";
    displayLives(MAX_WRONG - wrong);

    if (win)
        cout << "\n YOU SURVIVED! THE WORD WAS: " << word << "\n";
    else
        cout << "\n GAME OVER! THE WORD WAS: " << word << "\n";

    cout << "\nPress Enter to exit...";
    cin.ignore();
    cin.get();

    return 0;
}
