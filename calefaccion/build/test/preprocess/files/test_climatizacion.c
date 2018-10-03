#include "build/temp/_test_climatizacion.c"
#include "climatizacion.h"
#include "unity.h"




void setUp (void) {



}



void tearDown (void) {



}



void test_ClimatizacionOff(void) {



   

  _Bool 

       on_off_virtual = 

                        0

                             ;



   Climatizacion_create(&on_off_virtual);

   Climatizacion_OnOff(

                      1

                          );

   UnityAssertEqualNumber((UNITY_INT)((

  1

  )), (UNITY_INT)((on_off_virtual)), (

  ((void *)0)

  ), (UNITY_UINT)(19), UNITY_DISPLAY_STYLE_INT);

}



void test_ClimatizacionOn(void) {



   

  _Bool 

       on_off_virtual = 

                        0

                             ;



   Climatizacion_create(&on_off_virtual);

   Climatizacion_OnOff(

                      0

                           );

   UnityAssertEqualNumber((UNITY_INT)((

  0

  )), (UNITY_INT)((on_off_virtual)), (

  ((void *)0)

  ), (UNITY_UINT)(28), UNITY_DISPLAY_STYLE_INT);

}
