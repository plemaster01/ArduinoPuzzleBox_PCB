#include <Servo.h>
Servo myServo;  // create a servo object
const int servoPin = 3;
const int capSensor1 = A4;
const int capSensor2 = A5;
const int capSensor3 = A6;
const int capSensor4 = A7;
const int red1 = 13;
const int green1 = 9;
const int white1 = 5;
const int red2 = 12;
const int green2 = 8;
const int white2 = 4;
const int red3 = 11;
const int green3 = 7;
const int white3 = A0;
const int red4 = 10;
const int green4 = 6;
const int white4 = 2;
int state1 = 0;
int state2 = 0;
int state3 = 0;
int state4 = 0;
int cap1 = 0;
int cap2 = 0;
int cap3 = 0;
int cap4 = 0;
int last1 = 0;
int last2 = 0;
int last3 = 0;
int last4 = 0;
int angle;
String formatted_str;
int cap3_analog;
int cap4_analog;

int code[4] = {4,3,2,1};
int guess[4] = {0,0,0,0};
int place = 0;

void setup() {
  Serial.begin(9600);
  myServo.attach(servoPin);
  pinMode(capSensor1, INPUT);
  pinMode(capSensor2, INPUT);
  pinMode(capSensor3, INPUT);
  pinMode(capSensor4, INPUT);
  for (int pinNumber = 2; pinNumber < 14; pinNumber++) {
    pinMode(pinNumber, OUTPUT);
    digitalWrite(pinNumber, LOW);
  }
  pinMode(servoPin, OUTPUT);
  pinMode(white3, OUTPUT);
  digitalWrite(white3, LOW);
}

void check_answer(){
  if (guess[0] == code[0]){
      digitalWrite(green1, HIGH);
    }
  else{
      digitalWrite(red1, HIGH);
    }
  digitalWrite(white1, LOW);
  delay(300);

  if (guess[1] == code[1]){
    digitalWrite(green2, HIGH);
  }
  else{
    digitalWrite(red2, HIGH);
  }
  digitalWrite(white2, LOW);
  delay(300);

  if (guess[2] == code[2]){
    digitalWrite(green3, HIGH);
  }
  else{
    digitalWrite(red3, HIGH);
  }
  digitalWrite(white3, LOW);
  delay(300);

  if (guess[3] == code[3]){
    digitalWrite(green4, HIGH);
  }
  else{
    digitalWrite(red4, HIGH);
  }
  digitalWrite(white4, LOW);
  delay(1000);

  if (guess[0] == code[0] && guess[1] == code[1] && guess[2] == code[2] && guess[3] == code[3]) {
    myServo.write(0);
    Serial.println("IM TRYING OK");
    delay(1000);
  }

  else {
    myServo.write(180);
    delay(1000);
  }

  place = 0;
    Serial.print(guess[0]);
    Serial.print(guess[1]);
    Serial.print(guess[2]);
    Serial.println(guess[3]);
    Serial.print(code[0]);
    Serial.print(code[1]);
    Serial.print(code[2]);
    Serial.println(code[3]);
    int guess[] = {0,0,0,0};
    digitalWrite(red1, LOW);
    digitalWrite(red2, LOW);
    digitalWrite(red3, LOW);
    digitalWrite(red4, LOW);
    digitalWrite(green1, LOW);
    digitalWrite(green2, LOW);
    digitalWrite(green3, LOW);
    digitalWrite(green4, LOW);
}


void loop() {
  cap1 = digitalRead(capSensor1);
  cap2 = digitalRead(capSensor2);
  cap3_analog = analogRead(capSensor3);
  cap4_analog = analogRead(capSensor4);
  if (cap3_analog > 500){
    cap3 = true;
  }
  else {
    cap3 = false;
  }
  if (cap4_analog > 500){
    cap4 = true;
  }
  else {
    cap4 = false;
  }

  if (cap1 == 1 and last1 == 0){
    guess[place] = 1;
    place += 1;
    Serial.println('1');
  }
  if (cap2 == 1 and last2 == 0){
    guess[place] = 2;
    place += 1;
    Serial.println('2');
    }
  if (cap3 == 1 and last3 == 0){
    guess[place] = 3;
    place += 1;
    Serial.println('3');
  }
  if (cap4 == 1 and last4 == 0){
    guess[place] = 4;
    place += 1;
    Serial.println('4');
  }

  last1 = cap1;
  last2 = cap2;
  last3 = cap3;
  last4 = cap4;
  if (angle < 0){
    angle = 0;
  }
  if (angle > 180){
    angle = 180;
  }
  if (place > 0){
      digitalWrite(white1, HIGH);
  }
  if (place > 1){
      digitalWrite(white2, HIGH);
  }
  if (place > 2){
      digitalWrite(white3, HIGH);
  }
  if (place > 3){
      digitalWrite(white4, HIGH);
  }
  if (place == 4){
    check_answer();
  }

  delay(10);
}
