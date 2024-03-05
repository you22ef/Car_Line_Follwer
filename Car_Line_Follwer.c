//motor 1
#define input1 7
#define out1 6
#define speed1 5
//motor 2
#define input2 8
#define out2 9
#define speed2 10
//first IR
#define in1 2
#define in2 3
#define in3 4
//secound IR
#define in4 11
#define in5 12
#define in6 13
bool forword1 = 0;
bool left1 = 0;
bool right1 = 0;
void setup() {
  pinMode (input1 ,OUTPUT);
  pinMode (out1,OUTPUT);
  pinMode (speed1,OUTPUT);
  pinMode (input2 ,OUTPUT);
  pinMode (out2,OUTPUT);
  pinMode (speed2,OUTPUT);
  pinMode (in1,INPUT);
  pinMode (in2,INPUT);
  pinMode (in3,INPUT);
  pinMode (in4,INPUT);
  pinMode (in5,INPUT);
  pinMode (in6,INPUT);

}

void loop() 
{
  //forward();
 Car_Line();
  
}




 void forward()
 {
  analogWrite(speed1, 100);
  analogWrite(speed2, 100);
  digitalWrite(input1,HIGH);
  digitalWrite(out1,LOW);
  digitalWrite(input2,0);
  digitalWrite(out2,1);
 }
  void Backward()
 {
  analogWrite(speed1, 50);
  analogWrite(speed2, 50);
  digitalWrite(input1,LOW);
  digitalWrite(out1,HIGH);
  digitalWrite(input2,1);
  digitalWrite(out2,0);
 }
  void right()
 {
  analogWrite(speed1, 50);
  analogWrite(speed2, 80);
  digitalWrite(input1,HIGH);
  digitalWrite(out1,LOW);
  digitalWrite(input2,1);
  digitalWrite(out2,0);
 }
  void left()
 {
  analogWrite(speed1, 80);
  analogWrite(speed2, 50);
  digitalWrite(input1,LOW);
  digitalWrite(out1,HIGH);
  digitalWrite(input2,0);
  digitalWrite(out2,1);
 }
  void Car_Line()
 {
    int isObstacle1 = HIGH;
    int isObstacle2 = HIGH;
    int isObstacle4 = HIGH;
    int isObstacle3 = HIGH;
    int isObstacle5 = HIGH;
    int isObstacle6 = HIGH;
    isObstacle1 = digitalRead(in1);
    isObstacle2 = digitalRead(in2);
    isObstacle4 = digitalRead(in4);
    isObstacle3 = digitalRead(in3);
    isObstacle5 = digitalRead(in5);
    isObstacle6 = digitalRead(in6);

    if(isObstacle4 == HIGH && isObstacle1 == HIGH && isObstacle2 == HIGH && isObstacle3 == HIGH && isObstacle5 == HIGH && isObstacle6 == HIGH)
    {
      stop();
    }
    else if(isObstacle4 == HIGH && isObstacle1 == LOW && isObstacle2 == LOW && isObstacle3 == LOW && isObstacle5 == LOW && isObstacle6 == LOW  )
    {
      forword1 = 1;
      left1 = 0;
      right1 = 0;
      forward();
    }
    else if ((isObstacle5 == HIGH || isObstacle6 == HIGH) && isObstacle1 == LOW && isObstacle2 == LOW && isObstacle3 == LOW && isObstacle4 == LOW)
    {
      forword1 = 0;
      left1 = 1;
      right1 = 0;
      left();

    }
    else if (isObstacle1 == HIGH || isObstacle2 == HIGH )
    {
      forword1 = 0;
      left1 = 0;
      right1 = 1;
      right();
    }
    if(isObstacle4 == LOW && isObstacle1 == LOW && isObstacle2 == LOW && isObstacle3 == LOW && isObstacle5 == LOW && isObstacle6 == LOW)
    {
      if(forword1 == 1)
      {
        forward();
      }
      else if(left1 == 1)
      {
        left();
      }
      else if(right1 == 1)
      {
        right();
      }
    }
   
}
  void stop()
 {
  digitalWrite(input1,LOW);
  digitalWrite(out1,LOW);
  digitalWrite(input2,LOW);
  digitalWrite(out2,LOW);
 }