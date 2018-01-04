#include <iostream>
#include <thread>
#include <mutex>

using namespace std;
mutex m;
void fun(int value, char c){
	m.lock();
	for (int i=0; i<=value; ++i){
		cout << c;
	}
	cout << endl;
	m.unlock();
}

int main(){
	//mutex m;
	thread th1 ( fun, 5, '*' );
	thread th2 ( fun, 5, '$' );
	th1.join();
	th2.join();
	return 0;
}
