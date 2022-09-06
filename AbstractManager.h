#ifndef _ABSTRACT_MANAGER_H_
#define _ABSTRACT_MANAGER_H_

class AbstractManager
{
public:
	virtual void Display() = 0;
	virtual void Save() = 0;
	virtual void Load() = 0;
	virtual int Count() = 0;
	virtual void RemoveAll() = 0;
};

#endif