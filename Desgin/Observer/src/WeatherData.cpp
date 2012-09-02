/*
 * WeatherData.cpp
 *
 *  Created on: 2012-4-4
 *      Author: lfwu
 */

#include "WeatherData.h"
#include <list>
#include "Client.h"
WeatherData::WeatherData() {
	// TODO Auto-generated constructor stub

}

WeatherData::~WeatherData() {
	// TODO Auto-generated destructor stub
}

void WeatherData::Resgister(Client* observer)
{
	observer_list_.push_back(observer);
}

void WeatherData::RemoveObserver(Client* observer)
{
	std::list<Client*>::iterator iter;
	for(iter = observer_list_.begin(); iter != observer_list_.end(); ++iter)
	{
		if(observer == *iter)
		{
			observer_list_.remove(*iter);
			break;
		}
	}
}

void WeatherData::SetChanged()
{
	state_changed_ = true;
	Update();
}

void WeatherData::Update()
{
	if(state_changed_)
	{
		std::list<Client*>::iterator iter;
		for(iter = observer_list_.begin(); iter != observer_list_.end(); ++iter)
		{
			Client* observer = *iter;
			observer->Update();
		}
	}
}
