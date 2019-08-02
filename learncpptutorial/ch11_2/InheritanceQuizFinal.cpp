#include <iostream>
#include <string>

class Fruit{

  protected:
    std::string m_name;
    std::string m_color;
  public:

    Fruit(std::string name,std::string color)
        :m_name(name),m_color(color){}
    
};

class Apple : public Fruit{
  public:
    Apple(std::string d)
        :Fruit("apple",d){
        std::cout<<"Apple is created"<<std::endl;}
    std::string getName() {return m_name;}
    std::string getColor() {return m_color;}
};


class Banana : public Fruit{
  public:
    Banana()
        :Fruit("banana","yellow"){
        std::cout<<"Banana is created"<<std::endl;}
    std::string getName() {return m_name;}
    std::string getColor() {return m_color;}
};



//class Banana :public Fruit{
//  public:
//    Banana()
//        :Fruit(

int main()
{
    Apple a("red");
    Banana b;

    std::cout<<"My "<<a.getName()<<" is "<<a.getColor()<<".\n";
    std::cout<<"My"<<b.getName()<<" is "<<b.getColor()<<".\n";
    

    return 0;

}
