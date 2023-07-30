# Line-Follower-w/-and-w/o-Obstacle-Avoidance-on-Specific-Track-
Arduino UNO, Line Tracing, Object Avoidance, Robot, Caster Wheel, Infrared Sensors, L298N Motor Driver, Ultrasonic Sensor

<img width="461" alt="image" src="https://github.com/Jeydori/Line-Follower-with-and-without-Obstacle-Avoidance-on-Specific-Track-/assets/92672461/7a88666a-19ec-44ce-b182-8c84ce8eaa37">

Creating a line follower robot with obstacle avoidance using an Arduino and an L298N motor driver is a fun and educational project. Below, I'll provide a step-by-step tutorial for both versions of the robot. First, we'll build the basic line follower robot, and then we'll add the obstacle avoidance feature to it.

**Actual Track:**

<img width="330" alt="image" src="https://github.com/Jeydori/Line-Follower-with-and-without-Obstacle-Avoidance-on-Specific-Track-/assets/92672461/f22bf4ce-9953-4ae3-9b80-acb262824970">


**Note:** This tutorial assumes you have some basic knowledge of Arduino programming and electronics. If you're new to Arduino, consider learning the basics first.

**Components Needed:**
  1. 1x Arduino board (e.g., Arduino Uno)
  2. 1x L298N motor driver module
  3. 2x geared DC motors with wheels
  4. 2x Infrared (IR) line sensor module 
  5. 1x Ultrasonic distance sensor (HC-SR04) for obstacle avoidance version
  6. 1x Chassis (You can create your own)
  7. 7-12V battery pack
  8. Jumper wires / solid wires
  9. Optional: Breadboard for prototyping (recommended for beginners)

**Step 1: Assemble the Hardware:**

<img width="411" alt="image" src="https://github.com/Jeydori/Line-Follower-with-and-without-Obstacle-Avoidance-on-Specific-Track-/assets/92672461/cca9dc8f-e169-465c-84ac-1f86d6f0d2e6">

1. Mount the motors and wheels on the chassis.
2. Connect the motors to the L298N motor driver module.
3. Connect the motor driver to the Arduino as follows:
   - Motor Driver Input 1 (IN1): Arduino digital pin 4
   - Motor Driver Input 2 (IN2): Arduino digital pin 5
   - Motor Driver Input 3 (IN3): Arduino digital pin 6
   - Motor Driver Input 4 (IN4): Arduino digital pin 7
   - Motor Driver Enable A (ENA): Arduino digital pin 3
   - Motor Driver Enable B (ENB): Arduino digital pin 9
   - Motor Driver Vcc: 7-12V (from the battery power source)
   - Motor Driver GND: GND (common ground with Arduino)
   - Motor Driver Output 5V: Arduino Vin

4. Connect the IR line sensor module to the Arduino:
   - Sensor 1 (left) output: Arduino analog pin A0
   - Sensor 2 (right) output: Arduino analog pin A1

5. For the obstacle avoidance version, connect the ultrasonic sensor:
   - HC-SR04 Trig: Arduino digital pin 12
   - HC-SR04 Echo: Arduino digital pin 11
   - HC-SR04 Vcc: 5V (from Arduino or separate power source)
   - HC-SR04 GND: GND (common ground with Arduino)

**Step 2: Program the Line Follower:**
Now, let's write the code for the basic line follower robot. This code will use the sensor inputs to follow a line on the ground.

```arduino
// Line follower robot without obstacle avoidance

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
        
        //adjust depending on the IR sensor's response time and calibrate it properly
        analogWrite(enA, 210); 
        analogWrite(enB, 210); 
        
        delay(500);
        }
        
        void loop(){
        //if Right Sensor and Left Sensor are at White color then it will call forword function
         if((digitalRead(R_S) == 0)&&(digitalRead(L_S) == 0)){
         forward(); 
         }
        //if Right Sensor is Black and Left Sensor is White then it will call turn Right function
        else if((digitalRead(R_S) == 1)&&(digitalRead(L_S) == 0)){
         turnRight();
         }
        //if Right Sensor is White and Left Sensor is Black then it will call turn Left function
        else if((digitalRead(R_S) == 0)&&(digitalRead(L_S) == 1)){
         turnLeft();
         } 
        }
        
        void forward(){  //forword
        digitalWrite(in1, LOW); 
        digitalWrite(in2, HIGH); 
        digitalWrite(in3, HIGH); 
        digitalWrite(in4, LOW); 
        }
        
        void backword(){ //backword
        digitalWrite(in1, HIGH); 
        digitalWrite(in2, LOW);  
        digitalWrite(in3, LOW); 
        digitalWrite(in4, HIGH); 
        }
        
        void turnRight(){ //turnRight
        digitalWrite(in1, HIGH); 
        digitalWrite(in2, LOW); 
        digitalWrite(in3, HIGH);  
        digitalWrite(in4, LOW); 
        }
        
        void turnLeft(){ //turnLeft
        digitalWrite(in1, LOW);  
        digitalWrite(in2, HIGH);  
        digitalWrite(in3, LOW);
        digitalWrite(in4, HIGH); 
        }
        
        void Stop(){ //stop
        digitalWrite(in1, LOW); 
        digitalWrite(in2, LOW); 
        digitalWrite(in3, LOW);  
        digitalWrite(in4, LOW);
        }

```
The code defines the pin numbers for the motor driver inputs (enA, in1, in2, in3, in4, enB) and the IR sensors (L_S, R_S) connected to the Arduino.

The setup function sets the defined pins as input or output accordingly, and it configures the enable pins (enA, enB) to control the motor speed. The code also sets the motor speeds (using analogWrite) to 210, which determines the speed at which the robot will move.

The loop function is where the main logic of the robot's movement is implemented based on the readings from the IR sensors.

If both the right and left sensors detect a white surface (digitalRead == 0 for both R_S and L_S), the robot will move forward.

If the right sensor detects a black surface (digitalRead == 1) and the left sensor detects a white surface (digitalRead == 0), the robot will turn right.

If the right sensor detects a white surface (digitalRead == 0) and the left sensor detects a black surface (digitalRead == 1), the robot will turn left.

There is no specific action defined when both sensors detect black surfaces, so the robot will stop in such a situation as none of the conditions in the loop will be met.

The code provides four separate functions (forward, backward, turnRight, turnLeft) to control the robot's movement in different directions. The Stop function is used to stop the robot by setting all motor driver inputs to LOW.

Please note that the code comments mention calibrating the IR sensor's response time, which is essential for the robot to follow the line accurately. Proper calibration ensures the robot can distinguish between the white line and the black surface effectively.






**Step 3: Test the Line Follower:**
Upload the code to your Arduino board and place the robot on the line. Ensure that the sensors are correctly detecting the line and that the motors respond appropriately.

**Step 4: Adding Obstacle Avoidance (for the second version):**
Now, let's add the obstacle avoidance feature to the line follower robot using the HC-SR04 ultrasonic sensor.

```arduino
// Line follower robot with obstacle avoidance


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

        //This code is designed just for a specific track
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

```
Ultrasonic Sensor (HC-SR04):
This code introduces an ultrasonic distance sensor (HC-SR04) to the robot, connected to the Arduino's pins echo (pin 11) and trigger (pin 12). The sensor is used to detect the distance of an object in front of the robot, allowing it to perform obstacle avoidance.

Avoidance Logic:
This code has added an avoid function to handle obstacle avoidance. If the ultrasonic sensor detects an object at a distance less than the Set value (set to 15 in this code), the robot executes the avoid function. The avoid function performs a series of movements to navigate around the obstacle. It turns right, moves forward, turns left, moves forward again, and then checks if either the right or left sensor detects black (the line). If the robot detects black, it makes a quick right turn for 100 milliseconds. This helps the robot get back on track after avoiding the obstacle.

Interval-based Movement:(This code is designed just for the specific track shown above)
The code uses the millis() function to create a time interval-based movement. When both IR sensors detect a white surface (line lost), the robot performs a quick left turn followed by moving forward for 50 milliseconds each. The interval is set using the interval variable (set to 100 milliseconds in this code) to control the duration of these movements.






**Step 5: Test the Line Follower with Obstacle Avoidance:**
Upload the updated code to your Arduino board, and now your robot should follow the line while avoiding obstacles that are closer than the `distance_F` threshold.

That's it! You now have a line follower robot with and without obstacle avoidance using an Arduino and an L298N motor driver. Have fun experimenting and improving your robot!
