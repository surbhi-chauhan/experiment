#include <iostream>
#include <thread>
#include <string>
#include <mutex>

using namespace std;

mutex m;

void fun ( string strng ) {
	m.lock();
	cout << "Fun function string : " << strng << endl;
	strng = "XYZ";
	m.unlock();
}

int main(){
	string strng = "ABC";
	thread th ( &fun, ref(strng) );
	//cout << "Main function string : " << strng << endl;
	th.join();
	cout << "Main function string : " << strng << endl;

	return 0;
}
