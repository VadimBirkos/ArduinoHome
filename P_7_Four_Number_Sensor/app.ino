int pins[8] = {9, 13, 4, 6, 7, 10, 3, 5};

int pindigits[4] = {2, 8, 11, 12};

byte numbers[10] = { B11111100, B01100000, B11011010,
B11110010, B01100110, B10110110,
B10111110, B11100000, B11111110,
B11110110};

int digit = 0;
int number = 0;

void setup()
{
    for (int i = 0; i < 8; i++)
    {
        pinMode(pins[i], OUTPUT);
    }

    for (int i = 0; i < 4; i++)
    {
        pinMode(pindigits[i], OUTPUT);
        digitalWrite(pindigits[i], HIGH);
    }
}

void loop()
{
    number=(number+1)%10;
    showNumber(number); // DS
    for(int i=0;i<4;i++)
        digitalWrite(pindigits[i],HIGH);
    digit=random(0,4);
    digitalWrite(pindigits[digit],LOW);
    delay(3000);
}

void showNumber(int number)
{
    for (int i = 0; i < 7; i++)
    {
        if (bitRead(numbers[number], 7 - i) == HIGH)
        {
            digitalWrite(pins[i], HIGH);
        }
        else
        {
            digitalWrite(pins[i], LOW);
        }
    }
}
