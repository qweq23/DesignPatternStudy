#include <iostream>
using namespace std;

// 오직 한 개의 클래스 인스턴스만을 갖도록 보장하고, 이에 대한 전역적인 접근점을 제공합니다.
class Singleton
{
	static Singleton* instance;

protected:
	Singleton() {
		cout << "Singleton 생성" << '\n';
	}
	virtual ~Singleton() {
		cout << "Singleton 소멸" << '\n';
	}

public:
	static Singleton* GetInstance() {
		if (nullptr == instance)
			instance = new Singleton;
		return instance;
	}

	static void DestroyInstance() {
		delete instance;
		instance = nullptr;
	}

	void print() {
		cout << "I'm Singleton\n";
	}
};

Singleton* Singleton::instance = nullptr;

int main() {
	// Singleton s;						// 오류구문
	// Singleton* p = new Singleton;	// 오류구문

	Singleton::GetInstance()->print();
	Singleton::GetInstance();

	Singleton::DestroyInstance();
}
