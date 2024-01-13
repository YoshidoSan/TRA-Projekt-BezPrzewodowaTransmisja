#include <RH_ASK.h> 
#include <SPI.h> 
 
//RH_ASK rf_driver(10, 6, 8, 0);
//
//String words[] = {"Hello", "Matka", "Marka", "Kamil"};
int i = 1;

void setup()
{
//    rf_driver.init();
    Serial.begin(9600);
}
 
void loop()
{
  if (i>8){
    i = 0;
  }
  tone(8, 1000*i);
  Serial.println(1000*i);
  delay(4000);
  i++;
}
//  uint8_t buf[2];
//  uint8_t buflen = sizeof(buf);
//  if (rf_driver.recv(buf, &buflen))
//  {
//    Serial.println((char*)buf);  
//    if (i>3){
//      i = 0;
//    }
//    const char *msg = words[i].c_str();
//    i++;
//    Serial.println(msg);
//    rf_driver.send((uint8_t *)msg, strlen(msg));
//    rf_driver.waitPacketSent();
//    delay(100);       
//  }      
//}
