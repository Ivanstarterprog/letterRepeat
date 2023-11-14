/********************************************
* Автор - Нургазин И.В                      *
* Блок - 4                                  *
* Задача - 1                                *
* Ссылка - https://onlinegdb.com/vy2uXUjvI  *
********************************************/

#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;

void printStatsString(map<string, int> dict, string header) {
    string line;
    int counter;

    cout << header << endl;

    for (const auto& element : dict) {
        cout << element.first << ": " << element.second << endl;
    }
}

int main()
{
    int lenOfLine;
    char letter, nextLetter;
    string filename;
    string line;
    ifstream stream;
    map<string, int> oneLetterStats;
    map<string, int> twoLetterStats;

    setlocale(LC_CTYPE, "");

    cout << "Введите название файла: ";
    while (true) {
        cin >> filename;
        stream.open(filename);

        if (stream.is_open()) {
            break;
        }
        cout << "Файл не найден\nВведите название файла: ";
    }
    
    while (getline(stream, line)) {
        lenOfLine = line.length();

        for (int indOfLetter = 0; indOfLetter < lenOfLine; ++indOfLetter) {
            letter = line[indOfLetter];

            if ( (int)letter != 32) {
                string letterString{ letter };
                oneLetterStats[letterString] += 1;

                if (indOfLetter + 1 < lenOfLine) {
                    nextLetter = line[indOfLetter + 1];
                    
                    if (nextLetter != ' ') {
                        string twoLetters = string() + letter + nextLetter;
                        twoLetterStats[twoLetters] += 1;
                    }
                }
            }
        }
    }
    printStatsString(oneLetterStats, "Одиночные буквы");
    printStatsString(twoLetterStats, "Буквенные сочетания");
    
    system("pause");
}
