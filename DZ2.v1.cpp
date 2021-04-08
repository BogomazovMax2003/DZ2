// DZ2.v1.cpp 

#include <iostream>
#include<string>
#include<vector>
#include<stack>
#include <Windows.h>
#include<cmath>
using namespace std;
int Rang(char a)
{
    switch (a)
    {
    case '+': return 1;
    case '-': return 1;
    case '*': return 2;
    case '/': return 2;
    case '^': return 3;
    }
}


int main()
{
    setlocale(LC_ALL, "Russian");
    std::cout << "Введите пример:" << std::endl;
    stack <string> cifra;
    stack <char> znak;
    std::string str;
    std::cin >> str;
    int k = 0;
    int dopysk = 0;
    for (int i = 0; i < str.size(); i++) {
        int m = 0;
        if (str[i] == '0' or str[i] == '1' or str[i] == '2' or str[i] == '3' or str[i] == '4' or str[i] == '5' or str[i] == '6' or
            str[i] == '7' or str[i] == '8' or str[i] == '9' or str[i] == '*' or str[i] == '/' or
            str[i] == '+' or str[i] == '-' or str[i] == '^' or str[i] == '(' or str[i] == ')' or str[i] == '.' or str[i] == 'x')
        {
        }
        else {
            std::cout << "Пример введен неправиль.";
            dopysk++;
        }
        if ((str[i] == '*' or str[i] == '/' or str[i] == '+' or str[i] == '-' or str[i] == '^') and
            (str[i + 1] == '*' or str[i + 1] == '/' or str[i + 1] == '+' or str[i + 1] == '-' or str[i + 1] == '^'))
        {
            std::cout << "Пример введен неправиль.";
            dopysk++;
        }
        int skobki = 0;
        for (int i = 0; i < str.size(); i++) {
            if (str[i] == '(') {
                skobki++;
            }
            if (str[i] == ')') {
                skobki--;
            }
        }
        if (skobki != 0)
        {
            std::cout << "Пример введен неправиль.";
            dopysk++;
        }
        for (int i = 0; i < str.size(); i++) {
            int k2 = 0;
            int z = i;
            int t = 0;
            std::string a;
            if (str[i] >= '0' && str[i] <= '9') {
                while (k2 != 1) {
                    if ((str[z] >= '0' && str[z] <= '9') or str[z] == '.')
                        z++;
                    if (str[z] == '.') {
                        t++;
                    }
                    else {
                        k2++;
                        i = z;
                    }
                }
            }
            if (t > 1) {
                dopysk++;
            }
            t = 0;
        }
    }
    if (dopysk == 0) {
        for (size_t i = 0; i <= str.size(); i++) {
            k = 0;
            int z = i;
            std::string a;
            if (str[i] == 'x') {
                std::string ty;
                std::cout << "Введите х:" << std::endl;
                std::cin>> ty;
                cifra.push(ty);
            }
            if (str[i] >= '0' && str[i] <= '9') {
                while (k < 1) {
                    if ((str[z] >= '0' && str[z] <= '9') or str[z] == '.')
                        z++;
                    else {
                        a = str.substr(i, z);
                        cifra.push(a);
                        k++;
                        i = z;
                    }
                }
            }
            if (str[i] == '(' or str[i] == ')')
            {
                if (str[i] == '(') {
                    if (str[i - 1] >= '0' && str[i - 1] <= '9')
                        znak.push('*');
                    znak.push(str[i]);
                }
                else {
                    while (znak.top() != '(') {
                        std::string str12 = cifra.top();
                        cifra.pop();
                        std::string str13 = cifra.top();
                        cifra.pop();
                        double a1, a2, a3 = 0;
                        a1 = atof(str12.c_str());
                        a2 = atof(str13.c_str());
                        if (znak.top() == '+') {
                            a3 = a2 + a1;
                        }
                        if (znak.top() == '-') {
                            a3 = a2 - a1;
                        }
                        if (znak.top() == '*') {
                            a3 = a2 * a1;
                        }
                        if (znak.top() == '/') {
                            a3 = a2 / a1;
                        }
                        if (znak.top() == '^') {
                            a3 = pow(a2, a1);
                        }
                        std::string m = to_string(a3);
                        cifra.push(m);
                        znak.pop();
                    }
                    znak.pop();
                    if (str[i + 1] >= '0' && str[i + 1] <= '9')
                        znak.push('*');
                }
            }
            if (str[i] == '*' or str[i] == '/' or str[i] == '+' or str[i] == '-' or str[i] == '^') {
                int c = Rang(str[i]);
                if (znak.size() != 0) {
                    if (c <= Rang(znak.top())) {
                        while (znak.size() > 0 and c <= Rang(znak.top()) and znak.top() != '(') {
                            std::string str12 = cifra.top();
                            cifra.pop();
                            std::string str13 = cifra.top();
                            cifra.pop();
                            double a1, a2, a3 = 0;
                            a1 = atof(str12.c_str());
                            a2 = atof(str13.c_str());
                            if (znak.top() == '+') {
                                a3 = a2 + a1;
                            }
                            if (znak.top() == '-') {
                                a3 = a2 - a1;
                            }
                            if (znak.top() == '*') {
                                a3 = a2 * a1;
                            }
                            if (znak.top() == '/') {
                                a3 = a2 / a1;
                            }
                            if (znak.top() == '^') {
                                a3 = pow(a2, a1);
                            }
                            znak.pop();
                            std::string m = to_string(a3);
                            cifra.push(m);
                        }
                        znak.push(str[i]);
                    }
                }
                if (znak.size() != 0) {
                    if (c > Rang(znak.top())) {
                        znak.push(str[i]);
                    }
                }
                if (znak.size() == 0) {
                    znak.push(str[i]);
                }
            }
        }
            while (cifra.size() > 1) {
                std::string str12 = cifra.top();
                cifra.pop();
                std::string str13 = cifra.top();
                cifra.pop();
                double a1, a2, a3 = 0;
                a1 = atof(str12.c_str());
                a2 = atof(str13.c_str());
                if (znak.top() == '+') {
                    a3 = a2 + a1;
                }
                if (znak.top() == '-') {
                    a3 = a2 - a1;
                }
                if (znak.top() == '*') {
                    a3 = a2 * a1;
                }
                if (znak.top() == '/') {
                    a3 = a2 / a1;
                }
                if (znak.top() == '^') {
                    a3 = pow(a2, a1);
                }
                znak.pop();
                std::string m = to_string(a3);
                cifra.push(m);
            }
    std::cout << cifra.top();
    }
}
