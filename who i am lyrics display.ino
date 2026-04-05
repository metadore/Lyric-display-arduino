#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

unsigned long startTime;
unsigned long colorTimer = 0;

// 🌈 RGB pins
int rPin = 6;
int gPin = 9;
int bPin = 3;

// 📟 Smart LCD (no flicker)
void show(String l1, String l2) {
  static String p1 = "", p2 = "";

  if (l1 != p1 || l2 != p2) {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(l1);
    lcd.setCursor(0,1);
    lcd.print(l2);
    p1 = l1;
    p2 = l2;
  }
}

// 🌈 Set Color
void setColor(int r, int g, int b) {
  analogWrite(rPin, r);
  analogWrite(gPin, g);
  analogWrite(bPin, b);
}

// 💡 Beat-like color change (no delay)
void autoColor() {
  if (millis() - colorTimer > 200) {
    colorTimer = millis();
    setColor(random(50,255), random(0,150), random(50,255));
  }
}

void setup() {
  lcd.init();
  lcd.backlight();

  pinMode(rPin, OUTPUT);
  pinMode(gPin, OUTPUT);
  pinMode(bPin, OUTPUT);

  startTime = millis();
}

void loop() {
  unsigned long t = millis() - startTime;

  // 🌈 keep RGB dynamic
  autoColor();

  // 🎤 FAST LYRICS

  if (t < 3000) {
    show("Dont say this", "dont say that");
  }
  else if (t < 6000) {
    show("Im not playing", "by the rules");
  }
  else if (t < 9000) {
    show("If made by you", "I wont break");
  }
  else if (t < 12000) {
    show("Just like that", "I make mistakes");
  }
  else if (t < 15000) {
    show("Till Im wrong", "in right ways");
  }
  else if (t < 18000) {
    show("Save all your", "tears");
  }
  else if (t < 21000) {
    show("Dont waste them", "on me");
  }
  else if (t < 24000) {
    show("Im not like", "them");
  }
  else if (t < 27000) {
    show("This is the way", "that I am");
  }
  else if (t < 30000) {
    show("Head in clouds", "");
  }
  else if (t < 33000) {
    show("Dont fit in", "the crowd");
  }
  else if (t < 36000) {
    show("This is who", "I am");
  }
  else if (t < 39000) {
    show("Who I am", "");
  }
  else if (t < 42000) {
    show("If only I was", "wide awake");
  }
  else if (t < 45000) {
    show("More than I", "can take");
  }
  else if (t < 48000) {
    show("Dive into blue", "Im with you");
  }
  else {
    show("", "");
    setColor(0,0,0);
  }
}
