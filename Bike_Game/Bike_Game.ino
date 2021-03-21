float revolutions=0;
int rpm=0; 
long  startTime=0;
long  elapsedTime;
 
void setup() 
{   
    Serial.begin(9600); 
    pinMode(2, INPUT_PULLUP);
    pinMode(4, OUTPUT);        
    Serial.print("RPM :"); 
}
 
void loop() {
revolutions=0; rpm=0;
startTime=millis();         
attachInterrupt(digitalPinToInterrupt(2),interruptFunction,RISING);
delay(1000);
detachInterrupt(2);                

elapsedTime=millis()-startTime;    

if(revolutions>0)
{
  rpm=(max(1, revolutions) * 60000) / elapsedTime;        //calculates rpm
}

String outMsg = String("RPM :") + rpm;
Serial.println(outMsg);

if(rpm > 120)
digitalWrite(4, HIGH);
}

void interruptFunction() //interrupt service routine
{  
  revolutions++;
}
