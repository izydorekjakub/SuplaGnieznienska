test
#include <SPI.h>
#include <Ethernet.h>
#include <DHT.h>
#include <SuplaDevice.h>
#define NUM_OF(x) (sizeof(x)/sizeof(x[0]))

/*
 * SUPLA DEVICE - ARDUINO - ETHERNET SHIELD & DHT SENSOR
 * Author: Przemyslaw Zygmunt <przemek@supla.org>
 *
 * This example requires DHT sensor library installed. 
 * https://github.com/adafruit/DHT-sensor-library
 */

//#define DHTPIN 24
//#define DHTTYPE DHT22
 
// Setup a DHT instance
//DHT dht(DHTPIN, DHTTYPE);


// DS18B20 Sensor read implementation
//void get_temperature_and_humidity(int channelNumber, double *temp, double *humidity) {
//
//    *temp = dht.readTemperature();
//    *humidity = dht.readHumidity();
//
//    if ( isnan(*temp) || isnan(*humidity) ) {
//      *temp = -275;
//      *humidity = -1;
//    }
//
//}
int _relayInProgress = 0;

struct Button {
  int _port;
  int _relayPort;
  int _room;
 int _constTime;
 int _currentTime;
};

Button buttonsMARYSI[3] = {
  {20, 21, 1, 10000, 0},
  {22, 23, 1, 35000, 0},
  {24, 25, 1, 35000, 0}
};

Button buttonsSALONduza[3] = {
  {20, 21, 1, 10000, 0},
  {26, 27, 1, 35000, 0},
  {28, 29, 1, 35000, 0}
};

Button buttonsLewa[3] = {
  {20, 21, 1, 10000, 0},
  {30, 31, 1, 35000, 0},
  {32, 33, 1, 35000, 0}
};

Button buttonsPrawa[3] = {
  {20, 21, 1, 10000, 0},
  {34, 35, 1, 35000, 0},
  {36, 37, 1, 35000, 0}
};

Button buttonsEkran[3] = {
  {20, 21, 1, 10000, 0},
  {38, 39, 1, 35000, 0},
  {40, 41, 1, 35000, 0}
};

void realbuttonsMARYSI() {
  if(_relayInProgress != 1) {
    for (int i = 1; i < NUM_OF(buttonsMARYSI); i++) {
      if (digitalRead(buttonsMARYSI[i]._port) == HIGH) {
        //String send_topic = "smartflat/arduino/1/room/" + String(buttons[i]._room) + "/relay/" + String(i) + "/status";
        digitalWrite(buttonsMARYSI[i+1]._relayPort, HIGH);
        digitalWrite(buttonsMARYSI[i-1]._relayPort, HIGH);
        digitalWrite(buttonsMARYSI[i]._relayPort, LOW);
        //client.publish(send_topic.c_str(), "1");
        while (digitalRead(buttonsMARYSI[i]._port) == HIGH) {}
        digitalWrite(buttonsMARYSI[i]._relayPort, HIGH);
        //client.publish(send_topic.c_str(), "0");
      }
    }
  }
}

void realbuttonsSALONduza() {
  if(_relayInProgress != 1) {
    for (int i = 1; i < NUM_OF(buttonsSALONduza); i++) {
      if (digitalRead(buttonsSALONduza[i]._port) == HIGH) {
        //String send_topic = "smartflat/arduino/1/room/" + String(buttons[i]._room) + "/relay/" + String(i) + "/status";
        digitalWrite(buttonsSALONduza[i+1]._relayPort, HIGH);
        digitalWrite(buttonsSALONduza[i-1]._relayPort, HIGH);
        digitalWrite(buttonsSALONduza[i]._relayPort, LOW);
        //client.publish(send_topic.c_str(), "1");
        while (digitalRead(buttonsSALONduza[i]._port) == HIGH) {}
        digitalWrite(buttonsSALONduza[i]._relayPort, HIGH);
        //client.publish(send_topic.c_str(), "0");
      }
    }
  }
}

void realbuttonsLewa() {
  if(_relayInProgress != 1) {
    for (int i = 1; i < NUM_OF(buttonsLewa); i++) {
      if (digitalRead(buttonsLewa[i]._port) == HIGH) {
        //String send_topic = "smartflat/arduino/1/room/" + String(buttons[i]._room) + "/relay/" + String(i) + "/status";
        digitalWrite(buttonsLewa[i+1]._relayPort, HIGH);
        digitalWrite(buttonsLewa[i-1]._relayPort, HIGH);
        digitalWrite(buttonsLewa[i]._relayPort, LOW);
        //client.publish(send_topic.c_str(), "1");
        while (digitalRead(buttonsLewa[i]._port) == HIGH) {}
        digitalWrite(buttonsLewa[i]._relayPort, HIGH);
        //client.publish(send_topic.c_str(), "0");
      }
    }
  }
}

void realbuttonsPrawa() {
  if(_relayInProgress != 1) {
    for (int i = 1; i < NUM_OF(buttonsPrawa); i++) {
      if (digitalRead(buttonsPrawa[i]._port) == HIGH) {
        //String send_topic = "smartflat/arduino/1/room/" + String(buttons[i]._room) + "/relay/" + String(i) + "/status";
        digitalWrite(buttonsPrawa[i+1]._relayPort, HIGH);
        digitalWrite(buttonsPrawa[i-1]._relayPort, HIGH);
        digitalWrite(buttonsPrawa[i]._relayPort, LOW);
        //client.publish(send_topic.c_str(), "1");
        while (digitalRead(buttonsPrawa[i]._port) == HIGH) {}
        digitalWrite(buttonsPrawa[i]._relayPort, HIGH);
        //client.publish(send_topic.c_str(), "0");
      }
    }
  }
}

void realbuttonsEkran() {
  if(_relayInProgress != 1) {
    for (int i = 1; i < NUM_OF(buttonsEkran); i++) {
      if (digitalRead(buttonsEkran[i]._port) == HIGH) {
        //String send_topic = "smartflat/arduino/1/room/" + String(buttons[i]._room) + "/relay/" + String(i) + "/status";
        digitalWrite(buttonsEkran[i+1]._relayPort, HIGH);
        digitalWrite(buttonsEkran[i-1]._relayPort, HIGH);
        digitalWrite(buttonsEkran[i]._relayPort, LOW);
        //client.publish(send_topic.c_str(), "1");
        while (digitalRead(buttonsEkran[i]._port) == HIGH) {}
        digitalWrite(buttonsEkran[i]._relayPort, HIGH);
        //client.publish(send_topic.c_str(), "0");
      }
    }
  }
}


void setup() {
  for (int i = 0; i < 3; i++) {
    pinMode(buttonsMARYSI[i]._port, INPUT);
    pinMode(buttonsMARYSI[i]._relayPort, OUTPUT);
    digitalWrite(buttonsMARYSI[i]._relayPort, HIGH);
    
    pinMode(buttonsSALONduza[i]._port, INPUT);
    pinMode(buttonsSALONduza[i]._relayPort, OUTPUT);
    digitalWrite(buttonsSALONduza[i]._relayPort, HIGH);

    pinMode(buttonsLewa[i]._port, INPUT);
    pinMode(buttonsLewa[i]._relayPort, OUTPUT);
    digitalWrite(buttonsLewa[i]._relayPort, HIGH);

    pinMode(buttonsPrawa[i]._port, INPUT);
    pinMode(buttonsPrawa[i]._relayPort, OUTPUT);
    digitalWrite(buttonsPrawa[i]._relayPort, HIGH);

    pinMode(buttonsEkran[i]._port, INPUT);
    pinMode(buttonsEkran[i]._relayPort, OUTPUT);
    digitalWrite(buttonsEkran[i]._relayPort, HIGH);
    

  }

  Serial.begin(9600);

  // Init DHT library 
//  dht.begin(); 
  
  // Set temperature/humidity callback
 // SuplaDevice.setTemperatureHumidityCallback(&get_temperature_and_humidity);

  // ﻿Replace the falowing GUID
  char GUID[SUPLA_GUID_SIZE] = {0x5B,0x27,0x9A,0x31,0xE9,0xEF,0x93,0x3A,0x0C,0xBD,0xD9,0x8A,0x8F,0xC1,0x81,0x0D};
  // ﻿with GUID that you can retrieve from https://www.supla.org/arduino/get-guid


  // Ethernet MAC address
  uint8_t mac[6] = {0x00, 0x01, 0x02, 0x03, 0x04, 0x05};

  /*
   * Having your device already registered at cloud.supla.org,
   * you want to change CHANNEL sequence or remove any of them,
   * then you must also remove the device itself from cloud.supla.org.
   * Otherwise you will get "Channel conflict!" error.
   */
    
  // CHANNEL0 - RELAY
  SuplaDevice.addRelay(21, true);           // ﻿44 - ﻿Pin number where the relay is connected      
                                      // Call SuplaDevice.addRelay(44, true) with an extra "true" parameter 
                                      // to enable "port value inversion"
                                      // where HIGH == LOW, and LOW == HIGH   

  // CHANNEL1 - RELAY
  //SuplaDevice.addRelay(2, true);           // 45 - ﻿﻿Pin number where the relay is connected   

  // CHANNEL3 - TWO RELAYS (Roller shutter operation)
  SuplaDevice.addRollerShutterRelays(23,     // 46 - ﻿﻿Pin number where the 1st relay is connected   
                                     25, true);    // 47 - ﻿Pin number where the 2nd relay is connected  
  SuplaDevice.addRollerShutterRelays(27,     // 46 - ﻿﻿Pin number where the 1st relay is connected   
                                     29, true);    // 47 - ﻿Pin number where the 2nd relay is connected 
  SuplaDevice.addRollerShutterRelays(31,     // 46 - ﻿﻿Pin number where the 1st relay is connected   
                                     33, true);    // 47 - ﻿Pin number where the 2nd relay is connected 
    SuplaDevice.addRollerShutterRelays(35,     // 46 - ﻿﻿Pin number where the 1st relay is connected   
                                     37, true);    // 47 - ﻿Pin number where the 2nd relay is connected 
    SuplaDevice.addRollerShutterRelays(39,     // 46 - ﻿﻿Pin number where the 1st relay is connected   
                                     41, true);    // 47 - ﻿Pin number where the 2nd relay is connected 
                                       
  // CHANNEL4 - Opening sensor (Normal Open)
  //SuplaDevice.addSensorNO(A0); // A0 - ﻿Pin number where the sensor is connected
                               // Call SuplaDevice.addSensorNO(A0, true) with an extra "true" parameter
                               // to enable the internal pull-up resistor


  // CHANNEL5 - Opening sensor (Normal Open)
  //SuplaDevice.addSensorNO(A1); // A1 - ﻿Pin number where the sensor is connected


  // CHANNEL6 - DHT22 Sensor
  // SuplaDevice.addDHT11();
  // SuplaDevice.addAM2302();
  //SuplaDevice.addDHT22();


  /*
   * SuplaDevice Initialization.
   * Server address, LocationID and LocationPassword are available at https://cloud.supla.org 
   * If you do not have an account, you can create it at https://cloud.supla.org/account/create
   * SUPLA and SUPLA CLOUD are free of charge
   * 
   */

  SuplaDevice.begin(GUID,              // Global Unique Identifier 
                    mac,               // Ethernet MAC address
                    "svr2.supla.org",  // SUPLA server address
                    1084,                 // Location ID 
                    "ed75");               // Location Password
    
}

void loop() {
  SuplaDevice.iterate();
  realbuttonsSALONduza();
  realbuttonsMARYSI();
  realbuttonsLewa();
  realbuttonsPrawa();
  realbuttonsEkran();
}
