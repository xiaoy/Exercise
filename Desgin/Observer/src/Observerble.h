/*
 * Observerble.h
 *
 *  Created on: 2012-4-4
 *      Author: lfwu
 */

#ifndef OBSERVERBLE_H_
#define OBSERVERBLE_H_
#include <list>
class Client;
class Observerble {
public:
	Observerble();
	virtual ~Observerble();
	virtual void Resgister(Client* observer) = 0;
	virtual void RemoveObserver(Client*) = 0;
	virtual void SetChanged() = 0;
	virtual void Update() = 0;
protected:
	std::list<Client*> observer_list_;
	bool state_changed_;
};

#endif /* OBSERVERBLE_H_ */
