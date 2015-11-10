

// VARIABLES
// Static variables -- Variables that do not change throughout the code
int sensorPin = 0; //reference to analog pin 0 (A0)

// Dynamic variables -- Variables that do change throughout the code


void setup() {
  // setup routines
  Serial.begin(9600);
  while (! Serial);
  
  // Instruction message:
  // START REC.
  Serial.println("Enter 'start' to begin reading serial data from sensor");
  
}

// MAIN PROGRAM LOOP
void loop() {
  
  if (Serial.available()) {
    
    sensordataRead();   
    
  }// End 'if-statement'
  
}// End 'void-loop'


// PROGRAM SUBFUNCTIONS AND EXECUTIONS
void sensordataRead() {

  int resp = Serial.read();
  int expected = '1';  
  
  if (resp == expected) {
    
    Serial.println("START RECORDING");
    
    int outputArray[100];
    int i;
    
    for (i = 0; i < 100; i++) {
      
      int counter = i;
      int sensorVal = analogRead(sensorPin);
        
      outputArray[i] = sensorVal;
        
      String separator = ", ";
      String outputString = counter + separator + sensorVal;
      Serial.println(outputString);

      delay(100); // Purposely delay recording

      //if (i == 99) {
        
        //resp = '0';
          
      //}
      
    } // End of 'for-loop'
    
  } // End of 'if?'  

} // End of 'sensordataRead'

