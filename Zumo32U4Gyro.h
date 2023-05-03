#include <Zumo32U4IMU.h>

/*
Definieer Zumo32U4Gyro gyroscoop klasse
*/
class Zumo32U4Gyro
{
  public:

    /*
    Construeer een Zumo32U4 Gyro object met imu als parameter.
    */
    Zumo32U4Gyro(Zumo32U4IMU);

    /*
    Stel gyroscoop in om deze klaar voor gebruik te maken.
    */
    bool setup();

    /*
    Geeft de x waarde van de gyroscoop terug.
    */
    int16_t getX() const;

    /*
    Geeft de y waarde van de gyroscoop terug.
    */
    int16_t getY() const;

    /*
    Geeft de z waarde van de gyroscoop terug.
    */
    int16_t getZ() const;

    /*
    Geeft terug of de robot aan het draaien is.
    */
    bool getDraaiend() const;

    /*
    Geeft de status van de gyroscoop terug.
    */
    bool getStatus() const;

  private:

    /*
    Imu parameter die nodig is om de fysieke gyroscoop uit te lezen.
    */
    Zumo32U4IMU imu;

    /*
    X waarde van de gyroscoop.
    */
    int16_t xWaarde;

    /*
    Y waarde van de gyroscoop.
    */
    int16_t yWaarde;

    /*
    Z waarde van de gyroscoop.
    */
    int16_t zWaarde;

    /*
    Waarde die status van de gyroscoop bijhoudt.
    */
    bool klaar;

    /*
    Functie om de nieuwste waardes uit te lezen en op te slaan.
    */
    void read();

};