typedef struct {
   byte afzender;              // De zendende nodeID

   // false = niet ingedrukt / true = ingedrukt
   boolean knopSelectIngedrukt = false;
   boolean knopRechtsIngedrukt = false;
   boolean knopLinksIngedrukt = false;
   boolean knopOnderIngedrukt = false;
   boolean knopBovenIngedrukt = false;

   // 0 tot 1000 (500 is standaard)
   int C0_staatAnalogX = 500;
   int C0_staatAnalogY = 500;
} C0_structBericht; // Naam van structure
