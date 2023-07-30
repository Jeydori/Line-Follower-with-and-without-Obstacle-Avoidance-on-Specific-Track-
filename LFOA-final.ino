
#define enA 3 
#define in1 4 
#define in2 5
#define in3 6
#define in4 7 
#define enB 9 

#define L_S A0
#define R_S A1

#define echo 11 
#define trigger 12 


int Set=15;
int distance_F; 

unsigned long lastMillis = 0;
unsigned long interval = 100;

void setup(){ 

Serial.begin(115200);

pinMode(R_S, INPUT);
pinMode(L_S, INPUT);

pinMode(echo, INPUT );
pinMode(trigger, OUTPUT);   

pinMode(enA, OUTPUT); 
pinMode(in1, OUTPUT); 
pinMode(in2, OUTPUT); 
pinMode(in3, OUTPUT);  
pinMode(in4, OUTPUT); 
pinMode(enB, OUTPUT); 

analogWrite(enA, 115); 
analogWrite(enB, 115); 

distance_F = Ultrasonic_read();

delay(500);

}

void loop(){  
distance_F = Ultrasonic_read();
Serial.print("D F=");Serial.println(distance_F);

//if Right and Left Sensor are at white color then it'll turn left and forward for both 50 milliseconds
if((digitalRead(R_S) == 0)&&(digitalRead(L_S) == 0)){
      if(millis() - lastMillis >= interval){
        lastMillis = millis();
        
         turnLeft(); delay(50); forward();delay(50);
      } 
}

//if Right Sensor and Left Sensor are at White color then it will call forword function
 if((digitalRead(R_S) == 0)&&(digitalRead(L_S) == 0)){
   Serial.print("Right = 0"); Serial.println("Left = 0");
  if(distance_F > Set)
  {Serial.println("No object"); forward();} else{ avoid();} 
 }  
 
//if Right Sensor is Black and Left Sensor is White then it will call turn Right function
else if((digitalRead(R_S) == 1)&&(digitalRead(L_S) == 0)){
  Serial.print("Right = 1"); Serial.println("Left = 0"); turnRight();}  

//if Right Sensor is White and Left Sensor is Black then it will call turn Left function
else if((digitalRead(R_S) == 0)&&(digitalRead(L_S) == 1)){
  Serial.print("Right = 0"); Serial.println("Left = 1"); turnLeft();} 


}

long Ultrasonic_read(){
  digitalWrite(trigger, LOW);
  delayMicroseconds(2);
  digitalWrite(trigger, HIGH);
  delayMicroseconds(10);
  long time = pulseIn (echo, HIGH);
  return time / 29 / 2;
}

void avoid(){
    if(distance_F < Set){
  turnRight();
  delay(400);
  forward();
  delay(275);
  turnLeft();
  delay(250);
  forward();
  delay(400);

//if it detects black either left or right sensor after avoiding the object, it'll turn right for 100 milliseconds
  if((digitalRead(R_S) == 1)||(digitalRead(L_S) == 1)){turnRight(); delay(100);} 

    }delay(2);
  
}


void forward(){ 
digitalWrite(in1, LOW);
digitalWrite(in2, HIGH);
digitalWrite(in3, HIGH);
digitalWrite(in4, LOW);
}

void backword(){
digitalWrite(in1, HIGH);  
digitalWrite(in2, LOW);
digitalWrite(in3, LOW);
digitalWrite(in4, HIGH);
}

void turnRight(){
digitalWrite(in1, HIGH);
digitalWrite(in2, LOW);
digitalWrite(in3, HIGH);
digitalWrite(in4, LOW); 
}

void turnLeft(){ 
digitalWrite(in1, LOW); 
digitalWrite(in2, HIGH);
digitalWrite(in3, LOW); 
digitalWrite(in4, HIGH);
}

void Stop(){
digitalWrite(in1, LOW); 
digitalWrite(in2, LOW); 
digitalWrite(in3, LOW); 
digitalWrite(in4, LOW); 
}
