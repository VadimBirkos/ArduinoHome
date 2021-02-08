int pins[8] = {9, 13, 4, 6, 7, 10, 3, 5};

int pindigits[4] = {2, 12, 11, 8 };

byte numbers[10] = {B11111100, B01100000, B11011010,
                    B11110010, B01100110, B10110110,
                    B10111110, B11100000, B11111110,
                    B11110110};

int digit = 0;

int number = 0;
int number1 = 0;
int number2 = 0;

unsigned long millis1 = 0;
int mode = 0;
const int BUTTON = 14;
int tekButton = LOW;  // Переменная для сохранения текущего состояния кнопки
int prevButton = LOW; // Переменная для сохранения предыдущего состояния
// к нопки
boolean ledOn = false;

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
    tekButton = debounce(prevButton);
    if (prevButton == LOW && tekButton == HIGH) // если нажатие...
    {
        mode = 1 - mode; // изменение режима
        if (mode == 1)
            number = 0;
    }
    if (millis() - millis1 >= 100 && mode == 1)
    {
        millis1 = millis1 + 100;
        number = number + 1;
        if (number == 10000)
            number = 0;
    }
    number1 = number;
    for (int i = 0; i < 4; i++)
    {
        number2 = number1 % 10;
        number1 = number1 / 10;
        showNumber(number2, i);
        for (int j = 0; j < 4; j++)
            digitalWrite(pindigits[j], HIGH);
        digitalWrite(pindigits[i], LOW);
        delay(1);
    }
}

void showNumber(int number, int dig)
{
    for (int i = 0; i < 8; i++)
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

    if (dig == 1) 
    {
        digitalWrite(pins[7], HIGH);
    }
}

boolean debounce(boolean last)
{
    boolean current = digitalRead(BUTTON); 
    if (last != current)                   
    {
        delay(5);                      
        current = digitalRead(BUTTON); 
        return current;                
    }
}
