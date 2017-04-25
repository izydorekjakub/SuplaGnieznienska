v.1.8.2 Roller Shutter for WeMos D1 mini board

DS18B20        2/D4  termometr
CFG_PORT       0/D3  pull up - tryb button, czyli przejście do konfigu poprzez zwarcie na 5s do masy
RELAY1         4/D2
RELAY2         5/D1
BTN1          14/D5  pull down - sterowanie aktywne poprzez zwarcie do Vcc
BTN2          12/D6  pull down - sterowanie aktywne poprzez zwarcie do Vcc
SENSOR_PORT1  13/D7  pull down - czujnik zamknęcia rolet - sterowanie aktywne poprzez zwarcie do VCC
LED config    15/D8  dioda sygnalizacyjna, sprawdzić czy GPIO15 jest podłączone do masy bezpośrednio, czy poprzez rezystor 10k, jeżeli poprzez rezystor to równolegle do niego podłączyć diodę w szeregu z rezystorem 270-330 ohm.

Parametry wgrywania programem "ESP Falsh Download Tool":

CreystalFreq 26M
SPI SPEED 40 MHz
SPI MODE QIO
BAUDRATE 11520
FLASH SIZE 32Mbit  (4MByte)

Wgrywamy pod adresy:

wemos_rs_DS_noFOTA_4M_eagle.flash.bin ------------> 0x00000
wemos_rs_DS_noFOTA_4M_eagle.irom0text.bin --------> 0x40000
