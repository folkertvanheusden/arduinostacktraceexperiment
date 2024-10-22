#include "gen.h"


void setup() {
  Serial.begin(115200);

  while(!Serial) {
  }

  if (CrashReport) {
    Serial.println(CrashReport);
    CrashReport.clear();
  }

  Serial.println(F("Go!"));
}

void loop() {
  Serial.println(micros());
}
