const int RED=9; // вывод красной ноги RGB-светодиода
const int GREEN=10; // вывод зеленой ноги RGB-светодиода
const int BLUE=11; // вывод синей ноги RGB-светодиода
int red; // переменная для хранения R-составляющей цвета
int green; // переменная для хранения G-составляющей цвета
int blue; // переменная для хранения B-составляющей цвета

void setup()
{
}

void loop()
{
    red = 100; green = 0; blue = 0;

	for (green = 0; green <= 255; green++)
    {
        setRGB(red, green, blue);
    }

    for (red = 100; red  >= 0; red--)
    {
        setRGB(red, green, blue);
    }

    for (blue = 0; blue <= 100; blue++)
    {
        setRGB(red, green, blue);
    }

    for (green = 255; green  >= 0; green--)
    {
        setRGB(red, green, blue);
    }
    for (red = 0; red <= 100; red++)
    {
        setRGB(red, green, blue);
    }
    
     delay(2000);
}

void setRGB(int r, int g, int b)
{
    analogWrite(RED,r);
    analogWrite(GREEN,g);
    analogWrite(BLUE,b);
    delay(10); 
}
