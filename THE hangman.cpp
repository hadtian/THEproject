#include <iostream>  // ورودی و خروجی
#include <vector>  // وکتور 
#include <string>  
#include <ctime>  // گرفتن زمان برای رندوم بودن انتخاب
#include <cstdlib>
#include <algorithm>  

#ifdef _WIN32
#include <windows.h>  // صدا
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

//pjay sound
void playSuccess() {
#ifdef _WIN32
    Beep(1000, 150);
#else
    cout << "\a";
#endif
}
// تابع در کتابخانه ویندوز، دو پارامتر دریافت میکند پارامتر اول فرکانس پارامتر دوم مدت زمان پخش صدا
void playFail() {
#ifdef _WIN32
    Beep(400, 300);
#else
    cout << "\a";
#endif
}  // این دوتا صدا خیلی باهم فرق ندارن باید بعدا ببینم چشه

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
// تابع R برای چاپ یه استرینگ بزرگ و طولانی همونطور که هسته تا برای رفتن به خط بعد یا اسپیس نیاز به /t و /n و اینا نباشه 

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
// به تعدا کتگوریا با فور شماره میزنه و اسم کتگوری رو کنار شماره مینویسه تا لیست بشه
    int choice = 0; 
    while (true) {
        cout << "Enter 1-" << categories.size() << ": ";
        cin >> choice;
        if (choice >= 1 && choice <= static_cast<int>(categories.size())) break;
    } 
// میشد خیلی ساده توی سی‌اوت گیف از بین 1 تا 3 یکیو انتخاب کن چون تعداد کتگوریا مشخصن
    vector<string> words = categories[choice - 1].words;
    string word = words[rand() % words.size()];
    string hidden(word.size(), '_');

    vector<char> used;
    int wrong = 0;
    bool win = false;
// مقداردهی های اولیه
    while (wrong < MAX_WRONG) {
        clearScreen();
        cout << hangmanScenes[wrong] << "\n";
        displayLives(MAX_WRONG - wrong);
// این میاد به تعداد اشتباها اول صفحه رو تمیز میکنه بعد صحنه متناسب با تعداد اشتباها رو میذاره و تعداد جونارو میچینه
        cout << "Category: " << categories[choice - 1].name << "\n";
        cout << "Word: ";
        for (char c : hidden) cout << c << ' ';
        cout << "\n\nUsed letters: ";
        for (char c : used) cout << c << ' ';
        cout << "\n\nGuess a letter: ";

        char guess;
        cin >> guess;
        guess = tolower(guess);

        if (find(used.begin(), used.end(), guess) != used.end()) // چک کردن حروف وارد شده قبلی با پیمایش used که تکراری نباشن
            continue;

        used.push_back(guess); // میره ته لیست used

        bool correct = false;
        for (size_t i = 0; i < word.size(); i++) {
            if (word[i] == guess) {
                hidden[i] = guess;
                correct = true;
            } // دونه دونه حروف کلمه اصلی رو میگرده به ترتیب اگه حرف وارد شده باهاش یکی بود جایگزین میکنه با ایندکس متناسب توی وکتور hidden
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
        } // برای وقتی که کلمه کامل حدس زده میشه
    } // پایان وایل

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
