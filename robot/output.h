unsigned long laatsteBerichtVerzondenTijd = 0;

void rgbLed(byte red, byte green, byte blue, byte pinRed, byte pinGreen, byte pinBlue){
  analogWrite(pinRed, red);
  analogWrite(pinGreen, green);
  analogWrite(pinBlue, blue);
}

void output(byte pinRed, byte pinGreen, byte pinBlue){
  if(huidigeTijd > (laatsteBerichtVerzondenTijd + 300)){
    laatsteBerichtVerzondenTijd = huidigeTijd;
    verstuur(conceptBericht);
  }
  rgbLed(rgb[0], rgb[1], rgb[2], pinRed, pinGreen, pinBlue);
}
