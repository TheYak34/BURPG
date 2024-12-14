/*
General Thing I need to do:
  1. Arduino recieves input (button press)
  2. does digitalWrite on solenoid
  3. wait half a second
  4. fires ematch
  5. turn ematch and solenoid off after 2 seconds
*/

const int BUTTON_PIN = 2;    // Button Pin here
const int SOLENOID_PIN = 9;  // Solenoid Pin here
const int MOSFET_PIN = 0;    // MOSFET Pin goes here

int buttonState = 0;
bool runLoop = true;

void setup() {
  pinMode(BUTTON_PIN, INPUT);
  pinMode(SOLENOID_PIN, OUTPUT);
  pinMode(MOSFET_PIN, OUTPUT);
}


/* 
  What code should do, each time the loop runs it will check i
  button is pressed (by seeing if voltage is high) and then run if statement
  where write to solenoid (send high voltage to the pin of solenoid) waid quarter of
  a second and then fire ematch (send high voltage to Mosfet pin)
*/
void loop() {
  if (runLoop == true){
    buttonState = digitalRead(BUTTON_PIN);
    if (buttonState == HIGH) {
      digitalWrite(SOLENOID_PIN, HIGH);
      delay(250);
      digitalWrite(MOSFET_PIN, HIGH);
      delay(2000);
      digitalWrite(SOLENOID_PIN, LOW);
      digitalWrite(MOSFET_PIN, LOW);
      runLoop = false;
    }
  }
}
