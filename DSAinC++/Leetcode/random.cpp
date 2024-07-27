#include <iostream>
using namespace std;

int main()
{
    for (char i = 'a'; i <= 'h'; i++)
    {
        if (i != 'h')
        {
            cout << i << endl;
        }
        if (i == 'h')
        {
            cout << i << endl;
            for (char i = 'a'; i <= 'e'; i++)
            {
                if (i != 'e')
                {
                    cout << 'h' << i << endl;
                }
                if (i == 'e')
                {
                    cout << 'h' << i << endl;
                    for (char i = 'a'; i <= 'l'; i++)
                    {
                        if (i != 'l')
                        {
                            cout << 'h' << 'e' << i << endl;
                        }
                        if (i == 'l')
                        {
                            cout << 'h' << 'e' << i << endl;
                            for (char i = 'a'; i <= 'l'; i++)
                            {
                                if (i != 'l')
                                {
                                    cout << 'h' << 'e' << 'l' << i << endl;
                                }
                                if (i == 'l')
                                {
                                    cout << 'h' << 'e' << 'l' << i << endl;
                                    for (char i = 'a'; i <= 'o'; i++)
                                    {
                                        if (i != 'o')
                                        {
                                            cout << 'h' << 'e' << 'l' << 'l' << i << endl;
                                        }
                                        if (i == 'o')
                                        {
                                            cout << 'h' << 'e' << 'l' << 'l' << i << " " << endl;
                                            for (char i = 'a'; i <= 'w'; i++)
                                            {
                                                if (i != 'w')
                                                {
                                                    cout << 'h' << 'e' << 'l' << 'l' << 'o' << " " << i << endl;
                                                }
                                                if (i == 'w')
                                                {
                                                    cout << 'h' << 'e' << 'l' << 'l' << 'o' << " " << 'w' << endl;
                                                    for (char i = 'a'; i <= 'o'; i++)
                                                    {
                                                        if (i != 'o')
                                                        {
                                                            cout << 'h' << 'e' << 'l' << 'l' << 'o' << " " << 'w' << i << endl;
                                                        }
                                                        if (i == 'o')
                                                        {
                                                            cout << 'h' << 'e' << 'l' << 'l' << 'o' << " " << 'w' << i << endl;
                                                            for (char i = 'a'; i <= 'r'; i++)
                                                            {
                                                                if (i != 'r')
                                                                {
                                                                    cout << 'h' << 'e' << 'l' << 'l' << 'o' << " " << 'w' << 'o' << i << endl;
                                                                }
                                                                if (i == 'r')
                                                                {
                                                                    cout << 'h' << 'e' << 'l' << 'l' << 'o' << " " << 'w' << 'o' << i << endl;
                                                                    for (char i = 'a'; i <= 'l'; i++)
                                                                    {
                                                                        if (i != 'l')
                                                                        {
                                                                            cout << 'h' << 'e' << 'l' << 'l' << 'o' << " " << 'w' << 'o' << 'r' << i << endl;
                                                                        }
                                                                        if (i == 'l')
                                                                        {
                                                                            cout << 'h' << 'e' << 'l' << 'l' << 'o' << " " << 'w' << 'o' << 'r' << i << endl;
                                                                            for (char i = 'a'; i <= 'd'; i++)
                                                                            {
                                                                                if (i != 'd')
                                                                                {
                                                                                    cout << 'h' << 'e' << 'l' << 'l' << 'o' << " " << 'w' << 'o' << 'r' << 'l' << i << endl;
                                                                                }
                                                                                if (i == 'd')
                                                                                {
                                                                                    cout << 'h' << 'e' << 'l' << 'l' << 'o' << " " << 'w' << 'o' << 'r' << 'l' << i << endl;
                                                                                }
                                                                            }
                                                                        }
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    return 0;
}
