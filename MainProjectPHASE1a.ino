 #include <TinyGPS.h>
TinyGPS gps;  //Creates a new instance of the TinyGPS object

int motor1_dir1 = 5;
int motor1_dir2 = 4;

int motor2_dir1 = 7;
int motor2_dir2 = 2;

int enablepin = 3;

const int trigPin1=11;
const int echoPin1=10;

int switch1 = 6;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);

    pinMode(motor1_dir1,OUTPUT);
    pinMode(motor1_dir2,OUTPUT);
    
    pinMode(motor2_dir1,OUTPUT);
    pinMode(motor2_dir2,OUTPUT);

    pinMode(enablepin, OUTPUT);
  
    digitalWrite(motor1_dir1,HIGH);
    digitalWrite(motor1_dir2,LOW);
  
    digitalWrite(motor2_dir1,HIGH);
    digitalWrite(motor2_dir2,LOW);

    Serial.begin(9600);  
 Serial.println(TinyGPS::library_version());
  Serial.println("Testing GPS");
  Serial.println();
  
}

void loop() {
  // put your main code here, to run repeatedly:
int duration1,val,cm1=0;
//int speedmap = map(cm1, 0, 2000, 0, 255);
   pinMode(trigPin1,OUTPUT);
    digitalWrite(trigPin1,LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin1,HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin1,LOW);
    pinMode(echoPin1,INPUT);
    duration1=pulseIn(echoPin1,HIGH);
   cm1= microsecondsToCentimeters(duration1);

   if(cm1>50)
   {
 digitalWrite(motor1_dir1,HIGH);
    digitalWrite(motor1_dir2,LOW);
  
    digitalWrite(motor2_dir1,HIGH);
    digitalWrite(motor2_dir2,LOW);

    analogWrite(enablepin, cm1);
   }
else
{
 digitalWrite(motor1_dir1,LOW);
    digitalWrite(motor1_dir2,LOW);
  
    digitalWrite(motor2_dir1,LOW);
    digitalWrite(motor2_dir2,LOW);
}
val= digitalRead(switch1);
if(val==LOW)
{
  callGPS();
}

    
}

long microsecondsToCentimeters(long microseconds)
{
return microseconds / 29 / 2;
} 

void callGPS()
{
  bool newData = false;
  unsigned long chars;
  unsigned short sentences, failed;

  // For one second we parse GPS data and report some key values
  for (unsigned long start = millis(); millis() - start < 100;)
  {
    while (Serial.available())
    {
      char c = Serial.read();
      //Serial.print(c);
      if (gps.encode(c)) 
        newData = true;  
    }
  }

  if (newData)      //If newData is true
  {
    float flat, flon;
    unsigned long age;
    gps.f_get_position(&flat, &flon, &age);   
    Serial.print("Latitude = ");
    Serial.print(flat == TinyGPS::GPS_INVALID_F_ANGLE ? 0.0 : flat, 6);
    Serial.print(" Longitude = ");
    Serial.print(flon == TinyGPS::GPS_INVALID_F_ANGLE ? 0.0 : flon, 6);

  }
 
  Serial.println(failed);
 // if (chars == 0)
   // Serial.println("** No characters received from GPS: check wiring **");

}

