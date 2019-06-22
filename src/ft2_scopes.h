#ifndef __FT2_SCOPES_H
#define __FT2_SCOPES_H

#include <stdint.h>
#include <stdbool.h>
#include "ft2_header.h"

void resetOldScopeRates(void);
int32_t getSamplePosition(uint8_t ch);
void stopAllScopes(void);
void unmuteAllChansOnMusicLoad(void);
bool testScopesMouseDown(void);
void drawScopes(void);
void drawScopeFramework(void);
bool initScopes(void);

typedef struct lastChInstr_t
{
	uint8_t sampleNr, instrNr;
} lastChInstr_t;

extern lastChInstr_t lastChInstr[MAX_VOICES];

#endif
