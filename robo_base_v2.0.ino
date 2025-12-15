//written by ali

#include <EnableInterrupt.h>

#define SERIAL_PORT_SPEED 9600
#define RC_NUM_CHANNELS  4

#define RC_CH1  0
#define RC_CH2  1
#define RC_CH3  2
#define RC_CH4  3

#define RC_CH1_PIN  6
#define RC_CH2_PIN  5
#define RC_CH3_PIN  4
#define RC_CH4_PIN  3

uint16_t rc_values[RC_NUM_CHANNELS];
uint32_t rc_start[RC_NUM_CHANNELS];
volatile uint16_t rc_shared[RC_NUM_CHANNELS];

void rc_read_values() {
  noInterrupts();
  memcpy(rc_values, (const void *)rc_shared, sizeof(rc_shared));
  interrupts();
}

void calc_input(uint8_t channel, uint8_t input_pin) {
  if (digitalRead(input_pin) == HIGH) {
    rc_start[channel] = micros();
  } else {
    uint16_t rc_compare = (uint16_t)(micros() - rc_start[channel]);
    rc_shared[channel] = rc_compare;
  }
}

void calc_ch1() {
  calc_input(RC_CH1, RC_CH1_PIN);
}
void calc_ch2() {
  calc_input(RC_CH2, RC_CH2_PIN);
}
void calc_ch3() {
  calc_input(RC_CH3, RC_CH3_PIN);
}
void calc_ch4() {
  calc_input(RC_CH4, RC_CH4_PIN);
}


// const int Lmotor = 9;
// const int Lmotor_in1 = 8;
// const int Lmotor_in2 = 7;

// const int Rmotor = 11;
// const int Rmotor_in1 = 10;
// const int Rmotor_in2 = 12;

const int Lmotor = 11;
const int Lmotor_in1 = 10;
const int Lmotor_in2 = 12;

const int Rmotor = 9;
const int Rmotor_in1 = 8;
const int Rmotor_in2 = 7;

void setup() {

Serial.begin(SERIAL_PORT_SPEED);

pinMode(RC_CH1_PIN, INPUT);
pinMode(RC_CH2_PIN, INPUT);
pinMode(RC_CH3_PIN, INPUT);
pinMode(RC_CH4_PIN, INPUT);


enableInterrupt(RC_CH1_PIN, calc_ch1, CHANGE); // direction wheel
enableInterrupt(RC_CH2_PIN, calc_ch2, CHANGE); // trigger
enableInterrupt(RC_CH3_PIN, calc_ch3, CHANGE); // knob
enableInterrupt(RC_CH4_PIN, calc_ch4, CHANGE); // button
 

pinMode (Lmotor,OUTPUT);
pinMode (Lmotor_in1,OUTPUT);
pinMode (Lmotor_in2,OUTPUT);

pinMode (Rmotor,OUTPUT);
pinMode (Rmotor_in1,OUTPUT);
pinMode (Rmotor_in2,OUTPUT);


}

void forward(int speed){

  digitalWrite(Rmotor_in1, LOW);
  digitalWrite(Rmotor_in2, HIGH);
  analogWrite(Rmotor, speed);

  digitalWrite(Lmotor_in1, LOW);
  digitalWrite(Lmotor_in2, HIGH);
  analogWrite(Lmotor, speed);
}

void reverse(int speed){
  
  digitalWrite(Rmotor_in1, HIGH);
  digitalWrite(Rmotor_in2, LOW);
  analogWrite(Rmotor, speed);

  digitalWrite(Lmotor_in1, HIGH);
  digitalWrite(Lmotor_in2, LOW);
  analogWrite(Lmotor, speed);

}

void leftMove(int speed){
  
  digitalWrite(Lmotor_in1, LOW);
  digitalWrite(Lmotor_in2, HIGH);
  analogWrite(Lmotor, speed);

  digitalWrite(Rmotor_in1, HIGH);
  digitalWrite(Rmotor_in2, LOW);
  analogWrite(Rmotor, speed);

}

void rightMove(int speed){
  
  digitalWrite(Lmotor_in1, HIGH);
  digitalWrite(Lmotor_in2, LOW);
  analogWrite(Lmotor, speed);

  digitalWrite(Rmotor_in1, LOW);
  digitalWrite(Rmotor_in2, HIGH);
  analogWrite(Rmotor, speed);

}

void stop(){
  
  analogWrite(Rmotor, 0);
  analogWrite(Lmotor, 0);

}

void loop() {
  
   rc_read_values();


// robot moving forward and in reverse using Hobby RC controller
  if (rc_values[RC_CH2] > 1600) forward(map(rc_values[RC_CH2], 1600, 2056, 0, 180));  // power reduced from 225 to 180
  if (rc_values[RC_CH2] < 1450) reverse(map(rc_values[RC_CH2], 1450, 980, 0, 180));   // power reduced from 225 to 180
  if ((rc_values[RC_CH2] < 1700) && (rc_values[RC_CH2] > 1300)) stop();


// robot moving right and left using Hobby RC controller

  // if (rc_values[RC_CH1] > 1700) rightMove(map(rc_values[RC_CH1], 1700, 2200, 0, 255));
   if (rc_values[RC_CH4] > 1700) rightMove( 150);
  // if (rc_values[RC_CH1] < 1350) leftMove(map(rc_values[RC_CH1], 1300, 995, 0, 255));
 

  Serial.print("CH1:"); Serial.println(rc_values[RC_CH1]);
  Serial.print("CH2:"); Serial.println(rc_values[RC_CH2]);
  Serial.print("CH3:"); Serial.println(rc_values[RC_CH3]);
  Serial.print("CH4:"); Serial.println(rc_values[RC_CH4]);
  Serial.println();  // blank line


}
