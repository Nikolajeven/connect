# connect

**Door:**         Joppe Hoekstra & Nikolaj Even  
**Licentie:**     http://creativecommons.org/licenses/by/4.0/

## Inleiding

Voor dit project gebruiken we twee Arduino's met beiden een radiomodule. De radiomodules kunnen zowel zenden als ontvangen. Het apparaat dat de gebruiker in handen heeft noemen we de *zender*. Er is een joystick shield op de zender aangesloten. Het andere apparaat noemen we de *ontvanger*. De twee apparaten moeten met elkaar kunnen blijven communiceren als er er meerdere zenders en ontvangers zijn.

## Bestanden

Er zijn twee .ino bestanden die naar de Arduino's worden geupload. In de .ino bestanden wordt verwezen naar een aantal externe bestanden, deze staan genoemd onder *Libraries*. Deze bestanden moeten in [de *libraries* map van Arduino](https://www.arduino.cc/en/Hacking/Libraries) staan.

Variabelen, functies, et cetera hebben het voorvoegsel `connect_`. (Tenzij het niet onze code is.)

### Ontvanger
Dit .ino bestand is bedoeld voor de ontvanger.

### Zender
Dit .ino bestand is bedoeld voor de zender.

### Libraries

#### Jeelib
JeeLib is een bibliotheek die het verzenden en ontvangen van berichten een stuk makkelijker maakt.

Zie voor meer informatie:
- http://jeelabs.net/pub/docs/jeelib/
- https://github.com/jcw/jeelib

#### connect

In dit bestand staan de functies `connect_zend(bericht)` en `connect_ontvang()` (return -> bericht). Het bericht is een [struct](#connect_struct): `connect_structBericht`.

#### connect_joystick

Met de functies in dit bestand maken we het gemakkelijker om te controleren wat de staat van een bepaalde knop is. Bovendien is de notatie iets verduidelijkt:

Eerst: `if(!digitalRead(connect_pinKnop)) {De knop is ingedrukt}`

Nu: `if(connect_knopIngedrukt) {De knop is ingedrukt}`

#### connect_struct
*Structs* kunnen in Arduino niet in *functies* worden gebruikt als ze [in het .ino bestand](http://stackoverflow.com/questions/17493354/arduino-struct-pointer-as-function-parameter) staan. Daarom staat de *struct* van het te verzenden/ontvangen bericht in een apart bestand. Bovendien wordt de *struct* op zowel de zender als de ontvanger gebruikt. Door de *struct* te importeren wordt voorkomen dat er verschillen ontstaan tussen de *struct* op de zender en de ontvanger.

## To-do en vooruitgang
Op dit moment is de zender in staat de staat van de knoppen door te geven aan de ontvanger. De ontvanger toont de resultaten op de seriele monitor.

To-do list:
- Testprogramma om te controleren of alle berichten aankomen.
- Communicatie heen en weer. (momenteel nog eenrichtingsverkeer)
- Protecol om het verzenden en ontvangen van berichten in goede banen te leiden bij meerdere zenders en ontvangers.
