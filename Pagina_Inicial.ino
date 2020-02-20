
void Pagina_Inicial() {

  EthernetClient client = server.available(); //CRIA UMA CONEXÃO COM O CLIENTE
  StaticJsonDocument<256> doc;

  doc["sensor"] = "gps";
  doc["time"] = 1351824120;
  JsonArray data = doc.createNestedArray("data");
  data.add(48.756080);
  data.add(2.302038);


  if (client) { // SE EXISTE CLIENTE FAZ
    while (client.connected()) {//ENQUANTO EXISTIR CLIENTE CONECTADO, FAZ
      if (client.available()) { //SE O CLIENTE ESTÁ HABILITADO, FAZ

        client.println("HTTP/1.1 200 OK"); //ESCREVE PARA O CLIENTE A VERSÃO DO HTTP
        client.println("Content-Type: text/html"); //ESCREVE PARA O CLIENTE O TIPO DE CONTEÚDO(texto/html)
        client.println();
        //AS LINHAS ABAIXO CRIAM A PÁGINA HTML
        client.println("<body>"); //DEFINE A COR DE FUNDO DA PÁGINA
        client.println("<br>");
        //client.println("<br>");
        //serializeJson (doc, client);
        //client.println("<br>");
        //client.println("<br>");
        serializeJsonPretty(doc, client);
        client.println("<br>");
        client.println("</body></html>"); //FINALIZA A TAG "body" E "html"
        client.stop(); //FINALIZA A REQUISIÇÃO HTTP E DESCONECTA O CLIENTE
      }
    }
  }


}
