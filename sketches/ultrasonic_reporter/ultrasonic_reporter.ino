/**
 * This code interfaces with a Kuman HC-SR04 ultrasonic sensor.  It will continuously measure
 * distance with the HC-SR04 and write the values to the serial port.
 * 
 * The sensor works by sending a 10us pulse which triggers it to send out an ultrasonic burst
 * after which a pulse proportional to distance will be sent on the echo pin.
 * 
 * More documentation on the sensor can be found here: http://www.micropik.com/PDF/HCSR04.pdf
 * 
 * @author Anthony Barone
 */

// Pin constants
const int TRIGGER = A0;
const int ECHO = A1;

void setup() {
  Serial.begin(9600);
  pinMode(TRIGGER, OUTPUT);
  pinMode(ECHO, INPUT);
  digitalWrite(TRIGGER, LOW);
}

void loop() {
  // Get the distance in cm
  long distance = ping();
  
  Serial.println(distance);
  
  // The readings aren't stable without a delay between them
  delayMicroseconds(10);
}

/**
 * Sends a 10us pulse to the TRIGGER pin and reads the response from the ECHO pin, converting it to cm.
 * @return distance in cm
 */
long ping() {
  // Trigger a burst with a 10 us pulse
  digitalWrite(TRIGGER, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER, LOW);
  
  // Read the response
  long echoPulseDuration = pulseIn(ECHO, HIGH);
  
  // Magic calculation to get centimeters per HC-SR04 documentation
  return echoPulseDuration / 58;
}

