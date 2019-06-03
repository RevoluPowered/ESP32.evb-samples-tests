#define OLIMEX_REL1_PIN 32
#define OLIMEX_REL2_PIN 33
#define OLIMEX_BUT1_PIN 34

void configure_relay( int pin )
{
    // put your setup code here, to run once:
  pinMode(pin, OUTPUT);
  digitalWrite(pin, HIGH);
  delay(1000);
  digitalWrite(pin, LOW);  
}

void toggle_relay( int pin )
{
  digitalWrite(pin, HIGH);
  delay(1000);
  digitalWrite(pin, LOW);  
}

void setup() {
  // put your setup code here, to run once:
  configure_relay(OLIMEX_REL1_PIN);
  configure_relay(OLIMEX_REL2_PIN);

  pinMode(OLIMEX_BUT1_PIN, INPUT);
}

bool buttonState = false;
void loop() {
  // put your main code here, to run repeatedly:
  buttonState = digitalRead(OLIMEX_BUT1_PIN);

  if(!buttonState)
  {
    toggle_relay(OLIMEX_REL1_PIN);
    toggle_relay(OLIMEX_REL2_PIN);
  }

  delay(1000);

}
