#include <iostream>
#include <Windows.h>
#include <string>

using namespace std;

int main() {
    setlocale(LC_ALL, "RUS");

    cout << "Введите строчку для поиска символов: ";
    string stroka;
    getline(cin, stroka);

    cout << "Введите символы для поиска в строке: ";
    string simvol;
    getline(cin, simvol);

    HINSTANCE hDLL = LoadLibrary(L"practLib.dll");
    typedef bool (*serchstr)(const char*, const char*);

    serchstr findCharsInString = (serchstr)GetProcAddress(hDLL, "serchstr");

    bool res = findCharsInString(stroka.c_str(), simvol.c_str());

    if (res) {
        cout << "Все указаные символы '" << simvol << "'" <<" найдены в строке '" << stroka << "' "<< endl;
    }
    else {
        cout << "Не все указанные символы найдены в данной строке" << endl;
    }

    FreeLibrary(hDLL);

    return 0;
}
