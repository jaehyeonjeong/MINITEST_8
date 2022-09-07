#ifndef _ABSTRACT_MANAGER_H_
#define _ABSTRACT_MANAGER_H_

//ClientManager와 ProductManager의 클래스의 함수 중복을 피하기 위한 순수 가상함수 설정
class AbstractManager
{
public:
	virtual void Display() const = 0;
	virtual void Save() const = 0;
	virtual void Load() = 0;
	virtual int Count() const = 0;
	virtual void RemoveAll() = 0;
};

#endif