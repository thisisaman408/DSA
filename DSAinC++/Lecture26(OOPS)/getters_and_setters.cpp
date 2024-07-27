#include <iostream>
using namespace std;
// it is recommended to alwasy put data members in private, it helps in data security,
// so it is recommended to use setters(to set the value of data member) & getters(to get the value of the data member)
// to set and get the value of the data members respectively, these are normal functions, nothing new

class Player
{
private:
    int score;
    int health;

public:
    // setter
    void setScore(int s)
    {
        score = s;
    }
    void setHealth(int h)
    {
        health = h;
    }

    // getters

    int getScore()
    {
        return score;
    }
    int getHealth()
    {
        return health;
    }
};

int main()
{
    Player Aman;
    Aman.setScore(100);//these are setters
    Aman.setHealth(90);
    cout << Aman.getScore();//these are getters
    cout << endl;
    cout << Aman.getHealth();
}

//this practice is better than directly using and modifying the data members of the class