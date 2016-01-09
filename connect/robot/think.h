// BERICHT
structBericht conceptBericht;

// LED
byte rgb[3] = {255, 255, 255};
unsigned long laatsteLedKleurSwitchTijd = 0;

// CONNECTING
boolean connecting = true;  // zodra de arduino opstart begint connecting
byte connecting_fase = 0;   // het connecting proces verloopt in stappen
byte connecting_gekozenRemote;

  // Fase 0
  int connecting_aangemeldeRemotes[9]; // maximaal 8 (+ null) remotes kunnen zich aanmelden, bevat randomID's
  byte connecting_aantalAangemeldeRemotes = 0;

  byte connecting_AangemeldeRemotes_fadeR[9];
  byte connecting_AangemeldeRemotes_fadeG[9];
  byte connecting_AangemeldeRemotes_fadeB[9];

  byte connecting_AangemeldeRemotes_HuidigePreview = 0;

// RUNNING
boolean running; // == false, als connecting voltooid is, begint running


// fadeRGB
void fadeRGB(){

  if(connecting_aantalAangemeldeRemotes > 0){

    if(huidigeTijd > (laatsteLedKleurSwitchTijd + 500)){

      laatsteLedKleurSwitchTijd = huidigeTijd;
      rgb[0] = connecting_AangemeldeRemotes_fadeR[connecting_AangemeldeRemotes_HuidigePreview];
      rgb[1] = connecting_AangemeldeRemotes_fadeG[connecting_AangemeldeRemotes_HuidigePreview];
      rgb[2] = connecting_AangemeldeRemotes_fadeB[connecting_AangemeldeRemotes_HuidigePreview];

      if(connecting_AangemeldeRemotes_HuidigePreview == (connecting_aantalAangemeldeRemotes - 1)){
        connecting_AangemeldeRemotes_HuidigePreview = 0;
      }
      else{connecting_AangemeldeRemotes_HuidigePreview += 1;}

    }

  }


}

// CONNECT
void connect(int randomID){

  /* CONNECTING
  Voordat de gebruiker kan beginnen moet er een verbinding tussen de remote en robot tot stand worden gebracht. Dit gebeurt in de setup.

  De robot verzend een bericht naar alle remotes (0). Zodra een remote reageert wordt deze in de wachtrij gezet. De gebruiker kan vervolgens uit alle remotes in de wachtrij kiezen. Zodra de gebruiker een remote kiest (1) verstuurt de robot een bericht naar de betreffende remote om het verzoek te accepteren (het versturen gebeurt in output.h).
  */

  if(connecting_fase == 0){

    conceptBericht.afzender = randomID;
    conceptBericht.status = 1; // 1 = "ik ben beschikbaar"

    // Verwerk ontvangen bericht
    if(
      ontvangenBericht.afzender > 0 &&                // de afzender is een remote
      ontvangenBericht.geadresseerde == randomID &&   // dit bericht is voor deze robot bestemd
      ontvangenBericht.status == 1                    // "ik wil verbinding maken met geadresseerde"
     ){

       // Voordat de remote wordt toegevoegd aan connecting_aangemeldeRemotes[] wordt gekeken of deze er al in zit (om te voorkomen dat een remote er dubbel in komt te zitten).
       boolean isNogNietAangemeld = true;

       for(byte i = 0;i < connecting_aantalAangemeldeRemotes;i++){
         if(connecting_aangemeldeRemotes[i] == ontvangenBericht.afzender){
           isNogNietAangemeld = false;
         }
       }

       if(isNogNietAangemeld){

         // De remote wordt in de wachtrij gezet
         connecting_aangemeldeRemotes[connecting_aantalAangemeldeRemotes] = ontvangenBericht.afzender;
         connecting_aantalAangemeldeRemotes =+ 1;

       }

    }

    if(knopIsIngedrukt){
      connecting_gekozenRemote = connecting_AangemeldeRemotes_HuidigePreview;
      connecting_fase = 1;
    }
    else{
      fadeRGB();
    }

  }

  if(connecting_fase == 1){
    conceptBericht.afzender = randomID;
    conceptBericht.geadresseerde = 1; // geadresseerde = Gekozen remote
    conceptBericht.status = 2;
  }
}

// RUN
void run(){
  /* RUNNING
  Er is een verbinding met een remote. De remote kan de robot aansturen.
  */
}


// THINK
void think(int randomID){

  if(connecting){connect(randomID);}

  if(running){run();}

}
