int ledPin = 13; //considering real light
int inPin = 3;   //door open close reading from pin 2
int counter = 0;   //counter variable
int door_status = 0;   //for status of pin
int a = 0;
int ledPin1 = 0;

void setup() {

  pinMode(ledPin, OUTPUT);
  pinMode(inPin, INPUT);

  Serial.begin(9600);

}


void loop() {


  door_status = digitalRead(inPin);
  ledPin1 = digitalRead(ledPin);
  digitalWrite(ledPin, LOW);
  check();

  if (counter == 0)
  {
    digitalWrite(ledPin, LOW);
    Serial.println("ideal state");
  }

  else if (counter == 1)
  {
    digitalWrite(ledPin, HIGH);
    Serial.println("LIGHT IS ON door opend for first time ");
  }

  else if (counter == 2)
  {
    digitalWrite(ledPin, HIGH);
    Serial.println("light will remain on until door is opened from inside ");
  }
  else
  {
    digitalWrite(ledPin, LOW);
    Serial.println("OFF");
    delay(5000);
    counter = 0;
  }

}


void check() {

  if (door_status == LOW && ledPin1 == LOW)
  {

    // Serial.println("ideal state"); //case 1 door is closed by default
    // digitalWrite(ledPin,LOW);     // led is also off
    counter = 0;

  }

  else if (door_status == HIGH && ledPin1 == LOW && counter == 0 )
  {
    // CASE 2 sensor is active means door is open from outside
    //light will remain on until i close the door and timeout concept goes here
    //Serial.println("LIGHT IS ON door opend for first time ");

    //    Serial.println("ON");
    //  digitalWrite(ledPin,HIGH);

    counter = 1;

  }

  else if (ledPin1 == HIGH && door_status == LOW) //CASE 3 door is closed from inside means someone is inside [door is closed ][light is ON]
  {
    //  Serial.println("light will remain on until door is opened from inside ");//light will remain on until door is opened from inside
    //  digitalWrite(ledPin,HIGH);

    counter = 2; //explecitly setting counter to 2

  }

  else if (door_status == HIGH && ledPin1 == HIGH && counter == 2 )
  {


    counter = 3; //explecitly setting counter to 3

  }
}

