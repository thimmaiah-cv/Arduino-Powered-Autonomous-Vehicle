#define EnableR 10
#define LowR 9 
#define HighR 8
#define LowL 7 
#define HighL 6 
#define EnableL 5 
#define Left_IR A0 
#define Right_IR A1 
#define echo A2 
#define trigger A3 
int Obj_Distance_Limit = 25; 
int distance_Left; 
int distance_Front; 
int distance_Right; 
void setup() 
{ 
Serial.begin(9600); 
pinMode(Right_IR, INPUT); 
pinMode(Left_IR, INPUT); 
pinMode(echo, INPUT); 
pinMode(trigger, OUTPUT); 
pinMode(EnableR, OUTPUT); 
pinMode(LowR, OUTPUT); 
pinMode(HighR, OUTPUT); 
pinMode(LowL, OUTPUT); 
pinMode(HighL, OUTPUT); 
pinMode(EnableL, OUTPUT); 
analogWrite(EnableR, 60); 
analogWrite(EnableL, 60); 
pinMode(servo, OUTPUT);
distance_Front = Ultrasonic_read();
delay(500);
}
void loop() 
{
distance_Front = Ultrasonic_read();
Serial.print("D F=");
Serial.print(distance_Front);
Serial.println("cm");
if ((digitalRead(Right_IR) == 1) && (digitalRead(Left_IR) == 1)) 
{
if (distance_Front > Obj_Distance_Limit) 
{
forward();
} 
else 
{
Stop();
}
}
else if ((digitalRead(Right_IR) == 0) && (digitalRead(Left_IR) == 1)) 
{
turnRight();
}
else if ((digitalRead(Right_IR) == 1) && (digitalRead(Left_IR) == 0)) 
{
 turnLeft();
}
delay(10);
}
long Ultrasonic_read() 
{
digitalWrite(trigger, LOW);
delayMicroseconds(2);
digitalWrite(trigger, HIGH);
delayMicroseconds(10);
long time = pulseIn(echo, HIGH);
return time / 29 / 2;
}
void forward() 
{ 
digitalWrite(LowR, LOW); 
digitalWrite(HighR, HIGH); 
digitalWrite(LowL, HIGH); 
digitalWrite(HighL, LOW); 
}
void backward() 
{ 
digitalWrite(LowR, LOW); 
digitalWrite(HighR, HIGH); 
digitalWrite(LowL, HIGH); 
digitalWrite(HighL, LOW); 
}
void turnRight() 
{ 
digitalWrite(LowR, LOW); 
digitalWrite(HighR, LOW); 
digitalWrite(LowL, HIGH); 
digitalWrite(HighL, LOW); 
}
void turnLeft() 
{ 
digitalWrite(LowR, LOW); 
digitalWrite(HighR, HIGH); 
digitalWrite(LowL, LOW); 
digitalWrite(HighL, LOW); 
}
void Stop() 
{ 
digitalWrite(LowR, LOW); 
digitalWrite(HighR, LOW); 
digitalWrite(LowL, LOW); 
digitalWrite(HighL, LOW); 
}
