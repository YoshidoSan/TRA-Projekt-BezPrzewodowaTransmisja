#include <RCSwitch.h>

RCSwitch mySwitch = RCSwitch();

void setup() {
  Serial.begin(9600);
  mySwitch.enableReceive(0);  // Receiver on interrupt 0 => that is pin #2
}

void loop() {
  if (mySwitch.available()) {
    output(mySwitch.getReceivedValue(), mySwitch.getReceivedBitlength(), mySwitch.getReceivedDelay(), mySwitch.getReceivedRawdata(),mySwitch.getReceivedProtocol());
    mySwitch.resetAvailable();
  }
}



//#include <RH_ASK.h> 
//#include <SPI.h> 
// 
//RH_ASK rf_driver(2000, 6);
// 
//void setup()
//{
//    rf_driver.init();
//    Serial.begin(9600);
//}
// 
//void loop()
//{
//  uint8_t buf[5];
//  uint8_t buflen = sizeof(buf);
//  if (rf_driver.recv(buf, &buflen))
//  {
//    Serial.println((char*)buf);         
//  }      
//}


////#include <RH_ASK.h> 
//#include <SPI.h> 
// 
////RH_ASK rf_driver(2000, 6);
// 
//void setup()
//{
//  pinMode(2, INPUT);
//    Serial.begin(115200);
//
//    noInterrupts(); // Wyłącz przerwania
//  TCCR2A = 0; // Ustaw wszystkie bity rejestru TCCR1A na 0
//  TCCR2B = 0; // Analogicznie dla TCCR1B
//  TCNT2  = 0; // Inicjalizacja licznika timera1 na 0
//  OCR2A = 159; // Przerwanie będzie generowane, gdy licznik osiągnie tę wartość (16MHz/10000/2)
//  TCCR2B |= (1 << WGM12); // Włącz tryb CTC (Clear Timer on Compare match)
//  TCCR2B |= (1 << CS10); // Ustaw preskaler na 1 (brak preskalera)
//  TIMSK2 |= (1 << OCIE1A); // Włącz przerwanie porównania dla timera1
//  interrupts(); // Włącz przerwania
//}
//
//ISR(TIMER2_COMPA_vect) { // Procedura obsługi przerwania
//Serial.println(digitalRead(2));
//}
//
//void loop()
//{
//  uint8_t buf[1];
//  uint8_t buflen = sizeof(buf);
//  if (rf_driver.recv(buf, &buflen))
//  {
//    Serial.println((char*)buf);         
//  }      
//}

//void setup() {
//  // Konfiguracja pinu jako wejście
//  pinMode(7, INPUT);
//  pinMode(8, INPUT);
//  Serial.begin(115200);
//
//  // Konfiguracja timera1 do generowania przerwania co 100 mikrosekund (10 000 razy na sekundę)
//  noInterrupts(); // Wyłącz przerwania
//  TCCR1A = 0; // Ustaw wszystkie bity rejestru TCCR1A na 0
//  TCCR1B = 0; // Analogicznie dla TCCR1B
//  TCNT1  = 0; // Inicjalizacja licznika timera1 na 0
//  OCR1A = 159; // Przerwanie będzie generowane, gdy licznik osiągnie tę wartość (16MHz/10000/2)
//  TCCR1B |= (1 << WGM12); // Włącz tryb CTC (Clear Timer on Compare match)
//  TCCR1B |= (1 << CS10); // Ustaw preskaler na 1 (brak preskalera)
//  TIMSK1 |= (1 << OCIE1A); // Włącz przerwanie porównania dla timera1
//  interrupts(); // Włącz przerwania
//}
//
//ISR(TIMER1_COMPA_vect) { // Procedura obsługi przerwania
//int pin7 = digitalRead(7);
//int pin8 = digitalRead(8);
//if (pin7 == pin8){
//Serial.println(digitalRead(7));
//}
//}
//
//void loop() {
//}


// working good
//#include <RH_ASK.h> 
//#include <SPI.h> 
// 
//
//const int digitalInputPin = 7; // Numer cyfrowego pinu
//const int samplingRate = 10000; // Prędkość próbkowania w próbkach na sekundę
//const unsigned long samplingInterval = 1000000 / samplingRate; // Interwał próbkowania w mikrosekundach
//
//unsigned long lastSampleTime = 0; // Czas ostatniej próbki
//
//
//void setup()
//{
//    Serial.begin(115200);
//}
// 
//void loop()
//{
//  unsigned long currentTime = micros();
//  Serial.println(currentTime);
//
//
//  if (currentTime - lastSampleTime >= samplingInterval) {
//    lastSampleTime = currentTime;
//
//
//    int sampledValue = digitalRead(digitalInputPin);
//
//    Serial.println(sampledValue);
//}
//}


//#include <RH_ASK.h> 
//#include <SPI.h> 
//
//#define MAX_MESSAGE_LENGTH 64
// 
//RH_ASK rf_driver(2000, 6);
// 
//void setup()
//{
//    rf_driver.init();
//    Serial.begin(9600);
//}
// 
//void loop() {
//  uint8_t buf[MAX_MESSAGE_LENGTH];
//  uint8_t buflen = sizeof(buf);
//
//  if (rf_driver.recv(buf, &buflen)) {
////    buf[buflen] = '\0'; // Dodaj znak null, aby uzyskać poprawny ciąg znaków
//    Serial.println((char *)buf);
//  }
//}
