int32_t nwn_GetDamageVisualEffect(int32_t type, bool is_ranged) {
	C2DA *tda = nwn_GetCached2da("damagehitvisual");
	if ( tda ) {
		int idx = __builtin_ffs(type) - 1;
		if ( is_ranged ) {
			return nwn_Get2daInt(tda, "RangedEffectID", idx);
		}
		else {
			return nwn_Get2daInt(tda, "VisualEffectID", idx);
		}
	}
	
	return 0;
}
