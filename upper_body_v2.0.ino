// by Ali Noor

#include <Servo.h>

Servo r_shoulder;
Servo r_arm;
Servo r_4arm;

Servo l_shoulder;
Servo l_arm;
Servo l_4arm;



void setup() {
 initial ();
 delay(1000);
 talking(2);
 delay(1000);
  initial ();
 attention (2);
 delay(1000);
  initial ();
delay(1000);
  initial ();
flapping (2);
delay(1000);
  initial ();
speak(5);


}

void loop() { 
}


void initial (){ // setting up the robot in place 

  r_shoulder.write(180);
  r_shoulder.attach(20); 


  r_arm.write(30);
  r_arm.attach(21); 


  r_4arm.write(80);
  r_4arm.attach(19);
  

  l_shoulder.write(50);
  l_shoulder.attach(17); 


  l_arm.write(0);
  l_arm.attach(18); 


  l_4arm.write(90);
  l_4arm.attach(16);
}

void talking (int time){ // setting up the robot in place 

  r_shoulder.write(180);
  r_shoulder.attach(20); 

  r_arm.write(30);
  r_arm.attach(21); 

  r_4arm.write(80);
  r_4arm.attach(19);
  

  l_shoulder.write(50);
  l_shoulder.attach(17); 


  l_arm.write(0);
  l_arm.attach(18); 


  l_4arm.write(90);
  l_4arm.attach(16);

  for (int i=0 ; i<=time ; i++ ) {
  delay(500);
  r_4arm.write(120);
  r_4arm.attach(19);

    delay(500);
  r_4arm.write(80);
  r_4arm.attach(19);
  }

  

}

void attention ( int time){ // setting up the robot in place 

  r_shoulder.write(180);
  r_shoulder.attach(20); 


  r_arm.write(30);
  r_arm.attach(21); 


  r_4arm.write(0);
  r_4arm.attach(19);
  

  l_shoulder.write(50);
  l_shoulder.attach(17); 


  l_arm.write(0);
  l_arm.attach(18); 


  l_4arm.write(90);
  l_4arm.attach(16);

 for (int i = 0 ; i <= time ; i++){
  r_shoulder.write(80);
  r_shoulder.attach(20); 
  l_shoulder.write(100);
  l_shoulder.attach(17); 
 }


}



void flapping ( int time) {
    r_shoulder.write(180);
  r_shoulder.attach(20); 


  r_arm.write(30);
  r_arm.attach(21); 


  r_4arm.write(0);
  r_4arm.attach(19);
  

  l_shoulder.write(50);
  l_shoulder.attach(17); 


  l_arm.write(0);
  l_arm.attach(18); 


  l_4arm.write(90);
  l_4arm.attach(16);

  r_shoulder.write(180);
  r_shoulder.attach(20); 
  l_shoulder.write(20);
  l_shoulder.attach(17); 
  delay(500);
  for (int i = 0 ; i<=time; i++){
   l_shoulder.write(50);
  l_shoulder.attach(17); 
  delay(500);
  l_shoulder.write(20);
  l_shoulder.attach(17); 
  delay(500);
  }

 
}

void speak(int time) {

  // Repeat 'time' times
  for (int i = 0; i <= time; i++) {

    l_4arm.attach(16);   // Attach once before writing
    l_4arm.write(130);
    delay(500);

    l_4arm.write(90);
    delay(500);
  }

}
