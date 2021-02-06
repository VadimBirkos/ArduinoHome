#define POT 0

const int lights[4] = {9, 10, 11, 12};
int countLed = 0;


int potValue = 0;

void setup()
{
    Serial.begin(9600);
    for (int i = 0; i < 4; i++){
        pinMode(lights[i], OUTPUT);
    }
}

void loop()
{
  potValue = analogRead(POT);
    countLed = map(potValue, 0, 1023, 0, 4);

    Serial.println(potValue);
    Serial.println(countLed);
    Serial.println('-');

    for (int i = 0; i < 4; i++){
        if (i < countLed){
            digitalWrite(lights[i], HIGH);
        } else {
            digitalWrite(lights[i], LOW);
        }
    }

 //   delay(1000);
}
