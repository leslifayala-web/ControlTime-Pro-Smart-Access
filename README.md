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

1. Introducción  
2. Objetivos  
3. Descripción del proyecto
4. Diseño del circuito electrónico  
5. Programación en Arduino  
6. Lógica del sistema  
7. Pruebas de funcionamiento  
8. Corrección de errores    
9. Conclusiones  
10. Recomendaciones  
11. Tinkercad

# Introducción

El proyecto consiste en la creación de un sistema de control de acceso utilizando Arduino Uno, un teclado matricial 4x4, una pantalla LCD, LEDs indicadores y un servo motor. El sistema permite ingresar una contraseña para controlar la apertura de una puerta simulada.

El objetivo de esta etapa es realizar la simulación del circuito electrónico y desarrollar la programación necesaria en Arduino utilizando la plataforma Tinkercad, permitiendo comprobar el funcionamiento del prototipo antes de realizar una construcción física.

La simulación es importante porque ayuda a detectar errores en las conexiones, mejorar la programación y comprobar que todos los componentes trabajan correctamente, reduciendo costos y tiempo antes de implementar el proyecto real.


## Objetivo

## Objetivo general

Diseñar y programar un sistema de control de acceso mediante Arduino Uno, simulando su funcionamiento en Tinkercad para validar la integración de los componentes electrónicos.

## Objetivos específicos

- Crear el circuito electrónico utilizando Arduino y componentes de control.
- Programar el Arduino para validar contraseñas ingresadas por el usuario.
- Implementar indicadores visuales mediante LEDs y mensajes en pantalla LCD.
- Simular el funcionamiento del sistema antes de construir el prototipo físico.
- Realizar pruebas para detectar y corregir errores.

# Descripción del proyecto

## Problema que resuelve

Actualmente algunos sistemas de acceso requieren controles manuales que pueden ser poco seguros y difíciles de administrar. Este proyecto busca implementar una alternativa utilizando tecnología electrónica que permita controlar el acceso mediante una contraseña.

## Funcionamiento general

El usuario ingresa una contraseña utilizando un teclado matricial. Arduino procesa la información recibida y compara la contraseña ingresada con la contraseña almacenada.

Si la contraseña es correcta, el sistema permite el acceso activando un servo motor y encendiendo un LED verde.

Si la contraseña es incorrecta, se activa un LED rojo y se muestra un mensaje indicando que el acceso fue rechazado.

## Componentes utilizados

- Arduino Uno
- Pantalla LCD 16x2
- Teclado matricial 4x4
- Servo motor
- LED verde
- LED rojo
- Resistencias
- Protoboard
- Cables jumper

## Resultado esperado

Obtener un prototipo simulado funcional donde el usuario pueda ingresar una contraseña y el sistema permita o deniegue el acceso dependiendo del resultado.

# Diseño del circuito electrónico

## Descripción del circuito

El circuito fue diseñado en la plataforma Tinkercad utilizando Arduino Uno como controlador principal. Los componentes fueron conectados para permitir la lectura del teclado, mostrar información en la pantalla LCD y controlar el movimiento del servo motor.

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
| LED no encendía | Polaridad incorrecta | Se invirtió conexión | Solucionado |

# Conclusiones

- La simulación en Tinkercad permitió comprobar el funcionamiento del sistema antes de construir el prototipo físico.
- La programación en Arduino permitió integrar correctamente los componentes electrónicos utilizados.
- Las pruebas realizadas ayudaron a identificar errores y mejorar el funcionamiento del sistema.
- El uso de GitHub facilitó la organización y almacenamiento de la documentación del proyecto.

# Recomendaciones

- Revisar las conexiones antes de iniciar la simulación.
- Mantener el código correctamente comentado.
- Realizar pruebas con diferentes contraseñas y escenarios.
- Mantener actualizado el repositorio de GitHub.
- Guardar respaldos del código y documentación.


## Simulación en Tinkercad

Enlace:
https://www.tinkercad.com/things/2BxwdTdQFc1-copy-of-proyecto/editel?returnTo=https%3A%2F%2Fwww.tinkercad.com%2Fdashboard&sharecode=sA-zm33T4hUhF6Sxr5wIrwu7o65KhcQ9BmoccBYQ9SQ
