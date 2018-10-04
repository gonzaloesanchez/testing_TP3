#include "build/temp/_test_climatizacion.c"
#include "mock_hardware.h"
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



  getADC_value_CMockExpectAndReturn(73, 20);

  temperatura_ambiente = Climatizacion_readTemp();





  UnityAssertEqualNumber((UNITY_INT)(UNITY_UINT8 )((20)), (UNITY_INT)(UNITY_UINT8 )((temperatura_ambiente)), (

 ((void *)0)

 ), (UNITY_UINT)(77), UNITY_DISPLAY_STYLE_UINT8);



  EstadoCalefaccion = Climatizacion_Calefaccion(temperatura_ambiente);

  UnityAssertEqualNumber((UNITY_INT)((

 0

 )), (UNITY_INT)((EstadoCalefaccion)), (

 ((void *)0)

 ), (UNITY_UINT)(80), UNITY_DISPLAY_STYLE_INT);

}



void test_Calefaccion_caso3(void) {

  

 _Bool 

      on_off_virtual;

  uint8_t selector_temp_virtual;

  uint8_t temperatura_ambiente;

  

 _Bool 

      EstadoCalefaccion;















  Climatizacion_create(&on_off_virtual, &selector_temp_virtual);

  Climatizacion_SetTemp(24);

  Climatizacion_OnOff(

                     1

                         );



  getADC_value_CMockExpectAndReturn(99, 10);

  temperatura_ambiente = Climatizacion_readTemp();





  UnityAssertEqualNumber((UNITY_INT)(UNITY_UINT8 )((10)), (UNITY_INT)(UNITY_UINT8 )((temperatura_ambiente)), (

 ((void *)0)

 ), (UNITY_UINT)(103), UNITY_DISPLAY_STYLE_UINT8);



  EstadoCalefaccion = Climatizacion_Calefaccion(temperatura_ambiente);

  UnityAssertEqualNumber((UNITY_INT)((

 1

 )), (UNITY_INT)((EstadoCalefaccion)), (

 ((void *)0)

 ), (UNITY_UINT)(106), UNITY_DISPLAY_STYLE_INT);

}



void test_Calefaccion_caso4(void) {

  

 _Bool 

      on_off_virtual;

  uint8_t selector_temp_virtual;

  uint8_t temperatura_ambiente;

  

 _Bool 

      EstadoCalefaccion;















  Climatizacion_create(&on_off_virtual, &selector_temp_virtual);

  Climatizacion_SetTemp(16);

  Climatizacion_OnOff(

                     1

                         );



  getADC_value_CMockExpectAndReturn(125, 16);

  temperatura_ambiente = Climatizacion_readTemp();





  UnityAssertEqualNumber((UNITY_INT)(UNITY_UINT8 )((16)), (UNITY_INT)(UNITY_UINT8 )((temperatura_ambiente)), (

 ((void *)0)

 ), (UNITY_UINT)(129), UNITY_DISPLAY_STYLE_UINT8);



  EstadoCalefaccion = Climatizacion_Calefaccion(temperatura_ambiente);

  UnityAssertEqualNumber((UNITY_INT)((

 0

 )), (UNITY_INT)((EstadoCalefaccion)), (

 ((void *)0)

 ), (UNITY_UINT)(132), UNITY_DISPLAY_STYLE_INT);

}



void test_AC_caso2(void) {

  

 _Bool 

      on_off_virtual;

  uint8_t selector_temp_virtual;

  uint8_t temperatura_ambiente;

  

 _Bool 

      EstadoAC;















  Climatizacion_create(&on_off_virtual, &selector_temp_virtual);

  Climatizacion_SetTemp(20);

  Climatizacion_OnOff(

                     0

                          );



  getADC_value_CMockExpectAndReturn(151, 25);

  temperatura_ambiente = Climatizacion_readTemp();





  UnityAssertEqualNumber((UNITY_INT)(UNITY_UINT8 )((25)), (UNITY_INT)(UNITY_UINT8 )((temperatura_ambiente)), (

 ((void *)0)

 ), (UNITY_UINT)(155), UNITY_DISPLAY_STYLE_UINT8);



  EstadoAC = Climatizacion_AC(temperatura_ambiente);

  UnityAssertEqualNumber((UNITY_INT)((

 0

 )), (UNITY_INT)((EstadoAC)), (

 ((void *)0)

 ), (UNITY_UINT)(158), UNITY_DISPLAY_STYLE_INT);

}
