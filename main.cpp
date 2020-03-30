#include <fstream>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool palindrom(const char* s)
{
    
    int n = strlen(s);
    bool k = true;
    int y = 1;
    for (int i = 0; i < n / 2; i++)
    {
        if (s[n - 1 - i] != '.') {
            if (s[i] != s[n - y - i])
            {
                k = false;
                break;
            }
        }
        else
        {
            y = 2;
        }
    }
    return k;
}
int main(int argc, char* argv[]) {
    setlocale(LC_ALL, "Russian");
    string temp;
    std::vector <string> vec;

    std::ifstream fl(argv[1]);
    ofstream of("vivod.txt");

    if (!fl)
    {
        std::cout << "File not found" << std::endl;
        system("pause");
        return 1;
    }
    else
        while (fl >> temp)
            vec.push_back(temp);

    fl.close();

    for (string el : vec) {
        //char* s = new char[el.length() + 1];
        //strcpy(s, el.c_str());
        if (palindrom(el.c_str())) of << el << ' ';
    }
    of.close();
	return 0;
}