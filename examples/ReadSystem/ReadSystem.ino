#include <Wire.h>
#include "24s02ya__M24SR02.h"

nfcGadget nfc;

void setup() {
  Wire.begin();  //required for device check
  Serial.begin(9600);
  while (!Serial)
    ;  // Wait for Serial Monitor to open
  Serial.println("");
  Serial.println("interfata NFC");


  nfc._verbose = false; //enable to see various outputs
  nfc._cmds = false; //enable to see various inputs
  nfc._sendGetI2cSession = true;
  Serial.println("Open ");
  nfc.selectNFCapp(); //not mandatory

  Serial.println("Systemfile");
  nfc.selectFile(Systemfile);
  int j=nfc.readFileLength(); //size of payload, it must be called !!!
  char *c=nfc.readFile(); //read data
  nfc.explainFile();
  Serial.println("");
}


void loop() {
}
