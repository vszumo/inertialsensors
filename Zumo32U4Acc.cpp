#include <Zumo32U4.h>
#include <Wire.h>
#include "Zumo32U4Acc.h"

/*
Construct de Zumo32U4Acc accelerometer klasse:
- imu parameter op te slaan.
- klaar bepalen en opslaan.
- standaard waardes opslaan.
*/
Zumo32U4Acc::Zumo32U4Acc(Zumo32U4IMU zumoimu):imu(zumoimu)
{
  klaar = false;

  if (imu.getType() != Zumo32U4IMUType::Unknown) {
    klaar = true;
  }

  xWaarde = 0;
  yWaarde = 0;
  zWaarde = 0;
}

/*
Stel de accelerometer in door de imu te initialiseren en daarna klaar op te slaan.
*/
bool Zumo32U4Acc::setup() {
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

/*
Roep read() aan en geef de x waarde terug.
*/
int16_t Zumo32U4Acc::getX() const {
  read();
  return xWaarde;
}

/*
Roep read() aan en geef de y waarde terug.
*/
int16_t Zumo32U4Acc::getY() const {
  read();
  return yWaarde;
}

/*
Roep read() aan en geef de z waarde terug.
*/
int16_t Zumo32U4Acc::getZ() const {
  read();
  return zWaarde;
}

/*
Roep read() aan en geef aan of de robot ondersteboven is.
De robot wordt beschouwd als ondersteboven als de zWaarde onder -2000 ligt.
*/
bool Zumo32U4Acc::getOndersteboven() const {
  read();
  return zWaarde < -2000;
}

/*
Roep read() aan en geef aan of de robot gekanteld is.
De robot wordt beschouwd als gekanteld als de zWaarde tussen de -2000 en 2000 ligt.
*/
bool Zumo32U4Acc::getGekanteld() const {
  read();
  return zWaarde > -2000 && zWaarde < 2000;
}

/*
Geef de klaar waarde terug.
*/
bool Zumo32U4Acc::getStatus() const {
  return klaar;
}

/*
Lees de nieuwste waardes uit de imu en sla deze op.
*/
void Zumo32U4Acc::read() {
  imu.readAcc();
  xWaarde = imu.a.x;
  yWaarde = imu.a.y;
  zWaarde = imu.a.z;
}