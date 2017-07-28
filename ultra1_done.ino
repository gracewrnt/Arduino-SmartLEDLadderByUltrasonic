unsigned char echo[] = {3, 5, 7};
unsigned char trig[] = {2 ,4, 6} ;
const int speaker = A5;
unsigned long ultrasoundValue[] = {0.00, 0.00, 0.00};
double showCM[] = {0, 0, 0} ;
int relay[] = {A0, A1, A2};
int eve;

void setup() {
  pinMode(trig[0],OUTPUT);
  pinMode(echo[0],INPUT);
  pinMode(relay[0],OUTPUT);
 
  pinMode(trig[1],OUTPUT);
  pinMode(echo[1],INPUT);
  pinMode(relay[1],OUTPUT);
 
  pinMode(trig[2],OUTPUT);
  pinMode(echo[2],INPUT);
  pinMode(relay[2],OUTPUT);
  pinMode(speaker, OUTPUT);
}

void loop() {
  delay(250);
  for(int i = 0 ; i < 3 ; i++)
  {
  digitalWrite(trig[i], HIGH);
  delayMicroseconds(5);
  digitalWrite(trig[i], LOW);

  ultrasoundValue[i] = pulseIn(echo[i],HIGH);
  showCM[i] = ultrasoundValue[i]*0.017;

    if(showCM[i] <= 200)
  {
    digitalWrite(relay[i],LOW);
    switch (i){
      case 0:
        tone(speaker, 349);        break;
      case 1:
        tone(speaker, 392);        break;        
      case 2:
        tone(speaker, 440);        break;        
    }
  }  

  else if(showCM[i] >200  )
  {
   digitalWrite(relay[i],HIGH);
   noTone(speaker);     // Stop sound...
  }  
    }

}
