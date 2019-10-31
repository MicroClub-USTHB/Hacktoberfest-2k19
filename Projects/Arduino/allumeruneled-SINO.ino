const int L1 = 2; // broche 2 du micro-contrôleur se nomme maintenant : L1
void setup() //fonction d'initialisation de la carte
{
//contenu de l'initialisation
pinMode(L1, OUTPUT); //L1 est une broche de sortie
}
void loop() //fonction principale, elle se répète (s’exécute) à l'infini
{
//contenu du programme
digitalWrite(L1, HIGH); //allumer L1
delay(1000); // attendre 1 seconde
digitalWrite(L1, LOW); // Eteindre L1
delay(2000); // attendre 2 seconde
}
