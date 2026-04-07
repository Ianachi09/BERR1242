const int buttonPin = 7;
const int ledRedPin = 13;
const int ledYellowPin = 12;
const int ledGreenPin = 8;
const int buzzerPin = 4;
int buttonState = 0;
bool isRunning;
long randNum;

// Random number generator (for delay randomization)
int rng() {
  randNum = random(0,3);
  return randNum;
}

// Function for Traffic (red to green to red)
int greenToRed() {
  isRunning = true;
  Serial.println("Traffic function is running. . ."); //DEBUG
  digitalWrite(ledRedPin, LOW);
  digitalWrite(ledGreenPin, HIGH);
  tone(buzzerPin, 500); 
  delay(500);
  noTone(buzzerPin);       
     
  rng();
  Serial.println(randNum); //DEBUG
  
  // Delay randomizer for green
  if (randNum == 0) {
  	delay(10000);
  } else if (randNum == 1) {
    delay(5000);
  } else if (randNum == 2) {
    delay(15000);
  }
        
   digitalWrite(ledGreenPin, LOW);
   digitalWrite(ledYellowPin, HIGH);
        
   rng();
   Serial.println(randNum); //DEBUG
   // Delay randomizer for green
  
   if (randNum == 0) {
    delay(4000);
   } else if (randNum == 1) {
    delay(5000);
   } else if (randNum == 2) {
     delay(6000);
   }
      
   digitalWrite(ledYellowPin, LOW);
   digitalWrite(ledRedPin, HIGH);
   isRunning = false;
}

void setup()
{
  Serial.begin(9600);
   isRunning = false;
   randomSeed(analogRead(0));
   pinMode(buttonPin, INPUT);
   pinMode(ledRedPin, OUTPUT);
   pinMode(ledYellowPin, OUTPUT);
   pinMode(ledGreenPin, OUTPUT);
   pinMode(buzzerPin, OUTPUT);
   digitalWrite(ledRedPin, HIGH);
}

void loop() {
  buttonState = digitalRead(buttonPin);
  Serial.println("Circuit is running. . ."); //DEBUG
    
  // Checking if button is already pressed and traffic is running
  if (buttonState == HIGH) {
    Serial.println("Button is pressed"); //DEBUG
    if (isRunning == false) {
      greenToRed();
    }
  }
}
