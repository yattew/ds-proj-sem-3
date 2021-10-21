#include <bits/stdc++.h>
using namespace std;
bool is_number(string s)
{
    if (s[0] == '-')
        s = s.substr(1);
    for (int i = 0; i < s.length(); i++)
        if (isdigit(s[i]) == false)
            return false;
    return true;
}
class Interpreter
{
public:
    stack<string> main_stack;
    unordered_map<string, string> user_words_dictionary;
    unordered_map<string, string> user_variables_dictionary;
    Interpreter() {}
    void interpret(const string &s)
    {
        vector<string> tokens = tokenize(s);
        unsigned int idx = 0;
        while (idx != tokens.size())
        {
            if (is_number(tokens[idx]))
            {
                main_stack.push(tokens[idx]);
            }
            else if (tokens[idx] == "+")
            {
            }
            else if (tokens[idx] == "-")
            {
            }
            else if (tokens[idx] == "*")
            {
            }
            else if (tokens[idx] == "/")
            {
            }
            else if (tokens[idx] == "%")
            {
            }
            else if (tokens[idx] == "dup")
            {
            }
            else if (tokens[idx] == "makeword")
            {
            }
            else if (tokens[idx] == "begin")
            {
            }
            else if (tokens[idx] == "variable")
            {
            }
            else if (tokens[idx] == "pop")
                pop();
            else if (tokens[idx] == "show")
                show();
            else if (tokens[idx] == "top")
                top();
            else
            {
                unordered_map<string, string>::iterator it = user_words_dictionary.find(tokens[idx]);
                if (it == user_words_dictionary.end())
                {
                    cout << "the word <" << tokens[idx] << "> is not defined" << endl;
                }
                else
                {
                    string word_string = it->second;
                    run_word(word_string);
                }
            }
            idx++;
        }
    }
    vector<string> tokenize(const string &s)
    {
        vector<string> tokens;
        string temp;
        for (auto x : s)
        {
            if (x == ' ')
            {
                if (temp.size() > 0)
                {
                    tokens.push_back(temp);
                    temp.clear();
                }
            }
            else
            {
                temp.push_back(x);
            }
        }
        tokens.push_back(temp);
        return tokens;
    }
    void add() {}
    void subtract() {}
    void multiply() {}
    void divide() {}
    void remainder() {}
    void dup() {}
    void compile_word() {}
    void run_word(string word_string) {}
    void top()
    {
        cout << main_stack.top() << endl;
    }
    void pop()
    {
        main_stack.pop();
    }
    void show()
    {
        stack<string> temp = main_stack;
        stack<string> helper;
        while (!temp.empty())
        {
            helper.push(temp.top());
            temp.pop();
        }
        cout << "<" << helper.size() << "> ";
        while (!helper.empty())
        {
            cout << helper.top() << " ";
            helper.pop();
        }
        cout << endl;
    }
};

int main(int argc, char **argv)
{
    Interpreter I;
    if (argc == 1)
    {
        while (true)
        {
            string in;
            cout << ">>";
            getline(cin, in, '\n');
            I.interpret(in);
        }
    }
    else
    {
    }
}