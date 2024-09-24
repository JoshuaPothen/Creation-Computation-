/*

Silent Roar : Screaming LEDs
Joshua Jacob Pothen

Credits:
FSR Workshop - Experiment 1: Analog Mapping - 1 Sensor Value
 https://github.com/DigitalFuturesOCADU/CC2024/blob/main/experiment1/analogThreshold_1value/analogThreshold_1value.ino
*/



// initialize variables
int sensorValue = 0;
int sensorValue2 = 0;
int sensorPin = A0;
int sensorPin2 = A4;
int LEDpin = 2;
int LEDpin2 = 3;
int LEDpin3 = 4;
int LEDpin4 = 5;

//threshold initialization and setup
int threshold = 500; 
int threshold2 = 700;
int threshold3 = 800;
int threshold4 = 900;
int maxThreshold = 1100;
int CombSensorValue = 0;

void setup() {
  // initialize serial communication:
  Serial.begin(9600);
  //Set LED pins as outputs
  pinMode(LEDpin, OUTPUT);
  pinMode(LEDpin2, OUTPUT);
  pinMode(LEDpin3, OUTPUT);
  pinMode(LEDpin4, OUTPUT);
}

void loop() {
  // read light sensor pin and store value in a variable:
  sensorValue = analogRead(sensorPin);
  sensorValue2 = analogRead(sensorPin2)-500; //CALIBERATED BASED ON NEED(Soft Calibration)
 
 //Creates a combined output value for both sensor inputs
  CombSensorValue = (sensorValue + sensorValue2);
 
  //prints sensor input data on the serial monitor
  Serial.print("Sensor Value: ");
  Serial.print(sensorValue);
  Serial.print("|| Sensor Value 2: ");
  Serial.print(sensorValue2);
  Serial.print(" (Threshold: ");
  Serial.print(threshold);
  Serial.print("), LED: ");

//max threshold block, activates when max threshold is true
//strobe is activated
  if (CombSensorValue > maxThreshold ){
      digitalWrite(LEDpin, HIGH);
      delay (200);
      digitalWrite(LEDpin2, HIGH);
      delay (200);
      digitalWrite(LEDpin3, HIGH);
      delay (200);
      digitalWrite(LEDpin4, HIGH);
      delay (200);
       digitalWrite(LEDpin, LOW);
      delay (200);
      digitalWrite(LEDpin2, LOW);
      delay (200);
        digitalWrite(LEDpin3, LOW);
      delay (200);
      digitalWrite(LEDpin4, LOW);
      delay (200);
  }
  //threshold 4 - lights up last string of LEDs
   else if ((CombSensorValue < maxThreshold) && (CombSensorValue > threshold4)){
      digitalWrite(LEDpin4, HIGH);
      Serial.println("on!");
   }
   //threshold 3 - lights up 3rd string of LEDs
   else if ((CombSensorValue < threshold4) && (CombSensorValue > threshold3)){
      // set analog output accordingly
      digitalWrite(LEDpin3, HIGH);
      Serial.println("on!");
   }
   //threshold 2 - lights up 2nd string of LEDs
  else if ((CombSensorValue < threshold3) && (CombSensorValue > threshold2)){
      // set analog output accordingly
      digitalWrite(LEDpin2, HIGH);
      Serial.println("on!");
  }
  //threshold 1 - lights up 1st string of LEDs
  else if ((CombSensorValue < threshold2) && (CombSensorValue > threshold)){
      // set analog output accordingly
      digitalWrite(LEDpin, HIGH);
      Serial.println("on!");
  }
  else {
    //sets state of LED lights to false or off
    digitalWrite(LEDpin, LOW);
    digitalWrite(LEDpin2, LOW);
    digitalWrite(LEDpin3, LOW);
    digitalWrite(LEDpin4, LOW);
    Serial.println("off");
  }

  // delay between readings:
  delay(50);
}
