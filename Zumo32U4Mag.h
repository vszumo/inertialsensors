#include <Zumo32U4IMU.h>

// Definieer Zumo32U4Mag magnetometer klasse
class Zumo32U4Mag
{
  public:

    // Construeer een Zumo32U4 magnetometer object met imu als parameter.
    Zumo32U4Mag(Zumo32U4IMU);

    // Stel magnetometer in om deze klaar voor gebruik te maken.
    bool setup();

    // Geeft de x waarde van de magnetometer terug.
    int16_t getX() const;

    // Geeft de y waarde van de magnetometer terug.
    int16_t getY() const;

    // Geeft de z waarde van de magnetometer terug.
    int16_t getZ() const;

    // Geeft terug of de robot in de buurt van een magneet of stuk metaal is.
    bool getMagneet() const;

    // Geeft de status van de magnetometer terug.
    bool getStatus() const;

  private:

    // Imu parameter die nodig is om de fysieke magnetometer uit te lezen.
    Zumo32U4IMU imu;

    // X waarde van de magnetometer.
    int16_t xWaarde;

    // Y waarde van de magnetometer.
    int16_t yWaarde;

    // Z waarde van de magnetometer.
    int16_t zWaarde;

    // Waarde die status van de magnetometer bijhoudt.
    bool klaar;

    // Functie om de nieuwste waardes uit te lezen en op te slaan.
    void read();

};