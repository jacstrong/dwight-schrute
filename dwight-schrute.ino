#include <Servo.h>

Servo myservo;
int sensorPin = 4;

int pos = 100;

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  // start serial port at 9600 bps and wait for port to open:
//    Serial.begin(9600);
  //  while (!Serial) {
  //    ; // wait for serial port to connect. Needed for native USB port only
  //  }
  //  establishContact();
    
  myservo.attach(12);
  myservo.write(pos);
  pinMode(sensorPin, INPUT);
  randomSeed(analogRead(0));
}

void loop() {
  if (digitalRead(sensorPin) == 1) {
    digitalWrite(LED_BUILTIN, 0);
  } else {
    digitalWrite(LED_BUILTIN, 1);
    return;
  }

  delay(2000);

  if (digitalRead(sensorPin) == 1) {
    digitalWrite(LED_BUILTIN, 0);
  } else {
    digitalWrite(LED_BUILTIN, 1);
    return;
  }

  delay(2000);
    
  if (digitalRead(sensorPin) == 1) {
    blinkLight();
  } else {
    return;
  }

  int randomNumber = random(3);
  if (randomNumber == 0) {
    delay(10000);
    blinkLight();
    for (int i = 0; i < 20; i++) {
      pos++;
      myservo.write(pos);
      delay(70);
    }
    delay(5000);
    for (int i = 0; i < 20; i++) {
      pos--;
      myservo.write(pos);
      delay(70);
    }
  } else if (randomNumber == 1) {
    delay(10000);
    blinkLight();
    blinkLight();
    for (int i = 0; i < 10; i++) {
      pos += 2;
      myservo.write(pos);
      delay(70);
    }
    delay(5000);
    for (int i = 0; i < 20; i++) {
      pos--;
      myservo.write(pos);
      delay(70);
    }
  } else if (randomNumber == 2) {
    delay(10000);
    blinkLight();
    blinkLight();
    blinkLight();
    
    for (int i = 0; i < 10; i++) {
      pos += 2;
      myservo.write(pos);
      delay(70);
    }
    delay(2000);
    for (int i = 0; i < 10; i++) {
      pos--;
      myservo.write(pos);
      delay(70);
    }
    for (int i = 0; i < 10; i++) {
      pos++;
      myservo.write(pos);
      delay(70);
    }
    delay(4000);
    for (int i = 0; i < 20; i++) {
      pos--;
      myservo.write(pos);
      delay(70);
    }
  }
  digitalWrite(LED_BUILTIN, 1);
}

void blinkLight () {
  delay(300);
  digitalWrite(LED_BUILTIN, 1);
  delay(300);
  digitalWrite(LED_BUILTIN, 0);
}
