int ups=2;
int dws=3;
char oldv;
char newv;
void setup() {
  // put your setup code here, to run once:
pinMode(ups,INPUT);
pinMode(dws,INPUT);
Serial.begin(9600);

  if (digitalRead(ups)==1 && digitalRead(dws)==1)
  {
    oldv='c';
  }
    if ((digitalRead(ups)==1 && digitalRead(dws)==0) || (digitalRead(ups)==0 && digitalRead(dws)==1))
  {
    oldv='i';
  }
    if (digitalRead(ups)==0 && digitalRead(dws)==0)
  {
    oldv='u';
  }

}

void loop() {
  // put your main code here, to run repeatedly:
while (1)
{
  if (digitalRead(ups)==1 && digitalRead(dws)==1 && oldv!='c')
  {
    oldv='c';
    Serial.print("c");
  }
  else if (digitalRead(ups)==1 && digitalRead(dws)==0 && oldv!='i')
  {
    oldv='i';
    Serial.print("i");
  }
  else if (digitalRead(ups)==0 && digitalRead(dws)==1 && oldv!='i')
  {
    oldv='i';
    Serial.print("i");
  }
  else if (digitalRead(ups)==0 && digitalRead(dws)==0 && oldv!='u')
  {
    oldv='u';
    Serial.print("u");
  }
}
}
