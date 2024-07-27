#include <iostream>
using namespace std;
void notes(int amount)
{
    int notes[9] = {2000, 500, 200, 100, 50, 20, 10, 5, 1};
    int NoteCounter[9] = {0};
    for (int i = 0; i < 9; i++)
    {
        if (amount >= notes[i])
        {
            NoteCounter[i] = amount / notes[i];
            amount = amount % notes[i];
        }
    }
    for (int i = 0; i < 9; i++)
    {
        if (NoteCounter[i] != 0)
        {
            cout << notes[i] << " :" << NoteCounter[i] << endl;
        }
    }
}
int main()
{
    int amount = 0;
    cout << "Enter your amount" << endl;
    cin >> amount;
    notes(amount);
}