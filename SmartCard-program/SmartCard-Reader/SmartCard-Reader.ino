float sec = 1.5;               //time in seconds
bool stato = false;
bool flag;


void setup() {
 Serial.begin(9600);
 pinMode(2, OUTPUT);
 digitalWrite(2, LOW);
 sec *= 1000;
}


void loop() {
  if(digitalRead(1) == HIGH){
    digitalWrite(2, HIGH);
    Serial.println("Accensione");
    stato = true;
    delay(sec);
  }
  if(stato){
    Serial.println("Acceso");
    Serial.println("In attesa di carta...");
    while(flag == false){
      float controlla = analogRead(A0);
      controlla = controlla/0.2046;             //trasformation in mV
      if(controlla > 0.5){
        Serial.println("Connessa");
        flag = true;
      }else{
        Serial.println("Assente");
        flag = false;
      }
      if(digitalRead(1) == HIGH){
        digitalWrite(2, LOW);
        Serial.println("Spegnimento");
        stato = false;
        delay(sec);
    }
      delay(sec);
    }
    int cont = 0;
    while(flag == true){
      if(cont == 8){
        Serial.print("\n");
        cont = 0;
      }
      int lettura = digitalRead(0);
      float controlla = analogRead(A0);
      controlla = controlla/0.2046;             //trasformation in mV
      lettura = lettura/0.2046;
      Serial.print(lettura);
      if(controlla < 0.5){
        Serial.println("\nDisconnessa");
        flag = false;
      }
      cont++;
      delay(sec/4);
      if(digitalRead(1) == HIGH){
        digitalWrite(2, LOW);
        Serial.println("Spegnimento");
        stato = false;
        delay(sec);
    }
    }
  }else{
    Serial.println("Spento");
    delay(sec);
  }
}
