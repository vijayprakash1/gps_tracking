#include <HardwareSerial.h>
unsigned char incomer_data = 0;
unsigned char longitude[13];        // to store longitude
unsigned char latitude[13];         // to store latitude
unsigned int array_count=0;
unsigned int count=0;
void setup() {
  Serial.begin(115200);
  Serial2.begin(115200,SERIAL_8N1, 16, 17);

}

void loop() {
   Serial2.print("AT\r\n");           // SIM7000 AT commands
   delay(300);
    while (Serial2.available())                //If data is received through Serial 2
    {    
    Serial.print(Serial.read());
   // read_LatLong();
    delay(300);
    }
  /* Serial2.print("AT+CGNSPWR=1\r\n");   // GPS power control activation
    delay(300);
    Serial2.print("AT+CGNSINF\r\n");     // Get GPS information
    delay(300);
    while (Serial2.available())                //If data is received through Serial 2
    {    
    Serial.write(Serial.read());
    read_LatLong();

    }

  Serial.println("\r\n");
   delay(6000);*/

}
/*
//+CGNSINF: 1,1,20180806181347.000,19.173748,73.070148,62.300,0.00,214.6,1,,2.8,3.0,1.0,,13,4,,,34,,
void read_LatLong()
{
  incomer_data=Serial2.read(); // Check the string '+CGNSINF: 1,1,'
//------------------------------ Step by step finding the +CGNSINF: 1,1,line----------------------------
/*  if(incomer_data=='+')
  { // First statement of the GPS data start with a + sign
     incomer_data=Serial2.read(); // If the first if become true then the next phase
     if(incomer_data=='C')
     {
       incomer_data=Serial2.read();
       if(incomer_data=='G');
       {
         incomer_data=Serial2.read();
         if(incomer_data=='N');
         {
            incomer_data=Serial2.read();
            if(incomer_data=='S')
            {
               incomer_data=Serial2.read();
               if(incomer_data=='I')
               {
                 incomer_data=Serial2.read();
                 if(incomer_data=='N')
                 {
                   incomer_data=Serial2.read();
                   if(incomer_data=='F')
                   {
                     incomer_data=Serial2.read();
                     if(incomer_data==':')
                     {
                       incomer_data=Serial2.read();
                       if(incomer_data==' ')
                       {
                        incomer_data=Serial2.read();
                        if(incomer_data=='1')
                        {
                          incomer_data=Serial2.read();
                          if(incomer_data==',')
                          {
                             incomer_data=Serial2.read();
                              if(incomer_data=='1')
                              {
                                incomer_data=Serial2.read();
                                if(incomer_data==',')
                                    { // first , received
                                      incomer_data=Serial2.read(); // At this stage Final check in done, +CGNSINF: 1,1, is found.
          
                                          while (incomer_data != ',')
                                          { // skipping GMT Time 
                                              incomer_data=Serial2.read();
                                          }
                                          incomer_data=Serial2.read();
                                          latitude[0] = incomer_data;                                
          
                                          while(incomer_data != ',')
                                          {
                                              for(array_count=1;incomer_data!=',';array_count++)
                                              {
                                                incomer_data=Serial2.read();
                                                if(incomer_data==',')
                                                break;
                                                
                                                latitude[array_count]=incomer_data; // Store the Latitude data
                                              }
                           
                                          }
                                          incomer_data=Serial2.read();
                                          longitude[0] = incomer_data;
                                         while(incomer_data != ',')
                                         {
                                              for(array_count=1;incomer_data!=',';array_count++)
                                              {
                                                    incomer_data=Serial2.read();
                                                    if(incomer_data==',')
                                                    break;
                                                    
                                                    longitude[array_count]=incomer_data; // Store the Longitude data
                                              }
                                         }
                                              array_count=0; 
                                              Serial.print("Latitude: ");
                                              while(array_count<12){ // Array of Latitude data is 11 digit
                                                  Serial.write(latitude[array_count]); // Print the Latitude data
                                                  array_count++;
                                                  }
                                             
                                             array_count=0;
                                             Serial.println("\n\r");
                                             Serial.print("Longitude: ");
                                              while(array_count<13) // Array of Longitude data is 12 digit
                                              {
                                                  Serial.write(longitude[array_count]); // Print the Longitude data
                                                  array_count++;
                                              }    
                                             }
                                          }
                                        }
                                     }
                                  }
                               }
                            }
                         }
                     }
                  }
               }
            }
         }
     }
}*/
