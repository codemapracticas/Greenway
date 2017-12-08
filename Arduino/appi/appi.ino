int estado = 0;

void setup() {

    Serial.begin(19200) ;
    pinMode(13, OUTPUT) ;
    
}

void loop (){

   if (Serial.available() > 0) {
          char incomingData = Serial.read();
          if (incomingData == '1')
              estado = 1;
          else
              estado = 0;
    }
    if (estado == 1)
        digitalWrite(13, HIGH);
    else
        digitalWrite(13, LOW);
}



