#include <iostream>
using namespace std;
/// passing class objects to functions!
class Gun
{
private:
    int ammo;
    int damage;
    int scope;

public:
    // getters
    int getAmmo()
    {
        return ammo;
    }
    int getDamage()
    {
        return damage;
    }
    int getScope()
    {
        return scope;
    }

    // setters

    void setAmmo(int ammo)
    {
        this->ammo = ammo;
    }
    void setDamage(int damage)
    {
        this->damage = damage;
    }
    void setScope(int scope)
    {
        this->scope = scope;
    }
};
class Player
{
private:
    // we can also declare class inside class, here as every player has a helmet, level 1, 2, or 3
    class Helmet
    {
    private:
        int hp;
        int level;

    public:
        // getters
        int getHp()
        {
            return hp;
        }
        int getLevel()
        {
            return level;
        }
        // setters

        void setHp(int hp)
        {
            this->hp = hp;
        }
        void setLevel(int level)
        {
            this->level = level;
        }
    };
    int health;
    int age;
    int score;
    bool alive;
    string name;
    Gun gun;       // we can use a class also,as a gun here
    Helmet helmet;

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

    Gun getGun()
    {
        return gun;
    }
    Helmet getHelmet(){
        return helmet;
        cout<<helmet.getHp();
        cout<<helmet.getLevel();
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

    void setGun(Gun gun)
    {
        this->gun = gun;
    }

    void setHelmet(int level)
    {
        Helmet *helmet = new Helmet;
        helmet->setLevel(level);
        int hp = 0;
        if(level == 1) hp = 25;
        else if(level == 2) hp = 50;
        else if(level == 3) hp = 100;
        else{
            cout<<"Error, invalid level";
        }
        helmet->setHp(hp);
        this->helmet = *helmet;
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

    Gun akm;
    akm.setAmmo(40);
    akm.setAmmo(100);
    akm.setScope(3);

    Gun m416;
    m416.setAmmo(40);
    m416.setDamage(80);
    m416.setScope(2);

    Player aman; // this is static memory allocatin
    aman.setAge(21);
    aman.setHealth(100);
    aman.setScore(90);
    aman.setIsAlive(true);
    aman.setName("Aman Kumar");
    aman.setGun(m416);
    aman.setHelmet(3);

    Player ashu;
    ashu.setAge(22);
    ashu.setHealth(80);
    ashu.setScore(40);
    ashu.setIsAlive(true);
    ashu.setName("Ashutosh Arya");
    ashu.setGun(akm);
    ashu.setHelmet(2);
    // we can use, dynamic memory allocation, with the help of pointers

    Player *ashima = new Player; // this dynamic, memory will be allocated at runtime
    ashima->setAge(21);
    ashima->setHealth(100);
    ashima->setScore(80);
    ashima->setIsAlive(false);
    ashima->setName("Ashima Alam");
    ashima->setGun(m416);
    ashima->setHelmet(1);

    cout << addScore(aman, ashu) << endl;
    cout << averageAge(aman, ashu) << endl;
    areAll_alive(aman, ashu);
    aman.setIsAlive(false);
    areAll_alive(aman, ashu);

    Player power = get_max_score_player(aman, ashu);
    cout << "Max score is : " << power.getScore() << endl;
    cout << "The most handsome among " << aman.getName() << " and " << ashu.getName() << " is " << most_handsome(aman, ashu) << endl;
    Player power2 = get_max_score_player((*ashima), ashu);
    cout << "Max score is : " << power2.getScore() << " and the name of the player is " << power2.getName() << endl;


    aman.getHelmet();

    delete ashima;
    return 0;
}
