<p align="center">
  <img src="ImagenBanner/Banner.png.png" width="100%" height="335">
</p>

# ControlTime-Pro-Smart-Access
Proyecto de control de acceso y asistencia de maestros utilizando Arduino.

## Portada

**Nombre de la institución:** Instituto Católico Karol Wojtyla  
**Nombre del proyecto:** Sistema de Control de Acceso mediante Arduino.
**Etapa 2:** Simulación y Programación del Prototipo en Tinkercad  

**Integrantes:**
- Leslie Stefany Ayala Flores
- Ricardo Alexander Aguillon Ortiz
- Flor Stefany Campos Palacios

**Docente:** Lic Criseyda Guadalupe Araujo Melgar

**Nivel:** Tercer año tecnico vocacional en Desarrollo de Software 

**Fecha:** 10 de Julio 2026  

## Proyecto Integrador

# Índice

1. Diseño del circuito electrónico  
2. Programación en Arduino  
3. Lógica del sistema  
4. Pruebas de funcionamiento  
5. Corrección de errores     
6. Tinkercad enlace


# Diseño del circuito electrónico

## Descripción del circuito

El circuito fue diseñado en la plataforma Tinkercad utilizando Arduino Uno como controlador principal. Los componentes fueron conectados para permitir la lectura del teclado, mostrar información en la pantalla LCD y controlar el movimiento del servo motor.

# Programación

La programación fue desarrollada en lenguaje C++ para Arduino.

El código incluye:

- Declaración de variables.
- Configuración de entradas y salidas.
- Función `setup()`.
- Función `loop()`.
- Lectura de sensores.
- Control de actuadores.

# Problemas encontrados

Durante el desarrollo se presentaron algunos inconvenientes relacionados con las conexiones del circuito y con la programación de algunos componentes, lo que provocó que el sistema no respondiera correctamente en las primeras pruebas.

# Soluciones implementadas

Para solucionar estos inconvenientes se revisó el cableado del circuito, se corrigieron errores en el código y se realizaron nuevas pruebas hasta lograr el funcionamiento esperado de la simulación.

# Resultado obtenido

Se obtuvo una simulación funcional en Tinkercad que permite comprobar el correcto funcionamiento del sistema antes de construir el prototipo físico.


## Descripción de componentes

| Componente | Función |
|---|---|
| Arduino Uno | Controla el funcionamiento completo del sistema |
| LCD 16x2 | Muestra mensajes al usuario |
| Servo Motor | Simula la apertura y cierre de la puerta |
| Teclado 4x4 | Permite ingresar la contraseña |
| LED Verde | Indica acceso permitido |
| LED Rojo | Indica acceso denegado |
| Resistencias | Protegen los componentes electrónicos |
| Protoboard | Permite realizar conexiones temporales |
| Cables | Realizan la conexión entre componentes |

# Programación en Arduino

## Librerías utilizadas

Las librerías utilizadas permiten controlar los diferentes componentes:

- **LiquidCrystal.h:** Control de pantalla LCD.
- **Keypad.h:** Lectura del teclado matricial.
- **Servo.h:** Control del servo motor.

## Función setup()

La función setup() se ejecuta una sola vez al iniciar Arduino.

En ella se configuran:

- Pines de entrada y salida.
- Inicio de la pantalla LCD.
- Posición inicial del servo.
- Configuración del teclado.


## Función loop()

La función loop() se ejecuta continuamente y permite:

- Leer la contraseña ingresada.
- Comparar los datos.
- Mostrar mensajes.
- Controlar LEDs y servo.

## Funciones creadas

Ejemplo:

- `verificarClave()` → Comprueba si la contraseña es correcta.
- `abrirPuerta()` → Activa el servo motor.
- `bloquearAcceso()` → Indica acceso rechazado.


## Explicación del código

El programa recibe la contraseña mediante el teclado matricial, la compara con la contraseña almacenada y ejecuta una acción dependiendo del resultado.

El código fue documentado con comentarios para facilitar su comprensión.

# Lógica del sistema

El funcionamiento del sistema sigue los siguientes pasos:

1. El usuario ingresa una contraseña mediante el teclado.
2. Arduino recibe los datos ingresados.
3. El sistema compara la contraseña.

### Si la contraseña es correcta:

- Se enciende el LED verde.
- La pantalla LCD muestra "Acceso permitido".
- El servo motor abre la puerta.


### Si la contraseña es incorrecta:

- Se enciende el LED rojo.
- La pantalla LCD muestra "Acceso denegado".
- El sistema vuelve a esperar una nueva contraseña.

# Pruebas de funcionamiento

| Prueba | Entrada | Resultado esperado | Resultado obtenido |
|-|-|-|-|
| Contraseña correcta | 1234 | Servo abre y LED verde encendido | Correcto |
| Contraseña incorrecta | 1111 | LED rojo encendido | Correcto |
| Tres intentos fallidos | Contraseña incorrecta | Bloqueo temporal | Correcto |

# Corrección de errores

| Problema | Causa | Solución | Resultado |
|-|-|-|-|
| LCD no mostraba información | Pines incorrectos | Se revisaron conexiones | Solucionado |
| Servo no funcionaba | Error en programación del ángulo | Se modificó el código | Solucionado |
| LED no encendía | Pines incorrectos| Se invirtió conexión | Solucionado |

## Simulación en Tinkercad

Enlace:
https://www.tinkercad.com/things/2BxwdTdQFc1-copy-of-proyecto/editel?returnTo=https%3A%2F%2Fwww.tinkercad.com%2Fdashboard&sharecode=sA-zm33T4hUhF6Sxr5wIrwu7o65KhcQ9BmoccBYQ9SQ

#  Avances de la Etapa 3

Durante el desarrollo de ControlTime Pro Smart Access se han realizado diferentes avances con el objetivo de crear un sistema que permita mejorar el control de asistencia de los docentes mediante el uso de tecnología.

En esta etapa se trabajó principalmente en la creación de la aplicación móvil, donde se diseñaron las pantallas necesarias para que los usuarios puedan interactuar con el sistema de una manera más sencilla. También se inició el proceso de programación de las funciones principales, permitiendo avanzar en la estructura del funcionamiento de la aplicación.

Durante esta etapa se trabajó en el desarrollo de la aplicación móvil, implementando nuevas funciones y realizando diferentes pruebas para mejorar su funcionamiento.

Entre los principales avances se encuentran:

- Diseño y organización de la aplicación móvil.
- Programación mediante bloques en MIT App Inventor.
- Implementación del inicio de sesión.
- Conexión con una hoja de cálculo para validar usuarios.
- Corrección de errores encontrados durante las pruebas.
- Actualización de la documentación y del repositorio.

## Desarrollo de la interfaz

Se realizó la creación de la interfaz gráfica en App Inventor, organizando los diferentes elementos visuales como botones, campos de información y pantallas de navegación. Se buscó crear un diseño sencillo y fácil de comprender para que los usuarios puedan utilizar la aplicación sin dificultades.

Durante este proceso se realizaron cambios en la distribución de los elementos y pruebas de visualización para mejorar la apariencia y funcionamiento de la aplicación.

## Función de inicio de sesión

Una de las funciones implementadas fue el inicio de sesión de usuarios. Para realizar esta función se utilizó una hoja de cálculo como almacenamiento de información, donde se guardan los datos necesarios para realizar la validación de los usuarios.

Durante el desarrollo de esta función se realizaron diferentes pruebas para solucionar problemas relacionados con la conexión entre App Inventor y la hoja de cálculo, logrando mejorar el proceso de lectura y verificación de datos.

## Pruebas realizadas

Se realizaron pruebas del funcionamiento de la aplicación para comprobar que las pantallas, botones y funciones programadas respondieran correctamente. Estas pruebas permitieron encontrar errores y realizar ajustes necesarios para mejorar el funcionamiento general del sistema.

También se verificó la comunicación entre la aplicación y la base de datos utilizada para el registro de usuarios.

#  Funcionalidades implementadas

En esta etapa se desarrollaron las siguientes funciones:

- Inicio de sesión de usuarios.
- Validación de usuarios mediante hoja de cálculo.
- Navegación entre las diferentes pantallas de la aplicación.
- Programación de eventos mediante bloques.
- Organización de la estructura de la aplicación para facilitar futuras implementaciones.

#  Tecnologías utilizadas

- MIT App Inventor:Utilizado para el diseño y programación de la aplicación móvil.
- Arduino UNO
- Google Sheets: Utilizada como almacenamiento de datos para los usuarios.
- GitHub: Organización y documentación del proyecto

#  Próxima etapa

En la siguiente etapa se realizará la integración del prototipo físico utilizando Arduino y los diferentes componentes electrónicos del proyecto. Además, se efectuarán pruebas para comprobar la comunicación entre el hardware y la aplicación móvil, realizando los ajustes necesarios para mejorar el funcionamiento general del sistema.

