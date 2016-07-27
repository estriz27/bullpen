#include "view.hpp"

View::View(const int port):server(port){
  lcd.begin(16,2);
  server.begin();
  lcd.setRGB(0,0,255);
  lcd.setCursor(0,1);
  lcd.print("Employee Log");
  }

void View::update(String name, bool isIn,std::vector<Person> inList, std::vector<Person> outList){
  updateLCD(name, isIn);
  updateHTML(inList, outList);
}
void View::updateLCD(String name, bool isIn){
  lcd.clear();
  lcd.print(name);
  if(isIn){
    lcd.setRGB(BLColorG[0],BLColorG[1],BLColorG[2]);
  }
  else{
    lcd.setRGB(BLColorR[0],BLColorR[1],BLColorR[2]);
  }
}
void View::updateHTML(std::vector<Person> inList, std::vector<Person> outList){
    // listen for incoming clients
  WiFiClient client = server.available();
  if (client) {
    Serial.println("new client");
    // an http request ends with a blank line
    boolean currentLineIsBlank = true;
    while (client.connected()) {
      if (client.available()) {
        char c = client.read();
        // if you've gotten to the end of the line (received a newline
        // character) and the line is blank, the http request has ended,
        // so you can send a reply
        if (c == '\n' && currentLineIsBlank) {
          // send a standard http response header
          client.println("HTTP/1.1 200 OK");
          client.println("Content-Type: text/html");
          client.println("Connection: close");  // the connection will be closed after completion of the response
          client.println("Refresh: 2");         // refresh the page automatically every 2 sec
          client.println();
          client.println("<!DOCTYPE HTML>");
          client.println("<html>");
          client.println("<title>Employee Log using Grove Indoor Environment Kit using Intel Edison</title>"); 
          client.println("<font face=\"Arial\" color=\"#0071c5\"/>");
          client.println("<style>");  
          client.println("table, th, td{");
          client.println("border: 1px solid #333;");
          client.println("}");
          client.println("</style>");
          client.println("<h1 align=\"center\">Employee Log</h1>");
          client.print("<br />");
          client.println("<div class = \"container\">");
          client.println("<table align= \"center\">");
          client.println("<tr>");
          client.println("<th>IN</th>");
          client.println("<th>OUT</th>");
          client.println("<tr>");
          int larger = outList.size();
          if (inList.size()>outList.size()){
            larger = inList.size();
          }
          for(int i=0; i < larger; i++){
            client.println("<tr>");
            client.print("<td>");
            if(i<inList.size()){
              client.print(inList[i].getName());
            }
            client.println("</td>");
            client.print("<td>");
            if(i<outList.size()){
              client.print(outList[i].getName());
            }
            client.println("<td>");
            client.println("</tr>");
          }
          client.println("</table>");
          client.println("</div>");     
          client.println("</html>");
           break;
        }
        if (c == '\n') {
          // you're starting a new line
          currentLineIsBlank = true;
        } else if (c != '\r') {
          // you've gotten a character on the current line
          currentLineIsBlank = false;
        }
      }
    }
    // give the web browser time to receive the data
    delay(1);
    
    // close the connection:
    client.stop();
    Serial.println("client disonnected");
  } 
}

