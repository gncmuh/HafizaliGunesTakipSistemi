/* Herkese iyi çalışmalar 
 *  
*/

#include <Servo.h>
#include <Smoothed.h>

Smoothed <int> ldr_deger;
Servo servo;
const int pinler[] PROGMEM={A0,3};
struct sensor_deger{
  int ldr;
};
struct sensor_deger sens;
int aci=0;
int hafiza[181]={};
int sayac=0;bool aci_sayaci=false;
bool bayrak=false;
int buyuk,kucuk;
unsigned long zaman=0;int artirma,azaltma=0;
void setup() {
  Serial.begin(9600);
  ldr_deger.begin(SMOOTHED_AVERAGE,10);
  if(!Serial)
  {
    Serial.println(F("Seri haberlesme baslatilamadi."));
  }
  else
  {
    servo.attach(pinler[1]);servo.write(0);
    for(int i=0; i<2; i++)
      if(i==0) pinMode(pinler[i],INPUT);
      else pinMode(pinler[i],OUTPUT);
  
  }
}
void loop() {

  gunes_takip_panel();
  if(millis()-zaman>=35000)  // tarama zaman dilimi
  {
    zaman=millis();
    if(zaman>=35000) 
    {
      Serial.println("reset");
      gunes_tarama();
    }
    delay(1);
  }
  
  
}
void gunes_takip_panel() {

  if(!bool(0))
  {
    if(bayrak==false)
    {
      for(int i=0; i<=180; i++)
      {
        sens.ldr=ldr_deger_okuma();
        hafiza[i]=sens.ldr;
        if(aci_sayaci==false) servo.write(i);
        delay(150);
        if(i==180)
        {
          servo.detach();bayrak=!bayrak;aci_sayaci=!aci_sayaci;
        }
      }
    }
    if(bayrak==true)
    {
      servo.attach(pinler[1]);
      for(int x=0; x<=180; x++)
      {
        if(x==0)
        {
          kucuk=hafiza[x];
          buyuk=hafiza[x];
        }
        if(hafiza[x]>buyuk)
        {
          buyuk=hafiza[x];

        }
        if(hafiza[x]<kucuk)
        {
          kucuk=hafiza[x];
          aci=x;
        }
        delay(10);
      }
      sens.ldr=ldr_deger_okuma();
      Serial.println(aci);
      servo.write(aci);
      

    }
  }
}
int ldr_deger_okuma() {

    sens.ldr=analogRead(pinler[0]);
    ldr_deger.add(sens.ldr);
    int yeni_ldr=ldr_deger.get();
    return yeni_ldr;
}

void gunes_tarama() {
   bayrak=!bayrak;aci_sayaci=!aci_sayaci;
}
