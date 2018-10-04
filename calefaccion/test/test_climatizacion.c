#include "unity.h"
#include "climatizacion.h"


void setUp (void)  {

}

void tearDown (void)  {

}

/*****************************************************************************
    TEST Correspondientes a requerimiento AUTO-ER-0001-REQ0019
*******************************************************************************/
void test_ClimatizacionOff(void)  {
   //creamos un control virtual de encendido_apagado
   bool on_off_virtual = false;
   uint8_t selector_temp_virtual = 24;

   Climatizacion_create(&on_off_virtual, &selector_temp_virtual);
   Climatizacion_OnOff(true);
   TEST_ASSERT_EQUAL(true,on_off_virtual);
}

void test_ClimatizacionOn(void)  {
   //creamos un control virtual de encendido_apagado
   bool on_off_virtual = false;
   uint8_t selector_temp_virtual = 24;

   Climatizacion_create(&on_off_virtual, &selector_temp_virtual);
   Climatizacion_OnOff(false);
   TEST_ASSERT_EQUAL(false,on_off_virtual);
}
//-----------------------------------------------------------------------------


/*****************************************************************************
    TEST Correspondientes a requerimiento AUTO-ER-0001-REQ0018
*******************************************************************************/
void test_ClimatizacionSetTemp(void)  {
    //creamos un selector de temperatura virtual con valor por defecto
    bool on_off_virtual = false;
    uint8_t selector_temp_virtual = 24;

    Climatizacion_create(&on_off_virtual, &selector_temp_virtual);
    Climatizacion_SetTemp(26);
    TEST_ASSERT_EQUAL_UINT8(26,selector_temp_virtual);
}

//-----------------------------------------------------------------------------


/*****************************************************************************
    TEST Correspondientes a requerimiento AUTO-ER-0001-REQ0020
*******************************************************************************/
void test_Calefaccion_caso1(void)  {
  bool on_off_virtual = false;
  uint8_t selector_temp_virtual = 24;
  uint8_t temperatura_ambiente;
  bool EstadoCalefaccion;

/**Caso de prueba 1: Control encendido: No
    Temperatura ambiente 20 ºC
    Temperatura de control 22 ºC
    --> La calefacción no debe encenderse
*/

  Climatizacion_create(&on_off_virtual, &selector_temp_virtual);
  Climatizacion_SetTemp(22);
  Climatizacion_OnOff(false);
  temperatura_ambiente = Climatizacion_readTemp();
  EstadoCalefaccion = Climatizacion_Calefaccion(temperatura_ambiente);
  TEST_ASSERT_EQUAL(false,EstadoCalefaccion);
}
//-----------------------------------------------------------------------------
