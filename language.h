#ifndef LANGUAGE_H_INCLUDED
#define LANGUAGE_H_INCLUDED


typedef struct SelectLanguage
{
    char parameter[3][60];
    char warning[3][60];
	char alert[3][60];
}SelectLanguage;

extern SelectLanguage display[2];
void print(int language_v, int parameter_v, int warning, int Error_v);

#endif