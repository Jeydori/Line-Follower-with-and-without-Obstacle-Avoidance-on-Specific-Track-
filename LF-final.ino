
#define enA 3
#define in1 4 
#define in2 5 
#define in3 6  
#define in4 7 
#define enB 9 

#define L_S A0 
#define R_S A1 


void setup(){ 

pinMode(R_S, INPUT); 
pinMode(L_S, INPUT); 

pinMode(enA, OUTPUT);  
pinMode(in1, OUTPUT); 
pinMode(in2, OUTPUT); 
pinMode(in3, OUTPUT);   
pinMode(in4, OUTPUT);  
pinMode(enB, OUTPUT); 

//adjust depending on the IR sensor's response time
analogWrite(enA, 210); 
analogWrite(enB, 210); 

delay(500);

}

void loop(){  


 if((digitalRead(R_S) == 0)&&(digitalRead(L_S) == 0)){
 forward(); 
 }  else if((digitalRead(R_S) == 1)&&(digitalRead(L_S) == 0)){
 turnRight();
 }  else if((digitalRead(R_S) == 0)&&(digitalRead(L_S) == 1)){
 turnLeft();
 } 

}


void forward(){  //forword
digitalWrite(in1, LOW); //Left Motor backword Pin 
digitalWrite(in2, HIGH); //Left Motor forword Pin 
digitalWrite(in3, HIGH); //Right Motor forword Pin 
digitalWrite(in4, LOW); //Right Motor backword Pin 
}

void backword(){ //backword
digitalWrite(in1, HIGH); //Left Motor backword Pin 
digitalWrite(in2, LOW); //Left Motor forword Pin 
digitalWrite(in3, LOW); //Right Motor forword Pin 
digitalWrite(in4, HIGH); //Right Motor backword Pin 
}

void turnRight(){ //turnRight
digitalWrite(in1, HIGH); //Left Motor backword Pin 
digitalWrite(in2, LOW); //Left Motor forword Pin 
digitalWrite(in3, HIGH); //Right Motor forword Pin 
digitalWrite(in4, LOW); //Right Motor backword Pin 
}

void turnLeft(){ //turnLeft
digitalWrite(in1, LOW); //Left Motor backword Pin 
digitalWrite(in2, HIGH); //Left Motor forword Pin 
digitalWrite(in3, LOW); //Right Motor forword Pin 
digitalWrite(in4, HIGH); //Right Motor backword Pin 
}

void Stop(){ //stop
digitalWrite(in1, LOW); //Left Motor backword Pin 
digitalWrite(in2, LOW); //Left Motor forword Pin 
digitalWrite(in3, LOW); //Right Motor forword Pin 
digitalWrite(in4, LOW); //Right Motor backword Pin 
}
