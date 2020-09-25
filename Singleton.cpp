#include <iostream>
using namespace std;

// ���� �� ���� Ŭ���� �ν��Ͻ����� ������ �����ϰ�, �̿� ���� �������� �������� �����մϴ�.
class Singleton
{
	static Singleton* instance;

protected:
	Singleton() {
		cout << "Singleton ����" << '\n';
	}
	virtual ~Singleton() {
		cout << "Singleton �Ҹ�" << '\n';
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
	// Singleton s;						// ��������
	// Singleton* p = new Singleton;	// ��������

	Singleton::GetInstance()->print();
	Singleton::GetInstance();

	Singleton::DestroyInstance();
}
