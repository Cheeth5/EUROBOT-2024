float Max1 = -1;
float Min1 = 1024;
int cp1 = A0;
int x1;
float line1;
int val1;
///////
float Max2 = -1;
float Min2 = 1024;
int cp2 = A1;
int x2;
float line2;
int val2;
///////
float Max3 = -1;
float Min3 = 1024;
int cp3 = A2;
int x3;
float line3;
int val3;
/////
int val;
/////
int mRF = 9;
int mRB = 10;
int mLF = 6;
int mLB = 5;
////
int pin2=2 ;
long duration;




void stopp() {
  analogWrite(mRF, 0);
  analogWrite(mRB, 0);
  analogWrite(mLF, 0);
  analogWrite(mLB, 0);
}
void right() {
  analogWrite(mRF, 0);
  analogWrite(mRB, 250);
  analogWrite(mLF, 180);
  analogWrite(mLB, 0);
}
void left() {
  analogWrite(mRF, 250);
  analogWrite(mRB, 0);
  analogWrite(mLF, 0);
  analogWrite(mLB, 165);
}
void forward(vit1,vit2) {
  analogWrite(mRF, vit1);
  analogWrite(mRB, 0);
  analogWrite(mLF, vit2);
  analogWrite(mLB, 0);
}
void backward() {
  analogWrite(mRF, 0);
  analogWrite(mRB, 250);
  analogWrite(mLF, 0);
  analogWrite(mLB, 150);
}
void a() {
  forward();
  for (int i = 0 ; i < 1000; i++) {
    x1 = analogRead(cp1);
    x2 = analogRead(cp2);
    x3 = analogRead(cp3);
    if (x1 > Max1)  Max1 = x1;
    if (x1 < Min1)  Min1 = x1;
    ////////
    if (x2 > Max2)  Max2 = x2;
    if (x2 < Min2)  Min2 = x2;
    ////////
    if (x3 > Max3)  Max3 = x3;
    if (x3 < Min3)  Min3 = x3;
  }
  backward();
  for (int i = 0 ; i < 1000; i++) {
    x1 = analogRead(cp1);
    x2 = analogRead(cp2);
    x3 = analogRead(cp3);
    if (x1 > Max1)  Max1 = x1;
    if (x1 < Min1)  Min1 = x1;
    ////////
    if (x2 > Max2)  Max2 = x2;
    if (x2 < Min2)  Min2 = x2;
    ////////
    if (x3 > Max3)  Max3 = x3;
    if (x3 < Min3)  Min3 = x3;
  }
  stopp();
  line1 = (Max1 + Min1) / 2 ;
  line2 = (Max2 + Min2) / 2 ;
  line3 = (Max3 + Min3) / 2 ;

}
int Read(){
  if (analogRead(cp1) > line1) val1 = 1;
  else val1 = 0;
  if (analogRead(cp2) > line2) val2 = 1;
  else val2 = 0;
  if (analogRead(cp3) > line3) val3 = 1;
  else val3 = 0;
  int val=val1*100+val2*10+val3;
  return val;
}
void setup() {
  // put your setup code here, to run once:
  pinMode(cp1, INPUT);
  pinMode(cp2, INPUT);
  pinMode(cp3, INPUT);
  pinMode(mRF, OUTPUT);
  pinMode(mRB, OUTPUT);
  pinMode(mLF, OUTPUT);
  pinMode(mLB, OUTPUT);
  a();
  Serial.begin(9600);
}
void loop() {
val= Read();
  Serial.println(val);
  Serial.println();
  delay (500);
/////
 pinMode(pin2, INPUT_PULLUP);
//team blue 
 while(digitalRead(pin2)==1){

if (val==000){
  stopp();
}
if (val==010){
  forward();
}
if (val==100){
  left();
}
if (val==110){
  left();
}
if (val==101){
  left();
}
if (val==000){
  stopp();
}
///////////////////////////////////////////////////////////////////////
//team yellow 
//while(digitalRead(pin2)==1){
//if (val==000){
//  stopp();
//}
//if (val==010){
//  forward();
//}
//if (val==001){
//  right();
//}
//if (val==011){
//  right();
//}
//if (val==101){
//  right();
//}
//if (val==000){
//  stopp();
//}
 }


}
