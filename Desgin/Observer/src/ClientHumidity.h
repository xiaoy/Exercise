/*
 * ClientHumidity.h
 *
 *  Created on: 2012-4-4
 *      Author: lfwu
 */

#ifndef CLIENTHUMIDITY_H_
#define CLIENTHUMIDITY_H_
#include "Client.h"
class ClientHumidity : public Client{
public:
	ClientHumidity();
	virtual ~ClientHumidity();
	virtual void Update();
};

#endif /* CLIENTHUMIDITY_H_ */
