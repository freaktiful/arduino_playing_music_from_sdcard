#include <sd_l0.h>
#include <sd_l1.h>
#include <sd_l2.h>
#include <SimpleSDAudio.h>
#include <SimpleSDAudioDefs.h>


void setup() {
  Serial.begin(9600);
  // Using F("...") to avoid wasting RAM
    Serial.print(F("\nInitializing SD card..."));

    // If your SD card CS-Pin is not at Pin 4, enable and adapt the following line:
    // SdPlay.setSDCSPin(10);

    if (!SdPlay.init(SSDA_MODE_FULLRATE | SSDA_MODE_MONO | SSDA_MODE_AUTOWORKER)) {
      Serial.println(F("initialization failed. Things to check:"));
      Serial.println(F("* is a card is inserted?"));
      Serial.println(F("* Is your wiring correct?"));
      Serial.println(F("* maybe you need to change the chipSelect pin to match your shield or module?"));
      Serial.print(F("Error code: "));
      Serial.println(SdPlay.getLastError());
      while(1);
    } else {
     Serial.println(F("Wiring is correct and a card is present."));
    }

    Serial.print(F("Looking for on.wav... "));
    if(!SdPlay.setFile("ALARMA.WAV")) {
      Serial.println(F(" not found on card! Error code: "));
      Serial.println(SdPlay.getLastError());
      while(1);
    } else {
     Serial.println(F("found."));
    }
}

void loop() {
  Serial.print(F("Playing... "));
  SdPlay.play();
  while(!SdPlay.isStopped()) {
    ;   // no worker needed anymore :-)
  }
  Serial.println(F("done."));
  delay(3000);
}
