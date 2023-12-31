#include "web_page.h"

String web_page()
{
    String page = "<!DOCTYPE html>\n";
    page += "<html lang=\"en\">\n";
    page += "<head>\n";
    page += "  <meta charset=\"UTF-8\">\n";
    page += "  <meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">\n";
    page += "  <title>Kettle Control</title>\n";
    page += "  <style>\n";
    page += "    body {\n";
    page += "      font-family: Arial, sans-serif;\n";
    page += "      text-align: center;\n";
    page += "      background-color: #f4f4f4;\n";
    page += "      margin: 0;\n";
    page += "      padding: 0;\n";
    page += "    }\n";
    page += "    h1 {\n";
    page += "      color: #333;\n";
    page += "    }\n";
    page += "    #temperatureDisplay {\n";
    page += "      font-size: 20px;\n";
    page += "      margin-bottom: 20px;\n";
    page += "      display: block;\n";
    page += "    }\n";
    page += "    #temperatureSlider {\n";
    page += "      width: 80%;\n";
    page += "      margin: 0 auto;\n";
    page += "    }\n";
    page += "    #buttonsContainer {\n";
    page += "      display: flex;\n";
    page += "      justify-content: space-around;\n";
    page += "      margin-top: 20px;\n";
    page += "    }\n";
    page += "    .button {\n";
    page += "      padding: 10px 20px;\n";
    page += "      font-size: 16px;\n";
    page += "      cursor: pointer;\n";
    page += "    }\n";
    page += "    #kettleButton {\n";
    page += "      background-color: #4CAF50;\n";
    page += "      color: white;\n";
    page += "      border: none;\n";
    page += "    }\n";
    page += "    #kettleButton:hover {\n";
    page += "      background-color: #45a049;\n";
    page += "    }\n";
    page += "    #kettleButton:active {\n";
    page += "      background-color: #3e8e41;\n";
    page += "    }\n";
    page += "    #temperatureAlert {\n";
    page += "      color: red;\n";
    page += "    }\n";
    page += "  </style>\n";
    page += "</head>\n";
    page += "<body>\n";
    page += "  <h1>Kettle Control</h1>\n";
    page += "  <label for=\"temperature\">Select Temperature:</label>\n";
    page += "  <input type=\"range\" id=\"temperatureSlider\" name=\"temperature\" min=\"20\" max=\"100\" value=\"20\" oninput=\"updateTemperatureDisplay()\">\n";
    page += "  <span id=\"temperatureDisplay\"></span>\n";
    page += "  <div id=\"buttonsContainer\">\n";
    page += "    <button class=\"button\" onclick=\"sendTemperature()\">Set Temperature</button>\n";
    page += "    <button id=\"kettleButton\" class=\"button\" onclick=\"toggleKettle()\">Turn the kettle on</button>\n";
    page += "  </div>\n";
    page += "  <div id=\"temperatureAlert\"></div>\n";
    page += "  <div id=\"currentTemperature\"></div>\n";
    page += "  <script>\n";
    page += "    function updateTemperatureDisplay() {\n";
    page += "      var selectedTemperature = document.getElementById('temperatureSlider').value;\n";
    page += "      document.getElementById('temperatureDisplay').innerHTML = selectedTemperature + '°C';\n";
    page += "    }\n";
    page += "    function sendTemperature() {\n";
    page += "      var selectedTemperature = document.getElementById('temperatureSlider').value;\n";
    page += "      if (selectedTemperature <= 20) {\n";
    page += "        document.getElementById('temperatureAlert').innerHTML = 'Temperature must be more than 20 degrees.';\n";
    page += "        return;\n";
    page += "      }\n";
    page += "      document.getElementById('temperatureAlert').innerHTML = '';\n";
    page += "      var xhr = new XMLHttpRequest();\n";
    page += "      xhr.open('POST', '/set_temperature?temp=' + selectedTemperature, true);\n";
    page += "      xhr.send();\n";
    page += "    }\n";
    page += "    function toggleKettle() {\n";
    page += "      var selectedTemperature = document.getElementById('temperatureSlider').value;\n";
    page += "      if (selectedTemperature <= 20) {\n";
    page += "        document.getElementById('temperatureAlert').innerHTML = 'Temperature must be more than 20 degrees.';\n";
    page += "        return;\n";
    page += "      }\n";
    page += "      var xhr = new XMLHttpRequest();\n";
    page += "      xhr.open('POST', '/toggle_kettle', true);\n";
    page += "      xhr.send();\n";
    page += "      var button = document.getElementById('kettleButton');\n";
    page += "      if (button.innerHTML === 'Turn the kettle on') {\n";
    page += "        button.innerHTML = 'Turn the kettle off';\n";
    page += "      } else {\n";
    page += "        button.innerHTML = 'Turn the kettle on';\n";
    page += "      }\n";
    page += "    }\n";
    page += "    function fetchCurrentTemperature() {\n";
    page += "      var xhr = new XMLHttpRequest();\n";
    page += "      xhr.onreadystatechange = function() {\n";
    page += "        if (xhr.readyState === XMLHttpRequest.DONE) {\n";
    page += "          if (xhr.status === 200) {\n";
    page += "            var response = JSON.parse(xhr.responseText);\n";
    page += "            document.getElementById('currentTemperature').innerHTML = 'Current Temperature: ' + response.temperature + '°C';\n";
    page += "          }\n";
    page += "        }\n";
    page += "      };\n";
    page += "      xhr.open('GET', '/get_temperature', true);\n";
    page += "      xhr.send();\n";
    page += "    }\n";
    page += "    // Fetch current temperature every 5 seconds\n";
    page += "    setInterval(fetchCurrentTemperature, 5000);\n";
    page += "  </script>\n";
    page += "</body>\n";
    page += "</html>\n";

    return page;
}
