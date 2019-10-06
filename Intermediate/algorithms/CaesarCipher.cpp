#include <iostream>
#include <string>
using namespace std;
char caesar(char);
int main()
{
    string input;
    do
    {
        cout << "Enter cipertext and press enter to continue." << endl;
        cout << "Enter blank line to quit." << endl;
        getline(cin, input);
        string output = "";
        for (int x = 0; x < input.length(); x++)
        {
            output += caesar(input[x]);
        }
        cout << output << endl;
    }
    while (!input.length() == 0);
} //end main
 
char caesar(char c)
{
    if (isalpha(c))
    {
        c = toupper(c); //use upper to keep from having to use two seperate for A..Z a..z
        c = (((c - 65) + 13) % 26) + 65;
    }
    //if c isn't alpha, just send it back.
    return c;
}
