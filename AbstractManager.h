#ifndef _ABSTRACT_MANAGER_H_
#define _ABSTRACT_MANAGER_H_

//ClientManager�� ProductManager�� Ŭ������ �Լ� �ߺ��� ���ϱ� ���� ���� �����Լ� ����
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