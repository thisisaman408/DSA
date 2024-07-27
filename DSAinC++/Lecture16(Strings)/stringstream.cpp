#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;
// string stream is used to calcucate the number of words in a string, for example, in
// aman is a physics teacher, here, there are 5 words, although we can calulate it, by count++ on
// each space, or when the next letter is coming but string stream help us to do it easily

int main()
{

    string s;
    cout << "Enter your string : " << endl;
    getline(cin, s);
    stringstream str(s);
    string temp; // used to store the different words in a string
    while (str >> temp)// this is syntax of using string stream
    {
        cout << temp << endl;
    }
    return 0;
}