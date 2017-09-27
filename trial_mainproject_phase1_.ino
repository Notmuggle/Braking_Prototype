int motor1_dir1 = 5;
int motor1_dir2 = 4;

int motor2_dir1 = 3;
int motor2_dir2 = 2;

const int trigPin1=11;
const int echoPin1=10;


void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);

    pinMode(motor1_dir1,OUTPUT);
    pinMode(motor1_dir2,OUTPUT);
    
    pinMode(motor2_dir1,OUTPUT);
    pinMode(motor2_dir2,OUTPUT);
  
    digitalWrite(motor1_dir1,HIGH);
    digitalWrite(motor1_dir2,LOW);
  
    digitalWrite(motor2_dir1,HIGH);
    digitalWrite(motor2_dir2,LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
int cm1,duration1;
   pinMode(trigPin1,OUTPUT);
    digitalWrite(trigPin1,LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin1,HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin1,LOW);
    pinMode(echoPin1,INPUT);
    duration1=pulseIn(echoPin1,HIGH);
   cm1= microsecondsToCentimeters(duration1);

   if(cm1>10)
   {
 digitalWrite(motor1_dir1,HIGH);
    digitalWrite(motor1_dir2,LOW);
  
    digitalWrite(motor2_dir1,HIGH);
    digitalWrite(motor2_dir2,LOW);
   }
else
{
 digitalWrite(motor1_dir1,LOW);
    digitalWrite(motor1_dir2,LOW);
  
    digitalWrite(motor2_dir1,LOW);
    digitalWrite(motor2_dir2,LOW);
}
    
}

long microsecondsToCentimeters(long microseconds)
{
return microseconds / 29 / 2;
} 
