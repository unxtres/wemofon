int data;
int counter = 0;
unsigned long starter;
int relayPin = D1;

void setup() 
{
  // initialize serial communications at 9600 bps 
  Serial.begin(9600);
  pinMode(relayPin, OUTPUT);
  digitalWrite(relayPin, HIGH);
}

void open()
{
  digitalWrite(relayPin, LOW);
  delay(4000);
  digitalWrite(relayPin, HIGH);
}

void loop() 
{
  counter = 0;
  Serial.println("czekam na syganal");
  if (analogRead(A0) > 500)
  {
    data = analogRead(A0);
    Serial.println(data);
    counter = 1;
    delay(500);
    starter = millis();
    while (millis()-starter < 6000)
    {
      data = 0;
      data = analogRead(A0);
      yield();
      if (analogRead(A0) > 500 && data < 500)
      {
        counter++;
        Serial.println(counter);
        delay(500);
        if (counter>=4)
        {
          open();
          counter = 0;
          break;
        }
      }
    }
  }
}
