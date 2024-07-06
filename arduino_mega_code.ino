#include <Servo.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 20, 4);
String readString;
int mrf = 3;
int mrb = 11;
int mlf = 12;
int mlb = 13;
int f1 = 23;
int f2 = 33;
int f3 = 31;
int f4 = 27;
int m1 = A8;
int m2 = A9;
int m4 = A10;
int m3 = A11;
int f1_s = 0;
int f2_s = 0;
int f3_s = 0;
int f4_s = 0;
int prev = 0;
int prev_2 = 0;
//int r1 = ;
//int r2 =;
int s = 50;
bool flag_test = false;
bool flag_4 = false;
bool flag_6 = false;
bool flag_2 = false;
bool flag_0 = false;
bool flag1 = false;
bool flag2 = false;
bool flag3 = false;
bool flag4 = false;
bool flag5 = false;
bool flag6 = false;
bool flag7 = false;
bool flag8 = false;
Servo myservo51;  // create servo object to control a servo
Servo myservo53;// create servo object to control a servo
Servo myservo49;  // create servo object to control a servo
Servo myservo47;  // create servo object to control a servo
Servo myservo45;  // create servo object to control a servo
Servo myservo43;  // create servo object to control a servo
Servo myservo41;  // create servo object to control a servo
Servo myservo39;
//void saker_r() {
//  digitalWrite(r1, LOW);
//  digitalWrite(r2, LOW);
//  }
//  void hil_r() {
//  digitalWrite(r1, HIGH);
//  digitalWrite(r2, HIGH);
//  }
void emergency_stop() {
  digitalWrite(mrf, LOW);
  digitalWrite(mrb, LOW);
  digitalWrite(mlf, LOW);
  digitalWrite(mlb, LOW);
  myservo53.detach();  // attaches the servo on pin 9 to the servo object
  myservo51.detach();  // attaches the servo on pin 9 to the servo object
  myservo49.detach();  // attaches the servo on pin 9 to the servo object
  myservo47.detach();  // attaches the servo on pin 9 to the servo object
  myservo45.detach();  // attaches the servo on pin 9 to the servo object
  myservo43.detach();  // attaches the servo on pin 9 to the servo object
  myservo41.detach();  // attaches the servo on pin 9 to the servo object
  myservo39.detach();   // attaches the servo on pin 9 to the servo object

}
void up_right(int vit) {
  analogWrite(mrf, vit + 50);
  analogWrite(mrb, 0);
  analogWrite(mlf, 0);
  analogWrite(mlb, vit - 50);
}
void up_left(int vit) {
  analogWrite(mrf, vit - 50);
  analogWrite(mrb, 0);
  analogWrite(mlf, 0);
  analogWrite(mlb, vit + 50);
}

void back_right(int vit) {
  analogWrite(mrf, 0);
  analogWrite(mrb, vit - 50);
  analogWrite(mlf, vit + 50);
  analogWrite(mlb, 0);
}
void back_left(int vit) {
  analogWrite(mrf, 0);
  analogWrite(mrb, vit + 50);
  analogWrite(mlf, vit - 50);
  analogWrite(mlb, 0);
}
void down_1() {
  f2_s = digitalRead(f2);
  if (f2_s == 0) {
    f2_s = digitalRead(f2);
    digitalWrite(m1, HIGH);
    digitalWrite(m2, LOW);

  }
  else {
    f2_s = digitalRead(f2);
    digitalWrite(m1, LOW);
    digitalWrite(m2, LOW);
  }

}
void up_1() {
  f1_s = digitalRead(f1);
  if (f1_s == 0) {
    f1_s = digitalRead(f1);
    digitalWrite(m1, LOW);
    digitalWrite(m2, HIGH);

  } else {
    f1_s = digitalRead(f1);
    digitalWrite(m1, LOW);
    digitalWrite(m2, LOW);

  }

}
void down_2() {

  f4_s = digitalRead(f4);
  if (f4_s == 1) {
    f4_s = digitalRead(f4);
    digitalWrite(m3, LOW);
    digitalWrite(m4, HIGH);

  }
  else {
    f4_s = digitalRead(f4);
    digitalWrite(m3, LOW);
    digitalWrite(m4, LOW);

  }


}
void up_2() {
  f3_s = digitalRead(f3);
  if (f3_s == 1) {
    f3_s = digitalRead(f3);
    digitalWrite(m3, HIGH);
    digitalWrite(m4, LOW);

  }
  else {
    f3_s = digitalRead(f3);
    digitalWrite(m3, LOW);
    digitalWrite(m4, LOW);

  }
}
void hell_nos() {
  myservo47.write(15);
  myservo43.write(142);

}
void saker_nos() {
  myservo47.write(37);
  myservo43.write(122);

}
void open_ps() {
  myservo41.write(55);
  myservo39.write(45);

}
void close_ps() {
  myservo41.write(100);
  myservo39.write(0);

}
void hell_system2() {
  myservo49.write(180);

}
void saker_system2() {
  myservo49.write(70);

}
void saker_kabechalouta() {
  myservo53.write(43);
  myservo51.write(97);

}
void hell_kabechalouta() {
  myservo53.write(150);
  myservo51.write(0);

}
void Stop() {
  digitalWrite(mrf, 0);
  digitalWrite(mrb, 0);
  digitalWrite(mlf, 0);
  digitalWrite(mlb, 0);
}
void backward() {
  digitalWrite(mrf, HIGH);
  digitalWrite(mrb, 0);
  digitalWrite(mlf, HIGH);
  digitalWrite(mlb, 0);
}
void forward() {
  digitalWrite(mrf, 0);
  digitalWrite(mrb, HIGH);
  digitalWrite(mlf, 0);
  digitalWrite(mlb, HIGH);
}
void left() {
  digitalWrite(mrf, 0);
  digitalWrite(mrb, HIGH);
  digitalWrite(mlf, HIGH);
  digitalWrite(mlb, 0);
}
void right() {
  digitalWrite(mrf, HIGH);
  digitalWrite(mrb, 0);
  digitalWrite(mlf, 0);
  digitalWrite(mlb, HIGH);
}
void setup() {
  // put your setup code here, to run once:
  Serial1.begin(9600);
  Serial.begin(9600);
  Serial1.setTimeout(10);
  hell_nos();
  pinMode(mrf, OUTPUT);
  pinMode(mrb, OUTPUT);
  pinMode(mlf, OUTPUT);
  pinMode(mlb, OUTPUT);
  pinMode(m1, OUTPUT);
  pinMode(m2, OUTPUT);
  pinMode(m3, OUTPUT);
  pinMode(m3, OUTPUT);
  pinMode(f1, INPUT_PULLUP);
  pinMode(f2, INPUT_PULLUP);
  pinMode(f3, INPUT_PULLUP);
  pinMode(f4, INPUT_PULLUP);
  myservo53.attach(53);  // attaches the servo on pin 9 to the servo object
  myservo51.attach(51);  // attaches the servo on pin 9 to the servo object
  myservo49.attach(49);  // attaches the servo on pin 9 to the servo object
  myservo47.attach(47);  // attaches the servo on pin 9 to the servo object
  myservo45.attach(45);  // attaches the servo on pin 9 to the servo object
  myservo43.attach(43);  // attaches the servo on pin 9 to the servo object
  myservo41.attach(41);  // attaches the servo on pin 9 to the servo object
  myservo39.attach(39);   // attaches the servo on pin 9 to the servo object
  lcd.init();                      // initialize the lcd
  lcd.init();
  // Print a message to the LCD.
  lcd.backlight();
  lcd.setCursor(15, 3);
}
void loop() {
  if (Serial1.available() > 0) {
    String str = Serial1.readString();
    str.trim();
    //Serial.println(str);
    long int value = (str.toInt());
    //int x = value / 100000;
    //int y = (value % 100000) / 100;
    int butoons = value % 10;
    int new_butt = (value % 100) / 10;



    switch (butoons ) {
      case 1: if (1  == prev) {} else {
          flag1 = !flag1;
          if (flag1) {
            close_ps();
          } else {
            open_ps();
          }
        }
        break;
      case 2: if (2  == prev) {} else {
          flag2 = !flag2;
          if (flag2) {
            saker_kabechalouta();
          } else {
            hell_kabechalouta();
          }
        }
        break;
      case 3: if (3  == prev) {} else {
          flag3 = !flag3;
          if (flag3) {
            hell_nos();
          } else {
            saker_nos();
          }
        }
        break;
      case 4: if (4  == prev) {} else {
          flag4 = !flag4;
          if (flag4) {
            hell_system2();
          } else {
            saker_system2();
          }
        }
        break;
      case 5: if (5  == prev) {} else {
          flag5 = !flag5;

        }
        break;
      case 6: if (6  == prev) {} else {
          flag6 = !flag6;

        }
        break;
      case 7: if (7  == prev) {} else {
          flag7 = !flag7;
        }
        break;
        //case 8:   close_ps(); break;
        //case 9:               break;
    }
    Serial.println(butoons);

    if (flag5) {
      up_1();
    } else {
      down_1();
    }
    if (flag6) {
      up_2();
    } else {
      down_2();
    }
    if (flag7 == false) {
      Serial.print(new_butt);
      if (new_butt == 1 || new_butt == 3 || new_butt == 5 || new_butt == 7 ) {

        flag_test = true;
      }
      if (new_butt == 8) {
        flag_test = false;
      }
      if (flag_test ==  true) {
        new_butt = 8;
      }
      switch (new_butt) {

        case 0: forward(); break;
        case 2: right(); break;
        case 4: backward(); break;
        case 6: left(); break;
        case 8: Stop(); break;

        default: break;
      }
      Serial.println(" ");
    } else {
      switch (new_butt) {
        case 4: if (prev_2 != 4) {
            flag_4 = flag_4;
            if (flag_4 == flag_0) {
              Serial.print("nakes 10");
              lcd.clear(); s = s - 10; delay(150); lcd.setCursor(10, 2);  lcd.print(s);
            }
          }
          break;
        case 0: if (prev_2 != 0) {
            flag_0 = flag_0;
            if (flag_0 == flag_0) {
              Serial.print("zid 10");

              lcd.clear(); s = s + 10; delay(150); lcd.setCursor(10, 2);  lcd.print(s);
            }
          }
          break;

        case 2: if (prev_2 != 2) {
            flag_2 = flag_2;
            if (flag_2 == flag_2) {
              Serial.print("zid 1");

              lcd.clear(); s = s + 1; delay(150); lcd.setCursor(10, 2);  lcd.print(s);
            }
          }
          break;
        case 6: if (prev_2 != 6) {
            flag_6 = flag_6;
            if (flag_6 == flag_6) {
              Serial.print("nakes 1");

              lcd.clear(); s = s - 1; delay(150); lcd.setCursor(10, 2);  lcd.print(s);
            }
          }
          break;
      }
    }

    prev_2 = new_butt;
    prev = butoons;

  }
}
