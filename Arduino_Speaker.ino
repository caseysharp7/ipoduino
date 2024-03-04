#include <DFRobotDFPlayerMini.h>
#include <SoftwareSerial.h>

const int PIN_MP3_TX = 2;
const int PIN_MP3_RX = 3;
const int PIN_6 = 6;
const int PIN_7 = 7;
int playing = 1;

DFRobotDFPlayerMini player;

void setup() {
  SoftwareSerial softwareSerial(PIN_MP3_RX, PIN_MP3_TX);

  pinMode(6, INPUT_PULLUP);
  pinMode(7, INPUT_PULLUP);

  Serial.begin(9600);
  softwareSerial.begin(9600);

  if(!player.begin(softwareSerial)){
    Serial.println("Connection Failed");
  }

  player.volume(30);
  player.play(1);
}

void loop() {
  if(digitalRead(PIN_6) == LOW && playing == 1){
    player.pause();
    while(digitalRead(PIN_6) == LOW){delay(50);}
    delay(10);
    playing = 0;
  } else if(digitalRead(PIN_6) == LOW && playing == 0){
    player.start();
    while(digitalRead(PIN_6) == LOW){delay(50);}
    delay(10);
    playing = 1;
  }

  if(digitalRead(PIN_7) == LOW && playing == 1){
    player.next();
    while(digitalRead(PIN_7) == LOW){delay(50);}
    delay(10);
  } else if(digitalRead(PIN_7) == LOW && playing == 0){
    player.next();
    player.start();
    while(digitalRead(PIN_7) == LOW){delay(50);}
    delay(10);
    playing = 1;
  }
}
