#include "Zumo32U4Gyro.h"
#include "Zumo32U4Acc.h"

/*
Initialiseer imu object.
*/
Zumo32U4IMU imu;

/*
Maak gyroscoop object aan met imu als parameter.
*/
Zumo32U4Gyro gyro(imu);

/*
Maak accelerometer object aan met imu als parameter.
*/
Zumo32U4Acc acc(imu);

void setup() {
  /*
  Start seriele verbinding en print iets naar de console.
  */
  Serial.begin(9600);
  Serial.println("Starting VSZumo software");

  /*
  Constroleer of de gyroscoop status al true is.
  */
  if (!gyro.getStatus()) {
    /*
    Stel gyroscoop in en controleer uitkomst.
    */
    if (!gyro.setup()) {
      while(true) {
        Serial.println("Zumo Gyroscope failed to initialize.");
        delay(1000);
      }
    } else {
      Serial.println("Zumo Gyroscope initialized.");
    }
  }

  /*
  Constroleer of de accelerometer status al true is.
  */
  if (!acc.getStatus()) {
    /*
    Stel accelerometer in en controleer uitkomst.
    */
    if (!acc.setup()) {
      while(true) {
        Serial.println("Zumo Accelerometer failed to initialize.");
        delay(1000);
      }
    } else {
      Serial.println("Zumo Accelerometer initialized.");
    }
  }

}

void loop() {
  Serial.println("Gyroscope x,y,z");
  Serial.print(gyro.getX());
  Serial.print(", ");
  Serial.print(gyro.getY());
  Serial.print(", ");
  Serial.println(gyro.getZ());
  Serial.println("");

  Serial.println("Accelerometer x,y,z");
  Serial.print(acc.getX());
  Serial.print(", ");
  Serial.print(acc.getY());
  Serial.print(", ");
  Serial.println(acc.getZ());
  Serial.println("");

  delay(1000);
}
