
#include <UIPEthernet.h>
#include <ArduinoJson.h>

EthernetServer server(80);


void Config_Inicial();
void Pagina_Inicial();


void setup() {
  Config_Inicial();

}


void loop() {
  Pagina_Inicial();

}
