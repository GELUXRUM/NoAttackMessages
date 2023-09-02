#pragma once

namespace HookLineAndSinker
{
	void HookedShowHUDMessage(void*, const char*, const char*, bool);

	void RegisterHooks(F4SE::Trampoline& trampoline);
}
