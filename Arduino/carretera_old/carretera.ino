#include <DHT.h>  

#define DHTPIN 2     // Pin donde está conectado el sensor

//#define DHTTYPE DHT11   // Descomentar si se usa el DHT 11
#define DHTTYPE DHT22   // Sensor DHT22

DHT dht(DHTPIN, DHTTYPE);

int temporizador = 0; // temporizador a 0
int manual = 0;       // estado en AUTOMATICO
int leds = 0;         // leds apagados

void manageChar(char c){
    //if the char equals 1
      if(c=='9')
    {
        leds = 9;
    }
    
    if(c=='1')
    {
        leds = 1;
    }

    //if the char equals 0
    if(c=='0')
    {
        leds = 0;
    }
    if(c=='M')
    {
        manual = 1;
        leds = 0;
    }
    if(c=='A')
    {
        manual = 0;
        leds = 0;
    }

}

void setup() {
  Serial.begin(19200);
  //Serial.println("Iniciando...");
  dht.begin();
  
  pinMode(13, INPUT);   // sensor IR
  pinMode(12, INPUT);   // sensor IR
  pinMode(11, INPUT);   // sensor IR
  pinMode(10, INPUT);   // sensor IR
  pinMode(9, OUTPUT);   // led
  pinMode(8, OUTPUT);   // led
  pinMode(7, OUTPUT);   // led
  pinMode(6, OUTPUT);   // led
  pinMode(5, OUTPUT);   // led
  pinMode(4, OUTPUT);   // led
  pinMode(3, OUTPUT);   // led
  pinMode(2, INPUT);   // led
  pinMode(1, INPUT);    // sensor Temp y humedad
}

void loop() {
  float h = dht.readHumidity(); //Leemos la Humedad
  float t = dht.readTemperature(); //Leemos la temperatura en grados Celsius
  //--------Enviamos las lecturas por el puerto serial-------------
  Serial.print("H, ");
  Serial.println(h);
  Serial.print("T, ");
  Serial.println(t);
  
// Modo automatico
  if (manual == 0) {
    if (digitalRead(13) || digitalRead(12) || digitalRead(11) || digitalRead(10)) {

      if (temporizador == 0) {
          temporizador = 10;
      }
    }
    if (temporizador > 0) {
      temporizador = temporizador - 1;
      Serial.print("S, ");
      Serial.println(temporizador);
      
      digitalWrite(5, HIGH);  
      digitalWrite(4, HIGH); 
      digitalWrite(3, HIGH);  
      digitalWrite(2, HIGH); 
      delay(500);
      digitalWrite(5, LOW);   
      digitalWrite(4, LOW);    
      digitalWrite(3, LOW);   
      digitalWrite(2, LOW);
      digitalWrite(9, HIGH);  
      digitalWrite(8, HIGH);   
      digitalWrite(7, HIGH);    
      digitalWrite(6, HIGH); 
      delay(500);
      digitalWrite(9, LOW);  
      digitalWrite(8, LOW);    
      digitalWrite(7, LOW);     
      digitalWrite(6, LOW);
    }
    else {
      digitalWrite(9, LOW);  
      digitalWrite(8, LOW);   
      digitalWrite(7, LOW);    
      digitalWrite(6, LOW);   
      digitalWrite(5, LOW);   
      digitalWrite(4, LOW);    
      digitalWrite(3, LOW);   
      digitalWrite(2, LOW);
      delay(1000);
    }
  }
  else // Modo manual
       if (leds == 9) {
        digitalWrite(9, HIGH);  
        delay(250);
        digitalWrite(8,HIGH);
        delay(250);
        digitalWrite(7,LOW) ;
        delay(250);
        digitalWrite(6,HIGH);
        digitalWrite(8,LOW) ;
        delay(250);
        digitalWrite(5,HIGH);
        digitalWrite(8,LOW) ;
        delay(250);
        digitalWrite(4,HIGH);
        digitalWrite(7,LOW);
        delay(250);
        digitalWrite(3,HIGH);
        digitalWrite(6,LOW);
        delay(250);
        digitalWrite(2,HIGH);
        digitalWrite(5,LOW) ;
        delay(250);
        digitalWrite(4,LOW);
        delay(250);
        digitalWrite(3,LOW);
        delay(250);
        digitalWrite(2,LOW);
        Serial.println("X");
       }
      if (leds == 1) {
        digitalWrite(9, HIGH);  
        digitalWrite(8, HIGH);   
        digitalWrite(7, HIGH);    
        digitalWrite(6, HIGH);   
        digitalWrite(5, HIGH);   
        digitalWrite(4, HIGH);    
        digitalWrite(3, HIGH);   
        digitalWrite(2, HIGH); 
        Serial.println("L");
        delay(500);
        
     }
     else {
        digitalWrite(9, LOW);  
        digitalWrite(8, LOW);   
        digitalWrite(7, LOW);    
        digitalWrite(6, LOW);   
        digitalWrite(5, LOW);   
        digitalWrite(4, LOW);    
        digitalWrite(3, LOW);   
        digitalWrite(2, LOW);
        Serial.println("S, 0");
        delay(500);
     }

  while(Serial.available()>0){
    char incomingChar = Serial.read();
    manageChar(incomingChar);
  }
  
     
}
