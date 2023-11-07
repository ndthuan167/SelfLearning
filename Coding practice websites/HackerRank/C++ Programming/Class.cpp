/* 10 points : https://www.hackerrank.com/challenges/c-tutorial-class/problem?isFullScreen=true
Thuan 23.11.07 */

#include <iostream>
#include <sstream>
using namespace std;

/*
Enter code for class Student here.
Read statement for specification.
*/

class Student
{
private:
    int age;
    string first_name;
    string last_name;
    int standard;

public:
    void set_age(int age_set) { age = age_set; }
    int get_age() { return age; }

    void set_first_name(string first_name_set) { first_name = first_name_set; }
    string get_first_name() { return first_name; }

    void set_last_name(string last_name_set) { last_name = last_name_set; }
    string get_last_name() { return last_name; }
    
    void set_standard(int standard_set) { standard = standard_set; }
    int get_standard() { return standard; }

    string to_string()
    {
        ostringstream age_string, standard_string;
        age_string << age;
        standard_string << standard;
        return age_string.str() + "," + first_name + "," + last_name + "," + standard_string.str();
    }
};

int main()
{
    int age, standard;
    string first_name, last_name;

    cin >> age >> first_name >> last_name >> standard;

    Student st;
    st.set_age(age);
    st.set_standard(standard);
    st.set_first_name(first_name);
    st.set_last_name(last_name);

    cout << st.get_age() << "\n";
    cout << st.get_last_name() << ", " << st.get_first_name() << "\n";
    cout << st.get_standard() << "\n";
    cout << "\n";
    cout << st.to_string();

    return 0;
}