#include <iostream>
#include <thread>
using namespace std;

void myFun(){
	cout << "Inside the myFun function" << endl;
}
int main(){
	thread th1 (myFun);
	th1.join();
	return 0;
}
