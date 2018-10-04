#include <stdint.h>
#include <stdbool.h>

struct _climatizacionCtrl  {
  bool *IO_ctrl;
  uint8_t *temp_setting;
};

void Climatizacion_create (bool *IO, uint8_t *setTemp);
void Climatizacion_OnOff (bool X);
void Climatizacion_SetTemp (uint8_t temp);
uint8_t Climatizacion_readTemp(void);
bool Climatizacion_Calefaccion(uint8_t tempAmbiente);
