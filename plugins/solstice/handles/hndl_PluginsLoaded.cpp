#include "NWNXSolstice.h"

extern CNWNXSolstice solstice;

int Handle_PluginsLoaded(WPARAM p, LPARAM a) {
    if (!solstice.InitializeEventHandlers())
	solstice.Log(0, "ERROR: Unable to initialize NWNX event handlers!");

    return 0;
}
