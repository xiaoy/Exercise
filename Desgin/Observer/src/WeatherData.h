/*
 * WeatherData.h
 *
 *  Created on: 2012-4-4
 *      Author: lfwu
 */

#ifndef WEATHERDATA_H_
#define WEATHERDATA_H_
#include "Observerble.h"
class Client;
class WeatherData : public Observerble{
public:
	WeatherData();
	virtual ~WeatherData();
	virtual void Resgister(Client* observer);
	virtual void RemoveObserver(Client* observer);
	virtual void SetChanged();
private:
	virtual void Update();
};

#endif /* WEATHERDATA_H_ */
