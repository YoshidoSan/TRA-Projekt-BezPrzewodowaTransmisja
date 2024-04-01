const int samplingFrequency = 2000;
const long samplingIntervalMicros = 1000000 / samplingFrequency;

void setup() {
  Serial.begin(115200);
  pinMode(2, INPUT);
  noInterrupts();

  TCCR1A = 0;  // Tryb normalny
  TCCR1B = 0;  // Reset rejestrów konfiguracyjnych
  TCNT1 = 0;   // Reset licznika timera

  OCR1A = (16e6) / samplingFrequency - 1;  // 16e6 to częstotliwość mikrokontrolera Arduino
  TCCR1B |= (1 << WGM12);
  TCCR1B |= (1 << CS10) | (1 << CS11);
  TIMSK1 |= (1 << OCIE1A);  // przerwania po porównaniu z OCR1A

  interrupts();
}

void loop() {
}

ISR(TIMER1_COMPA_vect) {
  sampleFunction();
}

void sampleFunction() {
  Serial.println(digitalRead(2));
}
