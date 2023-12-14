/*
Solar Tracker V0.6
Robert James Hastings
Github CountZero1066

   ###############################################################
   #                     Solar Tracker V0.6                      #
   #                                                             #
   #                                                             #
   #                                                             #
   ###############################################################
   Version Detail:
            -Testing the usage of a shunt resistor to measure the relative current draw by the servo motors as
             a means to determine the minimum and maximum positions of the servo motors. The servo motors will
             draw a measurablly greater amount of current when they encounter physical resistance to their 
             movement (reaching the limits of the pan/tilt mechanism) and this measurement is used to 
             determine the minimum and maximum positions to prevent excessive current draw and/or physical damage
             to the pan/tilt mechanism.    

   Hardware:
            Arduino Nano
*/
 //-------------------------------------------------------------------------------------------   
    #include <Servo.h> 
    
     Servo left_right_servo;
     Servo up_down_servo;  // create servo objects
     
     int up_down_angle, left_right_angle;
     int top_left, top_right, bottom_left, bottom_right; //analog inputs for LDRs
     int servo_current_draw;
     int min_pan, max_pan, min_tilt, max_tilt;
//-------------------------------------------------------------------------------------------
//Setup
//-------------------------------------------------------------------------------------------
  void setup() {
    Serial.begin(115200);    
    up_down_servo.attach(9);  // attach the servo objects on pin 9 and 10
    left_right_servo.attach(10);
    Discover_min_max_servo_angles();
}
//-------------------------------------------------------------------------------------------
//Establish the limits of the servo motors
//-------------------------------------------------------------------------------------------
   void Discover_min_max_servo_angles(){
//Discover min/max pan servo positions
    servo_current_draw = analogRead(A5);
    Serial.println(servo_current_draw); 
    left_right_angle = left_right_servo.read();
    while(servo_current_draw <150){
          left_right_servo.write(left_right_angle - 1);
          servo_current_draw = analogRead(A5);
          delay(100);
    }
      min_pan = left_right_angle + 1;

      while(servo_current_draw <150){
          left_right_servo.write(left_right_angle + 1);
          servo_current_draw = analogRead(A5);
          delay(100);
    }
      max_pan = left_right_angle - 1;
      delay(100);
      left_right_servo.write(min_pan + (max_pan - min_pan));

//Discover min/max tilt servo positions
      up_down_angle = up_down_servo.read();
      while(servo_current_draw <150){
          up_down_servo.write(up_down_angle - 1);
          servo_current_draw = analogRead(A5);
          delay(100);
    }
      min_tilt = up_down_angle + 1;

      while(servo_current_draw <150){
          up_down_servo.write(up_down_angle + 1);
          servo_current_draw = analogRead(A5);
          delay(100);
    }
      max_tilt = up_down_angle - 1;
      delay(100);
      up_down_servo.write(min_tilt + (max_tilt - min_tilt));
//Serial.println("*************************************");  
//Serial.println("min pan :" + min_pan);    
//Serial.println("max pan :" + max_pan); 
//Serial.println("min tilt:" + min_tilt);    
//Serial.println("max tilt:" + max_tilt); 
//Serial.println("*************************************"); 
   }
//-------------------------------------------------------------------------------------------
//Check if OK to move pan servo
//-------------------------------------------------------------------------------------------
//Move servos only when they're within min and max servo position 
boolean Check_Max_Horizontal_Angle(){
  if(left_right_servo.read() >= max_pan || left_right_servo.read() <= min_pan){
    return false;
  }
  return true;
}
//-------------------------------------------------------------------------------------------
//Check if OK to move tilt servo
//-------------------------------------------------------------------------------------------
boolean Check_Max_Vertical_Angle(){
  if(up_down_servo.read() >= max_tilt || up_down_servo.read() <= min_tilt){
    return false;
  }
  return true;
}
//-------------------------------------------------------------------------------------------
//Incomplete Sleep Mode
//-------------------------------------------------------------------------------------------
boolean Nighttime_sleep_check(int top_l,int top_r,int bot_l,int bot_r){
  if(top_l + top_r + bot_l + bot_r <= 3200){
    //go to sleep
    //Serial.println("night time sleep mode not enabled yet"); 
  }
}
//-------------------------------------------------------------------------------------------
//Main Loop - Read LDR values and determine appropriate servo movement
//-------------------------------------------------------------------------------------------
void loop() {
  top_left = analogRead(A0);       //black
  top_right = analogRead(A1);      //orange
  bottom_left = analogRead(A2);    //yellow
  bottom_right = analogRead(A3);   //white
  
  //Serial.println("A0: " + (String)top_left + " A1: " + (String)top_right + " A2: " + (String)bottom_left + " A3:" + (String)bottom_right);
  //Serial.println("vert: " + (String)up_down_servo.read() + "hor: " + (String)left_right_servo.read());
  Nighttime_sleep_check(top_left, top_right, bottom_right, bottom_left);
//!!!recast analog inputs to String for print statements!!!

//************************************Pan Servo Motion************************************
  if (top_left + 5 > top_right  && top_left - 5 > top_right)
  //if top left ldr is darker than the top right 
  {
    if(Check_Max_Horizontal_Angle()){
    left_right_angle = left_right_servo.read();
    left_right_servo.write(left_right_angle - 1); //rotate horizontal counterclockwise (ie turn right)
    delay(50);
    }
  }

  if (top_left + 5 < top_right  && top_left - 5 < top_right) 
  //if top left ldr is brighter than top right
  {
    if(Check_Max_Horizontal_Angle()){
    left_right_angle = left_right_servo.read();
    left_right_servo.write(left_right_angle + 1); //rotate horizontal clockwise
    delay(50);
    }
  }

  if (bottom_left + 5 > bottom_right  && bottom_left - 5 > bottom_right)
  //if bottom left ldr is darker than the bottom right 
  {
    if(Check_Max_Horizontal_Angle()){
    left_right_angle = left_right_servo.read();
    left_right_servo.write(left_right_angle - 1); //rotate horizontal counterclockwise
    delay(50);
    }
  }

  if (bottom_left + 5 < bottom_right  && bottom_left - 5 < bottom_right) 
  //if bottom left ldr is brighter than bottom right
  {
    if(Check_Max_Horizontal_Angle()){
    left_right_angle = left_right_servo.read();
    left_right_servo.write(left_right_angle + 1); //rotate horizontal clockwise
    delay(50);
    }
  }

//************************************Tilt Servo Motion************************************
  if (top_left + 5 > bottom_left  && top_left - 5 > bottom_left)
  //if top left ldr is darker than the bottom left 
  {
    if(Check_Max_Vertical_Angle()){
    up_down_angle = up_down_servo.read();
    up_down_servo.write(up_down_angle + 1); //rotate vertical counterclockwise (ie rotate down)
    delay(50);
    }
  }

  if (top_left + 5 < bottom_left  && top_left - 5 < bottom_left)
  //if top left ldr is brighter than the bottom left 
  {
    if(Check_Max_Vertical_Angle()){
    up_down_angle = up_down_servo.read();
    up_down_servo.write(up_down_angle - 1); //rotate vertical clockwise (ie rotate up)
    delay(50);
    }
  }

  if (top_left + 5 > bottom_left  && top_left - 5 > bottom_left)
  //if top left ldr is darker than the bottom left 
  {
    if(Check_Max_Vertical_Angle()){
    up_down_angle = up_down_servo.read();
    up_down_servo.write(up_down_angle + 1); //rotate vertical counterclockwise (ie rotate down)
    delay(50);
    }
  }

  if (top_right + 5 < bottom_right  && top_right - 5 < bottom_right)
  //if top right ldr is brighter than the bottom right 
  {
    if(Check_Max_Vertical_Angle()){
    up_down_angle = up_down_servo.read();
    up_down_servo.write(up_down_angle - 1); //rotate vertical clockwise (ie rotate up)
    delay(50);
    }
  }

  if (top_right + 5 > bottom_right  && top_right - 5 > bottom_right)
  //if top right ldr is darker than the bottom right 
  {
    if(Check_Max_Vertical_Angle()){
    up_down_angle = up_down_servo.read();
    up_down_servo.write(up_down_angle + 1); //rotate vertical counterclockwise (ie rotate down)
    delay(50);
    }
  }
   
 
}
