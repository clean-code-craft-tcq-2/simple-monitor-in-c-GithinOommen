#include "header.h"


SelectLanguage display[2] ={{{"Temperature", "StateofCharge", "ChargeRate"},
                            {"is approaching Higher limit","is approaching Lower limit"},
                            {"is Higher than Upper limit", "is Lower than Lower limit"}},
                            {{"Temperatur","Ladezustand", "Ladestrom"},
                            {"nähert sich der höheren Grenze","nähert sich der unteren Grenze"},
                            {"ist höher als Obergrenze", "ist niedriger als die untere Grenze"}}};

void print(int language_v, int parameter_v, int alert, int Error_v)
{
    if (alert)
    {
        printf("\n %s %s",display[language_v].parameter[parameter_v], display[language_v].alert[Error_v]);
    }
    else
    {
        printf("\n %s %s",display[language_v].parameter[parameter_v], display[language_v].warning[Error_v]);
    }
}

