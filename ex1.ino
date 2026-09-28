// LED Pattern Controller using Push Buttons
// Arduino Uno

const int ledPins[] = {2, 3, 4, 5, 6, 7, 8, 9};
const int buttonPins[] = {10, 11, 12, 13};

const int NUM_LEDS = 8;
const int NUM_BUTTONS = 4;

void setup() {
  // Set LED pins as outputs
  for (int i = 0; i < NUM_LEDS; i++) {
    pinMode(ledPins[i], OUTPUT);
  }

  // Set buttons as inputs with internal pull-up resistors
  for (int i = 0; i < NUM_BUTTONS; i++) {
    pinMode(buttonPins[i], INPUT_PULLUP);
  }

  // Turn all LEDs off
  allOff();
}

void loop() {

  // Button 1 → Pattern 1
  if (digitalRead(buttonPins[0]) == LOW) {
    pattern1();
  }

  // Button 2 → Pattern 2
  if (digitalRead(buttonPins[1]) == LOW) {
    pattern2();
  }

  // Button 3 → Pattern 3
  if (digitalRead(buttonPins[2]) == LOW) {
    pattern3();
  }

  // Button 4 → Pattern 4
  if (digitalRead(buttonPins[3]) == LOW) {
    pattern4();
  }
}

// --------------------------------
// Pattern 1: Running LED
// --------------------------------
void pattern1() {

  for (int i = 0; i < NUM_LEDS; i++) {

    // Stop if another button is pressed
    if (anyButtonPressed()) return;

    allOff();
    digitalWrite(ledPins[i], HIGH);
    delay(100);
  }
}

// --------------------------------
// Pattern 2: Left and Right
// --------------------------------
void pattern2() {

  // Left to right
  for (int i = 0; i < NUM_LEDS; i++) {

    if (anyButtonPressed()) return;

    allOff();
    digitalWrite(ledPins[i], HIGH);
    delay(100);
  }

  // Right to left
  for (int i = NUM_LEDS - 1; i >= 0; i--) {

    if (anyButtonPressed()) return;

    allOff();
    digitalWrite(ledPins[i], HIGH);
    delay(100);
  }
}

// --------------------------------
// Pattern 3: Alternate LEDs
// --------------------------------
void pattern3() {

  if (anyButtonPressed()) return;

  // LEDs 1,3,5,7 ON
  for (int i = 0; i < NUM_LEDS; i++) {
    digitalWrite(ledPins[i], i % 2 == 0 ? HIGH : LOW);
  }

  delay(300);

  if (anyButtonPressed()) return;

  // LEDs 2,4,6,8 ON
  for (int i = 0; i < NUM_LEDS; i++) {
    digitalWrite(ledPins[i], i % 2 == 1 ? HIGH : LOW);
  }

  delay(300);
}

// --------------------------------
// Pattern 4: All LEDs blinking
// --------------------------------
void pattern4() {

  if (anyButtonPressed()) return;

  // All ON
  for (int i = 0; i < NUM_LEDS; i++) {
    digitalWrite(ledPins[i], HIGH);
  }

  delay(300);

  if (anyButtonPressed()) return;

  // All OFF
  allOff();

  delay(300);
}

// --------------------------------
// Turn all LEDs OFF
// --------------------------------
void allOff() {

  for (int i = 0; i < NUM_LEDS; i++) {
    digitalWrite(ledPins[i], LOW);
  }
}

// --------------------------------
// Check whether any button is pressed
// --------------------------------
bool anyButtonPressed() {

  for (int i = 0; i < NUM_BUTTONS; i++) {
    if (digitalRead(buttonPins[i]) == LOW) {
      allOff();
      return true;
    }
  }

  return false;
}
