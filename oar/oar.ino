#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);

int vin = A0;
int pulldown = A1;

int t=2;
int u=6;
int v=7;
int w=8;
int x=9;
int y=10;
int z=13;

int at;
int au;
int av;
int aw;
int ax;
int ay;
int az;
int a;
float vx;
float rx = 0;
float i;

void setup()
{
    pinMode(vin,INPUT);

    lcd.init();
    lcd.backlight();

    Serial.begin(9600);

    pinMode(t,OUTPUT);
    pinMode(u,OUTPUT);
    pinMode(v,OUTPUT);
    pinMode(w,OUTPUT);
    pinMode(x,OUTPUT);
    pinMode(y,OUTPUT);
    pinMode(z,OUTPUT);

    digitalWrite(t,LOW);
    digitalWrite(u,LOW);
    digitalWrite(v,LOW);
    digitalWrite(w,LOW);
    digitalWrite(x,LOW);
    digitalWrite(y,LOW);
    digitalWrite(z,LOW);
}

void loop()
{


/*
    av=analogRead(pulldown);
    delay(50);
    av=analogRead(vin);
    */
    digitalWrite(t,HIGH);
    digitalWrite(u,LOW);
    digitalWrite(v,LOW);
    digitalWrite(w,LOW);
    digitalWrite(x,LOW);
    digitalWrite(y,LOW);
    digitalWrite(z,LOW);
    analogRead(pulldown);
    delay(100);
    at=analogRead(vin);


    digitalWrite(t,LOW);
    digitalWrite(u,HIGH);
    digitalWrite(v,LOW);
    digitalWrite(w,LOW);
    digitalWrite(x,LOW);
    digitalWrite(y,LOW);
    digitalWrite(z,LOW);
    analogRead(pulldown);
    delay(100);
    au=analogRead(vin);


    digitalWrite(t,LOW);
    digitalWrite(u,LOW);
    digitalWrite(v,HIGH);
    digitalWrite(w,LOW);
    digitalWrite(x,LOW);
    digitalWrite(y,LOW);
    digitalWrite(z,LOW);
    analogRead(pulldown);
    delay(100);
    av=analogRead(vin);


    digitalWrite(t,LOW);
    digitalWrite(u,LOW);
    digitalWrite(v,LOW);
    digitalWrite(w,HIGH);
    digitalWrite(x,LOW);
    digitalWrite(y,LOW);
    digitalWrite(z,LOW);
    analogRead(pulldown);
    delay(100);
    aw=analogRead(vin);


    digitalWrite(t,LOW);
    digitalWrite(u,LOW);
    digitalWrite(v,LOW);
    digitalWrite(w,LOW);
    digitalWrite(x,HIGH);
    digitalWrite(y,LOW);
    digitalWrite(z,LOW);
    analogRead(pulldown);
    delay(100);
    ax=analogRead(vin);


    digitalWrite(t,LOW);
    digitalWrite(u,LOW);
    digitalWrite(v,LOW);
    digitalWrite(w,LOW);
    digitalWrite(x,LOW);
    digitalWrite(y,HIGH);
    digitalWrite(z,LOW);
    analogRead(pulldown);
    delay(100);
    ay=analogRead(vin);



    digitalWrite(t,LOW);
    digitalWrite(u,LOW);
    digitalWrite(v,LOW);
    digitalWrite(w,LOW);
    digitalWrite(x,LOW);
    digitalWrite(y,LOW);
    digitalWrite(z,HIGH);
    analogRead(pulldown);
    delay(100);
    az=analogRead(vin);



    if(az>=450)
    {
    Serial.println("az>=450");
        vx=az*0.00489;
        i=(5-vx-0.55)/22000;
        rx=(vx/i);
    }
    if(ay>=450 && az<450)
    {
    Serial.println("ay>=450 && az<450");
        vx=ay*0.00489;
        i=(5-vx-0.55)/10000;
        rx=(vx/i);
    }
    if(ax>=448 && ay<448 && az<448)
    {
    Serial.println("ax>=448 && ay<448 && az<448");
        vx=ax*0.00489;
        i=(5-vx-0.55)/4700;
        rx=(vx/i);
    }

    if(aw>=439 && ax<439 && ay<439 && az<439)
    {
    Serial.println("aw>=439 && ax<439 && ay<439 && az<439");
        vx=aw*0.00489;
        i=(5-vx-0.55)/2200;
        rx=(vx/i);
    }

    if(av>=439 && aw<439 && ax<439 && ay<439 && az<439)
    {
    Serial.println("av>=439 && aw<439 && ax<439 && ay<439 && az<439");
        vx=av*0.00489;
        i=(4.8-vx-0.55)/1000;
        rx=(vx/i);
    }

    if(au>=430 && av<430 && aw<430 && ax<430 && ay<430 && az<430)
    {
    Serial.println("au>=430 && av<430 && aw<430 && ax<430 && ay<430 && az<430");
        vx=au*0.00489;
        i=(4.5-vx-0.55)/560;
        rx=(vx/i);
    }

    if(at>=430 && au<430 && av<430 && aw<430 && ax<430 && ay<430 && az<430 )
    {
    Serial.println("at>=430 && au<430 && av<430 && aw<430 && ax<430 && ay<430 && az<430 ");
        vx=at*0.00489;
        i=(4.5-vx-0.55)/220;
        rx=(vx/i);
    }

    if(at<430 && au<430 && av<430 && aw<430 && ax<430 && ay<430 && az<430 )
    {
    Serial.println("at<430 && au<430 && av<430 && aw<430 && ax<430 && ay<430 && az<430 ");
        vx=at*0.00489;
        i=(4.5-vx-0.55)/220;
        rx=(vx/i);
    }
    lcd.setCursor(0,0);

    Serial.println("at  au  av  aw  ax  ay  az ");
    Serial.print(at);
    Serial.print(" ");
    Serial.print(au);
    Serial.print(" ");
    Serial.print(av);
    Serial.print(" ");
    Serial.print(aw);
    Serial.print(" ");
    Serial.print(ax);
    Serial.print(" ");
    Serial.print(ay);
    Serial.print(" ");
    Serial.print(az);
    Serial.print(" ");
    Serial.print(" vx ");
    Serial.print(vx);
    Serial.print(" i ");
    Serial.print(i);
    Serial.print(" rx ");
    Serial.print(rx);

    Serial.println(" ");


    if(vx>4.8)
    {
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("----INFINITY----");
    }
    else
    {
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print(i * 1000);
        lcd.setCursor(5,0);

        if(rx<1000)
        {
            lcd.print(rx);
            lcd.setCursor(15,0);
            lcd.print((char)244);
        }
        else
        {
            lcd.print(rx/1000,3);
            lcd.setCursor(14,0);
            lcd.print("k");
        }
        lcd.print((char)244);
    }
    lcd.setCursor(0,1);
    lcd.print("Arduino Ohmmeter");

}
