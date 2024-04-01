#include <RCSwitch.h>
RCSwitch mySwitch = RCSwitch();


void send(int k, int p, String msg){
  Serial.print("send_");
  Serial.print("rep_");
  Serial.print(k);
  Serial.print("_p_");
  Serial.print(p);
  Serial.print("_s_");
  Serial.println(msg);
  const char* msgCharArray = msg.c_str();
  mySwitch.send(msgCharArray);
  delay(500);
}

void setup() {
  Serial.begin(9600);
   
  mySwitch.enableTransmit(10);

  mySwitch.setProtocol(1);
 
  mySwitch.setRepeatTransmit(4); // 4 razy musi być powtarzana transmisja, żeby tamten odebrał przy prot1
}


void test_repetitions_protocols() {
  delay(5000);
  for (int k = 1; k<10; k++){
    mySwitch.setRepeatTransmit(k);
    for (int p = 1; p<27; p++){

    mySwitch.setProtocol(p);

    send(k, p, "00100101100010010110");
  
    send(k, p, "01000001011001000110000101101101");
    
    send(k, p, "100");
    
    send(k, p, "111");
    }
  }
}


void test(){
  Serial.println("00100101100010010110");
  mySwitch.send("00100101100010010110");
  delay(500);
  Serial.println("01000001011001000110000101101101");
  mySwitch.send("01000001011001000110000101101101");
  delay(500);
  Serial.println("100");
  mySwitch.send("100");
  delay(500);
  Serial.println("111");
  mySwitch.send("111");
  delay(500);
}


void loop(){
  test();
//  test_repetitions_protocols();
}
