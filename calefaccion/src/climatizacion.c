#include "climatizacion.h"

static bool *climatizacion_IO;

void Climatizacion_create (bool *X)  {
  climatizacion_IO = X;
}

void Climatizacion_OnOff (bool X)  {
  *climatizacion_IO = X;
}
