// by Ali Noor

#include <Servo.h>

Servo r_shoulder;
Servo r_arm;
Servo r_4arm;

Servo l_shoulder;
Servo l_arm;
Servo l_4arm;

Servo jaw;

void setup() {
 initial ();
 delay(1000);
forearm_talk();
delay(1000);
 initial ();
shoulder_groove();
delay(1000);
 initial ();
arm_flip();
delay(3000);
 initial ();
shoulder_flap();
shoulder_flap();
shoulder_flap();
shoulder_flap();
shoulder_flap();
delay(3000);
 initial ();
r_arm_r4arm ();
delay(3000);
 initial ();
dab();
delay(2000);
initial ();

}

void loop() { 
}


void initial (){ // setting up the robot in place 

  r_shoulder.write(60);
  r_shoulder.attach(20); 


  r_arm.write(180);
  r_arm.attach(21); 


  r_4arm.write(20);
  r_4arm.attach(19);
  

  l_shoulder.write(60);
  l_shoulder.attach(17); 


  l_arm.write(0);
  l_arm.attach(18); 


  l_4arm.write(0);
  l_4arm.attach(16);
}

void forearm_talk(){
r_4arm.write(0);
r_4arm.attach(19);

l_4arm.write(0);
l_4arm.attach(16);

delay(500);

r_4arm.write(20);
r_4arm.attach(19);

l_4arm.write(20);
l_4arm.attach(16);

delay(500);

r_4arm.write(0);
r_4arm.attach(19);

l_4arm.write(0);
l_4arm.attach(16);

delay(500);

r_4arm.write(20);
r_4arm.attach(19);

l_4arm.write(20);
l_4arm.attach(16);


}

void shoulder_groove(){
r_shoulder.write(50);
r_shoulder.attach(20); 

l_shoulder.write(50);
l_shoulder.attach(17);

delay (1000);
r_shoulder.write(60);
r_shoulder.attach(20); 

l_shoulder.write(60);
l_shoulder.attach(17);

delay (1000);

r_shoulder.write(50);
r_shoulder.attach(20); 

l_shoulder.write(50);
l_shoulder.attach(17);

delay (1000);

r_shoulder.write(60);
r_shoulder.attach(20); 

l_shoulder.write(60);
l_shoulder.attach(17);

delay (1000);

}

void arm_flip(){

r_arm.write(0);
r_arm.attach(21);

l_arm.write(180);
l_arm.attach(18); 

}

void  shoulder_flap () {
r_shoulder.write(60);
r_shoulder.attach(20); 

l_shoulder.write(60);
l_shoulder.attach(17);

delay (1000);
r_shoulder.write(80);
r_shoulder.attach(20); 

l_shoulder.write(40);
l_shoulder.attach(17);

delay (1000);

r_shoulder.write(60);
r_shoulder.attach(20); 

l_shoulder.write(60);
l_shoulder.attach(17);

delay (1000);
}

void r_arm_r4arm (){
  r_arm.write(0);
  r_arm.attach(21);
    delay(2000);
  r_4arm.write(0);
 r_4arm.attach(19);
 delay(1000);
 r_4arm.write(20);
 r_4arm.attach(19);
 delay(1000);
   r_4arm.write(0);
 r_4arm.attach(19);
 delay(1000);
 r_4arm.write(20);
 r_4arm.attach(19);
 delay(1000);
   r_4arm.write(0);
 r_4arm.attach(19);
 delay(1000);
 r_4arm.write(20);
 r_4arm.attach(19);
 delay(1000);

}

void dab(){

  l_arm.write(180);
  l_arm.attach(18);
  delay(2000);

  l_shoulder.write(10);
  l_shoulder.attach(17);
  r_shoulder.write(180);
  r_shoulder.attach(20); 
  r_4arm.write(0);
  r_4arm.attach(19);
  delay(5000);
  l_shoulder.write(60);
  l_shoulder.attach(17);
  r_shoulder.write(60);
  r_shoulder.attach(20); 
  r_4arm.write(90);
 r_4arm.attach(19);

  
  
}
