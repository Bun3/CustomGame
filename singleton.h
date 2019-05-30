#pragma once

// 클래스를 전역 변수처럼 사용할 수 있게 해준다.
template <typename T>
class singleton {
private:
	static T * p;
public:
	singleton() {};
	virtual ~singleton() {};

	static T * GetInstance() {
		if (!p)
			p = new T;
		return p;
	}

	static void ResetInstance() {
		if (p)
			delete p;
		p = nullptr;
	}
};
template <typename T>
T* singleton<T>::p = nullptr;