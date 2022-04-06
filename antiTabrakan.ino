#define echoPinA 3 //Echo Pin
#define trigPinA 2 //Trigger Pin
#define echoPinB 5 //Echo Pin
#define trigPinB 4
#include <Servo.h>
Servo servoku;
long durationA, durationB; //waktu untuk kalkulasi jarak
int distanceA, distanceB;
int matlab;
void setup() {
  Serial.begin (9600); //inisialiasasi komunikasi serial

  pinMode(trigPinA, OUTPUT);
  pinMode(echoPinA, INPUT);
  pinMode(trigPinB, OUTPUT);
  pinMode(echoPinB, INPUT);
  servoku.attach(6);
}

void loop() {

  digitalWrite(trigPinA, LOW);delayMicroseconds(2);
  digitalWrite(trigPinA, HIGH);delayMicroseconds(10);
  digitalWrite(trigPinA, LOW);
  durationA = pulseIn(echoPinA, HIGH);
  
  //perhitungan untuk dijadikan jarak
  distanceA = durationA/58.2;
  if (distanceA >= 100){
    distanceA = 100;
  }

  digitalWrite(trigPinB, LOW);delayMicroseconds(2);
  digitalWrite(trigPinB, HIGH);delayMicroseconds(10);
  digitalWrite(trigPinB, LOW);
  durationB = pulseIn(echoPinB, HIGH);
  
  //perhitungan untuk dijadikan jarak
  distanceB = durationB/58.2;
  if (distanceB >= 100){
    distanceB = 100;
  }
  while(Serial.available()>0){
    matlab = Serial.read();
  }



  //Serial.print("Jarak HCSR A: ");
  Serial.print(distanceA);
  //Serial.print("cm");
  Serial.print(";");

  //Serial.print(" Jarak HCSR B: ");
  Serial.println(distanceB);
  //Serial.println("cm");
  
  if(matlab==0){
    servoku.write(100);
    //Serial.println("Rem menyala");
  }
  else if(matlab==1){
    servoku.write(10);
    //Serial.println("Rem mati");
  }
  

  //waktu tunda 50mS
  delay(500
  );

}
