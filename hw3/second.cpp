#include <iostream>
#include <string>
#include <boost/regex.hpp>

using namespace std;

int main()
{
    std::string text = "Hello, my email is john.doe@email.com. Please send me an email at this address.";

    boost::regex expression("(\\b[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\\.[A-Z|a-z]{2,}\\b)");

    boost::sregex_iterator it(text.begin(), text.end(), expression);
    boost::sregex_iterator end;

    cout << "Email addresses found:" << endl;

    while (it != end) {
        cout << it->str() << endl;
        ++it;
    }

    return 0;
}