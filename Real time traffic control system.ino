//0,1,2,3 : Wider roads
//4,5 : Narrow Roads
//LED's
//1,2,3 side c wider
//4,5,6 side d narrow
//7,8,9 side a wider
//10,11,12 side b narrow
int i,a,b,c,d;
int A[6]={0,0,0,0,0,0};
int D[4]={0,0,0,0};
int Pin[6]={A0,A1,A2,A3,A4,A5};

void delay1()
{
    Serial.println("Side a gooo");
    Serial.println(D[0]);
    digitalWrite(3,HIGH);
    digitalWrite(4,HIGH);
    digitalWrite(7,HIGH);
    digitalWrite(10,HIGH);
    delay(D[0]);
    digitalWrite(3,LOW);
    digitalWrite(4,LOW);
    digitalWrite(7,LOW);
    digitalWrite(10,LOW);
}

void delay2()
{
    Serial.println("Side b gooo");
    Serial.println(D[1]);
    digitalWrite(9,HIGH);
    digitalWrite(1,HIGH);
    digitalWrite(4,HIGH);
    digitalWrite(10,HIGH);
    delay(D[1]);
    digitalWrite(9,LOW);
    digitalWrite(1,LOW);
    digitalWrite(4,LOW);
    digitalWrite(10,LOW);
}

void delay3()
{
    Serial.println("Side c gooo");
    Serial.println(D[2]);
    digitalWrite(12,HIGH);
    digitalWrite(1,HIGH);
    digitalWrite(4,HIGH);
    digitalWrite(7,HIGH);
    delay(D[2]);
    digitalWrite(12,LOW);
    digitalWrite(1,LOW);
    digitalWrite(4,LOW);
    digitalWrite(7,LOW);
}

void delay4()
{
    Serial.println("Side d gooo");
    Serial.println(D[3]);
    digitalWrite(6,HIGH);
    digitalWrite(1,HIGH);
    digitalWrite(7,HIGH);
    digitalWrite(10,HIGH);
    delay(D[3]);
    digitalWrite(6,LOW);
    digitalWrite(1,LOW);
    digitalWrite(7,LOW);
    digitalWrite(10,LOW);
}


void calc_para()
{
  a=0;
  b=0;
  c=0;
  d=0;
  if(A[0]==0)
  a+=1;
  if(A[1]==0)
  a+=1;
  if(A[2]==0)
  b+=1;
  if(A[3]==0)
  b+=1;
  if(A[4]==0)
  c+=1;
  if(A[5]==0)
  d+=1;
  delays(a,b,c,d);
}

void delays(int a,int b,int c,int d)
{
  D[0]=a*5000;
  D[1]=b*5000;
  D[2]=c*5000;
  D[3]=d*5000;
}

void setup() 
{
  Serial.begin(9600); 
  for(i=0;i<6;i++)
  {
   pinMode(Pin[0], INPUT);
  }
  for(i=1;i<13;i++)
  {
   pinMode(i, OUTPUT);
  }
}

void loop() 
{
  for(i=0;i<6;i++)
  {
    A[i]=digitalRead(Pin[i]);
  }
  
  calc_para();
  delay1();
  
  calc_para();
  delay2();
  
  calc_para();
  delay3();
  
  calc_para();
  delay4();
}
