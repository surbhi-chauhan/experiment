#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

static int num = 10;
mutex m;

void threadmethod(int id) {
	m.lock();
	cout << "Thread number : " << id << endl;
	m.unlock();
}

int main() {
	thread threadarray[num];
	for (int i=0; i<num; ++i) {
		threadarray[i] = thread (threadmethod, i);
	}
	for (int i=0; i<num; ++i) {
		threadarray[i].join();
	}
	return 0;
}
