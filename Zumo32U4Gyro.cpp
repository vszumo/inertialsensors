#include <Wire.h>
#include "Zumo32U4Gyro.h"

/*
Construct de Zumo32U4Gyro gyroscoop klasse:
- imu parameter op te slaan.
- klaar bepalen en opslaan.
- standaard waardes opslaan.
*/
Zumo32U4Gyro::Zumo32U4Gyro(Zumo32U4IMU zumoimu):imu(zumoimu)
{
  klaar = false;

  if (imu.getType() != Zumo32U4IMUType::Unknown) {
    klaar = true;
  }

  xWaarde = 0;
  yWaarde = 0;
  zWaarde = 0;
}

// Stel de gyroscoop in door de imu te initialiseren en daarna klaar op te slaan.
bool Zumo32U4Gyro::setup() {
  if (klaar) return false;

  Wire.begin();
  if (!imu.init()) return false;

  klaar = true;
  return true;
}

// Roep read() aan en geef de x waarde terug.
int16_t Zumo32U4Gyro::getX() const {
  read();
  return xWaarde;
}

// Roep read() aan en geef de y waarde terug.
int16_t Zumo32U4Gyro::getY() const {
  read();
  return yWaarde;
}

// Roep read() aan en geef de z waarde terug.
int16_t Zumo32U4Gyro::getZ() const {
  read();
  return zWaarde;
}

/*
Roep read() aan en geef aan of de robot aan het draaien is.
De robot wordt beschouwd als draaiend als de zWaarde onder de -1000 of boven de 1000 ligt.
*/
bool Zumo32U4Gyro::getDraaiend() const {
  read();
  return zWaarde < -1000 || zWaarde > 1000;
}

// Geef de klaar waarde terug.
bool Zumo32U4Gyro::getStatus() const {
  return klaar;
}

// Lees de nieuwste waardes uit de imu en sla deze op.
void Zumo32U4Gyro::read() {
  imu.readGyro();
  xWaarde = imu.g.x;
  yWaarde = imu.g.y;
  zWaarde = imu.g.z;
}