#define trigPin 3
#define echoPin 2
#define led 8
#define led2 9
#define led3 10

#include <LiquidCrystal.h> // includes the LiquidCrystal Library
LiquidCrystal lcd(0, 1, 4, 5, 6, 7); // Creates an LC object. Parameters: (rs, enable, d4, d5, d6, d7)

void setup() {
// Serial.begin (9600);
 pinMode(trigPin, OUTPUT);
 pinMode(echoPin, INPUT);
 pinMode(led, OUTPUT);
 pinMode(led2, OUTPUT);
 pinMode(led3, OUTPUT);
 lcd.begin(16,2); // Initializes the interface to the LCD screen, and specifies the dimensions (width and height) of the display
 
}

void loop() {

 lcd.setCursor(0,1); // Sets the location at which subsequent text written to the LCD will be displayed
 
 long duration, distance;
 digitalWrite(trigPin, LOW);  // Added this line
 delayMicroseconds(2); // Added this line
 digitalWrite(trigPin, HIGH);
//  delayMicroseconds(1000); - Removed this line
 delayMicroseconds(10); // Added this line
 digitalWrite(trigPin, LOW);
 duration = pulseIn(echoPin, HIGH);
 distance = (duration/2) / 29.1;

 
 if (distance > 30) {  // This is where the LED On/Off happens
  digitalWrite(led,HIGH); // When the Red condition is met, the Green LED should turn off
  digitalWrite(led2,LOW);
  digitalWrite(led3,LOW);
  lcd.clear();
  lcd.print("FIGHT!"); // Prints "Arduino" on the LCD
}
 else if (distance > 15 && distance <= 29  ){
   digitalWrite(led,LOW);
   digitalWrite(led2,HIGH);
   digitalWrite(led3,LOW);
   lcd.clear();
   lcd.print("OHH DAMN");
   
   
 } else {
   digitalWrite(led,LOW);
   digitalWrite(led2,LOW);
   digitalWrite(led3,HIGH);
   lcd.clear();
   lcd.print("FINISH HIM!");
 }

 
// if (distance >= 200 || distance <= 0){
//   Serial.println("Out of range");
// }
// else {
//   Serial.print(distance);
//   Serial.println(" cm");
// }
// delay(500);
}
