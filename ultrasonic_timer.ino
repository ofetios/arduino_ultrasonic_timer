/* 
  Timer using the HC-SR04 ultrasonic sensor to detect when an object is in front of the timer
  Was used for timing a line follower robot

  created 10 Apr 2022
  by Ban Alexandru M.
*/

#define echoPin 2 
#define trigPin 3 

long duration; 
int distance; 

float timer1;
float timer2;
float time_Seconds;
float distance_object = 30; //distance from the sensor to the object
int delayTime = 1000; //give the object time to get out of the view of the sensor, in miliseconds

void setup() {
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT); 
  Serial.begin(9600); 
  Serial.println("Ultrasonic Timer"); 
  Serial.println("by alexban011");
}
void loop() {
  //CALCULATE DISTANCE FROM SENSOR TO OBJECT
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)

  //THE OBJECT IS IN FRONT OF THE SENSOR
  if(distance < distance_object){
    timer1 = timer2;  //start time
    timer2 = millis(); //end time
    time_Seconds = (timer2-timer1)/1000; //calculate the time and convert in seconds
    Serial.print("Time: ");
    Serial.print(time_Seconds);
    Serial.print(" s");
    Serial.println();
    delay(delayTime); //
  }
}
