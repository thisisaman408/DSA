#include <iostream>
using namespace std;

class cricketer
{
private:
    string name;
    int age;
    int no_of_test_matches;
    int average_runs;

public:
    // getters
    string getName()
    {
        return name;
    }
    int getAge()
    {
        return age;
    }
    int getNoOfTestMatches()
    {
        return no_of_test_matches;
    }
    int getAverageRuns()
    {
        return average_runs;
    }

    // setters

    void setName(string name)
    {
        this->name = name;
    }
    void setAge(int age)
    {
        this->age = age;
    }
    void setNoOfTestMatches(int no_of_test_matches)
    {
        this->no_of_test_matches = no_of_test_matches;
    }
    void setAverageRuns(int average_runs)
    {
        this->average_runs = average_runs;
    }
};

int main()
{
    cricketer *Virat = new cricketer;
    Virat->setName("Virat Kohli");
    Virat->setAge(35);
    Virat->setAverageRuns(80);
    Virat->setNoOfTestMatches(200);

    cricketer *Sachin = new cricketer;
    Sachin->setName("Sachin Tendulkar");
    Sachin->setAge(42);
    Sachin->setAverageRuns(100);
    Sachin->setNoOfTestMatches(400);

    cricketer array[2] = {*Virat, *Sachin};
    for (int i = 0; i <= 1; i++)
    {
        cout << array[i].getName() << endl;
        cout << array[i].getAge() << endl;
        cout << array[i].getNoOfTestMatches() << endl;
        cout << array[i].getAverageRuns() << endl;

        cout << endl;
    }
    delete Virat;
    delete Sachin;
}
