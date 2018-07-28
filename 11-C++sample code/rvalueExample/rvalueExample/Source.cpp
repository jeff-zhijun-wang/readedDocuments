#include <iostream>
#include <string>
#include <vector>

using namespace std;

string&& r{ "Oxford" }; //now r is string type

vector<string&> v;

string f(string&& s) {//s is rvalue, it is the reference name of the temporary object
	for (char& c : s) c = toupper(c);
	return s;
};


int main(){
	string tmp{};
	tmp = f(move(r));//move change the type from string to string&&
	cout << tmp << endl;
	tmp = f("Oxford");
	cout << tmp << endl;
	string t1{ "one" };
	string t2{ "two" };
	string& rt1{ t1 };
	string& rt2{ t2 };
	v.push_back(rt1);
	v.push_back(rt2);
	cout << v[0] << endl;
	cout << v[1] << endl;
	getchar();
	return 0;
}