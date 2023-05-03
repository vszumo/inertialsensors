#include <Zumo32U4IMU.h>

/*
Definieer Zumo32U4Accelerometer klasse
*/
class Zumo32U4Accelerometer
{
  public:

    /*
    Construeer een Zumo32U4 accelerometer object met imu als parameter.
    */
    Zumo32U4Accelerometer(Zumo32U4IMU);

    /*
    Stel accelerometer in om deze klaar voor gebruik te maken.
    */
    bool setup();

    /*
    Geeft de x waarde van de accelerometer terug.
    */
    int16_t getX() const;

    /*
    Geeft de y waarde van de accelerometer terug.
    */
    int16_t getY() const;

    /*
    Geeft de z waarde van de accelerometer terug.
    */
    int16_t getZ() const;

    /*
    Geeft de status van de accelerometer terug.
    */
    bool getStatus() const;

  private:

    /*
    Imu parameter die nodig is om de fysieke accelerometer uit te lezen.
    */
    Zumo32U4IMU imu;

    /*
    X waarde van de accelerometer.
    */
    int16_t xWaarde;

    /*
    Y waarde van de accelerometer.
    */
    int16_t yWaarde;

    /*
    Z waarde van de accelerometer.
    */
    int16_t zWaarde;

    /*
    Waarde die status van de accelerometer bijhoudt.
    */
    bool klaar;

    /*
    Functie om de nieuwste waardes uit te lezen en op te slaan.
    */
    void read();

};