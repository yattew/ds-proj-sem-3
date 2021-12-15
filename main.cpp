#include <bits/stdc++.h>
#include "helper_functions.h"
#include "interpreter.h"
using namespace std;

int main(int argc, char *argv[])
{
    cout << endl
         << "Data Structures Lab Project v1.0 coded in C++\nInterpreter has been implemented using the stack data structure." << endl;
    cout << "Group Members are - \n1. Arpit Jain\n2. Nishttha Saharkar\n3. Simran Ahuja\n4. Yathansh Tewatia" << endl
         << endl;
    Interpreter I;
    if (argc == 1)
    {
        cout << "Type 'exit' to quit" << endl;
        while (true)
        {
            string in;
            cout << ">> ";
            getline(cin, in, '\n');
            I.interpret(in);
        }
    }
    char *name = *(++argv);
    ifstream file(name);
    string temp;
    while (file >> temp)
        I.interpret(temp);
}