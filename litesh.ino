int inch = 0;
int cm = 0;
long totaldistance(int trigpin, int echopin)
{
  pinMode(trigpin, OUTPUT); 
  digitalWrite(trigpin, LOW);
  delay(1500);
  digitalWrite(trigpin, HIGH);
  delay(900);
  digitalWrite(trigpin, LOW);
  pinMode(echopin, INPUT);
  return pulseIn(echopin, HIGH);
}

void setup()
{

  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);

}
void loop()
{
  cm = 0.01723 * totaldistance(8, 8);
  inch = (cm / 2.54);
  if (cm>100)
  {
    digitalWrite(LED_BUILTIN,HIGH);
    delay(2500);
    digitalWrite(LED_BUILTIN,LOW);
    delay(100);
  }
  Serial.print(inch);
  Serial.print("in, ");
  Serial.print(cm);
  Serial.println("cm");
  delay(1000); 
}
