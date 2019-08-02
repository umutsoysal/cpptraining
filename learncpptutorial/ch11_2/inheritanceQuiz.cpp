
#include <iostream>
#include <string>

class Fruit{
  private:
    std::string name;
    std::string color;

  public:
    Fruit(std::string a, std::string b)
        :name(a),color(b){
        std::cout<<"Fruit is constructed"<<std::endl;
    }
    std::string GetName() const{return name;};
    std::string GetColor() const{return color ;};     
};

class Apple : public Fruit{
  private:
    double fiber;
  public:
    Apple(std::string a,std::string b,double c)
        :Fruit(a,b),fiber(c){
        std::cout<<"Apple is contructed"<<std::endl;}

    std::string GetAName() const{return GetName();};
    std::string GetAColor() const{return GetColor();};
    double GetFiber() const{return fiber;};
             
};

std::ostream& operator<<(std::ostream& out, const Apple &a)
{
    out<<"Apple ("<<a.GetAName()<<", "<<a.GetAColor()<<", "<<a.GetFiber()<<")\n";
    return out;
}
 
class Banana : public Fruit{
  public:
    Banana(std::string a,std::string b)
        :Fruit(a,b){}

    std::string GetBName() const{return GetName();};
    std::string GetBColor() const{return GetColor();};


};


std::ostream& operator<<(std::ostream& out, const Banana &a)
{
    out<<"Banana ("<<a.GetBName()<<", "<<a.GetBColor()<<")\n";
    return out;
}



int main()
{
    const Apple a("Red delicious","red",4.2);
    std::cout<<a;

    const Banana b("Cavendish","yellow");
    std::cout<< b;

    return 0;
 
}
