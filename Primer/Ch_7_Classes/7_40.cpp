


class Book{

  public:
    Book():isbn(" "),name(" "),author(" "),publish_year(0),publisher(" "),version(0){} //Constructor 1
    Book(const std::string &i, const std::string &n, const std::vector<std::string&au, unsigned y, const std::string &p=" ",unsigned v=1)
        :isbn(i),name(n),author(au),publish_year(y),publisher(p), version(v) {}  // Constructor 2
    Book(std::istream &is){
        is>>isbn>>name;
        std::string s;
        is>>s;
        author.push_back(s);
        is>>publish_year>>publisher>>version;
    }
    

    
  private:
   std::string isbn;
   std::string name;
    std::vector<std::string>author;
    unsigned publish_year;
    std::string publisher;
    unsigned version;
};

