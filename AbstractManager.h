#ifndef _ABSTRACT_MANAGER_H_
#define _ABSTRACT_MANAGER_H_

class AbstractManager							//ClientManager�� ProductManager�� Ŭ������ �Լ� �ߺ��� ���ϱ� ���� ���� �����Լ� ����
{
public:
	virtual void Display() const = 0;			//AbstractManager�� ���� �����Լ� Display() ����
	virtual void Save() const = 0;				//AbstractManager�� ���� �����Լ� Save() ����	
	virtual void Load() = 0;					//AbstractManager�� ���� �����Լ� Load() ����
	virtual int Count() const = 0;				//AbstractManager�� ���� �����Լ� Cound() ����
	virtual void RemoveAll() = 0;				//AbstractManager�� ���� �����Լ� RemoveAll() ����
};

#endif