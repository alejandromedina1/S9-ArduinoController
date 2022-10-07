const int joystickX = A0;
const int joystickY = A1;
const int joystickButton = 2;
const int button = 3;
int percentX = 0;
int percentY = 0;
boolean doSomething = false;

int prevPercentX = 0;
int prevPercentY = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(joystickButton, INPUT);
  pinMode(button, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  percentX = makePercent(analogRead(joystickX));
  percentY = makePercent(analogRead(joystickY));

  if (digitalRead(button) == HIGH && doSomething == false) {

    Serial.print(doSomething);
    Serial.print(' ');
    Serial.print(percentX);
    Serial.print(' ');
    Serial.print(percentY);
    Serial.print(' ');
    Serial.println();
    doSomething = true;

  }

  if (digitalRead(button) == LOW) {
    doSomething = false;
  }


  if (percentX != prevPercentX || percentY != prevPercentY) {
    Serial.print(doSomething);
    Serial.print(' ');
    Serial.print(percentX);
    Serial.print(' ');
    Serial.print(percentY);
    Serial.print(' ');
    Serial.println();
    prevPercentX = percentX;
    prevPercentY = percentY;
  }
  /*
    if (percentX != prevPercentX || percentY != prevPercentY) {
      Serial.println(percent);
      prevPercent = percent;
    }*/
  delay(100);

}

int makePercent (float value) {
  return round(value / 1024.00 * 100);
}
