#include "unity.h"
#include "climatizacion.h"
#include "mock_hardware.h"

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
    TEST Correspondientes a casos de prueba dados en TP2
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

  getADC_value_ExpectAndReturn(20);
  temperatura_ambiente = Climatizacion_readTemp();

  //comprobacion de que el mock esta funcionando
  TEST_ASSERT_EQUAL_UINT8(20,temperatura_ambiente);

  EstadoCalefaccion = Climatizacion_Calefaccion(temperatura_ambiente);
  TEST_ASSERT_EQUAL(false,EstadoCalefaccion);
}

void test_Calefaccion_caso3(void)  {
  bool on_off_virtual;
  uint8_t selector_temp_virtual;
  uint8_t temperatura_ambiente;
  bool EstadoCalefaccion;

/**Caso de prueba 3: Control encendido: Si
    Temperatura ambiente 10 ºC
    Temperatura de control 24 ºC
    --> La calefacción debe encenderse
*/

  Climatizacion_create(&on_off_virtual, &selector_temp_virtual);
  Climatizacion_SetTemp(24);
  Climatizacion_OnOff(true);

  getADC_value_ExpectAndReturn(10);
  temperatura_ambiente = Climatizacion_readTemp();

  //comprobacion de que el mock esta funcionando
  TEST_ASSERT_EQUAL_UINT8(10,temperatura_ambiente);

  EstadoCalefaccion = Climatizacion_Calefaccion(temperatura_ambiente);
  TEST_ASSERT_EQUAL(true,EstadoCalefaccion);
}

void test_Calefaccion_caso4(void)  {
  bool on_off_virtual;
  uint8_t selector_temp_virtual;
  uint8_t temperatura_ambiente;
  bool EstadoCalefaccion;

/**Caso de prueba 4: Control encendido: si
    Temperatura ambiente 16 ºC
    Temperatura de control 16 ºC
    --> La calefacción o el aire acondicionado deben apagarse
*/

  Climatizacion_create(&on_off_virtual, &selector_temp_virtual);
  Climatizacion_SetTemp(16);
  Climatizacion_OnOff(true);

  getADC_value_ExpectAndReturn(16);
  temperatura_ambiente = Climatizacion_readTemp();

  //comprobacion de que el mock esta funcionando
  TEST_ASSERT_EQUAL_UINT8(16,temperatura_ambiente);

  EstadoCalefaccion = Climatizacion_Calefaccion(temperatura_ambiente);
  TEST_ASSERT_EQUAL(false,EstadoCalefaccion);
}

void test_AC_caso2(void)  {
  bool on_off_virtual;
  uint8_t selector_temp_virtual;
  uint8_t temperatura_ambiente;
  bool EstadoAC;

/**Caso de prueba 2: Control encendido: No
    Temperatura ambiente 25 ºC
    Temperatura de control 20 ºC
    --> El aire acondicionado no debe encenderse
*/

  Climatizacion_create(&on_off_virtual, &selector_temp_virtual);
  Climatizacion_SetTemp(20);
  Climatizacion_OnOff(false);

  getADC_value_ExpectAndReturn(25);
  temperatura_ambiente = Climatizacion_readTemp();

  //comprobacion de que el mock esta funcionando
  TEST_ASSERT_EQUAL_UINT8(25,temperatura_ambiente);

  EstadoAC = Climatizacion_AC(temperatura_ambiente);
  TEST_ASSERT_EQUAL(false,EstadoAC);
}


void test_AC_caso4(void)  {
  bool on_off_virtual;
  uint8_t selector_temp_virtual;
  uint8_t temperatura_ambiente;
  bool EstadoAC;

/**Caso de prueba 1: Control encendido: si
    Temperatura ambiente 16 ºC
    Temperatura de control 16 ºC
    --> La calefacción o el aire acondicionado deben apagarse
*/

  Climatizacion_create(&on_off_virtual, &selector_temp_virtual);
  Climatizacion_SetTemp(16);
  Climatizacion_OnOff(true);

  getADC_value_ExpectAndReturn(16);
  temperatura_ambiente = Climatizacion_readTemp();

  //comprobacion de que el mock esta funcionando
  TEST_ASSERT_EQUAL_UINT8(16,temperatura_ambiente);

  EstadoAC = Climatizacion_AC(temperatura_ambiente);
  TEST_ASSERT_EQUAL(false,EstadoAC);
}


void test_AC_caso5(void)  {
  bool on_off_virtual;
  uint8_t selector_temp_virtual;
  uint8_t temperatura_ambiente;
  bool EstadoAC;

/**Caso de prueba 5: Control encendido: si
    Temperatura ambiente 32 ºC
    Temperatura de control 24 ºC
    --> El aire acondicionado debe encenderse
*/

  Climatizacion_create(&on_off_virtual, &selector_temp_virtual);
  Climatizacion_SetTemp(24);
  Climatizacion_OnOff(true);

  getADC_value_ExpectAndReturn(32);
  temperatura_ambiente = Climatizacion_readTemp();

  //comprobacion de que el mock esta funcionando
  TEST_ASSERT_EQUAL_UINT8(32,temperatura_ambiente);

  EstadoAC = Climatizacion_AC(temperatura_ambiente);
  TEST_ASSERT_EQUAL(true,EstadoAC);
}

//-----------------------------------------------------------------------------
