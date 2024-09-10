#include <SoftwareSerial.h>
#define led 13
#define buzzer 10
SoftwareSerial bluetooth(2, 3); // TX sur pin 2, RX sur pin 3
void setup() {
  // Initialiser la communication avec le moniteur série (pour voir les données dans le terminal)
  Serial.begin(9600);
  
  // Initialiser la communication série pour le module Bluetooth
  bluetooth.begin(9600);
  pinMode(led, OUTPUT);
  pinMode(buzzer, OUTPUT);
}

void loop() {
  if (bluetooth.available() > 0) {
    // Lire la donnée reçue via Bluetooth
    String data = bluetooth.readString();
    Serial.print("Donnée reçue : ");
    Serial.println(data);
    if (data == "A"){
      digitalWrite(led, HIGH);
    }else if (data == "E"){
      digitalWrite(led, LOW);
    }else if (data == "B"){
      digitalWrite(buzzer, HIGH);
    }else if (data == "D"){
      digitalWrite(buzzer, LOW);
    }
    
  }

}/*
#define buzzer 10
void setup() {
  pinMode(buzzer, OUTPUT);
}
void loop() {
  digitalWrite(buzzer, HIGH);
  delay(1000);
  digitalWrite(buzzer, LOW);
}*/
