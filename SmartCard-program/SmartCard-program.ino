
 void setup() {
 Serial.begin(9600);
}

// (val/0.2046)
void loop() {
  float val = analogRead(A1);
  val = val/0.2046;
  if(val > 0.5){
    Serial.println("Connessa");
  }else{
    Serial.println("Disconnessa");
  }
  delay(2000);
}
