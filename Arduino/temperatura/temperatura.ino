#include <DHT.h>  

int ledPin = 2; 

void manageChar(char c){
    //if the char equals H
    if(c='H')
    {
        digitalWrite(ledPin, HIGH); //switch LED on   
    }

    //if the char equals L
    if(c='L')
    {
        digitalWrite(ledPin,LOW); //switch LED off
    }
}

void waitForInput(){
  while(Serial.available()==0){
    delay(500);    
    }
while(Serial.available()>0){
    char incomingChar = Serial.read();
    manageChar(incomingChar);
  }
}

#define DHTPIN 2     // Pin donde está conectado el sensor

//#define DHTTYPE DHT11   // Descomentar si se usa el DHT 11
#define DHTTYPE DHT22   // Sensor DHT22

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  Serial.println("Iniciando...");
  dht.begin();
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(6, OUTPUT);
}

void loop() {
  float h = dht.readHumidity(); //Leemos la Humedad
  float t = dht.readTemperature(); //Leemos la temperatura en grados Celsius
  //--------Enviamos las lecturas por el puerto serial-------------
  Serial.print("H, ");
  Serial.println(h);
  Serial.print("T, ");
  Serial.println(t);
  
digitalWrite(13, HIGH);  
digitalWrite(12, HIGH); 
digitalWrite(11, HIGH);  
digitalWrite(10, HIGH); 
delay(1000);
digitalWrite(13, LOW);   
digitalWrite(12, LOW);    
digitalWrite(11, LOW);   
digitalWrite(10, LOW);
digitalWrite(9, HIGH);  
digitalWrite(8, HIGH);   
digitalWrite(7, HIGH);    
digitalWrite(6, HIGH); 
delay(1000);
digitalWrite(9, LOW);  
digitalWrite(8, LOW);    
digitalWrite(7, LOW);     
digitalWrite(6, LOW);     
}
