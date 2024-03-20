import numpy as np
import handDetector as hand
import time
import cv2
import os
import serial

variable = "encender"
# Abrir una cámara para capturar video
url = 'http://192.168.137.51/400x296.jpg'
cap = cv2.VideoCapture(url)

detector = hand.handDetector()  # Crear un objeto para encontrar puntos de referencia de la mano

# Configura el puerto serial
puerto_serial = serial.Serial('COM3', 9600)  # Cambia 'COM3' al puerto serial que estés utilizando en tu sistema
time.sleep(2)  # Espera a que el puerto serial se inicialice

last_response = ""  # Variable para almacenar la última respuesta

while True:
    cap.open(url)
    ret, img = cap.read()  # Captura frame por frame

    if ret:
        img = detector.findHands(img)  # Buscar mano/s en la imagen
        lmList, bbox = detector.findPosition(img)  # Devuelve los puntos de referencia y el recuadro que encierra la mano

        if len(lmList) != 0:  # Verificar si hay mano
            fingers = detector.fingersUp()  # Verificar si los dedos están levantados

            # Contar los dedos levantados
            fingers_up_count = sum(fingers)

            # Reconocimiento de gestos de la mano basado en la cantidad de dedos levantados
            if fingers_up_count == 0:
                response = "Todos los dedos están abajo"
            elif fingers_up_count == 1:
                # Cada dedo por separado
                for i, finger in enumerate(fingers):
                    if finger == 1:
                        response = f"Solo el dedo {i} está arriba"
            elif fingers_up_count == 2:
                # Combinaciones de dos dedos arriba
                for i in range(5):
                    for j in range(i+1, 5):
                        if fingers[i] == 1 and fingers[j] == 1:
                            response = f"Dedo {i} y dedo {j} están arriba"
            elif fingers_up_count == 3:
                # Combinaciones de tres dedos arriba
                for i in range(5):
                    for j in range(i+1, 5):
                        for k in range(j+1, 5):
                            if fingers[i] == 1 and fingers[j] == 1 and fingers[k] == 1:
                                response = f"Dedo {i}, dedo {j} y dedo {k} están arriba"
            elif fingers_up_count == 4:
                # Combinaciones de cuatro dedos arriba
                for i in range(5):
                    for j in range(i+1, 5):
                        for k in range(j+1, 5):
                            for l in range(k+1, 5):
                                if fingers[i] == 1 and fingers[j] == 1 and fingers[k] == 1 and fingers[l] == 1:
                                    response = f"Dedo {i}, dedo {j}, dedo {k} y dedo {l} están arriba"
            elif fingers_up_count == 5:
                response = "Todos los dedos están arriba"

            print(response)
            last_response = response

        cv2.imshow("Image", img)  # Mostrar imagen

    key = cv2.waitKey(1)
    if key == ord('q'):  # Presionar la letra q del teclado para cerrar
        break
    elif key == ord(' '):  # Presionar la tecla espacio para tomar la última respuesta y detener el programa
        print("Última respuesta:", last_response)
        break


# Envía la cadena de texto completa
cadena = last_response # Agrega '\n' para indicar el final de la cadena
puerto_serial.write(cadena.encode())
print("Cadena enviada:", cadena)

# Espera un tiempo para permitir que Arduino procese y responda
time.sleep(1)

# Lee la respuesta de Arduino desde el puerto serial
respuesta = puerto_serial.readline().decode().strip()  # Lee una línea y elimina los espacios en blanco
print("Respuesta recibida:", respuesta)

# Cierra el puerto serial
puerto_serial.close()

cap.release()  # Liberar camara
cv2.destroyAllWindows()  # Destruir o cerrar las ventanas
