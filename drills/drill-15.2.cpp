/*
    g++ drill-15.2.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o drill-15.2 `fltk-config --ldflags --use-images` -std=c++11
*/
#include "Simple_window.h"
#include "Graph.h"

struct Person
{
  private:
        string first_name;
        string last_name;
        int age;

  public:
        Person() {}
	    Person(string fn, string ln, int a)

    {

      if (a <= 0 || a > 150)
      {
            error("Age must range from 0 to 150");
      }

      if (fn == "" || ln == "")
      {
            error("Missing first or last name");
      }

      if (fn.find_first_of(";:[]*&^%$#@!.") != string::npos || ln.find_first_of(";:[]*&^%$#@!.") != string::npos)
      {
            error("Unaccepted character(s) used (;:[]*&^%$#@!.)");
      }

      init(fn, ln, a);

    }

	void init(string fn, string ln, int a)
	{
	  first_name = fn;
    last_name = ln;
		age = a;
	}

    string get_first_name() const { return first_name; }
    string get_last_name() const { return last_name; }
	  int get_age() const { return age; } 
};

ostream& operator<<(ostream& os, const Person& p)
{
    os << p.get_first_name() << " " << p.get_last_name() << ":" << p.get_age() << "\n";
    return os;
}

istream& operator>>(istream& is, Person& pp)
{
    string f_n, l_n; int a;
    cout << "Define first name: ";
    is >> f_n;
    cout << "Define last name: ";
    is >> l_n;  
    cout << "Define age: ";
    is >> a;
    pp = Person{f_n, l_n, a};
    return is;
}

int main()
{
    Person p1{ "Goofy", "Goof", 63 };
    cout << p1;

    Person p2;
    cin >> p2;
    cout << p2;

    vector<Person> vecp;
    Person temp;

	for (int i = 0; i < 3; ++i)
	{
		cin >> temp;
		vecp.push_back(temp);
	}
  
	for (Person p : vecp)
    {
		cout << p;
    }

  return 0;
}
