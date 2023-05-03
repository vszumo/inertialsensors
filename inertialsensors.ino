#include "Zumo32U4Gyro.h"

/*
Initialiseer imu object en maak gyro object aan met imu als parameter.
*/
Zumo32U4IMU imu;
Zumo32U4Gyro gyro(imu);

void setup() {
  /*
  Start seriele verbinding en print iets naar de console.
  */
  Serial.begin(9600);
  Serial.println("Starting VSZumo software");

  /*
  Constroleer of de gyro status al true is.
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

}

void loop() {
  Serial.println("Gyroscope x,y,z");
  Serial.print(gyro.getX());
  Serial.print(", ");
  Serial.print(gyro.getY());
  Serial.print(", ");
  Serial.println(gyro.getZ());
  Serial.println("");
  delay(1000);
}
