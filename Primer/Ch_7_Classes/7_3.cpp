
#include <iostream>
#include <string>


struct Sales_data{     
	std::string bookNo;     
	unsigned units_sold=0;
	double revenue=0.0;

};

Sales_data &Sales_data::combine(const Sales_data &rhs) {
  units_sold += rhs.units_sold;
  revenue += rhs.revenue;
  return *this;
}

int main() {
  Sales_data total;   // Create an instance of Sales_data
  double price;  
  if (std::cin >> total.bookNo >> total.units_sold >> price) {  

    total.revenue = total.units_sold * price;  //calculate total revenue
    std::cout<<"Total Units sold "<<total.revenue<<std::endl;
    Sales_data trans;     // Create a second instance
    while (std::cin >> trans.bookNo >> trans.units_sold >> price) { 
      trans.revenue = trans.units_sold * price;
      std::cout<<"Transaction Revenue is "<<trans.revenue<<std::endl;
      if (total.bookNo == trans.bookNo) {  // If the transaction book is of same type
      	total.combine(trans);
      } else {   //replace the transaction with the total one and delete the previous data
        std::cout << total.bookNo << " "
                  << total.units_sold << " "
                  << total.revenue << std::endl;
        total.bookNo = trans.bookNo;
        total.units_sold = trans.units_sold;
        total.revenue = trans.revenue;
      }
    }
    std::cout << total.bookNo << " "
              << total.units_sold << " "
              << total.revenue << std::endl;
  } else {
    std::cerr << "No data!" << std::endl;
    return -1;
  }

  return 0;
}