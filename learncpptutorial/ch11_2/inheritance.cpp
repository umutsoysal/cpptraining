#include <iostream>
#include <string>

class Person
{
  public:
    std::string m_name;
    int m_age;

    std::string getName() const {return m_name;}
    int getAge() const {return m_age;}

    Person(std::string name="",int age=0)
        :m_name(name),m_age(age)
    { 
    }
};

//Employee publicly inherits from Person
class Employee: public Person
{
  public:
    double m_hourlySalary;
    long m_employeeID;

    Employee(double hourlySalary=0.0, long employeeID=0)
        :m_hourlySalary(hourlySalary), m_employeeID(employeeID){
    }

    void printNameAndSalary() const
    {
        std::cout<<m_name<<":"<<m_hourlySalary<<"\n";
    }

};


class BaseballPlayer : public Person
{
public:
    double m_battingAverage;
    int m_homeRuns;
 
    BaseballPlayer(double battingAverage = 0.0, int homeRuns = 0)
       : m_battingAverage(battingAverage), m_homeRuns(homeRuns)
    {
    }
};







int main()
{
    Employee umut (37,12345);
    BaseballPlayer Nilesh;
    umut.m_name="Umut";

    umut.printNameAndSalary();

    return 0;
}

  
