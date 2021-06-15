/*
 * This is a pretty simple sketch, basically the light sensor module is treated
 * as a digital input pull button and when it sends a 0, that means it is detecting light
 * 
 */

bool lightDetected = false;
int input = 4;
int output = 2;

void setup() {
  //start serial connection
  Serial.begin(9600);
  //configure pin 2 as an input and enable the internal pull-up resistor
  pinMode(input, INPUT_PULLUP);
  pinMode(output, OUTPUT);

}

void loop() {
  //read the pushbutton value into a variable
  int sensorVal = digitalRead(input);
  
  // Keep in mind the pull-up means the pushbutton's logic is inverted. It goes
  // HIGH when it's open, and LOW when it's pressed. Turn on pin 13 when the
  // button's pressed, and off when it's not:
  if (sensorVal == LOW && !lightDetected) {
    lightDetected = true;
    digitalWrite(output, HIGH);
    Serial.println("trigger active");
    delay(150);
    digitalWrite(output, LOW);
  }

  if(sensorVal == HIGH){
    lightDetected = false;
  }
}
