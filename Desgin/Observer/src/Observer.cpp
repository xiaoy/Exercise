//============================================================================
// Name        : Observer.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
#include "WeatherData.h"
#include "ClientTemp.h"
#include "ClientHumidity.h"
int main() {
	WeatherData* weather = new WeatherData;
	ClientTemp* temp = new ClientTemp;
	ClientHumidity* humidity = new ClientHumidity;
	temp->Resgister(weather);
	humidity->Resgister(weather);
	weather->SetChanged();
	humidity->RemoveObserver(weather);
	temp->RemoveObserver(weather);
	weather->SetChanged();
	delete weather;
	delete temp;
	delete humidity;
}
