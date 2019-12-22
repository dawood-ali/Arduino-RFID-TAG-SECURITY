#include <MFRC522.h>
#include <SPI.h>
#include <Servo.h>

#define SS_PIN 53
#define RST_PIN 49
#define Buzzer 8
#define RED 11
#define GREEN 12
#define button 7
int initial_pos=0;
long unsigned int keytounclock_decimal[4]= {137,187,93,71};
long unsigned key_read[4];
MFRC522 mfrc522(SS_PIN,RST_PIN);
Servo myservo;
void setup() {
 Serial.begin(9600);
 SPI.begin();
 myservo.attach(9);
 mfrc522.PCD_Init();
 pinMode(Buzzer,OUTPUT);
 pinMode(button,INPUT);
 digitalWrite(button,HIGH);
 pinMode(RED,OUTPUT);
 pinMode(GREEN,OUTPUT);
 Serial.println("Place card close to reader");
}

void loop() {
  if (mfrc522.PICC_IsNewCardPresent()) {
    if (mfrc522.PICC_ReadCardSerial()) {
      long unsigned key_read[mfrc522.uid.size];
      for (byte i=0; i<mfrc522.uid.size;i++) {
        key_read[i]=mfrc522.uid.uidByte[i];
      }
      int comparison=0;
      for (int i=0; i<4; i++) {
        if (keytounclock_decimal[i]==key_read[i]) {
          comparison++;
    }
    }
      if (comparison==4) {
        int button_count=0;
        Serial.println("access granted");
        digitalWrite(Buzzer,HIGH);
        digitalWrite(GREEN,HIGH);
        delay(1000);
        digitalWrite(Buzzer,LOW);
        Serial.println("Please press thy button to start and again to finish");
        while (digitalRead(button)==HIGH) {
          delay(5);
        }
        while(digitalRead(button)==LOW) {
          delay(15);
          if (digitalRead(button)==HIGH) {
            button_count++;
            Serial.println("Button pressed once");
          }
        }
        while (button_count==1) {
          int value= analogRead(0);
          int degree= (double(double(value)/1023)*180);
          myservo.write(degree);

          while (digitalRead(button)==LOW) {
            delay(15);
            if (digitalRead(button)==HIGH) {
              button_count++;
              Serial.println("Button pressed twice");
            }
          }
        }
        digitalWrite(GREEN,LOW);
  }
      if (comparison!=4) {
        Serial.println("Access denied");
        digitalWrite(Buzzer,HIGH);
        digitalWrite(RED,HIGH);
        delay(1000);
        digitalWrite(Buzzer,LOW);
        digitalWrite(RED,LOW);
        
  }
      
      Serial.flush();
      mfrc522.PICC_HaltA();
  }
  }
}
