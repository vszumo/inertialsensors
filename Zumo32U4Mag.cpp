#include <Wire.h>
#include "Zumo32U4Mag.h"

/*
Construct de Zumo32U4Mag magnetometer klasse:
- imu parameter op te slaan.
- klaar bepalen en opslaan.
- standaard waardes opslaan.
*/
Zumo32U4Mag::Zumo32U4Mag(Zumo32U4IMU zumoimu):imu(zumoimu)
{
  klaar = false;

  if (imu.getType() != Zumo32U4IMUType::Unknown) {
    klaar = true;
  }

  xWaarde = 0;
  yWaarde = 0;
  zWaarde = 0;
}

// Stel de magnetometer in door de imu te initialiseren en daarna klaar op te slaan.
bool Zumo32U4Mag::setup() {
  if (klaar) {
    return false;
  }

  Wire.begin();
  if (!imu.init()) {
    return false;
  }

  klaar = true;
  return true;
}

// Roep read() aan en geef de x waarde terug.
int16_t Zumo32U4Mag::getX() const {
  read();
  return xWaarde;
}

// Roep read() aan en geef de y waarde terug.
int16_t Zumo32U4Mag::getY() const {
  read();
  return yWaarde;
}

// Roep read() aan en geef de z waarde terug.
int16_t Zumo32U4Mag::getZ() const {
  read();
  return zWaarde;
}

/*
Roep read() aan en geef aan of de robot in de buurt van een magneet of stuk metaal is.
De robot wordt beschouwd als in de buurt van een magneet als de xWaarde > 0 is.
*/
bool Zumo32U4Mag::getMagneet() const {
  read();
  return xWaarde > 0;
}

// Geef de klaar waarde terug.
bool Zumo32U4Mag::getStatus() const {
  return klaar;
}

// Lees de nieuwste waardes uit de imu en sla deze op.
void Zumo32U4Mag::read() {
  imu.readMag();
  xWaarde = imu.m.x;
  yWaarde = imu.m.y;
  zWaarde = imu.m.z;
}