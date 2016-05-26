/*
 * Client software for lab monitor Xbee network
 * Enter string Query Alpha char (R) for read, Number(n) for data, 
 * followed by a control caharcter (return)
 * Client will respond with Query Alpha char and data value
 */

const char thisClient = 'A';
char inByte;
int queryNumber;    // data select number (input pin or collected data)
int querySelect;    //address of network client
const int arrayLimit = 50;
int inputArray[arrayLimit] = {0}; //The full array in proccessed inputs
unsigned long milliTime = millis();

const int LED = 13; // local indicator

void setup() {
  // initialize serial:
  Serial.begin(9600);
  // make the pins outputs:
  Serial.println(".");
  pinMode(LED,OUTPUT);
}

void loop() {
  // if there's any serial available, read it:
  while (Serial.available() > 0) {
    inByte = Serial.read();
    if (isDigit(inByte)){       // a number character is received
      queryNumber = queryNumber * 10 + (inByte - 48);
      queryNumber = constrain(queryNumber,0,arrayLimit);
//      Serial.write(inByte);
//      Serial.println("");
    }
    if (isAlpha(inByte)){       // a letter character is received
      querySelect = inByte;
//      Serial.println(inByte,DEC);
    }
    if (isControl(inByte)){     // a control character is received
      if(querySelect == thisClient){
//        Serial.write(thisClient);
        Serial.write(querySelect);
        Serial.println(inputArray[queryNumber]);
      }
      querySelect = 0;
      queryNumber = 0;      
    }
    
  }
  // Proccess inputs here ------------------------
  
  if(millis() > milliTime){    // So every 5 milliseconds do this stuff
    milliTime = millis() + 5;
    digitalWrite(LED,HIGH);
    delay(1);
    /* DATA ARRAY REGISTERS 00 TO 09 ARE RESERVED FOR STATIC INFORMATION 
     * SUCH AS SOFTWARE REVISION LEVELS AND CONFIGURATION INFORMATION 
     */
    /* this firstset of tests simply reads the digital inputs from Arduino D2-D13 and 
     *  puts a 1 or 0 in each of the registers 10-11
     */
    for(int i = 0;i < 11;i++){
      inputArray[i+10] = int(digitalRead(i+2));
    }
    /* This second set of tests simply takes the 6 analog inputs A0 to A5
     *  and puts each value read into registers 22-26
     */
    for(int i = 0;i < 6;i++){
      inputArray[i+21] = int(analogRead(i));
    }
  } // end milliTimer
  digitalWrite(LED,LOW);
}  //loop end





