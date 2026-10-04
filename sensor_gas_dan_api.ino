#include "CTBot.h"
CTBot myBot;

String ssid = "aziz_5G";     // Sesuikan dengan nama wifi anda
String pass = "aziz4212"; // sesuaikan password wifi
String token = "7175851413:AAGminELIq42Sya8HX-P-BnUx02EM2JH9Kk"; // token bot telegram yang telah dibuat

#define Api 12 //GPIO12 (D6)
#define Gas 14 //GPIO14 (D5)

void setup() {
  pinMode(Api, INPUT);
  pinMode(Gas, INPUT);
  Serial.begin(115200);
  myBot.wifiConnect(ssid, pass);

  myBot.setTelegramToken(token);

  // check if all things are ok
  if (myBot.testConnection())
    Serial.println("\n Terhubung");
  else
    Serial.println("\n Tidak Terhubung");
}
  
void loop() {
  int bacasensorapi = digitalRead(Api);
  int bacasensorgas = digitalRead(Gas);
  Serial.print("Api : ");
  Serial.print(bacasensorapi);
  Serial.print("   Gas : ");
  Serial.println(bacasensorgas);
  if(bacasensorgas==0) //terdeteksi gas
  {
    String kirim;
    kirim ="Lapor Bos.! Ada Kebocoran Gas";
    myBot.sendMessage(1118144326, kirim); 
    delay(500); 
  }
  if(bacasensorapi==0) //terdeteksi api
  {
    String kirim;
    kirim ="Lapor bos.! Ada Kebakaran";
    myBot.sendMessage(1118144326, kirim); 
    delay(500); 
  }
  delay(500);
}

