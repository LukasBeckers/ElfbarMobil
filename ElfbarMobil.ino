const int acceleratorPin = A3;
const int digitalAcceleratorPin = 3; // For testing, maybe the thumbthrottle sends a pwm signal, who knows? 
const int motorPin = 5;
const int mosfetPowerPin = 8; // Used to turn on, of the Mosfets

void setup() {
  // put your setup code here, to run once:
  pinMode(acceleratorPin, INPUT);

  // start the Mosfet driver
  digitalWrite(mosfetPowerPin, HIGH);

  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int acceleratorRead = analogRead(acceleratorPin);


  // convert to value between 255 and zero for 8 bit pwm input.
  int pwmValue = constrain(map(acceleratorRead, 180, 850, 0, 255), 0, 255);

  // adapt the pwd signal.
  analogWrite(motorPin, pwmValue);

  Serial.print("Potentiometer Value: ");
  Serial.println(acceleratorRead);
  Serial.print("PWM: ");
  Serial.println(pwmValue);
  
}
