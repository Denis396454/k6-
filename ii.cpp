#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    setlocale(LC_ALL, "RU");
    fstream fout;
    fout.open("a.cpp");
    if (!fout.is_open()) {
        cout << "Error";
    } else {
        fout << "#include <iostream>\n#include <fstream>\n#include <string>\n#include <variant>\n#include <Windows.h>\n#include <conio.h>\n#include <stdio.h>\nusing namespace std;\nHANDLE hConsole;\nint main(){\nhConsole = GetStdHandle(STD_OUTPUT_HANDLE);\nSetConsoleTextAttribute(hConsole, 10);\n";
    }
    string iy;
    cin >> iy;
    ifstream inputFile(iy);  // Открытие файла для чтения
    if (!inputFile) {
        cerr << "Не удалось открыть файл" << endl;
        return 1;  // Завершение программы с ошибкой
    }

    string line;
    while (getline(inputFile, line)) {  // Чтение файла построчно
        string input = line;
        if (input.substr(0, 1) == "s") {
            std::cout << line.size();
        } else if (line.substr(0, 1) == "}"){
	    if (!fout.is_open()) {
                cout << "Error";
            } else {
                fout << '}';
            }

	} else if (line.substr(0, 1) == "+") {
            cout << "+";
        } else if (line.size() >= 3 && line.substr(0, 3) == "for") {
            string op;
            for (int ttytt = 4; ttytt < input.size(); ttytt++) {
                op += input[ttytt];
            }
            if (!fout.is_open()) {
                cout << "Error";
            } else {
                fout << "\nfor ( int ttt=0; ttt <= " << op << "; ttt++) { ";
            }
        } else if (line.substr(0, 2) == "pi") {
            cout << 3.14;
        } else if (line.substr(0, 3) == "tea") {
            cout << "kettle tea secret version";
        } else if (line.substr(0, 3) == "var") {
            string otp;
            int yut = 0;
            string opp;
            for (int ttyttt = 4; ttyttt < input.size() && input[ttyttt] != '='; ttyttt++) {
                otp += input[ttyttt];
                yut = ttyttt;
            }
            for (int ttyttot = yut + 1; ttyttot < input.size() && input[ttyttot] != ';'; ttyttot++) {
                opp += input[ttyttot];
            }
            if (!fout.is_open()) {
                cout << "Error";
            } else {
                fout << "\nauto " << otp  << opp << ";\n";
            }
        } else if (line.substr(0, 3) == "cat") {
            cout << "cat";
        } else if (line.size() >= 5 && line.substr(0, 5) == "print") {
            string op;
            for (int ttytt = 6; ttytt < input.size(); ttytt++) {
                op += input[ttytt];
            }
            if (!fout.is_open()) {
                cout << "Error";
            } else {
                fout << "\ncout << " << op << " << endl;\n";
            }
        }  else if (line.size() >= 5 && line.substr(0, 5) == "color") {
            string op;
            for (int ttytt = 6; ttytt < input.size(); ttytt++) {
                op += input[ttytt];
            }
            if (!fout.is_open()) {
                cout << "Error";
            } else {
                fout << "\nSetConsoleTextAttribute(hConsole, " << op << ");";
            }
        } else if (line.size() >= 10 && line.substr(0, 11) == "console.log") {
            for (size_t ii = 12; ii < line.size(); ++ii) {
                cout << line[ii];
            }
            cout << endl;  // Переход на новую строку после вывода
        } else {
            cout << "error";
        }
    }

    inputFile.close();
    if (!fout.is_open()) {
        cout << "Error";
    } else {
        fout << "\nreturn 0;\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n}";
    }
    fout.close();
    return 0;
}