#include <Servo.h> // Utilisation de la bibliothèque Servo.h
#define pinServo 9 // Broche pour le signal du servomoteur X
const int SW_pin = 2; // Pin digital pour le bouton du joystick
const int X_pin = 0; // Pin analogique pour la coordonnée X
const int Y_pin = 1; // Pin analogique pour la coordonnée Y
unsigned short X; // Variables pour les valeurs du joystick
unsigned short Y; // Variables pour les valeurs du joystick
Servo Sx; // Déclaration du Servo

void setup() {
    pinMode(SW_pin, INPUT); // On configure SW comme une entré
    digitalWrite(SW_pin, HIGH); // On met de la tension dans SW pour dire au joystock que c'est une entré
    pinMode(pinServo, OUTPUT); // Broche servo moteur en sortie.
    Sx.attach(pinServo); // On fait la correspondance entre la broche du servomoteur et le pin
    Sx.write(90); // On met le servomoteur en position initiale.
    Serial.begin(9600); // On configure le moniteur série
}


void loop() {
    if(X == analogRead(X_pin))
  {
    Sx.write(rotation_servo(X)); // Envoi des signaux de rotation.
    delay(50);
  }
  else
  { 
    X = analogRead(Y_pin);
    Sx.write(rotation_servo_douvan_deye(X)); // Envoi des signaux de rotation.
    delay(50);
  }
}


byte rotation_servo(unsigned short n) // Fonction de correspondance.
{
  return (byte)(-0.175953 * n + 1023);
}

byte rotation_servo_avance_recule(unsigned short m) // Fonction de correspondance.
{
  return (byte)(-0.175953 * m + 180);
}
