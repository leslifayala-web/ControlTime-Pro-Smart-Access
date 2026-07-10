// Librería para controlar el teclado matricial 4x4
#include <Keypad.h>

// Librería para controlar la pantalla LCD 16x2
#include <LiquidCrystal.h>

// Librería para controlar el servomotor
#include <Servo.h>


// =====================================================
// CONFIGURACIÓN DEL TECLADO MATRICIAL 4x4
// =====================================================

// El teclado tiene 4 filas y 4 columnas
const byte ROWS = 4;
const byte COLS = 4;

// Distribución de las teclas del teclado
char keys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

// Pines del Arduino conectados a las filas del teclado
byte rowPins[ROWS] = {2, 3, 4, 5};

// Pines del Arduino conectados a las columnas del teclado
byte colPins[COLS] = {6, 7, 8, 9};

// Se crea el objeto keypad para poder leer las teclas presionadas
Keypad keypad = Keypad(
  makeKeymap(keys),
  rowPins,
  colPins,
  ROWS,
  COLS
);


// =====================================================
// CONFIGURACIÓN DE LA PANTALLA LCD 16x2
// =====================================================

// Se indican los pines del Arduino conectados al LCD
// RS = 10
// E  = 11
// D4 = A0
// D5 = A1
// D6 = A2
// D7 = A3
LiquidCrystal lcd(10, 11, A0, A1, A2, A3);


// =====================================================
// CONFIGURACIÓN DEL SERVOMOTOR
// =====================================================

// Se crea un objeto llamado servo
Servo servo;

// El cable de señal del servo está conectado al pin 12
const int servoPin = 12;


// =====================================================
// CONFIGURACIÓN DE LOS LEDS
// =====================================================

// LED verde: indica que el acceso fue permitido
const int ledVerde = 13;

// LED rojo: indica que el acceso fue rechazado
const int ledRojo = A4;



// VARIABLES DEL SISTEMA

// Guarda los números escritos por el usuario
String idIngresado = "";

// Indica si el usuario seleccionó registrar una entrada
bool modoEntrada = false;

// Indica si el usuario seleccionó registrar una salida
bool modoSalida = false;

// IDs AUTORIZADOS

// IDs válidos para registrar una entrada
String idsEntrada[] = {
  "3333",
  "4444",
  "5555"
};

// IDs válidos para registrar una salida
String idsSalida[] = {
  "6666",
  "7777",
  "8888"
};



// FUNCIÓN SETUP

// Esta función se ejecuta una sola vez
// cuando inicia la simulación o se enciende el Arduino
void setup() {

  // Inicializa la pantalla LCD con 16 columnas y 2 filas
  lcd.begin(16, 2);

  // Conecta el servomotor al pin indicado
  servo.attach(servoPin);

  // Coloca el servo en 0 grados, simulando la puerta cerrada
  servo.write(0);

  // Configura los pines de los LEDs como salidas
  pinMode(ledVerde, OUTPUT);
  pinMode(ledRojo, OUTPUT);

  // Apaga ambos LEDs al iniciar el sistema
  digitalWrite(ledVerde, LOW);
  digitalWrite(ledRojo, LOW);

  // Muestra el nombre del proyecto
  lcd.print("ControlTime Pro");

  // Mantiene el mensaje durante 2 segundos
  delay(2000);

  // Limpia la pantalla
  lcd.clear();

  // Muestra el menú principal
  mostrarMenu();
}



// FUNCIÓN LOOP

// Esta función se ejecuta continuamente
// mientras el Arduino se encuentra encendido
void loop() {

  // Obtiene la tecla presionada por el usuario
  char tecla = keypad.getKey();

  // Solo continúa si se presionó una tecla
  if (tecla) {


    // SELECCIÓN DE ENTRADA
    if (tecla == '1') {

      // Activa el modo entrada
      modoEntrada = true;

      // Desactiva el modo salida
      modoSalida = false;

      // Borra cualquier ID escrito anteriormente
      idIngresado = "";

      // Limpia la pantalla
      lcd.clear();

      // Muestra que se seleccionó Entrada
      lcd.print("Entrada");

      // Coloca el cursor en la segunda fila
      lcd.setCursor(0, 1);

      // Solicita el ID
      lcd.print("Ingrese ID");
    }


    // SELECCIÓN DE SALIDA

    else if (tecla == '2') {

      // Activa el modo salida
      modoSalida = true;

      // Desactiva el modo entrada
      modoEntrada = false;

      // Borra cualquier ID anterior
      idIngresado = "";

      // Limpia la pantalla
      lcd.clear();

      // Muestra que se seleccionó Salida
      lcd.print("Salida");

      // Coloca el cursor en la segunda fila
      lcd.setCursor(0, 1);

      // Solicita el ID
      lcd.print("Ingrese ID");
    }

    // INGRESO DEL ID

    else if (isdigit(tecla)) {

      // Solo permite escribir un máximo de 4 dígitos
      if (idIngresado.length() < 4) {

        // Agrega la tecla presionada al ID
        idIngresado += tecla;

        // Coloca el cursor en la segunda fila
        lcd.setCursor(0, 1);

        // Muestra el texto ID
        lcd.print("ID:");

        // Muestra el ID ingresado
        lcd.print(idIngresado);
      }
    }

    // CONFIRMAR EL ID
    else if (tecla == '#') {

      // Ejecuta la función que verifica el ID
      validarID();
    }

    // CANCELAR Y REGRESAR AL MENÚ
    else if (tecla == '*') {

      // Borra el ID ingresado
      idIngresado = "";

      // Desactiva los modos
      modoEntrada = false;
      modoSalida = false;

      // Limpia la pantalla
      lcd.clear();

      // Regresa al menú principal
      mostrarMenu();
    }
  }
}



// FUNCIÓN MOSTRAR MENÚ

// Esta función muestra las opciones principales del sistema
void mostrarMenu() {

  // Coloca el cursor en la primera fila
  lcd.setCursor(0, 0);

  // Muestra las opciones de Entrada y Salida
  lcd.print("1:Ent 2:Sal");

  // Coloca el cursor en la segunda fila
  lcd.setCursor(0, 1);

  // Muestra las opciones de confirmar y cancelar
  lcd.print("#=OK *=Menu");
}


// FUNCIÓN VALIDAR ID

// Esta función verifica si el ID ingresado está autorizado
void validarID() {

  // Variable que indica si el ID es correcto
  bool valido = false;

  // Limpia la pantalla antes de mostrar el resultado
  lcd.clear();

  // VALIDACIÓN PARA ENTRADA


  if (modoEntrada) {

    // Recorre los tres IDs autorizados para entrada
    for (int i = 0; i < 3; i++) {

      // Compara el ID ingresado con cada ID autorizado
      if (idIngresado == idsEntrada[i]) {

        // Indica que el ID es válido
        valido = true;

        // Finaliza el ciclo porque ya se encontró una coincidencia
        break;
      }
    }
  }

  // VALIDACIÓN PARA SALIDA

  if (modoSalida) {

    // Recorre los tres IDs autorizados para salida
    for (int i = 0; i < 3; i++) {

      // Compara el ID ingresado con cada ID autorizado
      if (idIngresado == idsSalida[i]) {

        // Indica que el ID es válido
        valido = true;

        // Finaliza el ciclo
        break;
      }
    }
  }

  // SI EL ID ES CORRECTO

  if (valido) {

    // Muestra el mensaje de acceso autorizado
    lcd.print("Acceso OK");

    // Enciende el LED verde
    digitalWrite(ledVerde, HIGH);

    // Se asegura de que el LED rojo esté apagado
    digitalWrite(ledRojo, LOW);

    // Ejecuta la apertura de la puerta
    abrirServo();

    // Apaga el LED verde después de cerrar la puerta
    digitalWrite(ledVerde, LOW);
  }


 // SI EL ID ES INCORRECTO
  else {

    // Muestra el mensaje de acceso rechazado
    lcd.print("Acceso NO");

    // Enciende el LED rojo
    digitalWrite(ledRojo, HIGH);

    // Se asegura de que el LED verde esté apagado
    digitalWrite(ledVerde, LOW);

    // Mantiene el LED rojo encendido durante 3 segundos
    delay(3000);

    // Apaga el LED rojo
    digitalWrite(ledRojo, LOW);
  }


  // REINICIO DEL SISTEMA
 
  // Borra el ID ingresado
  idIngresado = "";

  // Desactiva ambos modos
  modoEntrada = false;
  modoSalida = false;

  // Espera un segundo antes de volver al menú
  delay(1000);

  // Limpia la pantalla
  lcd.clear();

  // Muestra nuevamente el menú principal
  mostrarMenu();
}


// FUNCIÓN ABRIR SERVO

// Esta función simula la apertura y cierre de una puerta
void abrirServo() {

  // Gira el servomotor a 90 grados
  // Esto representa la puerta abierta
  servo.write(90);

  // Mantiene la puerta abierta durante 3 segundos
  delay(3000);

  // Regresa el servomotor a 0 grados
  // Esto representa la puerta cerrada
  servo.write(0);
}
