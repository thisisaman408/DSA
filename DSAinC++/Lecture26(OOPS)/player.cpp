#include <iostream>
using namespace std;
/// passing class objects to functions!
class Player
{
private:
    int health;
    int age;
    int score;
    bool alive;
    string name;

public:
    // getters
    int getHealth()
    {
        return health;
    }
    int getAge()
    {
        return age;
    }
    int getScore()
    {
        return score;
    }
    int isAlive()
    {
        return alive;
    }

    string getName()
    {
        return name;
    }

    // setters
    void setHealth(int health)
    {
        this->health = health;
    }
    void setAge(int age)
    {
        this->age = age;
    }
    void setScore(int score)
    {
        this->score = score;
    }
    void setIsAlive(bool alive)
    {
        this->alive = alive;
    }
    void setName(string name)
    {
        this->name = name;
    }
    // this basically gives the value of the variable of the present class, not the present scope
};

int addScore(Player a, Player b)
{
    return (a.getScore() + b.getScore());
}

int averageAge(Player a, Player b)
{
    return ((a.getAge() + b.getAge()) / 2);
}
void areAll_alive(Player a, Player b)
{
    if (a.isAlive() == 1 && b.isAlive() == 1)
    {
        cout << "Yes, all are alive" << endl;
    }
    else
    {
        cout << "No, atleast one of these is dead" << endl;
    }
}

Player get_max_score_player(Player a, Player b)
{
    if (a.getScore() > b.getScore())
        return a;
    return b;
}

string most_handsome(Player a, Player b)
{
    if (a.getScore() > b.getScore())
    {
        return a.getName();
    }
    return b.getName();
}
int main()
{
    Player aman; // this is static memory allocatin
    aman.setAge(21);
    aman.setHealth(100);
    aman.setScore(90);
    aman.setIsAlive(true);
    aman.setName("Aman Kumar");

    Player ashu;
    ashu.setAge(22);
    ashu.setHealth(80);
    ashu.setScore(40);
    ashu.setIsAlive(true);
    ashu.setName("Ashutosh Arya");
    // we can use, dynamic memory allocation, with the help of pointers

    Player *ashima = new Player; // this dynamic, memory will be allocated at runtime
    ashima->setAge(21);
    ashima->setHealth(100);
    ashima->setScore(80);
    ashima->setIsAlive(false);
    ashima->setName("Ashima Alam");

    cout << addScore(aman, ashu) << endl;
    cout << averageAge(aman, ashu) << endl;
    areAll_alive(aman, ashu);
    aman.setIsAlive(false);
    areAll_alive(aman, ashu);

    Player power = get_max_score_player(aman, ashu);
    cout << "Max score is : " << power.getScore() << endl;
    cout << "The most handsome among " << aman.getName() << " and " << ashu.getName() << " is " << most_handsome(aman, ashu) << endl;
    Player power2 = get_max_score_player((*ashima), ashu);
    cout << "Max score is : " << power2.getScore() << "and the name of the player is " << power2.getName() << endl;
}
