#include <Keypad.h>
#include <LiquidCrystal.h>
#include <Servo.h>
 
// --- Teclado 4x4 ---
const byte ROWS = 4;
const byte COLS = 4;
 
char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
 
byte rowPins[ROWS] = {2, 3, 4, 5}; // Filas
byte colPins[COLS] = {6, 7, 8, 9}; // Columnas
 
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);
 
// --- LCD 16x2 en paralelo ---
LiquidCrystal lcd(10, 11, A0, A1, A2, A3);
// RS=10, E=11, D4=A0, D5=A1, D6=A2, D7=A3
 
// --- Servo SG90 ---
Servo servo;
const int servoPin = 12;
 
// --- LEDs indicadores ---
const int ledVerde = 13; // Se enciende si el ID es correcto
const int ledRojo  = A4; // Se enciende si el ID es incorrecto
 
// --- Variables ---
String idIngresado = "";
bool modoEntrada = false;
bool modoSalida = false;
 
// --- IDs validos ---
String idsEntrada[] = {"3333", "4444", "5555"};
String idsSalida[]  = {"6666", "7777", "8888"};
 
void setup() {
  lcd.begin(16, 2);
 
  servo.attach(servoPin);
  servo.write(0); // Servo cerrado
 
  pinMode(ledVerde, OUTPUT);
  pinMode(ledRojo, OUTPUT);
 
  digitalWrite(ledVerde, LOW);
  digitalWrite(ledRojo, LOW);
 
  lcd.print("ControlTime Pro");
  delay(2000);
  lcd.clear();
  mostrarMenu();
}
 
void loop() {
  char tecla = keypad.getKey();
 
  if (tecla) {
 
    if (tecla == '1') {
      modoEntrada = true;
      modoSalida = false;
      idIngresado = "";
      apagarLeds();
      lcd.clear();
      lcd.print("Entrada: ID?");
    }
 
    else if (tecla == '2') {
      modoSalida = true;
      modoEntrada = false;
      idIngresado = "";
      apagarLeds();
      lcd.clear();
      lcd.print("Salida: ID?");
    }
 
    else if (isdigit(tecla)) {
      if (idIngresado.length() < 4) {
        idIngresado += tecla;
        lcd.setCursor(0, 1);
        lcd.print("ID: ");
        lcd.print(idIngresado);
      }
    }
 
    else if (tecla == '#') {
      if (modoEntrada || modoSalida) {
        validarID();
      } else {
        lcd.clear();
        lcd.print("Elija modo 1/2");
        delay(1500);
        lcd.clear();
        mostrarMenu();
      }
    }
 
    else if (tecla == '*') {
      idIngresado = "";
      modoEntrada = false;
      modoSalida = false;
      apagarLeds();
      lcd.clear();
      mostrarMenu();
    }
  }
}
 
void mostrarMenu() {
  lcd.setCursor(0, 0);
  lcd.print("1:Entrada 2:Sal");
  lcd.setCursor(0, 1);
  lcd.print("#:OK  *:Volver");
}
 
void validarID() {
  lcd.clear();
 
  bool valido = false;
 
  if (modoEntrada) {
    for (int i = 0; i < 3; i++) {
      if (idIngresado == idsEntrada[i]) {
        valido = true;
        break;
      }
    }
  }
 
  else if (modoSalida) {
    for (int i = 0; i < 3; i++) {
      if (idIngresado == idsSalida[i]) {
        valido = true;
        break;
      }
    }
  }
 
  if (valido) {
    lcd.print("Acceso permitido");
    digitalWrite(ledVerde, HIGH);
    digitalWrite(ledRojo, LOW);
    abrirServo();
    digitalWrite(ledVerde, LOW);
  }
 
  else {
    lcd.print("Acceso denegado");
    digitalWrite(ledVerde, LOW);
    digitalWrite(ledRojo, HIGH);
    delay(2000);
    digitalWrite(ledRojo, LOW);
  }
 
  idIngresado = "";
  modoEntrada = false;
  modoSalida = false;
 
  delay(1000);
  lcd.clear();
  mostrarMenu();
}
 
void abrirServo() {
  servo.write(90); // Abre
  delay(3000);
  servo.write(0);  // Cierra
}
 
void apagarLeds() {
  digitalWrite(ledVerde, LOW);
  digitalWrite(ledRojo, LOW);
}
