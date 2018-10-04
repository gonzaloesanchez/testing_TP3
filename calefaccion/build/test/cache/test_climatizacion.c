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

   uint8_t selector_temp_virtual = 24;



   Climatizacion_create(&on_off_virtual, &selector_temp_virtual);

   Climatizacion_OnOff(

                      1

                          );

   UnityAssertEqualNumber((UNITY_INT)((

  1

  )), (UNITY_INT)((on_off_virtual)), (

  ((void *)0)

  ), (UNITY_UINT)(23), UNITY_DISPLAY_STYLE_INT);

}



void test_ClimatizacionOn(void) {



   

  _Bool 

       on_off_virtual = 

                        0

                             ;

   uint8_t selector_temp_virtual = 24;



   Climatizacion_create(&on_off_virtual, &selector_temp_virtual);

   Climatizacion_OnOff(

                      0

                           );

   UnityAssertEqualNumber((UNITY_INT)((

  0

  )), (UNITY_INT)((on_off_virtual)), (

  ((void *)0)

  ), (UNITY_UINT)(33), UNITY_DISPLAY_STYLE_INT);

}













void test_ClimatizacionSetTemp(void) {



    

   _Bool 

        on_off_virtual = 

                         0

                              ;

    uint8_t selector_temp_virtual = 24;



    Climatizacion_create(&on_off_virtual, &selector_temp_virtual);

    Climatizacion_SetTemp(26);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_UINT8 )((26)), (UNITY_INT)(UNITY_UINT8 )((selector_temp_virtual)), (

   ((void *)0)

   ), (UNITY_UINT)(48), UNITY_DISPLAY_STYLE_UINT8);

}















void test_Calefaccion_caso1(void) {

  

 _Bool 

      on_off_virtual = 

                       0

                            ;

  uint8_t selector_temp_virtual = 24;

  uint8_t temperatura_ambiente;

  

 _Bool 

      EstadoCalefaccion;















  Climatizacion_create(&on_off_virtual, &selector_temp_virtual);

  Climatizacion_SetTemp(22);

  Climatizacion_OnOff(

                     0

                          );

  temperatura_ambiente = Climatizacion_readTemp();

  EstadoCalefaccion = Climatizacion_Calefaccion(temperatura_ambiente);

  UnityAssertEqualNumber((UNITY_INT)((

 0

 )), (UNITY_INT)((EstadoCalefaccion)), (

 ((void *)0)

 ), (UNITY_UINT)(74), UNITY_DISPLAY_STYLE_INT);

}
