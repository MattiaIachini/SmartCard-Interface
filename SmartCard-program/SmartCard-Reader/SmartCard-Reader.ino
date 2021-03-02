float sec = 1.5;               //time in seconds 
void setup() {
 Serial.begin(9600);
 sec *= 1000;
}

void loop() {
  float val = analogRead(A1);
  val = val/0.2046;             //trasformation in mV
  if(val > 0.5){
    Serial.println("Connect");
    
  }else{
    Serial.println("Disconnect");
  }
  delay(sec);
}
