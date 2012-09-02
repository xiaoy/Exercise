/*
 * Client.h
 *
 *  Created on: 2012-4-4
 *      Author: lfwu
 */

#ifndef CLIENT_H_
#define CLIENT_H_
class Observerble;
class Client {
public:
	Client();
	virtual ~Client();
	virtual void Update() = 0;
	void Resgister(Observerble* observers);
	void RemoveObserver(Observerble* observers);
};

#endif /* CLIENT_H_ */
