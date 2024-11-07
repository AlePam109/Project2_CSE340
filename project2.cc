/*
 * Copyright (C) Mohsen Zohrevandi, 2017
 *               Rida Bazzi 2019
 * Do not share this file with anyone
 */
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include "lexer.h"
#include <set>
#include <map>
#include <vector>


using namespace std;
vector<string> terminals;
vector<string> nonTerminals;
set<String> uniqueSymbols;
LexicalAnalyzer lexer;
bool syntax_Error = false;   //Flag to indicate a syntax error


// read grammar
void ReadGrammar()
{
    Token token = lexer.GetToken();

    while (token.token_type != HASH)
    {
        if (token.token_type == ID)
        {
            std::string lhs = token.lexeme;
            if (uniqueSymBols.insert(lhs).second)
            {
                nonTerminals.push_bask(lhs)
            }

            // Expect an arrow (->) after the non-terminal
            token = lexer.GetToken();
            if (token.token_type != ARROW)
            {
                syntax_Error = true;
                cout << "SYNTAX ERROR !!!" << endl;
                return;
            }

            // Parse the right-hand side until we encounter a STAR
            token = lexer.GetToken();
            while (token.token_type != STAR)
            {
                if ((token.token_type == ERROR) || (token.token_type == END_OF_FILE))
                {
                    syntax_Error = true;
                    cout << "SYNTAX ERROR !!!" << endl;
                    return;
                }

                if (token.token_type == ID)
                {
                    std::string rhs = token.lexeme;
                    if (uniqueSymbols.insert(rhs).second)
                    {
                        terminals.push_back(rhs);
                    }
                }

                token = lexer.GetToken(); // Move to next symbol
            }  
        } else {
            syntax_Error = true;
            cout << "SYNTAX ERROR !!!" << endl;
            return;
        }

        token = lexer.GetToken();   // Move to next rule or HASH
    }
}

// Task 1
void Task1()
{
    cout << "1\n";
}

// Task 2
void Task2()
{
    cout << "2\n";
}

// Task 3
void Task3()
{
    cout << "3\n";
}

// Task 4
void Task4()
{
    cout << "4\n";
}

// Task 5
void Task5()
{
    cout << "5\n";
}

// Task 6
void Task6()
{
    cout << "5\n";
}
    
int main (int argc, char* argv[])
{
    int task;

    if (argc < 2)
    {
        cout << "Error: missing argument\n";
        return 1;
    }

    /*
       Note that by convention argv[0] is the name of your executable,
       and the first argument to your program is stored in argv[1]
     */

    task = atoi(argv[1]);
    
    ReadGrammar();  // Reads the input grammar from standard input
                    // and represent it internally in data structures
                    // ad described in project 2 presentation file

    switch (task) {
        case 1: Task1();
            break;

        case 2: Task2();
            break;

        case 3: Task3();
            break;

        case 4: Task4();
            break;

        case 5: Task5();
            break;
        
        case 6: Task6();
            break;

        default:
            cout << "Error: unrecognized task number " << task << "\n";
            break;
    }
    return 0;
}

