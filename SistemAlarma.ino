
const int trigPin = 11;//trigger
const int echoPin = 10; //echo

int ledPin = 5;//Pin led
int buttonApin = 9;//Pin armat
int buttonBpin = 8;//Pin dezarmat
int value_A;
int value_B;


int buzzer = 6;// buzzer pin
int delayTime1= 250;
int delayTime2=250;

long duration; // timpul de parcurgere
int distance; // calculam distanta

void setup() {

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
  pinMode(ledPin, OUTPUT);
  pinMode(buttonApin, INPUT_PULLUP);  
  pinMode(buttonBpin, INPUT_PULLUP);  

  pinMode(buzzer, OUTPUT);
  
  pinMode(12, INPUT);
  
  Serial.begin(9600);

  

}

void loop() {

 
  value_A = digitalRead(buttonApin);
  value_B = digitalRead(buttonBpin);
  
  delay(500);

  
   if (value_A == LOW)
  {
    //Armat -> led on
    digitalWrite(ledPin, HIGH);
    while(ledPin, HIGH)
    {
      
      digitalWrite(trigPin, LOW);
      delayMicroseconds(2);
    
      digitalWrite(trigPin, HIGH);
      delayMicroseconds(10);
      digitalWrite(trigPin, LOW);
    
      duration = pulseIn(echoPin, HIGH);
      distance = duration*0.034/2;
    
      Serial.print("Distance:");
      Serial.println(distance);

      while (distance < 98)
      {
        // Distanta mai mica de 98cm 
           
            digitalWrite(buzzer,HIGH);
            digitalWrite(ledPin, HIGH);
            delay(delayTime1);
            digitalWrite(buzzer,LOW);
            digitalWrite(ledPin, LOW);
            delay(delayTime1);

 
                digitalWrite(buzzer,HIGH);
                digitalWrite(ledPin, HIGH);
                delay(delayTime2);//wait for 2ms
                digitalWrite(buzzer,LOW);
                digitalWrite(ledPin, LOW);
                delay(delayTime2);//wait for 2ms   

             // Dezarmare la buton
             if (digitalRead(buttonBpin) == LOW)
              {
                break;
                }
      
          
      }
    
      delay(100);

      // Dezarmare la buton
      if (digitalRead(buttonBpin) == LOW)
      {
        break;
      }
      

      }

      
  }
  // Dezarmat -> led off
  if (value_B == LOW)
  {
    digitalWrite(ledPin, LOW);
  }

 
  
  
 
}

 
