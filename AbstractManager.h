#ifndef _ABSTRACT_MANAGER_H_
#define _ABSTRACT_MANAGER_H_

class AbstractManager							//ClientManager와 ProductManager의 클래스의 함수 중복을 피하기 위한 순수 가상함수 설정
{
public:
	virtual void Display() const = 0;			//AbstractManager의 순수 가상함수 Display() 선언
	virtual void Save() const = 0;				//AbstractManager의 순수 가상함수 Save() 선언	
	virtual void Load() = 0;					//AbstractManager의 순수 가상함수 Load() 선언
	virtual int Count() const = 0;				//AbstractManager의 순수 가상함수 Cound() 선언
	virtual void RemoveAll() = 0;				//AbstractManager의 순수 가상함수 RemoveAll() 선언
};

#endif