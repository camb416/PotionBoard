 #include <ProTrinketKeyboard.h>  // Ensure the library is installed

 #define NUM_KEYS 6
 #define LED_PIN 13
 
const int keys[] = {9,3,4,5,6,8};
int keyStates[NUM_KEYS];
int prevKeyStates[NUM_KEYS];
char* keyCodes[] = {
  "Strategy.\n",
  "Innovation.\n",
  "Design.\n",
  "Production.\n",
  "Development.\n",
  "Deployment.\n",
};
int prevState[NUM_KEYS];



void setup() {

  //configure pin2 as an input and enable the internal pull-up resistor
 for(int i=0;i<NUM_KEYS;i++){
  pinMode(keys[i], INPUT_PULLUP);
  prevState[i] == HIGH; // keys up
 }
  pinMode(LED_PIN, OUTPUT);
  TrinketKeyboard.begin();
}

void loop() {
 TrinketKeyboard.poll();
  int sensorVal = LOW;
  for(int i=0;i<NUM_KEYS;i++){
     if(digitalRead(keys[i]) == LOW &&
     prevState[i] == HIGH){

        
             TrinketKeyboard.print(keyCodes[i]); 
             prevState[i] = LOW;

        sensorVal = HIGH;
     }
     prevState[i] = digitalRead(keys[i]);
  }
   digitalWrite(LED_PIN, sensorVal );
}



