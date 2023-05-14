#include "Zumo32U4Gyro.h"
#include "Zumo32U4Acc.h"
#include "Zumo32U4Mag.h"


// Initialiseer imu object.
Zumo32U4IMU imu;

// Maak gyroscoop object aan met imu als parameter.
Zumo32U4Gyro gyro(imu);

// Maak accelerometer object aan met imu als parameter.
Zumo32U4Acc acc(imu);

// Maak magnetometer object aan met imu als parameter.
Zumo32U4Mag mag(imu);

void setup() {
  // Start seriele verbinding en print iets naar de console.
  Serial.begin(9600);
  Serial.println("Starting VSZumo software");

  // Constroleer of de gyroscoop status al true is.
  if (!gyro.getStatus()) {
    // Stel gyroscoop in en controleer uitkomst.
    if (!gyro.setup()) {
      while(true) {
        Serial.println("Zumo Gyroscope failed to initialize.");
        delay(1000);
      }
    } else {
      Serial.println("Zumo Gyroscope initialized.");
    }
  }

  // Constroleer of de accelerometer status al true is.
  if (!acc.getStatus()) {
    // Stel accelerometer in en controleer uitkomst.
    if (!acc.setup()) {
      while(true) {
        Serial.println("Zumo Accelerometer failed to initialize.");
        delay(1000);
      }
    } else {
      Serial.println("Zumo Accelerometer initialized.");
    }
  }

  //Constroleer of de magnetometer status al true is.
  if (!mag.getStatus()) {
    // Stel magnetometer in en controleer uitkomst.
    if (!mag.setup()) {
      while(true) {
        Serial.println("Zumo Magnetometer failed to initialize.");
        delay(1000);
      }
    } else {
      Serial.println("Zumo Magnetometer initialized.");
    }
  }

}

void loop() {
  // Print informatie over de gyroscoop naar de console.
  Serial.println("Gyroscope x,y,z");
  Serial.print(gyro.getX());
  Serial.print(", ");
  Serial.print(gyro.getY());
  Serial.print(", ");
  Serial.println(gyro.getZ());
  if (gyro.getDraaiend()) Serial.println("draaiend");
  Serial.println("");

  // Print informatie over de accelerometer naar de console.
  Serial.println("Accelerometer x,y,z");
  Serial.print(acc.getX());
  Serial.print(", ");
  Serial.print(acc.getY());
  Serial.print(", ");
  Serial.println(acc.getZ());
  if (acc.getGekanteld()) Serial.println("gekanteld");
  if (acc.getOndersteboven()) Serial.println("ondersteboven");
  Serial.println("");

  // Print informatie over de magnetometer naar de console.
  Serial.println("Mag x,y,z");
  Serial.print(mag.getX());
  Serial.print(", ");
  Serial.print(mag.getY());
  Serial.print(", ");
  Serial.println(mag.getZ());
  if (mag.getMagneet()) Serial.println("magneet");
  Serial.println("");

  delay(1000);
}