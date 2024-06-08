const int acceleratorPin = A3;
const int motorPin = 5;
const int mosfetPowerPin; // Used to turn on, of the Mosfets

void setup() {
  // put your setup code here, to run once:
  pinMode(acceleratorPin, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int acceleratorRead = analogRead(acceleratorPin);

  // convert to value between 255 and zero for 8 bit pwm input.
  int pwmValue = map(acceleratorRead, 0, 1023, 0, 255);

  analogWrite(motorPin, pwmValue);

  Serial.print("Potentiometer Value: ");
  Serial.println(acceleratorRead);
  Serial.print("PWM: ");
  Serial.println(pwmValue);
  
}
