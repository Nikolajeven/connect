# connect

**Door:**         Joppe Hoekstra & Nikolaj Even  
**Licentie:**     http://creativecommons.org/licenses/by/4.0/

## Inleiding

Voor dit project gebruiken we twee Arduino's met beiden een radiomodule. De radiomodules kunnen zowel zenden als ontvangen. Het apparaat dat de gebruiker in handen heeft noemen we *remote*. Er is een joystick shield op de remote aangesloten. Het andere apparaat noemen we *robot*. De twee apparaten moeten met elkaar kunnen blijven communiceren als er er meerdere zenders en ontvangers zijn. Dit project is nog in ontwikkeling.

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

#### Jeelib
JeeLib is een bibliotheek die het verzenden en ontvangen van berichten een stuk makkelijker maakt.

Zie voor meer informatie:
- http://jeelabs.net/pub/docs/jeelib/
- https://github.com/jcw/jeelib

#### Connect

In dit bestand staan de functies `setupConnect(byte apparaat)`, `ontvang()` en `verstuur(structBericht bericht)` en de struct `structBericht`.

## To-do en vooruitgang
Op dit moment is de zender in staat de staat van de knoppen door te geven aan de ontvanger. De ontvanger toont de resultaten op de seriele monitor.

To-do list:
- Uitwerken connecting systeem
