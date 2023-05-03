#include "Zumo32U4IMU.h"
#include <Zumo32U4.h>

/*

*/
class Zumo32U4Gyro
{
  public:

    /*

    */
    Zumo32U4Gyro(Zumo32U4IMU);

    /*

    */
    bool setup();

    /*

    */
    int16_t getX() const;

    /*

    */
    int16_t getY() const;

    /*

    */
    int16_t getZ() const;

    /*

    */
    bool getStatus() const;

  private:

    /*

    */
    Zumo32U4IMU imu;

    /*

    */
    int16_t xWaarde;

    /*

    */
    int16_t yWaarde;

    /*

    */
    int16_t zWaarde;

    /*

    */
    bool klaar;

    /*

    */
    void read();


};