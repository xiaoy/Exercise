/*
 * ClientTemp.h
 *
 *  Created on: 2012-4-4
 *      Author: lfwu
 */

#ifndef CLIENTTEMP_H_
#define CLIENTTEMP_H_
#include "Client.h"
class ClientTemp : public Client{
public:
	ClientTemp();
	virtual ~ClientTemp();
	virtual void Update();
};

#endif /* CLIENTTEMP_H_ */
