#include "climatizacion.h"
#include "hardware.h"

static struct _climatizacionCtrl g_sControl_climatizacion;
static bool g_bCalefactor = false;
static bool g_bAireAcondicionado = false;

void Climatizacion_create (bool *IO, uint8_t *setTemp)  {
  g_sControl_climatizacion.IO_ctrl = IO;
  g_sControl_climatizacion.temp_setting = setTemp;
}

void Climatizacion_OnOff (bool X)  {
  *(g_sControl_climatizacion.IO_ctrl) = X;
}

void Climatizacion_SetTemp (uint8_t temp)  {
    *(g_sControl_climatizacion.temp_setting) = temp;
}


void Climatizacion_setEstadoCalefactor (bool X)  {
  g_bCalefactor = X;
}

bool Climatizacion_getEstadoCalefactor (void)  {
  return g_bCalefactor;
}

void Climatizacion_setEstadoAC (bool X)  {
  g_bAireAcondicionado = X;
}

bool Climatizacion_getEstadoAC (void)  {
  return g_bAireAcondicionado;
}

uint8_t Climatizacion_readTemp(void)  {
  uint8_t rawValue;

  rawValue = getADC_value();
  return rawValue;
}


bool Climatizacion_Calefaccion(uint8_t tempAmbiente)  {
  bool Ret;
  if (*(g_sControl_climatizacion.IO_ctrl))  {
    if (tempAmbiente < (*(g_sControl_climatizacion.temp_setting) - 2 ))  {
      Climatizacion_setEstadoCalefactor(true);
    }
    else  {
      Climatizacion_setEstadoCalefactor(false);
    }
  }
  Ret = Climatizacion_getEstadoCalefactor();

  return Ret;
}


bool Climatizacion_AC(uint8_t tempAmbiente)  {
  bool Ret;

  if (*(g_sControl_climatizacion.IO_ctrl))  {
    if (tempAmbiente > (*(g_sControl_climatizacion.temp_setting) + 2 ))  {
      Climatizacion_setEstadoAC(true);
    }
    if (tempAmbiente == *(g_sControl_climatizacion.temp_setting))  {
      Climatizacion_setEstadoAC(false);
    }
  }
  Ret = Climatizacion_getEstadoAC();

  return Ret;
}
