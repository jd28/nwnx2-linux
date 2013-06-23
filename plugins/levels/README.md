Purpose:
* This plugin was designed to allow player characters to level beyond 40th level.
  The levels added are no different than those added by the game on successful level up.
  However, the leveling process post 40th must still be conversation based.
* Hooks spell known by level & spell gain by level in order to avoid overrunning buffers at post 40th level.

Known Issues:
* Using SetXP on player characters after having taken levels beyond 40
  can result in a total loss of those levels.  Characters however would
  be able to relevel.

Todo:
* Try to get rid of hardcoded variable names.
