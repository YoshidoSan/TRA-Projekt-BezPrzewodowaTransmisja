#include <RCSwitch.h>
RCSwitch mySwitch = RCSwitch();


String textToBinary(String inputText) {
  String binaryString = "";

  for (size_t i = 0; i < inputText.length(); i++) {
    char currentChar = inputText.charAt(i);

    for (int j = 7; j >= 0; j--) {
      if (bitRead(currentChar, j)) {
        binaryString += '1';
      } else {
        binaryString += '0';
      }
    }

//    binaryString += ' ';  // Dodaj spację po każdym bajcie
  }

  return binaryString;
}


void setup() {
//  Serial.begin(9600);
  
  // Transmitter is connected to Arduino Pin #10  
  mySwitch.enableTransmit(10);

  // Optional set pulse length.
  mySwitch.setPulseLength(416);
  
  // Optional set protocol (default is 1, will work for most outlets)
  mySwitch.setProtocol(1);
  
  // Optional set number of transmission repetitions.
   mySwitch.setRepeatTransmit(0);
}

void loop() {
  // Binary code - button 3
  mySwitch.send("001");
//  Serial.println("001");
  delay(1000);  
  mySwitch.send("010");
//  Serial.println("010");
  delay(1000);
  
  // Binary code - button 4
  mySwitch.send("100");
//  Serial.println("100");
  delay(1000);  
  mySwitch.send("111");
//  Serial.println("111");
  delay(1000);
}




//#include <RH_ASK.h>
//#include <SPI.h> 
// 
//RH_ASK rf_driver(2000, 4, 36, 0);
//
//String words[] = {"Hello", "Matka", "Marka", "Kamil", "SOOOS"};
//int i = 0;
//void setup()
//{
//    rf_driver.init();
//    Serial.begin(9600);
//}
// 
//void loop()
//{
//    if (i>4){
//      i = 0;
//    }
//    const char *msg = words[i].c_str();
//    i++;
//    Serial.println(msg);
//    rf_driver.send((uint8_t *)msg, strlen(msg));
//    rf_driver.waitPacketSent();
//    delay(250);
//}


//#include <RH_ASK.h>
//
//RH_ASK driver;
//
//void setup() {
//  if (!driver.init()) {
//    Serial.println("init failed");
//  }
//}
//
//void loop() {
//  uint8_t buf[1] = {0};
//  
//  // Send 0
//  driver.send(buf, sizeof(buf));
//  driver.waitPacketSent();
//  delay(500);
//  
//  // Send 1
//  buf[0] = 1;
//  driver.send(buf, sizeof(buf));
//  driver.waitPacketSent();
//  delay(500);
//}


//#define TRANSMIT_PIN 10 // Pin, na którym będzie wysyłany sygnał
//
//void setup() {
//  Serial.begin(9600);
//  pinMode(TRANSMIT_PIN, OUTPUT); // Ustaw pin jako wyjście
//}
//
//void loop() {
//  tone(10, 2000);
//  Serial.println("1");
//  delay(500);
//  noTone(10);
//  Serial.println("0");
//  delay(500);
//}


//#include <RH_ASK.h>
//#include <SPI.h> 
 
//RH_ASK rf_driver(2000, 4, 36, 0);

//String words[] = {"Hello", "Matka", "Marka", "Kamil"};
//int i = 0;
//int normalDelayTime = 500;
//int bigDelayTime = 5000;
//int tone_fr = 5000;
//
//
//String textToBinary(String inputText) {
//  String binaryString = "";
//
//  for (size_t i = 0; i < inputText.length(); i++) {
//    char currentChar = inputText.charAt(i);
//
//    for (int j = 7; j >= 0; j--) {
//      if (bitRead(currentChar, j)) {
//        binaryString += '1';
//      } else {
//        binaryString += '0';
//      }
//    }
//
//    binaryString += ' ';  // Dodaj spację po każdym bajcie
//  }
//
//  return binaryString;
//}
//
//
//void setup()
//{
////    rf_driver.init();
//    Serial.begin(9600);
//    tone(36, 433000);
//}
// 
//void loop()
//{
////  tone(36, 10000);
////  noTone(36);
////  if (i>3){
////    i = 0;
////  }
////  String msg = textToBinary(words[i]);
////  Serial.println(msg);
////  int msg_len = msg.length();
////  tone(36, tone_fr);
////  delay(normalDelayTime);
////  noTone(36);
////  delay(normalDelayTime);
////  tone(36, tone_fr);
////  delay(normalDelayTime);
////  noTone(36);
////  delay(normalDelayTime);
////  tone(36, tone_fr);
////  delay(normalDelayTime);
////  noTone(36);
////  delay(normalDelayTime);
////  tone(36, tone_fr);
////  delay(normalDelayTime);
////  noTone(36);
////  delay(normalDelayTime);
////  tone(36, tone_fr);
////  delay(normalDelayTime);
////  for (int j = 0; j < msg_len; j++) {
////    if (msg[j] == '1') {
////      Serial.println("1");
////      tone(36, tone_fr);
////    } else {
////      Serial.println("0");
////      noTone(36);
////    }
////    delay(normalDelayTime);
////  }
////  Serial.println("End");
////  tone(36, tone_fr);
////  noTone(36);
////  i++;
////  delay(bigDelayTime);
//}


//#include <RH_ASK.h>
//#include <SPI.h> 
// 
//RH_ASK rf_driver(2000, 4, 36, 0);
// 
//void setup()
//{
//    rf_driver.init();
//    Serial.begin(9600);
//}
// 
//void loop() {
//  String inputString = Serial.readStringUntil('\n');
//  int msg_len = inputString.length();
//  
//  if (msg_len > 0) {
//    Serial.println(inputString.c_str());
//    const char *msg = inputString.c_str();
//    for (int i = 0; i < msg_len; i++) {
//      Serial.println(msg[i]);
//      rf_driver.send((uint8_t)msg[i], 1);
//      rf_driver.waitPacketSent();
//      delay(100);
//    }
//  }else{
//    const char *msg = "Hello worlds";
//    for (int i = 0; i < int(strlen(msg)/2); i++) {
//      char message[3] = {msg[2*i], msg[2*i+1], '\0'};
//      Serial.println(message);
//      rf_driver.send((uint8_t)message, 1);
//      rf_driver.waitPacketSent();
//      delay(100);
//    }
//  }
//}
