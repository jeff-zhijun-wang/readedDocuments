#include <iostream>
//using namespace std;

 extern int x; //used here, define elsewhere
 int f();//no need extern here as functions have always external linkage be default.

int main() {
	int a = f();
	std::getchar();
	return 0;
}