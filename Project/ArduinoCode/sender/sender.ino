// Include RadioHead Amplitude Shift Keying Library
#include <RH_ASK.h>
// Include dependant SPI Library 
#include <SPI.h> 
 
// Create Amplitude Shift Keying Object
RH_ASK rf_driver;
 
void setup()
{
    // Initialize ASK Object
    rf_driver.init();

    Serial.begin(9600);
    while (!Serial);
}
 
void loop()
{
    String inputString = Serial.readStringUntil('\n');

    Serial.flush();

    const char *msg = inputString.c_str();
    rf_driver.send((uint8_t *)msg, strlen(msg));
    rf_driver.waitPacketSent();
}
