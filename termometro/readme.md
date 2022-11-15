# Repositorio con programa ejemplo en C para PIC16F887
Para trabajar con el compilador XC8 v2.10 con MPLABX IDE v5.30.
## Datos del alumno
Completa con tus datos la siguiente tabla:
Campo|Detalle
------|-----------
Nombre| Juan
Apellido| Diaz
Curso| 6°Electrónica
Año| 2022

## Objetivos del TP
Comprobar el correcto funcionamiento de la Placa de Circuito con PIC para TP, el Programador de PIC, el cable ICSP y el módulo de comunicación serie, mediante un firmware previamente testeado que le será provisto.

Luego crear un proyecto, codificar, compilar y bajar un programa simple al PIC que utilice en forma muy básica los dispositivos conectados al microcontrolador.

## Enunciado del TPSE01: PUESTA EN MARCHA

## 1. Verificación de hardware con firmware provisto
- [ ] Baja al microcontrolador el firmware para verificación de hardware `FW_CircTPhv6_Testv1.2.hex` provisto en este repositorio, luego:
- [ ] Verifica el funcionamiento del microparlante escuchando el beep luego del reset
- [ ] Verifica que los cuatro leds enciendan en forma consecutiva y luego se apaguen simultáneamente
- [ ] Gira potenciómetro en sentido antihorario (subir) y verifica que el valor que muestra el display se incremente
- [ ] Verifica que al presionar cada uno de los 4 botones, intercambie el estado del led correspondiente
- [ ] Verifica el funcionamiento del pulsador de reset, para reiniciar la secuencia de prueba
- [ ] Verifica la comunicación serie:
  - [ ] Desconecta la alimentación, conecta el módulo serie y vuelve a alimentar el circuito
  - [ ] Abre una terminal serie en algún dispositivo conectándolo al módulo serie y luego resetea la placa
  - [ ] Verifica la recepción del mensaje de inicio en la terminal
  - [ ] Envía mediante la aplicación de terminal caracteres de '1' a '4' y verifica la correcta recepción al intercambiar el estado del led correspondientes

## 2. Uso de botones y señales visuales
Crea un proyecto en este repositorio con los siguientes requerimientos:
Opción|Requerimiento
------|-----------
Project Type|Standalone Project
Device|PIC16F887
Tool|Alternete Tools → PICkit2
Compiler Toolchain|XC8 (v2.10)
Projet Name|TP01
Projet Location|Elije la carpeta del repositorio que has clonado
Set as main project|Si
Use project location as project folder|Si (lo ubica en el mismo repositorio)
Encoding|UTF-8

Agrega en el proyecto creado los archivos `main.c` y  `readme.md` recibidos, que ya se encuentran en el repositorio y termina de codificar un programa que:
- [x] Defina las etiquetas y constantes necesarias e inicialice las entradas y salidas todas en modo digital. Dejando los leds apagados y el display 7 segmentos en 0
- [x] Genere luego del reset por única vez un tono de 2 kHz durante 500 ms aproximadamente
- [x] Al pulsar el botón 1 (con etiqueta `PIN_TEC1` en el código) prenda el led rojo (con etiqueta `PIN_LED1`) y cuando se suelte lo apague
- [x] Al pulsar el botón 2 (con etiqueta `PIN_TEC2` en el código) prenda el led amarillo (con etiqueta `PIN_LED2`) y cuando se suelte lo apague
- [x] Al pulsar el botón 3 (con etiqueta `PIN_TEC3` en el código) prenda el led verde (con etiqueta `PIN_LED3`) y cuando se suelte lo apague
- [x] Al pulsar el botón 4 (con etiqueta `PIN_TEC4` en el código) prenda el led azul (con etiqueta `PIN_LED4`) y cuando se suelte lo apague
- [x] Sabiendo que la tensión que entrega el potenciómetro esta conectada a una entrada actualmente configurada como digital (con etiqueta `PIN_POTE`):
  - [x] Si la tensión en esta entrada es un nivel bajo (por ej. pote al mínimo) ponga un 0 en el display 7 segmentos
  - [x] Si la tensión en esta entrada es un nivel alto (por ej. pote al máximo) ponga un 1 en el display 7 segmentos
- [x] Una vez terminada la codificación, compila y baja el programa al PIC en la placa de desarrollo, para probar que cumpla con los requerimientos anteriores

Si es necesario puede consultar el manual del PIC [PIC16F882/883/884/886/887 Data Sheet](http://ww1.microchip.com/downloads/en/DeviceDoc/41291D.pdf)

## Definición 😅

![imagen](https://user-images.githubusercontent.com/64550311/157506128-bd0506ad-58b3-4f69-94b2-614a1e9e9673.png)

