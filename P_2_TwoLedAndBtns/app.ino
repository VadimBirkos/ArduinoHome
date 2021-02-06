// Turn on btn and turn off with 2 LED.


#define BUTTON_ON_PIN 12
#define BUTTON_OFF_PIN 11
#define LIGHT_PIN 10
boolean ledState;


class Button
{
public:
    Button(byte initPin);
    void clickPerformed();
    boolean getClickedValue();

private:
    byte pin;
    boolean btnState;
    boolean prevState;
    boolean clicked;
};

Button::Button(byte initPin){
    pin = initPin;
    pinMode(initPin, INPUT_PULLUP);
}

void Button::clickPerformed()
{

    btnState = digitalRead(pin);

    if (!btnState && prevState)
    {
        clicked = true;
    }

    prevState = btnState;
}

boolean Button::getClickedValue()
{
    boolean isClicked = clicked;

    clicked = false;

    return isClicked;
}

Button turnOnBtn(BUTTON_ON_PIN);
Button turnOffBtn(BUTTON_OFF_PIN);


void setup()
{
    pinMode(LED_BUILTIN, OUTPUT);
    pinMode(LIGHT_PIN, OUTPUT);
}

void loop()
{
    turnOnBtn.clickPerformed();
    turnOffBtn.clickPerformed();

    if (turnOnBtn.getClickedValue())
    {
        //ledState = !ledState;
        digitalWrite(LED_BUILTIN, HIGH);
        digitalWrite(LIGHT_PIN, HIGH);
    }

    if(turnOffBtn.getClickedValue()){
        digitalWrite(LED_BUILTIN, LOW);   
        digitalWrite(LIGHT_PIN, LOW);
    }
}

