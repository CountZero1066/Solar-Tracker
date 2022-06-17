    #include <Servo.h> 
    
     Servo left_right_servo;
     Servo up_down_servo;  // create servo objects
     
     int up_down_angle, left_right_angle;
     int top_left, top_right, bottom_left, bottom_right; //analog inputs for LDRs
  
  void setup() {
    Serial.begin(115200);    
    Serial.println("################################################");                                                           
    up_down_servo.attach(9);  // attaches the servos objects on pin 9 and 10
    left_right_servo.attach(10);
    
    left_right_servo.write(90);
    up_down_servo.write(90);

}
//Move servos only when they're within 1 to 179 degrees 
boolean Check_Max_Horizontal_Angle(){
  if(left_right_servo.read() >= 180 || left_right_servo.read() <= 0){
    return false;
  }
  return true;
}

boolean Check_Max_Vertical_Angle(){
  if(up_down_servo.read() >= 180 || up_down_servo.read() <= 0){
    return false;
  }
  return true;
}

void loop() {
  top_left = analogRead(A0);       //black
  top_right = analogRead(A1);      //orange
  bottom_left = analogRead(A2);    //yellow
  bottom_right = analogRead(A3);   //white
  
  Serial.println("A0: " + (String)top_left + " A1: " + (String)top_right + " A2: " + (String)bottom_left + " A3:" + (String)bottom_right);
  Serial.println("vert: " + (String)up_down_servo.read() + "hor: " + (String)left_right_servo.read());
//!!!recast analog inputs to String for print statements!!!

//-----------------------------------------------------------------------------------------
//Horizontal Servo Motion
//-----------------------------------------------------------------------------------------

  if (top_left + 5 > top_right  && top_left - 5 > top_right)
  //if top left ldr is darker than the top right 
  {
    if(Check_Max_Horizontal_Angle()){
    left_right_angle = left_right_servo.read();
    left_right_servo.write(left_right_angle - 1); //rotate horizontal counterclockwise (ie turn right)
    delay(15);
    }
  }

  if (top_left + 5 < top_right  && top_left - 5 < top_right) 
  //if top left ldr is brighter than top right
  {
    if(Check_Max_Horizontal_Angle()){
    left_right_angle = left_right_servo.read();
    left_right_servo.write(left_right_angle + 1); //rotate horizontal clockwise
    delay(15);
    }
  }

  if (bottom_left + 5 > bottom_right  && bottom_left - 5 > bottom_right)
  //if bottom left ldr is darker than the bottom right 
  {
    if(Check_Max_Horizontal_Angle()){
    left_right_angle = left_right_servo.read();
    left_right_servo.write(left_right_angle - 1); //rotate horizontal counterclockwise
    delay(15);
    }
  }

  if (bottom_left + 5 < bottom_right  && bottom_left - 5 < bottom_right) 
  //if bottom left ldr is brighter than bottom right
  {
    if(Check_Max_Horizontal_Angle()){
    left_right_angle = left_right_servo.read();
    left_right_servo.write(left_right_angle + 1); //rotate horizontal clockwise
    delay(15);
    }
  }

//-----------------------------------------------------------------------------------------
//Vertical Servo Motion
//-----------------------------------------------------------------------------------------

  if (top_left + 5 > bottom_left  && top_left - 5 > bottom_left)
  //if top left ldr is darker than the bottom left 
  {
    if(Check_Max_Vertical_Angle()){
    up_down_angle = up_down_servo.read();
    up_down_servo.write(up_down_angle - 1); //rotate vertical counterclockwise (ie rotate down)
    delay(15);
    }
  }

  if (top_left + 5 < bottom_left  && top_left - 5 < bottom_left)
  //if top left ldr is brighter than the bottom left 
  {
    if(Check_Max_Vertical_Angle()){
    up_down_angle = up_down_servo.read();
    up_down_servo.write(up_down_angle + 1); //rotate vertical clockwise (ie rotate up)
    delay(15);
    }
  }

  if (top_left + 5 > bottom_left  && top_left - 5 > bottom_left)
  //if top left ldr is darker than the bottom left 
  {
    if(Check_Max_Vertical_Angle()){
    up_down_angle = up_down_servo.read();
    up_down_servo.write(up_down_angle - 1); //rotate vertical counterclockwise (ie rotate down)
    delay(15);
    }
  }

  if (top_right + 5 < bottom_right  && top_right - 5 < bottom_right)
  //if top right ldr is brighter than the bottom right 
  {
    if(Check_Max_Vertical_Angle()){
    up_down_angle = up_down_servo.read();
    up_down_servo.write(up_down_angle + 1); //rotate vertical clockwise (ie rotate up)
    delay(15);
    }
  }

  if (top_right + 5 > bottom_right  && top_right - 5 > bottom_right)
  //if top right ldr is darker than the bottom right 
  {
    if(Check_Max_Vertical_Angle()){
    up_down_angle = up_down_servo.read();
    up_down_servo.write(up_down_angle - 1); //rotate vertical counterclockwise (ie rotate down)
    delay(15);
    }
  }
  
  delay(100);
 
}
