int pins[7] = {2, 3, 4, 5, 6, 7, 8};
byte numbers[10]  = {B11111100, B01100000, B11011010, B11110010, B01100110,
B10110110, B10111110, B11100000, B11111110, B11100110};
int currentNumber = 0;


void setup()
{
    for (int i = 0; i < 7; i++){
        pinMode(pins[i], OUTPUT);
    }
}

void loop()
{
    showNumber(currentNumber);
    delay(1000);
    currentNumber = (currentNumber + 1) % 10;
}

void showNumber(int number){
    for (int i = 0; i < 7; i++)
    {
        if (bitRead(numbers[number], 7-i) == HIGH){
            digitalWrite(pins[i], HIGH);
        } else {
            digitalWrite(pins[i], LOW);
        }
    }
    
}
