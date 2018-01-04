#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

mutex m;

void fun (int id) {
	m.lock();
	cout << "Thread id : " << id << endl;
	m.unlock();
}

int main() {
	thread th1 (fun, 100);
	thread th2 (fun, 200);
	th1.detach();
	th2.join();
	return 0;
}
