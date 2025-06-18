#include "Arduino.h"
#include "WiFi.h"
#include "Audio.h"
#include <time.h>

#define I2S_DOUT 25
#define I2S_BCLK 27
#define I2S_LRC 26

Audio audio;

String ssid = "IOT_COE LAB";
String password = "IOT@54321";


void setup() {
  WiFi.disconnect();
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid.c_str(), password.c_str());
  Serial.begin(115200);
  Serial1.begin(9600, SERIAL_8N1, 3, -1);
  Serial.println("UART receiver ready");

  while (WiFi.status() != WL_CONNECTED) {
    delay(1500);
  }

  if (WiFi.status() == WL_CONNECTED) {
    Serial.println("WiFi connected");
  }
  initTime();
  audio.setPinout(I2S_BCLK, I2S_LRC, I2S_DOUT);
  audio.setVolume(100);
  audio.connecttospeech("Hello, My name is Gyanendriya and I am a humanoid. Tell me how can i assist you", "en");
}

void loop() {
  audio.loop();

  // Check if data is available on Serial
  if (Serial1.available()) {
    String inputMessage = Serial1.readStringUntil('\n');  // Read input till newline
    // inputMessage.trim();                                 // Remove any leading/trailing spaces

    if (inputMessage == "stop") {
      // Stop radio streaming
      Serial.println("Stopping radio streaming...");
      audio.stopSong();

    } else if (inputMessage == "radio") {
      // Start radio streaming
      audio.stopSong();
      Serial.println("Starting radio streaming...");
      audio.connecttohost("https://stream-171.zeno.fm/aurb3mmagphvv?zt=eyJhbGciOiJIUzI1NiJ9.eyJzdHJlYW0iOiJhdXJiM21tYWdwaHZ2IiwiaG9zdCI6InN0cmVhbS0xNzEuemVuby5mbSIsInJ0dGwiOjUsImp0aSI6IkZKNkFKSC1GUTBxc3BNZncxX1BPc1EiLCJpYXQiOjE3NDczNzE1MTQsImV4cCI6MTc0NzM3MTU3NH0.yIrt3ce5Qx9_3mGdMQGTnsEye-d8fx1ZUPS6LXcQxp8");  // Replace with actual radio stream URL

    } else if (inputMessage == "news") {
      // Start radio streaming
      audio.stopSong();
      Serial.println("Starting news streaming...");
      audio.connecttohost("https://tunein.cdnstream1.com/4530_128_2.mp3?aw_0_1st.skey=1734371675&lat=38.8557&lon=-77.1486&aw_0_1st.abtest=&aw_0_1st.stationId=s327997&aw_0_1st.premium=false&source=TuneIn&aw_0_req.gdpr=true&aw_0_1st.platform=tunein&aw_0_1st.genre_id=g255&aw_0_1st.class=talk&aw_0_1st.ads_partner_alias=ce.Other&aw_0_azn.planguage=en&aw_0_1st.is_ondemand=false&aw_0_1st.topicId=na&aw_0_1st.programId=p3970575&aw_0_1st.affiliateIds=a131909&aw_0_1st.bandId=16?adtonosListenerId=01JS7BC308MV3BHHHNRESF0NV1&aw_0_req_lsid=96ec620d28a666d33de562fcc31b7bcd");  // Replace with actual radio stream URL
    }else if (inputMessage == "time") {
      String time = getCurrentTimeInWords();
      audio.connecttospeech(time.c_str(), "en");
    } else if (inputMessage.length() > 0) {
      // Speak out any other message
      audio.stopSong();
      Serial.print("Saying: ");
      Serial.println(inputMessage);
      audio.connecttospeech(inputMessage.c_str(), "en");
    }
  }
}