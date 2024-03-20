#include <Servo.h>

Servo servo0,servo1, servo2, servo3, servo4,servo01; //valores de los dedos 0,1,2,3,4 el servo 01 es la movilidad circular del pulgar el 0 lo recoje
int pos = 0;

void setup() {
  Serial.begin(9600);
  servo0.attach(3); //GPIO 2
  servo1.attach(5); //GPIO 13
  servo2.attach(6); //GPIO 12
  servo3.attach(9); //GPIO 1 
  servo4.attach(10); //GPIO 3
  servo01.attach(11); //GPIO 16
}

void loop() {
  if (Serial.available() > 0) {
    String input = Serial.readStringUntil('\n'); 
    Serial.print("Mensaje recibido: ");
    Serial.println(input);

    if (input =="Todos los dedos están abajo") {
      for (pos = 0; pos <= 180; pos += 10) { 
            // in steps of 1 degree
            servo0.write(pos);
            servo1.write(pos);
            servo2.write(pos);
            servo3.write(pos);
            servo4.write(pos);  
            delay(15);                      
      }
    }
    if(input=="Solo el dedo 0 está arriba"){
        for (pos = 0; pos <= 180; pos += 10) { 
            servo1.write(pos);
            servo2.write(pos);
            servo3.write(pos);
            servo4.write(pos);  
            delay(15);                      
          }
          for (pos = 180; pos >= 0; pos -= 1) { 
            servo0.write(pos);              
            delay(15);                     
          }
        }
        if(input=="Solo el dedo 1 está arriba"){
          for (pos = 0; pos <= 180; pos += 10) { 
            // in steps of 1 degree
            servo0.write(pos);
            servo2.write(pos);
            servo3.write(pos);
            servo4.write(pos);  
            delay(15);                      
          }
          for (pos = 180; pos >= 0; pos -= 1) { 
            servo1.write(pos);              
            delay(15);                     
          }
        }
        if(input=="Solo el dedo 2 está arriba"){
          for (pos = 0; pos <= 180; pos += 10) { 
            // in steps of 1 degree
            servo0.write(pos);
            servo1.write(pos);
            servo3.write(pos);
            servo4.write(pos);  
            delay(15);                      
          }
          for (pos = 180; pos >= 0; pos -= 1) { 
            servo2.write(pos);              
            delay(15);                     
          }
        }
        if(input=="Solo el dedo 3 está arriba"){
          for (pos = 0; pos <= 180; pos += 10) { 
            // in steps of 1 degree
            servo0.write(pos);
            servo1.write(pos);
            servo2.write(pos);
            servo4.write(pos);  
            delay(15);                      
          }
          for (pos = 180; pos >= 0; pos -= 1) { 
            servo3.write(pos);              
            delay(15);                     
          }
        }
        if(input=="Solo el dedo 4 está arriba"){
          for (pos = 0; pos <= 180; pos += 10) { 
            // in steps of 1 degree
            servo0.write(pos);
            servo1.write(pos);
            servo2.write(pos);
            servo3.write(pos);
            delay(15);                      
          }
          for (pos = 180; pos >= 0; pos -= 1) { 
            servo4.write(pos);              
            delay(15);                     
          }
        }
        //--------------dos dedos arriba ----------------------------------------------------------------------------------------//
        if(input=="Dedo 0 y dedo 1 están arriba"){
          for (pos = 180; pos >= 0; pos -= 1) { 
            servo0.write(pos);
            servo1.write(pos);               
            delay(15);                     
          }
          for (pos = 0; pos <= 180; pos += 10) { 
            servo2.write(pos);
            servo3.write(pos);
            servo4.write(pos);  
            delay(15);                      
          }
        }
        if(input=="Dedo 0 y dedo 2 están arriba"){
          for (pos = 180; pos >= 0; pos -= 1) { 
            servo0.write(pos);
            servo2.write(pos);               
            delay(15);                     
          }
          for (pos = 0; pos <= 180; pos += 10) {
            servo1.write(pos);
            servo3.write(pos);
            servo4.write(pos);  
            delay(15);                      
          }
        }
        if(input=="Dedo 0 y dedo 3 están arriba"){
          for (pos = 180; pos >= 0; pos -= 1) { 
            servo0.write(pos);
            servo3.write(pos);               
            delay(15);                     
          }
          for (pos = 0; pos <= 180; pos += 10) { 
            servo1.write(pos);
            servo2.write(pos);
            servo4.write(pos);  
            delay(15);                      
          }
        }
        if(input=="Dedo 0 y dedo 4 están arriba"){
          for (pos = 180; pos >= 0; pos -= 1) { 
            servo0.write(pos);
            servo4.write(pos);               
            delay(15);                     
          }
          for (pos = 0; pos <= 180; pos += 10) { 
            servo1.write(pos);
            servo2.write(pos);
            servo3.write(pos);
            delay(15);                      
          }
        }
        if(input=="Dedo 1 y dedo 2 están arriba"){
          for (pos = 180; pos >= 0; pos -= 1) { 
            servo1.write(pos);
            servo2.write(pos);               
            delay(15);                     
          }
          for (pos = 0; pos <= 180; pos += 10) { 
            servo0.write(pos);
            servo3.write(pos);
            servo4.write(pos);  
            delay(15);                      
          }
        }
        if(input=="Dedo 1 y dedo 3 están arriba"){
          for (pos = 180; pos >= 0; pos -= 1) { 
            servo1.write(pos);
            servo3.write(pos);               
            delay(15);                     
          }
          for (pos = 0; pos <= 180; pos += 10) { 
            servo2.write(pos);
            servo0.write(pos);
            servo4.write(pos);  
            delay(15);                      
          }
        }
        if(input=="Dedo 1 y dedo 4 están arriba"){
          for (pos = 180; pos >= 0; pos -= 1) { 
            servo1.write(pos);
            servo4.write(pos);               
            delay(15);                     
          }
          for (pos = 0; pos <= 180; pos += 10) {
            servo0.write(pos);
            servo2.write(pos);
            servo3.write(pos);  
            delay(15);                      
          }
        }
        if(input=="Dedo 2 y dedo 3 están arriba"){
          for (pos = 180; pos >= 0; pos -= 1) { 
            servo2.write(pos);
            servo3.write(pos);               
            delay(15);                     
          }
           for (pos = 0; pos <= 180; pos += 10) { 
            servo0.write(pos);
            servo1.write(pos);
            servo4.write(pos);  
            delay(15);                      
          }
        }
        if(input=="Dedo 2 y dedo 4 están arriba"){
          for (pos = 180; pos >= 0; pos -= 1) { 
            servo2.write(pos);
            servo4.write(pos);               
            delay(15);                     
          }
           for (pos = 0; pos <= 180; pos += 10) { 
            servo0.write(pos);
            servo1.write(pos);
            servo3.write(pos);  
            delay(15);                      
          }
        }
        if(input=="Dedo 3 y dedo 4 están arriba"){
          for (pos = 180; pos >= 0; pos -= 1) { 
            servo2.write(pos);
            servo3.write(pos);               
            delay(15);                     
          }
           for (pos = 0; pos <= 180; pos += 10) { 
            servo0.write(pos);
            servo1.write(pos);
            servo2.write(pos);  
            delay(15);                      
          }
        }
        //---------- tres dedos ---------------------------------------------//
        
        if(input=="Dedo 0, dedo 1 y dedo 2 están arriba"){
          for (pos = 180; pos >= 0; pos -= 1) { 
            servo0.write(pos);
            servo1.write(pos); 
            servo2.write(pos);              
            delay(15);                     
          }
           for (pos = 0; pos <= 180; pos += 10) { 
            servo3.write(pos);
            servo4.write(pos);  
            delay(15);                      
          }
         }
         if(input=="Dedo 0, dedo 1 y dedo 3 están arriba"){
          for (pos = 180; pos >= 0; pos -= 1) { 
            servo0.write(pos);
            servo1.write(pos); 
            servo3.write(pos);              
            delay(15);                     
          }
          for (pos = 0; pos <= 180; pos += 10) { 
            servo2.write(pos);
            servo4.write(pos);  
            delay(15);                      
          }
         }
        if(input=="Dedo 0, dedo 1 y dedo 4 están arriba"){
          for (pos = 180; pos >= 0; pos -= 1) { 
            servo0.write(pos);
            servo1.write(pos); 
            servo4.write(pos);              
            delay(15);                     
          }
          for (pos = 0; pos <= 180; pos += 10) { 
            servo2.write(pos);
            servo3.write(pos);  
            delay(15);                      
          }
         }
         if(input=="Dedo 0, dedo 2 y dedo 3 están arriba"){
          for (pos = 180; pos >= 0; pos -= 1) { 
            servo0.write(pos);
            servo2.write(pos); 
            servo3.write(pos);              
            delay(15);                     
          }
          for (pos = 0; pos <= 180; pos += 10) { 
            servo1.write(pos);
            servo4.write(pos);  
            delay(15);                      
          }
         }
         if(input=="Dedo 0, dedo 2 y dedo 4 están arriba"){
          for (pos = 180; pos >= 0; pos -= 1) { 
            servo0.write(pos);
            servo2.write(pos); 
            servo4.write(pos);              
            delay(15);                     
          }
          for (pos = 0; pos <= 180; pos += 10) { 
            servo1.write(pos);
            servo3.write(pos);  
            delay(15);                      
          }
         }
          if(input=="Dedo 0, dedo 3 y dedo 4 están arriba"){
          for (pos = 180; pos >= 0; pos -= 1) { 
            servo0.write(pos);
            servo3.write(pos); 
            servo4.write(pos);              
            delay(15);                     
          }
          for (pos = 0; pos <= 180; pos += 10) {
            servo1.write(pos);
            servo2.write(pos);  
            delay(15);                      
          }
         }
         if(input=="Dedo 1, dedo 2 y dedo 3 están arriba"){
          for (pos = 180; pos >= 0; pos -= 1) { 
            servo1.write(pos);
            servo2.write(pos); 
            servo3.write(pos);              
            delay(15);                     
          }
          for (pos = 0; pos <= 180; pos += 10) { 
            servo0.write(pos);
            servo4.write(pos);  
            delay(15);                      
          }
         }
          if(input=="Dedo 1, dedo 2 y dedo 4 están arriba"){
          for (pos = 180; pos >= 0; pos -= 1) { 
            servo1.write(pos);
            servo2.write(pos); 
            servo4.write(pos);              
            delay(15);                     
          }
          for (pos = 0; pos <= 180; pos += 10) { 
            servo0.write(pos);
            servo3.write(pos);  
            delay(15);                      
          }
         }
          if(input=="Dedo 1, dedo 3 y dedo 4 están arriba"){
          for (pos = 180; pos >= 0; pos -= 1) { 
            servo1.write(pos);
            servo3.write(pos); 
            servo4.write(pos);              
            delay(15);                     
          }
          for (pos = 0; pos <= 180; pos += 10) { 
            servo0.write(pos);
            servo2.write(pos);  
            delay(15);                      
          }
         }
          if(input=="Dedo 2, dedo 3 y dedo 4 están arriba"){
          for (pos = 180; pos >= 0; pos -= 1) { 
            servo2.write(pos);
            servo3.write(pos); 
            servo4.write(pos);              
            delay(15);                     
          }
          for (pos = 0; pos <= 180; pos += 10) { 
            servo0.write(pos);
            servo1.write(pos);  
            delay(15);                      
          }
         }
         //------------------------ cuatro dedos arriba --------------------------------------/
         
         if(input=="Dedo 1, dedo 2, dedo 3 y dedo 4 están arriba"){
          for (pos = 180; pos >= 0; pos -= 1) { 
            servo1.write(pos);
            servo2.write(pos); 
            servo3.write(pos);  
            servo4.write(pos);                    
            delay(15);                     
          }
          for (pos = 0; pos <= 180; pos += 10) { 
            servo0.write(pos);
            delay(15);                      
          }
         }
         if(input=="Dedo 0, dedo 2, dedo 3 y dedo 4 están arriba"){
          for (pos = 180; pos >= 0; pos -= 1) { 
            servo0.write(pos);
            servo2.write(pos); 
            servo3.write(pos);  
            servo4.write(pos);                    
            delay(15);                     
          }
          for (pos = 0; pos <= 180; pos += 10) { 
            servo1.write(pos);
            delay(15);                      
          }
         }
         if(input=="Dedo 0, dedo 1, dedo 3 y dedo 4 están arriba"){
          for (pos = 180; pos >= 0; pos -= 1) { 
            servo0.write(pos);
            servo1.write(pos); 
            servo3.write(pos);  
            servo4.write(pos);                    
            delay(15);                     
          }
          for (pos = 0; pos <= 180; pos += 10) { 
            servo2.write(pos);
            delay(15);                      
          }
         }
         if(input=="Dedo 0, dedo 1, dedo 2 y dedo 4 están arriba"){
          for (pos = 180; pos >= 0; pos -= 1) { 
            servo0.write(pos);
            servo1.write(pos); 
            servo2.write(pos);  
            servo4.write(pos);                    
            delay(15);                     
          }
          for (pos = 0; pos <= 180; pos += 10) { 
            servo3.write(pos);
            delay(15);                      
          }
         }
         if(input=="Dedo 0, dedo 1, dedo 2 y dedo 3 están arriba"){
          for (pos = 180; pos >= 0; pos -= 1) { 
            servo0.write(pos);
            servo1.write(pos); 
            servo2.write(pos);  
            servo3.write(pos);                    
            delay(15);                     
          }
          for (pos = 0; pos <= 180; pos += 10) { 
            servo4.write(pos);
            delay(15);                      
          }
         }
         //------------------------ todos los dedos arriba -----------------------//
         if(input=="Última respuesta: Todos los dedos están arriba"){
          for (pos = 180; pos >= 0; pos -= 1) {
            servo0.write(pos); 
            servo1.write(pos);
            servo2.write(pos); 
            servo3.write(pos);  
            servo4.write(pos);                    
            delay(15);                     
          }
         }
  }
}
