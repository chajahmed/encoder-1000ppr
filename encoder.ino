/*
 * Author: Chaudhary Ahmed Javaid
 * Website: https://github.com/chajahmed
 * Description: Count the number of encoder pulses per revolution.  
 */
 
// Encoder output to Arduino Interrupt pin. Tracks the pulse count.
#define ENC_IN_RIGHT_A PA7
#define ENC_IN_RIGHT_B PA6
 
// Keep track of the number of right wheel pulses
volatile long right_wheel_pulse_count = 0;
void setup() {
 
  // Open the serial port at 9600 bps
  Serial.begin(9600); 
 
  // Set pin states of the encoder
  pinMode(ENC_IN_RIGHT_A , INPUT_PULLUP);
  pinMode(ENC_IN_RIGHT_B , INPUT);
 
  // Every time the pin goes high, this is a pulse
  attachInterrupt(digitalPinToInterrupt(ENC_IN_RIGHT_A), right_wheel_pulse, RISING);
 // attachInterrupt(digitalPinToInterrupt(ENC_IN_RIGHT_B), left_wheel_pulse, FALLING);
   
}
 
void loop() {
  
    Serial.print(" Pulses: ");
    Serial.println(right_wheel_pulse_count); 
    
}
 
// Increment the number of pulses by 1
void right_wheel_pulse() {
  if  (digitalRead(ENC_IN_RIGHT_B) == HIGH) {
    right_wheel_pulse_count++;
  }
}
