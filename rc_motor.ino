#include <Wire.h>  
#include <LiquidCrystal_I2C.h> // Using version 1.2.1
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);  

int pos = 0; //position for servo

int ch1=0000; // Here's where we'll keep our channel values

int ch2=0000;

int ch3=0000;
int i=000;
int u=000;
int y=000;
int range=0;

void setup() {
  // put your setup code here, to run once:
pinMode(11, OUTPUT);//pin 11 is connected to mosfet
pinMode(9, OUTPUT);
pinMode(5, OUTPUT);
  Serial.begin(9600); // Pour a bowl of Serial
lcd.begin(16,2); // sixteen characters across - 2 lines
  lcd.backlight();
  // first character - 1st line
  lcd.setCursor(1,0);
  lcd.print("STARTING...");
  // 8th character - 2nd line 
  lcd.setCursor(0,1);
  
for (int p = 0; p <=16 ; p++) {
    // turn the pin on:
    lcd.print("=");
     delay(50);
  
  }
  delay(100);
  lcd.setCursor(0,0);
  lcd.print("                   ");
  lcd.setCursor(0,1);
   lcd.print("                   ");
}

void loop() {
  // any pin can read pwm
ch1 = pulseInLong(4, HIGH, 25000); // Read the pulse width of

ch2 = pulseInLong(6, HIGH, 25000); // each channel

ch3 = pulseInLong(7, HIGH, 25000);

Serial.print("Channel 1:"); // Print the value of

Serial.println(ch1); // each channel

Serial.print("Channel 2:");

Serial.println(ch2);

Serial.print("Channel 3:");

Serial.println(ch3);
while(range<=3) {
    switch (range) {
    case 0:    // your hand is on the sensor
      lcd.setCursor(0,1);
  lcd.print("Channel 1");
lcd.setCursor(0,0);
  lcd.print("RAW:");
  lcd.print("0000");
  lcd.setCursor(4,0);
   lcd.print(ch1);
  lcd.setCursor(9,0);
  lcd.print("PWM:");
  lcd.print("000");
  //lcd.setCursor(12,0);
   lcd.print("100");
      break;
    case 1:    // your hand is close to the sensor
      lcd.setCursor(0,1);
  lcd.print("Channel 2");
lcd.setCursor(0,0);
  lcd.print("RAW:");
  lcd.print("0000");
  lcd.setCursor(4,0);
   lcd.print("1000");
  lcd.setCursor(9,0);
  lcd.print("PWM:");
  lcd.print("000");
  //lcd.setCursor(12,0);
   lcd.print("100");
      break;
    case 2:    // your hand is a few inches from the sensor
       lcd.setCursor(0,1);
  lcd.print("Channel 3");
lcd.setCursor(0,0);
