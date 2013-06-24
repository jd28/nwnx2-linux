#include "NWNXLib.h"

// Derived from virusman's version in nwnx_events
CExoLocStringElement *nwn_GetCExoLocStringElement(CExoLocString* str, uint32_t locale){
    if(str->strref != -1) return NULL;
    CExoLocStringElement *ele;
    CExoLinkedListNode *node = NULL;
    for(node = str->list->header->first; node; node = node->next){
        ele = (CExoLocStringElement *)node->data;

        nx_log(NX_LOG_INFO, 3, "Text: %s, Locale: %d", 
               ele->text.text,
               ele->lang);

        if (ele->lang == locale)
            return ele;
    }
    return NULL;
}


// Derived from virusman's version in nwnx_events
const char *nwn_GetCExoLocStringText(CExoLocString* str, uint32_t locale){
    nx_log(NX_LOG_INFO, 0, "Strref: %d", str->strref);
    CExoLocStringElement *ele = nwn_GetCExoLocStringElement(str, locale);
    if ( ele ) {
        return ele->text.text;
    }
	
    return NULL;
}
