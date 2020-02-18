int pos = 0; //position for servo

int ch1; // Here's where we'll keep our channel values

int ch2;

int ch3;
int i;
int u;
int y;

void setup() {
  // put your setup code here, to run once:
pinMode(11, OUTPUT);//pin 11 is connected to mosfet
pinMode(9, OUTPUT);
pinMode(5, OUTPUT);
Serial.begin(9600); // Pour a bowl of Serial

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
//=========================================
//=============channel 1=============  
 if(ch1<1010)
{
   Serial.print("Ch1 pwm:");
Serial.println(i);
analogWrite(11, 0);
}
else{
  i = 0.273*(ch1)-263; //converts 2000-1000 to 1-255
  Serial.print("Ch1 pwm:");
 Serial.println(i);
 analogWrite(11, i);
}
//=========================================
//=============channel 2=============
 if(ch2<1010)
{
  Serial.print("Ch2 pwm:");
Serial.println(u);
analogWrite(9, 0);
}
else{
  u = 0.273*(ch2)-253; //converts 2000-1000 to 1-255
  Serial.print("Ch2 pwm:");
 Serial.println(u);
 analogWrite(9, u);
}
//=========================================
//=============channel 3=============
 if(ch3<1010)
{
   Serial.print("Ch3 pwm:");
Serial.println(y);
analogWrite(5, 0);
}
    else{
  y = 0.273*(ch3)-253; //converts 2000-1000 to 1-255
   Serial.print("Ch3 pwm:");
 Serial.println(y);
 analogWrite(5, y);
}
}
