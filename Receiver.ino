// =====================================================================
//                    INTEGRATED ROBOT RECEIVER
//          23 Tracks with Custom Choreography & LED Moods
//                    CORRECTED DIALOGUE ORDER
// =====================================================================

// -------------------- NRF24L01 SETUP --------------------
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

const int NRF_CE_PIN = A11;
const int NRF_CSN_PIN = A15;

RF24 radio(NRF_CE_PIN, NRF_CSN_PIN);

const byte CUSTOM_ADDRESS_BYTE = 0x33;
const int CUSTOM_CHANNEL_NUMBER = 90;

const byte xmtrAddress[] = { CUSTOM_ADDRESS_BYTE, CUSTOM_ADDRESS_BYTE, 0xC7, 0xE6, 0xCC };
const byte rcvrAddress[] = { CUSTOM_ADDRESS_BYTE, CUSTOM_ADDRESS_BYTE, 0xC7, 0xE6, 0x66 };

const int RF24_POWER_LEVEL = RF24_PA_LOW;

uint8_t pipeNum;

struct DataStruct {
  uint8_t stateNumber;
};
DataStruct data;

// -------------------- MUSIC MAKER SHIELD --------------------
#include <Adafruit_VS1053.h>
#include <SD.h>

#define SHIELD_RESET -1
#define SHIELD_CS 7
#define SHIELD_DCS 6
#define CARDCS 4
#define DREQ 3

Adafruit_VS1053_FilePlayer musicPlayer = 
  Adafruit_VS1053_FilePlayer(SHIELD_RESET, SHIELD_CS, SHIELD_DCS, DREQ, CARDCS);

// -------------------- SERVO MOTORS --------------------
#include <Servo.h>

Servo r_shoulder;
Servo r_arm;
Servo r_4arm;

Servo l_shoulder;
Servo l_arm;
Servo l_4arm;

// -------------------- NEOPIXELS --------------------
#include <Adafruit_NeoPixel.h>

#define EYE1_PIN   2
#define EYE2_PIN   5
#define CROWN_PIN  8

#define NUM_EYES 2
#define NUM_CROWN 28

Adafruit_NeoPixel eye1(NUM_EYES, EYE1_PIN, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel eye2(NUM_EYES, EYE2_PIN, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel crown(NUM_CROWN, CROWN_PIN, NEO_GRB + NEO_KHZ800);

int baseBrightness = 80;

// =====================================================================
//                      NEOPIXEL FUNCTIONS
// =====================================================================

void setEyesColor(uint8_t r, uint8_t g, uint8_t b) {
  for (int i = 0; i < NUM_EYES; i++) {
    eye1.setPixelColor(i, eye1.Color(r, g, b));
    eye2.setPixelColor(i, eye2.Color(r, g, b));
  }
  eye1.show();
  eye2.show();
}

void setCrownColor(uint8_t r, uint8_t g, uint8_t b) {
  for (int i = 0; i < NUM_CROWN; i++) {
    crown.setPixelColor(i, crown.Color(r, g, b));
  }
  crown.show();
}

void pulseEyes(uint8_t r, uint8_t g, uint8_t b, int duration = 1000) {
  int steps = 30;
  int delayTime = duration / (steps * 2);
  
  for (int i = 0; i <= steps; i++) {
    int br = map(i, 0, steps, 0, baseBrightness);
    eye1.setBrightness(br);
    eye2.setBrightness(br);
    setEyesColor(r, g, b);
    delay(delayTime);
  }
  
  for (int i = steps; i >= 0; i--) {
    int br = map(i, 0, steps, 0, baseBrightness);
    eye1.setBrightness(br);
    eye2.setBrightness(br);
    setEyesColor(r, g, b);
    delay(delayTime);
  }
}

void flickerEyes(uint8_t r, uint8_t g, uint8_t b, int duration = 1000) {
  unsigned long startTime = millis();
  while (millis() - startTime < duration) {
    int br = random(20, baseBrightness);
    eye1.setBrightness(br);
    eye2.setBrightness(br);
    setEyesColor(r, g, b);
    delay(random(20, 80));
  }
}

void pulseCrown(uint8_t r, uint8_t g, uint8_t b, int duration = 1000) {
  int steps = 30;
  int delayTime = duration / (steps * 2);
  
  for (int i = 0; i <= steps; i++) {
    int br = map(i, 0, steps, 0, baseBrightness);
    crown.setBrightness(br);
    setCrownColor(r, g, b);
    delay(delayTime);
  }
  
  for (int i = steps; i >= 0; i--) {
    int br = map(i, 0, steps, 0, baseBrightness);
    crown.setBrightness(br);
    setCrownColor(r, g, b);
    delay(delayTime);
  }
}

void setMood(uint8_t er, uint8_t eg, uint8_t eb, uint8_t cr, uint8_t cg, uint8_t cb) {
  eye1.setBrightness(baseBrightness);
  eye2.setBrightness(baseBrightness);
  crown.setBrightness(baseBrightness);
  setEyesColor(er, eg, eb);
  setCrownColor(cr, cg, cb);
}

// =====================================================================
//                      SERVO FUNCTIONS
// =====================================================================

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

// =====================================================================
//                   PERFORMANCE FUNCTIONS (Tracks 1-23)
// =====================================================================

// Track 1: "You've been practicing..." - Playful/Flirtatious
void performTrack001() {
  Serial.println(F("Track 1: Playful"));
  initial();
  delay(1000);

  setMood(0, 255, 100, 0, 200, 50);  // Green - happy
  
  musicPlayer.startPlayingFile("track001.mp3");
  
  
  delay(500);
  pulseEyes(0, 255, 100, 1000);

  delay(800);



  
  while (musicPlayer.playingMusic) delay(100);
    initial();
    speak(1);
    talking(1);
}

// Track 2: "It was just harmless dancing..." - Defensive
void performTrack002() {
  Serial.println(F("Track 2: Defensive"));
  

  setMood(150, 0, 255, 100, 0, 200);  // Purple - confused/defensive
  
  musicPlayer.startPlayingFile("track002.mp3");
  
  delay(1000);

  delay(2000);

  
  while (musicPlayer.playingMusic) delay(100);
    initial();
    speak(1);
    flapping(1);
}

// Track 3: "Honey, you're overreacting." - Dismissive
void performTrack003() {
  Serial.println(F("Track 3: Dismissive"));
  
  initial();
  setMood(255, 255, 255, 200, 200, 200);  // White - neutral
  
  musicPlayer.startPlayingFile("track003.mp3");
  
  delay(300);

  delay(500);

  
  while (musicPlayer.playingMusic) delay(100);
  speak(1);
  attention(1);
}

// Track 4: "Well, maybe if you were willing..." - Accusatory
void performTrack004() {
  Serial.println(F("Track 4: Accusatory"));
  
initial();

  setMood(255, 100, 0, 255, 80, 0);  // Orange - irritated
  
  musicPlayer.startPlayingFile("track004.mp3");
  
  delay(800);

  delay(1500);

  
  while (musicPlayer.playingMusic) delay(100);
initial();
speak(1);
talking(1);


}

// Track 5: "GO TO BED!" - Angry
void performTrack005() {
  Serial.println(F("Track 5: Angry"));
  
  initial();
  setMood(255, 0, 0, 255, 0, 0);  // Red - angry
  
  musicPlayer.startPlayingFile("track005.mp3");
  
  delay(200);
  
  flickerEyes(255, 0, 0, 1500);
  
  while (musicPlayer.playingMusic) delay(100);
  initial();
  flapping(1);
  speak(1);
}

// Track 6: "Wow, I've never heard..." - Sarcastic then Aggressive
void performTrack006() {
  Serial.println(F("Track 6: Sarcastic/Aggressive"));
  
  
  setMood(255, 255, 255, 200, 200, 200);  // Start white
  
  musicPlayer.startPlayingFile("track006.mp3");
  
  // Sarcastic phase
  delay(1000);

  delay(2000);
  
  // Transition to aggressive
  setMood(255, 0, 0, 255, 0, 0);  // Red
  delay(1000);

  delay(1500);

  delay(2000);

  
  while (musicPlayer.playingMusic) delay(100);

}

// Track 7: "I can't believe we're dividing..." - Weary
void performTrack007() {
  Serial.println(F("Track 7: Weary"));
  

  setMood(0, 0, 200, 0, 0, 150);  // Blue - sad/tired
  
  musicPlayer.startPlayingFile("track007.mp3");
  
  delay(1000);

  delay(2000);

  
  while (musicPlayer.playingMusic) delay(100);

}

// Track 8: "I want the coffee machine." - Firm/Possessive
void performTrack008() {
  Serial.println(F("Track 8: Firm/Possessive"));
  

  setMood(200, 50, 0, 180, 40, 0);  // Red-orange - possessive
  
  musicPlayer.startPlayingFile("track008.mp3");
  
  delay(300);

  delay(800);

  
  while (musicPlayer.playingMusic) delay(100);
initial();
}

// Track 9: "Visual superiority?" - Confused/Annoyed
void performTrack009() {
  Serial.println(F("Track 9: Confused"));
  
initial();
  setMood(150, 0, 255, 100, 0, 200);  // Purple
  
  musicPlayer.startPlayingFile("track009.mp3");
  
  delay(400);

  delay(800);

  
  while (musicPlayer.playingMusic) delay(100);
initial();
}

// Track 10: "Did I just lose custody..." - Defeated
void performTrack010() {
  Serial.println(F("Track 10: Defeated"));
  
initial();
  setMood(0, 0, 200, 50, 0, 150);  // Dark blue
  
  musicPlayer.startPlayingFile("track010.mp3");
  
  delay(800);

  delay(1500);

  
  while (musicPlayer.playingMusic) delay(100);
initial();
}

// Track 11: "It's just stuff, kid..." - Dismissive
void performTrack011() {
  Serial.println(F("Track 11: Dismissive"));
  
initial();
  setMood(255, 100, 0, 200, 80, 0);  // Orange
  
  musicPlayer.startPlayingFile("track011.mp3");
  
  delay(1500);

  delay(2000);

  delay(2000);

  
  while (musicPlayer.playingMusic) delay(100);
initial();
}

// Track 12: "Go put that phone down." - Authoritative
void performTrack012() {
  Serial.println(F("Track 12: Authoritative"));
  
initial();
  setMood(255, 50, 0, 200, 40, 0);  // Red-orange
  
  musicPlayer.startPlayingFile("track012.mp3");
  
  delay(300);

  
  while (musicPlayer.playingMusic) delay(100);
initial();
}

// Track 13: "What? Give me that." - Panicked
void performTrack013() {
  Serial.println(F("Track 13: Panicked"));
  
initial();
  setMood(255, 255, 0, 255, 200, 0);  // Yellow - panic
  
  musicPlayer.startPlayingFile("track013.mp3");
  
  delay(200);

  flickerEyes(255, 255, 0, 1000);
  
  while (musicPlayer.playingMusic) delay(100);
initial();
}

// Track 14: "Stop! That's private..." - Desperate
void performTrack014() {
  Serial.println(F("Track 14: Desperate"));
  
initial();
  setMood(255, 200, 0, 255, 150, 0);  // Yellow-orange
  
  musicPlayer.startPlayingFile("track014.mp3");
  
  delay(200);

  delay(1000);

  flickerEyes(255, 100, 0, 2000);
  
  while (musicPlayer.playingMusic) delay(100);
initial();
}

// Track 15: "You don't understand..." - Defensive
void performTrack015() {
  Serial.println(F("Track 15: Defensive"));
  
initial();
  setMood(200, 0, 200, 150, 0, 150);  // Purple - conflicted
  
  musicPlayer.startPlayingFile("track015.mp3");
  
  delay(1500);

  delay(2000);

  delay(2000);

  
  while (musicPlayer.playingMusic) delay(100);
initial();
}

// Track 16: "Where did you even find that?" - Guilty
void performTrack016() {
  Serial.println(F("Track 16: Guilty"));
  
initial();
  setMood(0, 0, 100, 50, 0, 80);  // Dim blue - guilty
  
  musicPlayer.startPlayingFile("track016.mp3");
  
  delay(500);

  delay(1500);

  
  while (musicPlayer.playingMusic) delay(100);
initial();
}

// Track 17: "Wait—I didn't actually—" - Protesting
void performTrack017() {
  Serial.println(F("Track 17: Protesting"));
  
initial();
  setMood(255, 255, 0, 200, 200, 0);  // Yellow
  
  musicPlayer.startPlayingFile("track017.mp3");
  
  delay(300);

  delay(700);

  
  while (musicPlayer.playingMusic) delay(100);
initial();
}

// Track 18: "You're not helping." - Frustrated
void performTrack018() {
  Serial.println(F("Track 18: Frustrated"));
  
initial();
  setMood(200, 200, 200, 150, 150, 150);  // Dim white - exhausted
  
  musicPlayer.startPlayingFile("track018.mp3");
  
  delay(400);

  
  while (musicPlayer.playingMusic) delay(100);
initial();
}

// Track 19: "Hold on. Why is the Judge..." - Suspicious
void performTrack019() {
  Serial.println(F("Track 19: Suspicious"));
  
initial();
  setMood(200, 100, 0, 150, 80, 0);  // Orange - suspicious
  
  musicPlayer.startPlayingFile("track019.mp3");
  
  delay(800);

  delay(1200);

  
  while (musicPlayer.playingMusic) delay(100);
initial();
}

// Track 20: "Why do YOU have HER phone?" - Angry/Confused
void performTrack020() {
  Serial.println(F("Track 20: Angry/Confused"));
  
initial();
  setMood(255, 0, 100, 200, 0, 100);  // Red-purple mix
  
  musicPlayer.startPlayingFile("track020.mp3");
  
  delay(400);

  flickerEyes(255, 0, 0, 1500);
  delay(800);

  
  while (musicPlayer.playingMusic) delay(100);
initial();
}

// Track 21: "IT LOOKS LIKE YOU WERE SLEEPING..." - Explosive
void performTrack021() {
  Serial.println(F("Track 21: Explosive"));
  
initial();
  setMood(255, 0, 0, 255, 0, 0);  // Bright red
  
  musicPlayer.startPlayingFile("track021.mp3");
  
  delay(300);
 
  flickerEyes(255, 0, 0, 2000);
  delay(500);

  
  while (musicPlayer.playingMusic) delay(100);
initial();
}

// Track 22: "I cannot BELIEVE this..." - Betrayed
void performTrack022() {
  Serial.println(F("Track 22: Betrayed"));
  
initial();
  setMood(255, 0, 0, 200, 0, 0);  // Start red
  
  musicPlayer.startPlayingFile("track022.mp3");
  
  delay(1000);

  delay(2000);
  
  // Transition to blue (betrayal)
  setMood(0, 0, 200, 0, 0, 150);
  delay(2000);

  
  while (musicPlayer.playingMusic) delay(100);
initial();
}

// Track 23: "So what now?" - Resigned
void performTrack023() {
  Serial.println(F("Track 23: Resigned"));
  
initial();
  setMood(0, 0, 100, 0, 0, 80);  // Dim blue
  
  musicPlayer.startPlayingFile("track023.mp3");
  
  delay(800);

  
  while (musicPlayer.playingMusic) delay(100);
initial();
}

// =====================================================================
//                         SETUP FUNCTIONS
// =====================================================================

void setupRF24Common() {
  if (!radio.begin()) {
    Serial.println(F("Radio failed"));
    while (1);
  }
  Serial.println(F("Radio OK"));
  
  radio.setDataRate(RF24_250KBPS);
  radio.setChannel(CUSTOM_CHANNEL_NUMBER);
  radio.setPALevel(RF24_POWER_LEVEL);
}

void setupRF24() {
  setupRF24Common();
  radio.openWritingPipe(rcvrAddress);
  radio.openReadingPipe(1, xmtrAddress);
  Serial.println(F("Receiver ready"));
}

void setupMusicMakerShield() {
  if (!musicPlayer.begin()) {
    Serial.println(F("VS1053 not found"));
    while (1);
  }
  Serial.println(F("VS1053 OK"));

  if (!SD.begin(CARDCS)) {
    Serial.println(F("SD failed"));
    while (1);
  }
  Serial.println(F("SD OK"));

  musicPlayer.setVolume(20, 20);
  musicPlayer.useInterrupt(VS1053_FILEPLAYER_PIN_INT);
}

void setupNeoPixels() {
  eye1.begin();
  eye2.begin();
  crown.begin();

  eye1.setBrightness(baseBrightness);
  eye2.setBrightness(baseBrightness);
  crown.setBrightness(baseBrightness);

  eye1.show();
  eye2.show();
  crown.show();
  
  Serial.println(F("NeoPixels OK"));
}

void setupServoMotors() {
initial();
  Serial.println(F("Servos OK"));
}

// =====================================================================
//                            SETUP
// =====================================================================

void setup() {
  Serial.begin(9600);
  Serial.println(F("===================================="));
  Serial.println(F("   ROBOT RECEIVER - 23 TRACKS"));
  Serial.println(F("   CORRECTED DIALOGUE ORDER"));
  Serial.println(F("===================================="));

  setupMusicMakerShield();
  setupServoMotors();
  setupNeoPixels();
  setupRF24();

  // Flash to indicate ready
  setEyesColor(0, 255, 0);
  setCrownColor(0, 255, 0);
  delay(500);
  setEyesColor(0, 0, 0);
  setCrownColor(0, 0, 0);
  
  Serial.println(F("Ready!"));
}

// =====================================================================
//                            MAIN LOOP
// =====================================================================

void loop() {
  radio.startListening();
  
  if (radio.available(&pipeNum)) {
    radio.read(&data, sizeof(data));
    
    Serial.print(F("Command: "));
    Serial.println(data.stateNumber);

    // Execute performance based on state number (0-23)
    // State 0 = Initial pose (no dialogue)
    // States 1-23 = Dialogues (track001.mp3 - track023.mp3)
    switch (data.stateNumber) {
      case 0:
        Serial.println(F("State 0: Initial pose"));
      initial();
        setEyesColor(0, 255, 0);  // Green - ready
        setCrownColor(0, 255, 0);
        delay(500);
        setEyesColor(0, 0, 0);
        setCrownColor(0, 0, 0);
        break;
        
      case 1:  performTrack001(); break;
      case 2:  performTrack002(); break;
      case 3:  performTrack003(); break;
      case 4:  performTrack004(); break;
      case 5:  performTrack005(); break;
      case 6:  performTrack006(); break;
      case 7:  performTrack007(); break;
      case 8:  performTrack008(); break;
      case 9:  performTrack009(); break;
      case 10: performTrack010(); break;
      case 11: performTrack011(); break;
      case 12: performTrack012(); break;
      case 13: performTrack013(); break;
      case 14: performTrack014(); break;
      case 15: performTrack015(); break;
      case 16: performTrack016(); break;
      case 17: performTrack017(); break;
      case 18: performTrack018(); break;
      case 19: performTrack019(); break;
      case 20: performTrack020(); break;
      case 21: performTrack021(); break;
      case 22: performTrack022(); break;
      case 23: performTrack023(); break;
      
      default:
        Serial.print(F("Invalid state: "));
        Serial.println(data.stateNumber);
        setMood(150, 0, 255, 100, 0, 200);
        delay(1000);
        setEyesColor(0, 0, 0);
        setCrownColor(0, 0, 0);
    }
    
    Serial.println(F("Performance complete"));
  }
}
