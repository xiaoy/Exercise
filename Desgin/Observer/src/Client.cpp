/*
 * Client.cpp
 *
 *  Created on: 2012-4-4
 *      Author: lfwu
 */

#include "Client.h"
#include "Observerble.h"
Client::Client() {
	// TODO Auto-generated constructor stub

}

Client::~Client() {
	// TODO Auto-generated destructor stub
}

void Client::Resgister(Observerble* observers)
{
	observers->Resgister(this);
}

void Client::RemoveObserver(Observerble* observers)
{
	observers->RemoveObserver(this);
}
