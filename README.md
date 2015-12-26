# connect

**Door:**         Joppe Hoekstra & Nikolaj Even  
**Licentie:**     http://creativecommons.org/licenses/by/4.0/

## Inleiding

Voor dit project gebruiken we twee Arduino's met beiden een radiomodule. De radiomodules kunnen zowel zenden als ontvangen. Het apparaat dat de gebruiker in handen heeft noemen we *remote*. Er is een joystick shield op de remote aangesloten. Het andere apparaat noemen we *robot*. De twee apparaten moeten met elkaar kunnen blijven communiceren als er er meerdere zenders en ontvangers zijn.

## Bestanden

Er zijn twee .ino bestanden die naar de Arduino's worden geupload. In de .ino bestanden wordt verwezen naar een aantal *libraries*. Deze bestanden moeten in [de *libraries* map van Arduino](https://www.arduino.cc/en/Hacking/Libraries) staan.

```
libraries/
  connect/
    connect.h
  JeeLib/
    ...
remote/
  remote.ino
  joystick.h
robot/
  robot.ino
```

### Libraries

#### Jeelib.h
JeeLib is een bibliotheek die het verzenden en ontvangen van berichten een stuk makkelijker maakt.

Zie voor meer informatie:
- http://jeelabs.net/pub/docs/jeelib/
- https://github.com/jcw/jeelib

#### connect

In dit bestand staan de functies `connect_zend(bericht)` en `connect_ontvang()` (return -> bericht). Het bericht is een [struct](#connect_struct): `connect_connect_structBericht`.

#### connect_struct
*Structs* kunnen in Arduino niet in *functies* worden gebruikt als ze [in het .ino bestand](http://stackoverflow.com/questions/17493354/arduino-struct-pointer-as-function-parameter) staan. Daarom staat de *struct* van het te verzenden/ontvangen bericht in een apart bestand. Bovendien wordt de *struct* op zowel de zender als de ontvanger gebruikt. Door de *struct* te importeren wordt voorkomen dat er verschillen ontstaan tussen de *struct* op de zender en de ontvanger.

## To-do en vooruitgang
Op dit moment is de zender in staat de staat van de knoppen door te geven aan de ontvanger. De ontvanger toont de resultaten op de seriele monitor.

To-do list:
- Testprogramma om te controleren of alle berichten aankomen.
- Communicatie heen en weer. (momenteel nog eenrichtingsverkeer)
- Protecol om het verzenden en ontvangen van berichten in goede banen te leiden bij meerdere zenders en ontvangers.
