#include <iostream>
#include <random>
#include <functional> 
using namespace std;

int main() {
	default_random_engine generator;
	uniform_int_distribution<int> distribution(0, 4);
	auto dice = bind(distribution, generator);
	int histgram[5] = { 0 };
	for (int i = 0; i < 200; i++) {
		++histgram[dice()];
	}
	for (int i = 0; i <5; i++) {
		cout << i << ' ';
		for(int j=0; j<histgram[i]; j++) cout<<'*';
		cout << endl;
	}
	getchar();
	return 0;
}